#include <iostream>
#include <fstream>
#include <cwchar>

#include "header.hxx"
#include "header_output.hxx"

using namespace std;

Header* ProcessEMFHeader(ifstream &emfFile)
{
    Header header;

    // get the file size
    int fileSize;
    emfFile.seekg(0, ios::end);
    fileSize = emfFile.tellg();
    emfFile.seekg(0, ios::beg);

    emfFile.read(reinterpret_cast<char *>(&header.type), 4);

    if (header.type != EMR_HEADER) {
        cerr << "Header RecordType is not EMR_HEADER! It is " 
             << header.type << endl; 
    }

    emfFile.read(reinterpret_cast<char *>(&header.size), 4);
    
    EmfMetafileHeader     *emfHeader;
    EmfMetafileHeaderExt1 *emfHeaderExt1;
    EmfMetafileHeaderExt2 *emfHeaderExt2;
    EmfMetafileHeaderDesc *emfDesc;
    PixelFormatDescriptor *emfPxlFmtDesc;

    emfHeader = ProcessMetafileHeader(emfFile);

    // process header size based on algorithm as described in [MS-EMF]
    // section 2.3.4.2 EMR_HEADER Record Types

    int HeaderSize=88;

    if (header.size < 88) {
        cerr << "Header size less than 88 bytes - possible file "
                "corruption!" << endl;
    } else {
        HeaderSize=header.size;

        // offDescription is a 32-bit unsigned integer that specifies the
        // position in the header (offset from the beginning) where the 
        // description array exists (0 indicates no description)
         
        if (emfHeader->offDescription != 0 &&       // cannot be < size
            emfHeader->offDescription < 88) {       // of header!
            cerr << "offDescription cannot be less than the min size "
                    "of EMF header - possible file corruption!";
        } else if (emfHeader->offDescription != 0) {
            // nDescription is the size of the UTF16-LE encoded 
            // description...
            // obviously the offset position of the description + the
            // size of the description cannot be bigger than the size of
            // the header
            int descSize = emfHeader->offDescription +
                            (emfHeader->nDescription * 2);

            if (descSize > header.size) {
                cerr << "Invalid description data! This may indicate "
                        "the EMF file is corrupted";
            } else {
                HeaderSize = emfHeader->offDescription;
            }

            // header is large enough to contain extensions
            if (HeaderSize >= 100) {

                // valid pixel format values?
                int pixelSize = emfHeaderExt1->offPixelFormat + 
                                    emfHeaderExt1->cbPixelFormat;

                if (emfHeaderExt1->offPixelFormat >= 100 &&
                        pixelSize <= header.size) {
                    // yep! Then is the pixel format located before
                    // the description?
                    if (emfHeaderExt1->offPixelFormat < 
                            emfHeader->offDescription) {
                        HeaderSize = emfHeaderExt1->offPixelFormat;
                    }
                } else {
                    cerr << "Invalid pixel format size! This may "
                            "indicate the EMF file is corrupted" << endl;
                }
            }
        }
    }

    string *headerType;

    if (HeaderSize >= 108) {
        headerType = new string("EmfMetafileHeaderExtension2");

        emfHeaderExt1 = ProcessMetafileHeaderExt1(emfFile);
        emfHeaderExt2 = ProcessMetafileHeaderExt2(emfFile);
        emfDesc = ProcessMetafileHeaderDesc(emfFile, 
                    emfHeader->offDescription, emfHeader->nDescription);
        emfPxlFmtDesc = ProcessMetafileHeaderPixelFormat(emfFile,
                    emfHeaderExt1->offPixelFormat, 
                    emfHeaderExt1->cbPixelFormat);

    } else if (HeaderSize >= 100) {

        headerType = new string("EmfMetafileHeaderExtension1");
        
        emfHeaderExt1 = ProcessMetafileHeaderExt1(emfFile);
        emfDesc = ProcessMetafileHeaderDesc(emfFile, 
        emfHeader->offDescription, emfHeader->nDescription);

    } else if (HeaderSize == 88) {

        headerType = new string("EmfMetafileHeader");

        emfDesc = ProcessMetafileHeaderDesc(emfFile, 
        emfHeader->offDescription, emfHeader->nDescription);

    } else {    // this should NOT be possible!
        headerType = new string("invalid!");
    }

    header.header=emfHeader;
    header.headerExt1=emfHeaderExt1;
    header.headerExt2=emfHeaderExt2;
    header.headerDesc=emfDesc;
    header.headerPxlFmtDesc=emfPxlFmtDesc;

    cout << "Header size is " << HeaderSize << "." << endl;
    cout << "Record type for header is " << *headerType << endl << endl;

    Header *retHdr = &header;

    return retHdr;
}

EmfMetafileHeader* ProcessMetafileHeader(ifstream &emfFile) {
    EmfMetafileHeader *emfHeader = new EmfMetafileHeader();

    // get the file size
    int fileSize;
    int currentPos;

    currentPos = emfFile.tellg();
    emfFile.seekg(0, ios::end);
    fileSize = emfFile.tellg();
    emfFile.seekg(currentPos, ios::beg);

    // bounds box (in device units)
    emfHeader->bounds = new RectL();
    emfFile.read(reinterpret_cast<char *>(&emfHeader->bounds->left), 4);
    emfFile.read(reinterpret_cast<char *>(&emfHeader->bounds->top), 4);
    emfFile.read(reinterpret_cast<char *>(&emfHeader->bounds->right), 4);
    emfFile.read(reinterpret_cast<char *>(&emfHeader->bounds->bottom), 4);

    // frame box (in mm)
    emfHeader->frame = new RectL();
    emfFile.read(reinterpret_cast<char *>(&emfHeader->frame->left), 4);
    emfFile.read(reinterpret_cast<char *>(&emfHeader->frame->top), 4);
    emfFile.read(reinterpret_cast<char *>(&emfHeader->frame->right), 4);
    emfFile.read(reinterpret_cast<char *>(&emfHeader->frame->bottom), 4);

    emfFile.read(reinterpret_cast<char *>(&emfHeader->recordSignature), 4);

    if (emfHeader->recordSignature != ENHMETA_SIGNATURE) {
        cerr << "Record signature not valid in header! Should be "
             << "0x464D4520 (\"EMF \") but it is " 
             << std::hex << std::showbase 
                << emfHeader->recordSignature << endl;
    }

    emfFile.read(reinterpret_cast<char *>(&emfHeader->version), 4);
    emfFile.read(reinterpret_cast<char *>(&emfHeader->bytes), 4);
    emfFile.read(reinterpret_cast<char *>(&emfHeader->records), 4);

    if (emfHeader->bytes != fileSize) {
        cerr << "Header bytes field is not the same as the filesize! "
             << "bytes field is " << emfHeader->bytes 
             << " and the size of the file is " << fileSize << "." << endl;
    }

    emfFile.read(reinterpret_cast<char *>(&emfHeader->handles), 2);
    emfFile.read(reinterpret_cast<char *>(&emfHeader->reserved), 2);

    // note: this MUST be 0x0000 and according to Microsoft it MUST be
    // ignored... however, this makes a nice check to see if there is
    // corruption :-) So I ignore Microsoft 

    if (emfHeader->reserved != 0x0000) {
        cerr << "Reserved field MUST be 0x0000, but is actually "
             << std::hex << std::showbase << emfHeader->reserved << endl;
    }

    emfFile.read(reinterpret_cast<char *>(&emfHeader->nDescription), 4);
    emfFile.read(reinterpret_cast<char *>(&emfHeader->offDescription), 4);
    emfFile.read(reinterpret_cast<char *>(&emfHeader->nPalEntries), 4);

    // size in device units
    emfHeader->device = new SizeL();
    emfFile.read(reinterpret_cast<char *>(&emfHeader->device->cx), 4);
    emfFile.read(reinterpret_cast<char *>(&emfHeader->device->cy), 4);

    // size in millimeters
    emfHeader->millimeters = new SizeL();
    emfFile.read(reinterpret_cast<char *>(&emfHeader->millimeters->cx), 4);
    emfFile.read(reinterpret_cast<char *>(&emfHeader->millimeters->cy), 4);

    return emfHeader;
}

EmfMetafileHeaderExt1* ProcessMetafileHeaderExt1(ifstream &emfFile) {
    EmfMetafileHeaderExt1 *emfHeaderExt1 = new EmfMetafileHeaderExt1();

    emfFile.read(reinterpret_cast<char *>(&emfHeaderExt1->cbPixelFormat), 4);
    emfFile.read(reinterpret_cast<char *>(&emfHeaderExt1->offPixelFormat), 4);
    emfFile.read(reinterpret_cast<char *>(&emfHeaderExt1->bOpenGL), 4);

    return emfHeaderExt1;
}

EmfMetafileHeaderExt2* ProcessMetafileHeaderExt2(ifstream &emfFile) {
    EmfMetafileHeaderExt2 *emfHeaderExt2 = new EmfMetafileHeaderExt2();

    emfFile.read(reinterpret_cast<char *>(&emfHeaderExt2->microMetersX), 4);
    emfFile.read(reinterpret_cast<char *>(&emfHeaderExt2->microMetersY), 4);
    
    return emfHeaderExt2;
}

EmfMetafileHeaderDesc*   ProcessMetafileHeaderDesc(ifstream& emfFile, int offset, int size) {
    EmfMetafileHeaderDesc *emfHeaderDesc = new EmfMetafileHeaderDesc();

    if (offset != 0) {
        int currentPos;

        currentPos = emfFile.tellg();
        emfFile.seekg(offset, ios::beg);

        emfFile.read(reinterpret_cast<char *>(&emfHeaderDesc->description), 2*size);

        emfFile.seekg(currentPos, ios::beg);
    } else {
        emfHeaderDesc->description = new UTF_16LE();
    }

    return emfHeaderDesc;
}

PixelFormatDescriptor*   ProcessMetafileHeaderPixelFormat(ifstream &emfFile, 
                                int offset, int size) {
    PixelFormatDescriptor *emfPixelFmt = new PixelFormatDescriptor();
    int flags;
    int pixelType;

    if (offset != 0) {
        int currentPos;
       
        currentPos = emfFile.tellg();
        emfFile.seekg(offset, ios::beg);
       
        emfFile.read(reinterpret_cast<char *>(&emfPixelFmt->nSize), 2);
        emfFile.read(reinterpret_cast<char *>(&emfPixelFmt->nVersion), 2);
        emfFile.read(reinterpret_cast<char *>(flags), 4);
        emfFile.read(reinterpret_cast<char *>(pixelType), 2);
        emfFile.read(reinterpret_cast<char *>(&emfPixelFmt->cColorBits), 2);
        emfFile.read(reinterpret_cast<char *>(&emfPixelFmt->cRedBits), 2);
        emfFile.read(reinterpret_cast<char *>(&emfPixelFmt->cRedShift), 2);
        emfFile.read(reinterpret_cast<char *>(&emfPixelFmt->cGreenBits), 2);
        emfFile.read(reinterpret_cast<char *>(&emfPixelFmt->cGreenShift), 2);
        emfFile.read(reinterpret_cast<char *>(&emfPixelFmt->cBlueBits), 2);
        emfFile.read(reinterpret_cast<char *>(&emfPixelFmt->cBlueShift), 2);
        emfFile.read(reinterpret_cast<char *>(&emfPixelFmt->cAlphaBits), 2);
        emfFile.read(reinterpret_cast<char *>(&emfPixelFmt->cAlphaShift), 2);
        emfFile.read(reinterpret_cast<char *>(&emfPixelFmt->cAccumBits), 2);
        emfFile.read(reinterpret_cast<char *>(&emfPixelFmt->cAccumRedBits), 2);
        emfFile.read(reinterpret_cast<char *>(&emfPixelFmt->cAccumGreenBits), 2);
        emfFile.read(reinterpret_cast<char *>(&emfPixelFmt->cAccumBlueBits), 2);
        emfFile.read(reinterpret_cast<char *>(&emfPixelFmt->cAccumAlphaBits), 2);
        emfFile.read(reinterpret_cast<char *>(&emfPixelFmt->cDepthBits), 2);
        emfFile.read(reinterpret_cast<char *>(&emfPixelFmt->cStencilBits), 2);
        emfFile.read(reinterpret_cast<char *>(&emfPixelFmt->cAuxBuffers), 2);
        emfFile.read(reinterpret_cast<char *>(&emfPixelFmt->iLayerType), 2);
        emfFile.read(reinterpret_cast<char *>(&emfPixelFmt->bReserved), 2);
        emfFile.read(reinterpret_cast<char *>(&emfPixelFmt->dwLayerMask), 4);
        emfFile.read(reinterpret_cast<char *>(&emfPixelFmt->dwVisibleMask), 4);
        emfFile.read(reinterpret_cast<char *>(&emfPixelFmt->dwDamageMask), 4);
       
        emfPixelFmt->dwFlags = ExtractEMFFlags (flags);
        emfPixelFmt->iPixelType = ExtractEMFPixelType (pixelType);

        emfFile.seekg(currentPos, ios::beg); 
    }

    return emfPixelFmt;
}

// Taken from [MS-EMF] section 2.22 PixelFormatDescription Object

PFFlags ExtractEMFFlags(const int flags) {
    PFFlags returnFlags;

    returnFlags.PFD_NEED_PALETTE    = flags & 0x00000001;  // bit 1 (P)
    returnFlags.PFD_GENERIC_FORMAT  = flags & 0x00000002;  // bit 2 (F)
    returnFlags.PFD_SUPPORT_OPENGL  = flags & 0x00000004;  // bit 3 (SO)
    returnFlags.PFD_SUPPORT_GDI     = flags & 0x00000008;  // bit 4 (G)
    returnFlags.PFD_DRAW_TO_BITMAP  = flags & 0x00000010;  // bit 5 (M)
    returnFlags.PFD_DRAW_TO_WINDOW  = flags & 0x00000020;  // bit 6 (W)
    returnFlags.PFD_STEREO          = flags & 0x00000040;  // bit 7 (S)
    returnFlags.PFD_DOUBLEBUFFER    = flags & 0x00000080;  // bit 8 (D)
    returnFlags.PFD_SUPPORT_COMPOSITION 
                                    = flags & 0x00000100;  // bit 9 (C)
    returnFlags.PFD_DIRECT3D_ACCELERATED 
                                    = flags & 0x00000200;  // bit 10 (DA)
    returnFlags.PFD_SUPPORT_DIRECTDRAW 
                                    = flags & 0x00000400;  // bit 11 (DS)
    returnFlags.PFD_GENERIC_ACCELERATED
                                    = flags & 0x00000800;  // bit 12 (A)
    returnFlags.PFD_SWAP_LAYER_BUFFERS
                                    = flags & 0x00001000;  // bit 13 (SL)
    returnFlags.PFD_SWAP_COPY       = flags & 0x00002000;  // bit 14 (SC)
    returnFlags.PFD_SWAP_EXCHANGE   = flags & 0x00004000;  // bit 15 (SE)
    returnFlags.PFD_NEED_SYSTEM_PALETTE
                                    = flags & 0x00008000;  // bit 16 (SP)
    // bits 17 to 28 are 0
    returnFlags.PFD_STEREO_DONTCARE = flags & 0x10000000;  // bit 29 (SD)
    returnFlags.PFD_DOUBLEBUFFER_DONTCARE
                                    = flags & 0x20000000;  // bit 30 (DD)
    returnFlags.PFD_DEPTH_DONTCARE  = flags & 0x40000000;  // bit 31 (DP)
    // bit 32 is 0

    if (returnFlags.PFD_SUPPORT_GDI && returnFlags.PFD_DOUBLEBUFFER) {
        cerr << "PFD_SUPPORT_GDI and PFD_DOUBLE_BUFFER must "
             << "NOT both be set!" << endl;
    }

    return returnFlags;
}

PFPixelType ExtractEMFPixelType (const int pixelType) {
    PFPixelType returnPixelType;

    switch (pixelType) {
        case 0x00:
            returnPixelType = PFD_TYPE_RGBA;
            break;
        case 0x01:
            returnPixelType = PFD_TYPE_COLORINDEX;
            break;
        default:
            cerr << "Pixel type is not valid!" << endl;
    }

    return returnPixelType;
}

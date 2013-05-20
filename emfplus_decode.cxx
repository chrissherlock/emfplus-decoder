#include <iostream>
#include <fstream>

#include "emfheader.hxx"

using namespace std;

// forward declarations
void ProcessEMFHeader(ifstream&);
EmfMetafileHeader*       ProcessMetafileHeader(ifstream&);
EmfMetafileHeaderExt1*   ProcessMetafileHeaderExt1(ifstream&);
EmfMetafileHeaderExt2*   ProcessMetafileHeaderExt2(ifstream&);

std::ostream& operator << (std::ostream&, Header&); 

int main () {
    ifstream emfFile;
    emfFile.open("image5.emf", ios::binary);
    
    ProcessEMFHeader(emfFile);
    return 0;
}

// forward declarations of redirect operators
std::ostream& operator << (std::ostream&, EmfMetafileHeader&);
std::ostream& operator << (std::ostream&, EmfMetafileHeaderExt1&);
std::ostream& operator << (std::ostream&, EmfMetafileHeaderExt2&);


std::ostream& operator << (std::ostream &s, Header &header) {
    std::ios_base::fmtflags basefield = s.basefield;

    s << "EMR_HEADER        " << endl
      << "==================================" << endl
      << "Type:             " << std::hex << std::showbase << header.type << endl
      << "Size:             " << std::dec << header.size << endl;
    
    s.setf(basefield);

    s << *header.header << endl;

    if (header.headerExt1) {
        s << *header.headerExt1 << endl;
    }

    if (header.headerExt2) {
        s << *header.headerExt2 << endl;
    }

    return s;
}

std::ostream& operator << (std::ostream &s, EmfMetafileHeader &emfHeader) {
    std::ios_base::fmtflags basefield = s.basefield;

    s << "Bounds:           " << endl
      << "    Left:         " << emfHeader.bounds->left << endl
      << "    Top:          " << emfHeader.bounds->top << endl
      << "    Right:        " << emfHeader.bounds->right << endl
      << "    Bottom:       " << emfHeader.bounds->bottom << endl
      << "Frame:            " << endl
      << "    Left:         " << emfHeader.frame->left << endl
      << "    Top:          " << emfHeader.frame->top << endl
      << "    Right:        " << emfHeader.frame->right << endl
      << "    Bottom:       " << emfHeader.frame->bottom << endl
      << "RecordSignature:  " << std::hex << std::showbase << emfHeader.recordSignature << endl
      << "Version:          " << emfHeader.version << endl
      << "Bytes:            " << std::dec << emfHeader.bytes << endl
      << "Records:          " << emfHeader.records << endl
      << "Handles:          " << emfHeader.handles << endl
      << "Reserved:         " << std::hex << std::showbase << emfHeader.reserved << endl
      << "Desc. size:       " << std::dec << emfHeader.nDescription << endl
      << "Desc. offset:     " << std::hex << std::showbase << emfHeader.offDescription << endl
      << "PAL entries:      " << std::dec << emfHeader.nPalEntries << endl
      << "Size (dev units): " << endl
      << "    cx:           " << emfHeader.device->cx << endl
      << "    cy:           " << emfHeader.device->cy << endl
      << "Size (mm):        " << endl
      << "    cx:           " << emfHeader.millimeters->cx << "mm" << endl
      << "    cy:           " << emfHeader.millimeters->cy << "mm" << endl; 
    
    s.setf(basefield);
    return s;
}

std::ostream& operator << (std::ostream &s, EmfMetafileHeaderExt1 &emfHeaderExt1) {
    std::ios_base::fmtflags basefield = s.basefield;

    s << "Header Extension 1" << endl
      << "==================================" << endl
      << "cbPixelFormat:   " << emfHeaderExt1.cbPixelFormat << endl
      << "offPixelFormat:  " << emfHeaderExt1.offPixelFormat << endl;

    s.setf(basefield);
    return s;
}

std::ostream& operator << (std::ostream &s, EmfMetafileHeaderExt2 &emfHeaderExt2) {
    std::ios_base::fmtflags basefield = s.basefield;

    s << "Header Extension 2" << endl
      << "==================================" << endl
      << "microMetersX:    " << emfHeaderExt2.microMetersX << endl
      << "microMetersY:    " << emfHeaderExt2.microMetersY << endl;

    s.setf(basefield);
    return s;
}

void ProcessEMFHeader(ifstream &emfFile)
{
    Header header;
    emfFile.seekg(0, ios::beg);
    emfFile.read(reinterpret_cast<char *>(&header.type), 4);
    emfFile.read(reinterpret_cast<char *>(&header.size), 4);
    
    // Detect what sort of header extension is being used
    // If       size == 88  -> EmfMetafileHeader
    // Else if  size == 100 -> EmfMetafileHeaderExtension1
    // Else if  size == 108 -> EmfMetafileHeaderExtension2
    // Else     not a valid size, possibly corrupted metafile

    EmfMetafileHeader *emfHeader;
    EmfMetafileHeaderExt1 *emfHeaderExt1;
    EmfMetafileHeaderExt2 *emfHeaderExt2;


    switch (header.size) {
        case 88:
            emfHeader = ProcessMetafileHeader(emfFile);
            break;
        case 100:
            emfHeader = ProcessMetafileHeader(emfFile);
            emfHeaderExt1 = ProcessMetafileHeaderExt1(emfFile);
            break;
        case 108:
            emfHeader = ProcessMetafileHeader(emfFile);
            emfHeaderExt1 = ProcessMetafileHeaderExt1(emfFile);
            emfHeaderExt2 = ProcessMetafileHeaderExt2(emfFile);
            break;
        default:
            break;
    }

    header.header=emfHeader;
    header.headerExt1=emfHeaderExt1;
    header.headerExt2=emfHeaderExt2;

    // process header size based on algorithm as described in [MS-EMF]
    // section 2.3.4.2 EMR_HEADER Record Types

    int HeaderSize=88;

    if (header.size < 88) {
        cerr << "Header size less than 88 bytes - possible file "
                "corruption!";
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
                            "indicate the EMF file is corrupted";
                }
            }
        }
    }

    string headerType = new string;

    if (HeaderSize >= 108) {
        headerType = "EmfMetafileHeaderExtension2";
    } else if (HeaderSize >= 100) {
        headerType = "EmfMetafileHeaderExtension1";
    } else if (HeaderSize == 88) {
        headerType = "EmfMetafileHeader";
    } else {    // this should NOT be possible!
         = "invalid!";
    }

    cout << "Header size is " << HeaderSize << "." << endl;
    cout << "Record type for header is " << headerType << endl << endl;
    cout << header << endl;
}

EmfMetafileHeader* ProcessMetafileHeader(ifstream &emfFile) {
    EmfMetafileHeader *emfHeader = new EmfMetafileHeader();

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

    if (emfSignature->recordSignature != ENHMETA_SIGNATURE) {
        cerr << "Record signature not valid in header! Should be "
             << "0x464D4520 (\"EMF \") but it is " 
             << std::hex << std::showbase 
                << emfSignature->recordSignature;
    }

    emfFile.read(reinterpret_cast<char *>(&emfHeader->version), 4);
    emfFile.read(reinterpret_cast<char *>(&emfHeader->bytes), 4);
    emfFile.read(reinterpret_cast<char *>(&emfHeader->records), 4);
    emfFile.read(reinterpret_cast<char *>(&emfHeader->handles), 4);
    emfFile.read(reinterpret_cast<char *>(&emfHeader->reserved), 4);

    // note: this MUST be 0x0000 and according to Microsoft it MUST be
    // ignored... however, this makes a nice check to see if there is
    // corruption :-) So I ignore Microsoft 

    if (emfHeader->reserved != 0x0000) {
        cerr << "Reserved field MUST be 0x0000, but is actually "
             << std::hex << std::showbase << emfHeader->reserved;
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

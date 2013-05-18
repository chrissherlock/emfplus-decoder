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

std::ostream& operator << (std::ostream &s, Header &header) {
    std::ios_base::fmtflags basefield = s.basefield;

    EmfMetafileHeader *emfHeader = header.header;
    EmfMetafileHeaderExt1 *emfHeaderExt1 = header.headerExt1;
    EmfMetafileHeaderExt2 *emfHeaderExt2 = header.headerExt2;

    s << "Type: 0x"   << std::hex << header.type << "(" << sizeof(header.type) << ")" << endl
      << "Size: "     << std::dec << header.size << endl
      << "Bounds: "   << endl
      << "\tLeft: \t"    << emfHeader->bounds->left << endl
      << "\tTop: \t"     << emfHeader->bounds->top << endl
      << "\tRight: \t"   << emfHeader->bounds->right << endl
      << "\tBottom: "  << emfHeader->bounds->bottom << endl
      << "Frame: "    << endl
      << "\tLeft: \t"   << emfHeader->frame->left << endl
      << "\tTop: \t"    << emfHeader->frame->top << endl
      << "\tRight: \t"  << emfHeader->frame->right << endl
      << "\tBottom: " << emfHeader->frame->bottom << endl
      << "RecordSignature: " << std::hex << emfHeader->recordSignature << endl;
    
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

    cout << header;
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
    emfFile.read(reinterpret_cast<char *>(&emfHeader->version), 4);
    emfFile.read(reinterpret_cast<char *>(&emfHeader->bytes), 4);
    emfFile.read(reinterpret_cast<char *>(&emfHeader->records), 4);
    emfFile.read(reinterpret_cast<char *>(&emfHeader->handles), 4);
    emfFile.read(reinterpret_cast<char *>(&emfHeader->reserved), 4);
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
    return new EmfMetafileHeaderExt1();
}

EmfMetafileHeaderExt2* ProcessMetafileHeaderExt2(ifstream &emfFile) {
    return new EmfMetafileHeaderExt2();
}

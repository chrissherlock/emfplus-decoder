#include <iostream>
#include <fstream>
#include <cwchar>

#include "header.hxx"
#include "header_output.hxx"
#include "record.hxx"

using namespace std;

int main () {
    ifstream emfFile;
    // TODO command line options needed to point to a different file
    emfFile.open("test/image5.emf", ios::binary);
    
    Header *header;

    header = ProcessEMFHeader(emfFile);

    cout << header << endl;

    ReadRecords(emfFile, header->header->records);

    return 0;
}

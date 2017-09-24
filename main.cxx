#include <iostream>
#include <fstream>
#include <cwchar>
#include <vector>

#include "header.hxx"
#include "header_output.hxx"
#include "emfrecord.hxx"

using namespace std;

int main () {
    ifstream emfFile;
    // TODO command line options needed to point to a different file
    emfFile.open("test/image1.emf", ios::binary);

    Header header;
    header = *(ProcessEMFHeader(emfFile));
    cout << header << endl;

    EmfRecords records;
    records = ReadRecords(emfFile, header.header->records);

    for (auto &record : records) {
        cout << record << endl;
    }

    return 0;
}

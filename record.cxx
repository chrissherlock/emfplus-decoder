#include <iostream>
#include <fstream>
#include <vector>

#include "record.hxx"

using namespace std;

EmfRecords ReadRecords(ifstream &emfFile, unsigned int numRecords) {

    EmfRecords records(numRecords+1);

    for (int i=0; i < numRecords; i++) {
        EmfRecord record;

        int currentPos = emfFile.tellg();

        emfFile.read(reinterpret_cast<char *>(&record.type), 4);
        emfFile.read(reinterpret_cast<char *>(&record.size), 4);

        records[i] = record;

        cout << "Offset: " << currentPos << " "
             << "Record " << i << " is of type " 
             << std::hex << std::showbase << record.type
             << " and is " << std::dec << record.size << " bytes long." << endl;

        emfFile.seekg(currentPos + record.size, ios::beg);
    }

    return records;
}


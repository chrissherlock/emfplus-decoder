#include <iostream>
#include <fstream>

#include "record.hxx"

void ReadRecords(ifstream &emfFile, unsigned int records) {

    for (int i=0; i < records; i++) {
        int type, size;

        int currentPos = emfFile.tellg();

        emfFile.read(reinterpret_cast<char *>(&type), 4);
        emfFile.read(reinterpret_cast<char *>(&size), 4);

        cout << "Offset: " << currentPos << " "
             << "Record " << i << " is of type " 
             << std::hex << std::showbase << type
             << " and is " << std::dec << size << " bytes long." << endl;

        emfFile.seekg(currentPos + size, ios::beg);
    }

}


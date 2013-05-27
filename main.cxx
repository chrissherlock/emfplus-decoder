#include <iostream>
#include <fstream>
#include <cwchar>

#include "header.hxx"

using namespace std;

int main () {
    ifstream emfFile;
    // TODO command line options needed to point to a different file
    emfFile.open("../test/image5.emf", ios::binary);
    
    ProcessEMFHeader(emfFile);
    return 0;
}

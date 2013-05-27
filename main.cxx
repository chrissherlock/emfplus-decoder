#include <iostream>
#include <fstream>
#include <cwchar>

#include "header.hxx"

using namespace std;

int main () {
    ifstream emfFile;
    emfFile.open("test/image5.emf", ios::binary);
    
    ProcessEMFHeader(emfFile);
    return 0;
}

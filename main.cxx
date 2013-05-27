#include <iostream>
#include <fstream>
#include <cwchar>

#include "header.hxx"

using namespace std;

int main () {
    ifstream emfFile;
    emfFile.open("image5.emf", ios::binary);
    
    ProcessEMFHeader(emfFile);
    return 0;
}

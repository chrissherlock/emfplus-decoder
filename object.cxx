#include <fstream>
#include <iostream>

#include "object.hxx"

using namespace std;

ColorAdjustment *ReadColorAdjustment(ifstream &emfFile) {
    ColorAdjustment *adjustment;

    emfFile.read(reinterpret_cast<char *>(&adjustment.Size), 2);
    emfFile.read(reinterpret_cast<char *>(&adjustment.Values), 2);
    emfFile.read(reinterpret_cast<char *>(&adjustment.IlluminantIndex), 2);
    emfFile.read(reinterpret_cast<char *>(&adjustment.RedGamma), 2);
    emfFile.read(reinterpret_cast<char *>(&adjustment.GreenGamma), 2);
    emfFile.read(reinterpret_cast<char *>(&adjustment.BlueGamma), 2);
    emfFile.read(reinterpret_cast<char *>(&adjustment.ReferenceBlack), 2);
    emfFile.read(reinterpret_cast<char *>(&adjustment.ReferenceWhite), 2);
    emfFile.read(reinterpret_cast<char *>(&adjustment.Contrast), 2);
    emfFile.read(reinterpret_cast<char *>(&adjustment.Brightness), 2);
    emfFile.read(reinterpret_cast<char *>(&adjustment.Colorfulness), 2);
    emfFile.read(reinterpret_cast<char *>(&adjustment.RedGreenTint), 2);

    return adjustment;
}

UniversalFontId *ReadUniversalFontId(ifsteam &emfFile) {
    UniversalFontId *ufi;

    emfFile.read(reinterpret_cast<char *>(&ufi.Checksum), 4);
    emfFile.read(reinterpret_cast<char *>(&ufi.Index), 4);

    return ufi;
}




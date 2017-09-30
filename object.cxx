#include <fstream>
#include <iostream>

#include "object.hxx"

using namespace std;

XForm *ReadXForm(ifstream &emf) {
    XForm *xform;

    emf.read(reinterpret_cast<char *>(&xform.M11), 4);
    emf.read(reinterpret_cast<char *>(&xform.M12), 4);
    emf.read(reinterpret_cast<char *>(&xform.M21), 4);
    emf.read(reinterpret_cast<char *>(&xform.M22), 4);
    emf.read(reinterpret_cast<char *>(&xform.Dx), 4);
    emf.read(reinterpret_cast<char *>(&xform.Dy), 4);

    return xform;
}

std::ostream& operator << (std::ostream &s, XForm xform) {
    std::ios_base::fmtflags basefield = s.basefield;
    s.setf(basefield);

    s << "\t\tM11:              " << xform.M11 << endl
      << "\t\tM12:              " << xform.M12 << endl
      << "\t\tM21:              " << xform.M21 << endl
      << "\t\tM22:              " << xform.M22 << endl
      << "\t\tDx:               " << xform.Dx << endl
      << "\t\tDy:               " << xform.Dy << endl;

    return s;
}

ColorAdjustment *ReadColorAdjustment(ifstream &emf) {
    ColorAdjustment *adjustment;

    emf.read(reinterpret_cast<char *>(&adjustment.Size), 2);
    emf.read(reinterpret_cast<char *>(&adjustment.Values), 2);
    emf.read(reinterpret_cast<char *>(&adjustment.IlluminantIndex), 2);
    emf.read(reinterpret_cast<char *>(&adjustment.RedGamma), 2);
    emf.read(reinterpret_cast<char *>(&adjustment.GreenGamma), 2);
    emf.read(reinterpret_cast<char *>(&adjustment.BlueGamma), 2);
    emf.read(reinterpret_cast<char *>(&adjustment.ReferenceBlack), 2);
    emf.read(reinterpret_cast<char *>(&adjustment.ReferenceWhite), 2);
    emf.read(reinterpret_cast<char *>(&adjustment.Contrast), 2);
    emf.read(reinterpret_cast<char *>(&adjustment.Brightness), 2);
    emf.read(reinterpret_cast<char *>(&adjustment.Colorfulness), 2);
    emf.read(reinterpret_cast<char *>(&adjustment.RedGreenTint), 2);

    return adjustment;
}

std::ostream& operator << (std::ostream &s, ColorAdjustment &adjustment) {
    std::ios_base::fmtflags basefield = s.basefield;
    s.setf(basefield);

    s << "\t\tSize:             " << adjustment.Size << endl
      << "\t\tValues:           " << adjustment.Values << endl
      << "\t\tIlluminantIndex:  " << adjustment.IlluminantIndex << endl
      << "\t\tRedGamma:         " << adjustment.RedGamma << end
      << "\t\tGreenGamma:       " << adjustment.GreenGamma << endl
      << "\t\tBlueGamma:        " << adjustment.BlueGamma << endl
      << "\t\tReferenceBlack:   " << adjustment.ReferenceBlack << endl
      << "\t\tReferenceWhite:   " << adjustment.ReferenceWhite << endl
      << "\t\tContrast:         " << adjustment.Contrast << endl
      << "\t\tBrightness:       " << adjustment.Brightness << endl
      << "\t\tColorfulness:     " << adjustment.Colorfulness << endl
      << "\t\tRedGreenTint:     " << adjustment.RedGreenTint << endl;

    return s;
}

UniversalFontId *ReadUniversalFontId(ifsteam &emf) {
    UniversalFontId *ufi;

    emf.read(reinterpret_cast<char *>(&ufi.Checksum), 4);
    emf.read(reinterpret_cast<char *>(&ufi.Index), 4);

    return ufi;
}

std::ostream& operator << (std::ostream &s, UniversalFontId &ufi) {
    std::ios_base::fmtflags basefield = s.basefield;
    s.setf(basefield);

    s << "\t\tCheckSum:         " << ufi.CheckSum << endl
      << "\t\tIndex:            " << ufi.Index << endl;

    return s;
}

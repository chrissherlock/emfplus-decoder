#include <fstream>
#include <iostream>

#include "wmf.hxx"

using namespace std;

RectL *ReadRectL(ifstream &emf) {
    RectL *rect;

    emf.read(reinterpret_cast<char *>(&rect->left), 4);
    emf.read(reinterpret_cast<char *>(&rect->top), 4);
    emf.read(reinterpret_cast<char *>(&rect->right), 4);
    emf.read(reinterpret_cast<char *>(&rect->bottom), 4);

    return rect;
}

std::ostream& operator << (std::ostream &s, RectL &rect) {
    std::ios_base::fmtflags basefield = s.basefield;
    s.setf(basefield);

    s << "\t\tLeft:             " << rect.left << endl
      << "\t\tTop:              " << rect.top << endl
      << "\t\tRight:            " << rect.right << endl
      << "\t\tBottom:           " << rect.bottom << endl;

    return s;
}

SizeL *ReadSizeL(ifstream &emf) {
    SizeL *size;

    emf.read(reinterpret_cast<char *>(&size->cx), 4);
    emf.read(reinterpret_cast<char *>(&size->cy), 4);

    return size;
}

std::ostream& operator << (std::ostream &s, SizeL &size) {
    std::ios_base::fmtflags basefield = s.basefield;
    s.setf(basefield);

    s << "\t\tcx:               " << size.cx << endl
      << "\t\tcy:               " << size.cy << endl;

    return s;
}

ColorRef *ReadColorRef(ifstream &emf) {
    ColorRef *color;

    emf.read(reinterpret_cast<char *>(&color->Red), 4);
    emf.read(reinterpret_cast<char *>(&color->Green), 4);
    emf.read(reinterpret_cast<char *>(&color->Blue), 4);
    emf.read(reinterpret_cast<char *>(&color->Reserved), 4);

    return color;
}

std::ostream& operator << (std::ostream &s, ColorRef &color) {
    std::ios_base::fmtflags basefield = s.basefield;
    s.setf(basefield);

    s << "\t\tRed:              " << std::hex << color.Red << endl
      << "\t\tGreen:            " << std::hex << color.Green << endl
      << "\t\tBlue:             " << std::hex << color.Blue << endl
      << "\t\tReserved:         " << std::hex << color.Reserved << endl;

    return s;
}

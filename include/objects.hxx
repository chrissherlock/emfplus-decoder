#ifndef EMFOBJECT
#define EMFOBJECT

// defined in [MS-EMF] 2.2.28 XForm Object
// it's a two-dimensional, linear transform matrix

struct XForm {
    float M11;
    float M12;
    float M21;
    float M22;
    float Dx;
    float Dy;
};

std::ostream& operator << (std::ostream&, XForm&);
XForm *ReadXForm(ifstream &emf);

// defined in [MS-EMF] 2.1.9 DIBColors Enumeration

enum DIBColors {
    DIB_RGB_COLORS  = 0x00,
    DIB_PAL_COLORS  = 0x01,
    DIB_PAL_INDICES = 0x02
};

// defined in [MS-EMF] 2.2.2 ColorAdjustment Object

struct ColorAdjustment {
    short int Size;
    short int Values;
    short int IlluminantIndex;
    short int RedGamma;
    short int GreenGamma;
    short int BlueGamma;
    short int ReferenceBlack;
    short int ReferenceWhite;
    short int Contrast;
    short int Brightness;
    short int Colorfulness;
    short int RedGreenTint;
};

std::ostream& operator << (std::ostream&, ColorAdjustment&);
ColorAdjustment *ReadColorAdjustment(ifstream &emf);

struct UniversalFontId {
    unsigned int Checksum;
    unsigned int Index;
};

std::ostream& operator << (std::ostream&, UniversalFontId&);
UniversalFontId *ReadUniversalFontId(ifstream &emf);

#endif

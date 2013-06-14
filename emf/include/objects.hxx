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

// defined in [MS-EMF] 2.1.9 DIBColors Enumeration

enum DIBColors {
    DIB_RGB_COLORS  = 0x00,
    DIB_PAL_COLORS  = 0x01,
    DIB_PAL_INDICES = 0x02
};

#endif

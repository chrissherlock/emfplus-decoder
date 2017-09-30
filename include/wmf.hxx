#ifndef WMF
#define WMF

struct RectL {
    int left;
    int top;
    int right;
    int bottom;
};

struct SizeL {
    int cx;
    int cy;
};

struct PointL {
    int x;
    int y;
};

// defined in [MS-WMF] 2.2.2.8 ColorRef Object

struct ColorRef {
    unsigned int    Red;
    unsigned int    Green;
    unsigned int    Blue;
    unsigned int    Reserved;
};

enum TernaryRasterOperation {
    BLACKNESS   = 0x00,
    DPSOON      = 0x01,
    DPSONA      = 0x02,
    PSON        = 0x03,
    SDPONA      = 0x04,
    DPON        = 0x05,
    PDSXNON     = 0x06,
    PDSAON      = 0x07,
    SDPNAA      = 0x08,
    PDSXON      = 0x09,
    DPNA        = 0x0A,
    PSDNAON     = 0x0B,
    SPNA        = 0x0C,
    PDSNAON     = 0x0D,
    PDSONON     = 0x0E,
    PN          = 0x0F,
    PDSONA      = 0x10,
    NOTSRCERASE = 0x11,
    SDPXNON     = 0x12,
    SDPAON      = 0x13,
    DPSXNON     = 0x14,
    DPSAON      = 0x15,
    PSDPSANAXX  = 0x16,
    SSPXDSXAXN  = 0x17,
    SPXPDXA     = 0x18,
    SDPSANAXN   = 0x19,
    PDSPAOX     = 0x1A,
    SDPSXAXN    = 0x1B,
    PSDPAOX     = 0x1C,
    DSPDXAXN    = 0x1D,
    PDSOX       = 0x1E,
    PDSOAN      = 0x1F,
    DPSNAA      = 0x20,
    SDPXON      = 0x21,
    DSNA        = 0x22,
    SPDNAON     = 0x23,
    SPXDSXA     = 0x24,
    PDSPANAXN   = 0x25,
    SDPSAOX     = 0x26,
    SDPSXNOX    = 0x27,
    DPSXA       = 0x28,
    PSDPSAOXXN  = 0x29,
    DPSANA      = 0x2A,
    SSPXPDXAXN  = 0x2B,
    SPDSOAX     = 0x2C,
    PSDNOX      = 0x2D,
    PSDPXOX     = 0x2E,
    PSDNOAN     = 0x2F,
    PSNA        = 0x30,
    SDPNAON     = 0x31,
    SDPSOOX     = 0x32,
    NOTSRCCOPY  = 0x33,
    SPDSAOX     = 0x34,
    SPDSXNOX    = 0x35,
    SDPOX       = 0x36,
    SDPOAN      = 0x37,
    PSDPOAX     = 0x38,
    SPDNOX      = 0x39,
    SPDSXOX     = 0x3A,
    SPDNOAN     = 0x3B,
    PSX         = 0x3C,
    SPDSONOX    = 0x3D,
    SPDSNAOX    = 0x3E,
    PSAN        = 0x3F,
    PSDNAA      = 0x40,
    DPSXON      = 0x41,
    SDXPDXA     = 0x42,
    SPDSANAXN   = 0x43,
    SRCERASE    = 0x44,
    DPSNAON     = 0x45,
    DSPDAOX     = 0x46,
    PSDPXAXN    = 0x47,
    SDPXA       = 0x48,
    PDSPDAOXXN  = 0x49,
    DPSDOAX     = 0x4A,
    PDSNOX      = 0x4B,
    SDPANA      = 0x4C,
    SSPXDSXOXN  = 0x4D,
    PDSPXOX     = 0x4E,
    PDSNOAN     = 0x4F,
    PDNA        = 0x50,
    DSPNAON     = 0x51,
    DPSDAOX     = 0x52,
    SPDSXAXN    = 0x53,
    DPSONON     = 0x54,
    DSTINVERT   = 0x55,
    DPSOX       = 0x56,
    DPSOAN      = 0x57,
    PDSPOAX     = 0x58,
    DPSNOX      = 0x59,
    PATINVERT   = 0x5A,
    DPSDONOX    = 0x5B,
    DPSDXOX     = 0x5C,
    DPSNOAN     = 0x5D,
    DPSDNAOX    = 0x5E,
    DPAN        = 0x5F,
    PDSXA       = 0x60,
    DSPDSAOXXN  = 0x61,
    DSPDOAX     = 0x62,
    SDPNOX      = 0x63,
    SDPSOAX     = 0x64,
    DSPNOX      = 0x65,
    SRCINVERT   = 0x66,
    SDPSONOX    = 0x67,
    DSPDSONOXXN = 0x68,
    PDSXXN      = 0x69,
    DPSAX       = 0x6A,
    PSDPSOAXXN  = 0x6B,
    SDPAX       = 0x6C,
    PDSPDOAXXN  = 0x6D,
    SDPSNOAX    = 0x6E,
    PDXNAN      = 0x6F,
    PDSANA      = 0x70,
    SSDXPDXAXN  = 0x71,
    SDPSXOX     = 0x72,
    SDPNOAN     = 0x73,
    DSPDXOX     = 0x74,
    DSPNOAN     = 0x75,
    SDPSNAOX    = 0x76,
    DSAN        = 0x77,
    PDSAX       = 0x78,
    DSPDSOAXXN  = 0x79,
    DPSDNOAX    = 0x7A,
    SDPXNAN     = 0x7B,
    SPDSNOAX    = 0x7C,
    DPSXNAN     = 0x7D,
    SPXDSXO     = 0x7E,
    DPSAAN      = 0x7F,
    DPSAA       = 0x80,
    SPXDSXON    = 0x81,
    DPSXNA      = 0x82,
    SPDSNOAXN   = 0x83,
    SDPXNA      = 0x84,
    PDSPNOAXN   = 0x85,
    DSPDSOAXX   = 0x86,
    SRCAND      = 0x88,
    SDPSNAOXN   = 0x89,
    DSPNOA      = 0x8A,
    DSPDXOXN    = 0x8B,
    SDPNOA      = 0x8C,
    SDPSXOXN    = 0x8D,
    SSDXPDXAX   = 0x8E,
    PDSANAN     = 0x8F,
    PDSXNA      = 0x90,
    SDPSNOAXN   = 0x91,
    DPSDPOAXX   = 0x92,
    SPDAXN      = 0x93,
    PSDPSOAXX   = 0x94,
    DPSAXN      = 0x95,
    DPSXX       = 0x96,
    PSDPSONOXX  = 0x97,
    SDPSONOXN   = 0x98,
    DSXN        = 0x99,
    DPSNAX      = 0x9A,
    SDPSOAXN    = 0x9B,
    SPDNAX      = 0x9C,
    DSPDOAXN    = 0x9D,
    DSPDSAOXX   = 0x9E,
    PDSXAN      = 0x9F,
    DPA         = 0xA0,
    PDSPNAOXN   = 0xA1,
    DPSNOA      = 0xA2,
    DPSDXOXN    = 0xA3,
    PDSPONOXN   = 0xA4,
    PDXN        = 0xA5,
    DSPNAX      = 0xA6,
    PDSPOAXN    = 0xA7,
    DPSOA       = 0xA8,
    DPSOXN      = 0xA9,
    D           = 0xAA,
    DPSONO      = 0xAB,
    SPDSXAX     = 0xAC,
    DPSDAOXN    = 0xAD,
    DSPNAO      = 0xAE,
    DPNO        = 0xAF,
    PDSNOA      = 0xB0,
    PDSPXOXN    = 0xB1,
    SSPXDSXOX   = 0xB2,
    SDPANAN     = 0xB3,
    PSDNAX      = 0xB4,
    DPSDOAXN    = 0xB5,
    DPSDPAOXX   = 0xB6,
    SDPXAN      = 0xB7,
    PSDPXAX     = 0xB8,
    DSPDAOXN    = 0xB9,
    DPSNAO      = 0xBA,
    MERGEPAINT  = 0xBB,
    SPDSANAX    = 0xBC,
    SDXPDXAN    = 0xBD,
    DPSXO       = 0xBE,
    DPSANO      = 0xBF,
    MERGECOPY   = 0xC0,
    SPDSNAOXN   = 0xC1,
    SPDSONOXN   = 0xC2,
    PSXN        = 0xC3,
    SPDNOA      = 0xC4,
    SPDSXOXN    = 0xC5,
    SDPNAX      = 0xC6,
    PSDPOAXN    = 0xC7,
    SDPOA       = 0xC8,
    SPDOXN      = 0xC9,
    DPSDXAX     = 0xCA,
    SPDSAOXN    = 0xCB,
    SRCCOPY     = 0xCC,
    SDPONO      = 0xCD,
    SDPNAO      = 0xCE,
    SPNO        = 0xCF,
    PSDNOA      = 0xD0,
    PSDPXOXN    = 0xD1,
    PDSNAX      = 0xD2,
    SPDSOAXN    = 0xD3,
    SSPXPDXAX   = 0xD4,
    DPSANAN     = 0xD5,
    PSDPSAOXX   = 0xD6,
    DPSXAN      = 0xD7,
    PDSPXAX     = 0xD8,
    SDPSAOXN    = 0xD9,
    DPSDANAX    = 0xDA,
    SPXDSXAN    = 0xDB,
    SPDNAO      = 0xDC,
    SDNO        = 0xDD,
    SDPXO       = 0xDE,
    SDPANO      = 0xDF,
    PDSOA       = 0xE0,
    PDSOXN      = 0xE1,
    DSPDXAX     = 0xE2,
    PSDPAOXN    = 0xE3,
    SDPSXAX     = 0xE4,
    PDSPAOXN    = 0xE5,
    SDPSANAX    = 0xE6,
    SPXPDXAN    = 0xE7,
    SSPXDSXAX   = 0xE8,
    DSPDSANAXXN = 0xE9,
    DPSAO       = 0xEA,
    DPSXNO      = 0xEB,
    SDPAO       = 0xEC,
    SDPXNO      = 0xED,
    SRCPAINT    = 0xEE,
    SDPNOO      = 0xEF,
    PATCOPY     = 0xF0,
    PDSONO      = 0xF1,
    PDSNAO      = 0xF2,
    PSNO        = 0xF3,
    PSDNAO      = 0xF4,
    PDNO        = 0xF5,
    PDSXO       = 0xF6,
    PDSANO      = 0xF7,
    PDSAO       = 0xF8,
    PDSXNO      = 0xF9,
    DPO         = 0xFA,
    PATPAINT    = 0xFB,
    PSO         = 0xFC,
    PSDNOO      = 0xFD,
    DPSOO       = 0xFE,
    WHITENESS   = 0xFF
};

#endif

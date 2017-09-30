#include <fstream>

#include "emfrecord.hxx"
#include "defs.hxx"
#include "objects.hxx"
#include "wmf.hxx"

#ifndef EMFBITMAP
#define EMFBITMAP

// AlphaFormat field EMR_ALPHABLEND
#define AC_SRC_ALPHA 0x01

EmfRecord *ReadBitBltRecord(std::ifstream&, unsigned int);
EmfRecord *ReadStretchBltRecord(std::ifstream&, unsigned int);
EmfRecord *ReadMaskBltRecord(std::ifstream&, unsigned int);
EmfRecord *ReadPlgBltRecord(std::ifstream&, unsigned int);
EmfRecord *ReadSetDIBitsToDeviceRecord(std::ifstream&, unsigned int);
EmfRecord *ReadStretchDIBitsRecord(std::ifstream&, unsigned int);
EmfRecord *ReadAlphaBlendRecord(std::ifstream&, unsigned int);
EmfRecord *ReadTransparentBltRecord(std::ifstream&, unsigned int);

int isBitmapRecord(unsigned int);
int isClippingRecord(unsigned int);
int isCommentRecord(unsigned int);
int isControlRecord(unsigned int);
int isDrawingRecord(unsigned int);
int isEscapeRecord(unsigned int);
int isObjectCreationRecord(unsigned int);
int isObjectManipulationRecord(unsigned int);
int isOpenGLRecord(unsigned int);
int isPathBracketRecord(unsigned int);
int isStateRecord(unsigned int);
int isTransformRecord(unsigned int);

// [MS-EMF] section 2.3.1.2 EMR_BITBLT

struct EmfBitBltRecord : EmfRecord {
    RectL           *Bounds;
    int             xDest;
    int             yDest;
    int             cxDest;
    int             cyDest;
    unsigned int    BitBltRasterOperation;
    int             xSrc;
    int             ySrc;
    XForm           *XformSrc;
    ColorRef        *BkColorSrc;
    unsigned int    UsageSrc;       // MUST be in DIBColors enum
    unsigned int    offBmiSrc;
    unsigned int    cbBmiSrc;
    unsigned int    offBitsSrc;
    unsigned int    cbBitsSrc;
    char            *BmiSrc;
    char            *BitsSrc;
};

struct EmfStretchBltRecord : EmfRecord {
    RectL           *Bounds;
    int             xDest;
    int             yDest;
    int             cxDest;
    int             cyDest;
    unsigned int    BitBltRasterOperation;
    int             xSrc;
    int             ySrc;
    XForm           *XformSrc;
    ColorRef        *BkColorSrc;
    unsigned int    UsageSrc;       // MUST be in DIBColors enum
    unsigned int    offBmiSrc;
    unsigned int    cbBmiSrc;
    unsigned int    offBitsSrc;
    unsigned int    cbBitsSrc;
    char            *BmiSrc;
};

struct EmfMaskBltRecord : EmfRecord {
    RectL           *Bounds;
    int             xDest;
    int             yDest;
    int             cxDest;
    int             cyDest;
    // ROP4
    int             ROP4Reserved;
    char            BackgroundROP3;
    char            ForegroundROP3;
    // end ROP4
    int             xSrc;
    int             ySrc;
    XForm           *XformSrc;
    ColorRef        *BkColorSrc;
    unsigned int    UsageSrc;       // MUST be in DIBColors enum
    unsigned int    offBmiSrc;
    unsigned int    cbBmiSrc;
    unsigned int    offBitsSrc;
    unsigned int    cbBitsSrc;
    unsigned int    xMask;
    unsigned int    yMask;
    unsigned int    UsageMask;
    unsigned int    offBmiMask;
    unsigned int    cbBmiMask;
    unsigned int    offBitsMask;
    unsigned int    cbBitsMask;
    char            *BmiSrc;
    char            *BitsSrc;
    char            *BmiMask;
    char            *BitsMask;
};

struct EmfPlgBltRecord : EmfRecord {
    RectL           *Bounds;
    PointL          *dstPoint1;
    PointL          *dstPoint2;
    PointL          *dstPoint3;
    int             xSrc;
    int             ySrc;
    int             cxSrc;
    int             cySrc;
    XForm           *XformSrc;
    ColorRef        *BkColorSrc;
    unsigned int    UsageSrc;       // MUST be in DIBColors enum
    unsigned int    offBmiSrc;
    unsigned int    cbBmiSrc;
    unsigned int    offBitsSrc;
    unsigned int    cbBitsSrc;
    unsigned int    xMask;
    unsigned int    yMask;
    unsigned int    UsageMask;
    unsigned int    offBmiMask;
    unsigned int    cbBmiMask;
    unsigned int    offBitsMask;
    unsigned int    cbBitsMask;
    char            *BmiSrc;
    char            *BitsSrc;
    char            *BmiMask;
    char            *BitsMask;
};

struct EmfSetDIBitsToDeviceRecord : EmfRecord {
    RectL           *Bounds;
    int             xDest;
    int             yDest;
    int             xSrc;
    int             ySrc;
    int             cxSrc;
    int             cySrc;
    unsigned int    offBmiSrc;
    unsigned int    cbBmiSrc;
    unsigned int    offBitsSrc;
    unsigned int    cbBitsSrc;
    unsigned int    UsageSrc;       // MUST be in DIBColors enum
    unsigned int    iStartScan;
    unsigned int    cScans;
    char            *BmiSrc;
    char            *BitsSrc;
};

struct EmfStretchDIBitsRecord : EmfRecord {
    RectL           *Bounds;
    int             xDest;
    int             yDest;
    int             xSrc;
    int             ySrc;
    int             cxSrc;
    int             cySrc;
    unsigned int    offBmiSrc;
    unsigned int    cbBmiSrc;
    unsigned int    offBitsSrc;
    unsigned int    cbBitsSrc;
    unsigned int    UsageSrc;       // MUST be in DIBColors enum
    unsigned int    BitBltRasterOperation;
    int             cxDest;
    int             cyDest;
    char            *BmiSrc;
    char            *BitsSrc;
};

struct EmfAlphaBlendRecord : EmfRecord {
    RectL           *Bounds;
    int             xDest;
    int             yDest;
    int             cxDest;
    int             cyDest;
    // start BLENDFUNCTION
    char            BlendOperation;
    char            BlendFlags;
    char            SrcConstantAlpha;
    char            AlphaFormat;
    // end BLENDFUNCTION
    int             xSrc;
    int             ySrc;
    XForm           *XformSrc;
    ColorRef        *BkColorSrc;
    unsigned int    UsageSrc;
    unsigned int    offBmiSrc;
    unsigned int    cbBmiSrc;
    unsigned int    offBitsSrc;
    unsigned int    cbBitsSrc;
    int             cxSrc;
    int             cySrc;
    char            *BmiSrc;
    char            *BitsSrc;
};

struct EmfTransparentBltRecord : EmfRecord {
    RectL           *Bounds;
    int             xDest;
    int             yDest;
    int             cxDest;
    int             cyDest;
    ColorRef        *TransparentColor;
    int             xSrc;
    int             ySrc;
    XForm           *XformSrc;
    ColorRef        *BkColorSrc;
    unsigned int    UsageSrc;
    unsigned int    offBmiSrc;
    unsigned int    cbBmiSrc;
    unsigned int    offBitsSrc;
    unsigned int    cbBitsSrc;
    int             cxSrc;
    int             cySrc;
    char            *BmiSrc;
    char            *BitsSrc;
};

#endif

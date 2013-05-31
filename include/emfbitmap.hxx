#include <fstream>

#include "emfrecord.hxx"
#include "defs.hxx"
#include "objects.hxx"
#include "wmf.hxx"

using namespace std;

#ifndef EMFBITMAP
#define EMFBITMAP

EmfRecord ReadBitmap(ifstream&, const EmfRecord&); 
EmfRecord ReadBitBltRecord(ifstream&, const EmfRecord&);

// [MS-EMF] section 2.3.1.2 EMR_BITBLT

struct EmfBitBltBitmap : EmfRecord {
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
}

struct EmfStretchBlt : EmfRecord {
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
}

struct EmfMaskBlt : EmfRecord {
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
}


struct EmfStretchBlt : EmfRecord {
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
}

struct EmfPlgBlt : EmfRecord {
    RectL           *Bounds;
    PointL          *aptlDest;
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
}

#endif

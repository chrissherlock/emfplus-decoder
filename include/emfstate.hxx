#include <fstream>

#include "emfrecord.hxx"
#include "defs.hxx"
#include "objects.hxx"
#include "wmf.hxx"

#ifndef EMFSTATE
#define EMFSTATE

EmfRecord *ReadSetWindowOrgExRecord(std::ifstream&);
EmfRecord *ReadSetViewportExtExRecord(std::ifstream&);
EmfRecord *ReadSetViewportOrgExRecord(std::ifstream&);
EmfRecord *ReadSetBrushOrgExRecord(std::ifstream&);
EmfRecord *ReadSetColorAdjustmentRecord(std::ifstream&);

// [MS-EMF] section 2.3.11.31 EMR_SETWINDOWORGEX

struct EmfSetWindowOrgExRecord : EmfRecord {
    PointL          *Origin;
};


// [MS-EMF] section 2.3.11.28 EMR_SETVIEWPORTEXTEX

struct EmfSetViewportExtExRecord : EmfRecord {
    SizeL           *Extent;
};

// [MS-EMF] section 2.3.11.28 EMR_SETVIEWPORTORGEX

struct EmfSetViewportOrgExRecord : EmfRecord {
    PointL          *Origin;
};

// [MS-EMF] section 2.3.11.12 EMR_SETBRUSHORGEX

struct EmfSetBrushOrgExRecord : EmfRecord {
    PointL          *Origin;
};

// [MS-EMF] section 2.3.11.13 EMR_SETCOLORADJUSTMENT

struct EmfSetColorAdjustmentRecord : EmfRecord {
    ColorAdjustment *Adjustment;
};

// [MS-EMF] section 2.3.11.30 EMR_SETWINDOWEXTEX

struct EmfSetWindowExtExRecord : EmfRecord {
    SizeL           *Extent;
};

// [MS-EMF] section 2.3.11.1 EMR_COLORMATCHTOTARGETW

struct EmfColorMatchToTargetWRecord : EmfRecord {
    unsigned int dwAction;
    unsigned int dwFlags;
    unsigned int cbName;
    unsigned int cbData;
    char *Data;
};

// [MS-EMF] section 2.3.11.2 EMR_FORCEUFIMAPPING

struct EmfForceUFIMappingRecord : EmfRecord {
    UniversalFontId ufi;
}

#endif

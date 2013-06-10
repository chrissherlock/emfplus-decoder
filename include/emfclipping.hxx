#include <fstream>
#include <vector>

#include "emfrecord.hxx"
#include "defs.hxx"
#include "wmf.hxx"

#ifndef EMFCLIPPING
#define EMFCLIPPING

EmfRecord *ReadClipping(std::ifstream&, const EmfRecord&); 
EmfRecord *ReadExcludeClipRecord(std::ifstream&, const EmfRecord&); 
EmfRecord *ReadExtSelectClipRgnRecord(std::ifstream&, const EmfRecord&);


// defined in [MS-EMF] section 2.1.29 RegionMode Enumeration
enum RegionMode {
    RGN_AND  = 0x01,
    RGN_OR   = 0x02,
    RGN_XOR  = 0x03,
    RGN_DIFF = 0x04,
    RGN_COPY = 0x05
};

// defined in [MS-EMF] 2.2.25 RegionDataHeader Object
struct RegionDataHeader {
    unsigned int    rgnDataSize;
    unsigned int    rgnDataType;  // SHOULD be RDH_RECTANCLES
    unsigned int    CountRects;
    unsigned int    RgnSize;
    RectL           *Bounds;
};

// defined in [MS-EMF] 2.2.24 RegionData Object
struct RegionData : RegionDataHeader {
    vector<RectL>   Data;
};

// defined in [MS-EMF] section 2.3.2.1 EMR_EXCLUDECLIPRECT Record
struct EmfExcludeClipBitmap : EmfRecord {
    RectL           *Clip;
};

// defined in [MS-EMF] section 2.3.2.1 EMR_EXTSELECTCLIPRGN Record
struct EmfExtSelectClipRgn : EmfRecord {
    unsigned int    RgnDataSize;
    unsigned int    RegionMode;
    RegionData      *RgnData;   // if RegionMode is RGN_COPY, 
                                // should be NULL
};
    
RegionDataHeader ReadRegionDataHeader(std::ifstream&);
RegionData       *ReadRegionData(std::ifstream&);

#endif

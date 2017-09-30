#include <fstream>
#include <iostream>
#include <vector>

#include "emfrecord.hxx"
#include "emfclipping.hxx"
#include "defs.hxx"

using namespace std;

EmfRecord *ReadClippingRecord(ifstream &emf, unsigned int type) {
    EmfRecord *record;

    switch (type) {
        case EMR_EXCLUDECLIPRECT:
            record = ReadExcludeClipRecord(emf);
            break;

        case EMR_EXTSELECTCLIPRGN:
            record = ReadExtSelectClipRgnRecord(emf);
            break;

        case EMR_INTERSECTCLIPRECT:
            record = ReadIntersectClipRectRecord(emf);
            break;

        case EMR_OFFSETCLIPRGN:
//            record = ReadOffsetClipRgnRecord(emf);
            break;

        case EMR_SELECTCLIPPATH:
//            record = ReadSelectClipPathRecord(emf);
            break;

        case EMR_SETMETARGN:
//            record = ReadSetMetaRgnRecord(emf);
            break;

        default:
            cerr << "There is no way we should have got here..." << endl;
    }

    record->type = type;

    return record;
}

EmfRecord *ReadExcludeClipRecord(ifstream &emf) {
    EmfExcludeClipRect excludeClipRectRecord;

    emf.read(reinterpret_cast<char *>(&excludeClipRectRecord.Clip->left), 4);
    emf.read(reinterpret_cast<char *>(&excludeClipRectRecord.Clip->top), 4);
    emf.read(reinterpret_cast<char *>(&excludeClipRectRecord.Clip->right), 4);
    emf.read(reinterpret_cast<char *>(&excludeClipRectRecord.Clip->bottom), 4);

    EmfExcludeClipRect* retVal = &excludeClipRectRecord;
    return retVal;
}

RegionDataHeader *ReadRegionDataHeader(ifstream &emf) {
    RegionDataHeader rgnDataHdr;

    emf.read(reinterpret_cast<char *>(&rgnDataHdr.rgnDataSize), 4);
    emf.read(reinterpret_cast<char *>(&rgnDataHdr.rgnDataType), 4);
    emf.read(reinterpret_cast<char *>(&rgnDataHdr.CountRects), 4);
    emf.read(reinterpret_cast<char *>(&rgnDataHdr.RgnSize), 4);
    emf.read(reinterpret_cast<char *>(&rgnDataHdr.Bounds->left), 4);
    emf.read(reinterpret_cast<char *>(&rgnDataHdr.Bounds->top), 4);
    emf.read(reinterpret_cast<char *>(&rgnDataHdr.Bounds->right), 4);
    emf.read(reinterpret_cast<char *>(&rgnDataHdr.Bounds->bottom), 4);

    RegionDataHeader* retVal = &rgnDataHdr;
    return retVal;
}

RegionData *ReadRegionData(ifstream &emf) {
    RegionData *rgnData;
    rgnData = static_cast<RegionData*> (ReadRegionDataHeader(emf));

    int numRects = rgnData->RgnSize / sizeof(RectL);
    vector<RectL> rgnRects(numRects);

    for (int i=0; i < numRects; i++)
    {
        RectL rect;
        emf.read(reinterpret_cast<char *>(&rect.left), 4);
        emf.read(reinterpret_cast<char *>(&rect.top), 4);
        emf.read(reinterpret_cast<char *>(&rect.right), 4);
        emf.read(reinterpret_cast<char *>(&rect.bottom), 4);

        rgnRects[i] = rect;
    }

    rgnData->Data = rgnRects;

    return rgnData;
}

EmfRecord *ReadExtSelectClipRgnRecord(ifstream &emf) {
    EmfExtSelectClipRgn extSelectClipRgnRecord;

    emf.read(reinterpret_cast<char *>(&extSelectClipRgnRecord.RgnDataSize), 4);
    emf.read(reinterpret_cast<char *>(&extSelectClipRgnRecord.RegionMode), 4);

    extSelectClipRgnRecord.RgnData = ReadRegionData(emf);

    EmfExtSelectClipRgn* retVal = &extSelectClipRgnRecord;
    return retVal;
}

EmfRecord *ReadIntersectClipRectRecord(ifstream &emf) {
    EmfIntersectClipRect intersectClipRectRecord;

    emf.read(reinterpret_cast<char *>(&intersectClipRectRecord.Clip->left), 4);
    emf.read(reinterpret_cast<char *>(&intersectClipRectRecord.Clip->top), 4);
    emf.read(reinterpret_cast<char *>(&intersectClipRectRecord.Clip->right), 4);
    emf.read(reinterpret_cast<char *>(&intersectClipRectRecord.Clip->bottom), 4);

    EmfIntersectClipRect *retVal = &intersectClipRectRecord;
    return retVal;
}

EmfRecord *ReadOffsetClipRgnRecord(ifstream &emf) {
    EmfOffsetClipRgn offsetClipRgnRecord;

    emf.read(reinterpret_cast<char *>(&offsetClipRgnRecord.Offset->x), 4);
    emf.read(reinterpret_cast<char *>(&offsetClipRgnRecord.Offset->y), 4);

    EmfOffsetClipRgn *retVal = &offsetClipRgnRecord;
    return retVal;
}

EmfRecord *ReadSelectClipPathRecord(ifstream &emf) {
    EmfSelectClipPath selectClipPathRecord;

    emf.read(reinterpret_cast<char *>(selectClipPathRecord.RegionMode), 4);

    EmfSelectClipPath *retVal = &selectClipPathRecord;
    return retVal;
}

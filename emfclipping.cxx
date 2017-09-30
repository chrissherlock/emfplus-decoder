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
    EmfExcludeClipRect record;

    emf.read(reinterpret_cast<char *>(&record.Clip->left), 4);
    emf.read(reinterpret_cast<char *>(&record.Clip->top), 4);
    emf.read(reinterpret_cast<char *>(&record.Clip->right), 4);
    emf.read(reinterpret_cast<char *>(&record.Clip->bottom), 4);

    EmfExcludeClipRect* retVal = &record;
    return retVal;
}

RegionDataHeader *ReadRegionDataHeader(ifstream &emf) {
    RegionDataHeader record;

    emf.read(reinterpret_cast<char *>(&record.recordSize), 4);
    emf.read(reinterpret_cast<char *>(&record.recordType), 4);
    emf.read(reinterpret_cast<char *>(&record.CountRects), 4);
    emf.read(reinterpret_cast<char *>(&record.RgnSize), 4);
    emf.read(reinterpret_cast<char *>(&record.Bounds->left), 4);
    emf.read(reinterpret_cast<char *>(&record.Bounds->top), 4);
    emf.read(reinterpret_cast<char *>(&record.Bounds->right), 4);
    emf.read(reinterpret_cast<char *>(&record.Bounds->bottom), 4);

    RegionDataHeader* retVal = &record;
    return retVal;
}

RegionData *ReadRegionData(ifstream &emf) {
    RegionData *record;
    record = static_cast<RegionData*> (ReadRegionDataHeader(emf));

    int numRects = record->RgnSize / sizeof(RectL);
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

    record->Data = rgnRects;

    return record;
}

EmfRecord *ReadExtSelectClipRgnRecord(ifstream &emf) {
    EmfExtSelectClipRgn record;

    emf.read(reinterpret_cast<char *>(&record.RgnDataSize), 4);
    emf.read(reinterpret_cast<char *>(&record.RegionMode), 4);

    record.RgnData = ReadRegionData(emf);

    EmfExtSelectClipRgn* retVal = &record;
    return retVal;
}

EmfRecord *ReadIntersectClipRectRecord(ifstream &emf) {
    EmfIntersectClipRect record;

    emf.read(reinterpret_cast<char *>(&record.Clip->left), 4);
    emf.read(reinterpret_cast<char *>(&record.Clip->top), 4);
    emf.read(reinterpret_cast<char *>(&record.Clip->right), 4);
    emf.read(reinterpret_cast<char *>(&record.Clip->bottom), 4);

    EmfIntersectClipRect *retVal = &record;
    return retVal;
}

EmfRecord *ReadOffsetClipRgnRecord(ifstream &emf) {
    EmfOffsetClipRgn record;

    emf.read(reinterpret_cast<char *>(&record.Offset->x), 4);
    emf.read(reinterpret_cast<char *>(&record.Offset->y), 4);

    EmfOffsetClipRgn *retVal = &record;
    return retVal;
}

EmfRecord *ReadSelectClipPathRecord(ifstream &emf) {
    EmfSelectClipPath record;

    emf.read(reinterpret_cast<char *>(record.RegionMode), 4);

    EmfSelectClipPath *retVal = &record;
    return retVal;
}

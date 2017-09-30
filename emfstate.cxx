#include <fstream>
#include <iostream>

#include "emfstate.hxx"
#include "defs.hxx"

using namespace std;

EmfRecord *ReadStateRecord(ifstream &emf, unsigned int type) {
    EmfRecord *record;

    switch (type) {
        case EMR_SETWINDOWORGEX:
            record = ReadSetWindowOrgExRecord(emf);
            break;

        case EMR_SETVIEWPORTEXTEX:
            record = ReadSetViewportExtExRecord(emf);
            break;

        case EMR_SETVIEWPORTORGEX:
            record = ReadSetViewportOrgExRecord(emf);
            break;

        case EMR_SETBRUSHORGEX:
            record = ReadSetBrushOrgExRecord(emf);
            break;

        case EMR_SETPIXELV:
            record = ReadSetPixelVRecord(emf);
            break;

        case EMR_SETMAPPERFLAGS:
            record = ReadSetMapperFlagsRecord(emf);
            break;

        case EMR_SETMAPMODE:
            record = ReadSetMapModeRecord(emf);
            break;

        case EMR_SETBKMODE:
            record = ReadSetBkModeRecord(emf);
            break;

        case EMR_SETPOLYFILLMODE:
            record = ReadSetPolyfillModeRecord(emf);
            break;

        case EMR_SETROP2:
            record = ReadSetRop2Record(emf);
            break;

        case EMR_SETSTRETCHBLTMODE:
            record = ReadSetStretchBltModeRecord(emf);
            break;

        case EMR_SETTEXTALIGN:
            record = ReadSetTextAlignRecord(emf);
            break;

        case EMR_SETCOLORADJUSTMENT:
            record = ReadSetColorAdjustmentRecord(emf);
            break;

        case EMR_SETTEXTCOLOR:
            record = ReadSetTextColorRecord(emf);
            break;

        case EMR_SETBKCOLOR:
            record = ReadSetBkColorRecord(emf);
            break;

        case EMR_OFFSETCLIPRGN:
            record = ReadOffsetClipRgnRecord(emf);
            break;

        case EMR_MOVETOEX:
            record = ReadMoveToExRecord(emf);
            break;

        case EMR_SETMETARGN:
            record = ReadSetMetaRgnRecord(emf);
            break;

        case EMR_EXCLUDECLIPRECT:
            record = ReadExcludeClipRectRecord(emf);
            break;

        case EMR_INTERSECTCLIPRECT:
            record = ReadIntersectClipRectRecord(emf);
            break;

        case EMR_SCALEVIEWPORTEXTEX:
            record = ReadViewportExtExRecord(emf);
            break;

        case EMR_SCALEWINDOWEXTEX:
            record = ReadScaleWindowExtExRecord(emf);
            break;

        case EMR_SAVEDC:
            record = ReadSaveDCRecord(emf);
            break;

        case EMR_RESTOREDC:
            record = ReadRestoreDCRecord(emf);
            break;

        case EMR_RESIZEPALETTE:
            record = ReadResizePaletteRecord(emf);
            break;

        case EMR_REALIZEPALETTE:
            record = ReadRealizePaletteRecord(emf);
            break;

        case EMR_SETARCDIRECTION:
            record = ReadSetArcDirectionRecord(emf);
            break;

        case EMR_SETMITERLIMIT:
            record = ReadSetMiterLimitRecord(emf);
            break;

        case EMR_INVERTRGN:
            record = ReadInvertRgnRecord(emf);
            break;

        case EMR_SETICMMODE:
            record = ReadSetICMModeRecord(emf);
            break;

        case EMR_PIXELFORMAT:
            record = ReadPixelFormatRecord(emf);
            break;

        case EMR_FORCEUFIMAPPING:
            record = ReadForceUFIMappingRecord(emf);
            break;

        case EMR_SETICMPROFILEA:
            record = ReadSetICMProfileARecord(emf);
            break;

        case EMR_SETICMPROFILEW:
            record = ReadSetICMProfileWRecord(emf);
            break;

        case EMR_SETLAYOUT:
            record = ReadSetLayoutRecord(emf);
            break;

        case EMR_SETLINKEDUFIS:
            record = ReadSetLinkedUFIsRecord(emf);
            break;

        case EMR_SETTEXTJUSTIFICATION:
            record = ReadSetTextJustificationRecord(emf);
            break;

        case EMR_COLORMATCHTOTARGETW:
            record = ReadColorMatchToTargetWRecord(emf);
            break;

        default:
            cerr << "There is no way we should have got here..." << endl;
    }

    record->type = type;

    return record;
}

EmfRecord *ReadSetWindowOrgExRecord(ifstream &emf) {
    EmfSetWindowOrgExRecord record;

    emf.read(reinterpret_cast<char *>(&record.Origin->x), 4);
    emf.read(reinterpret_cast<char *>(&record.Origin->y), 4);

    EmfRecord *retRecord = &record;
    return retRecord;
}

EmfRecord *ReadSetViewportExtExRecord(ifstream &emf) {
    EmfSetWindowExtExRecord record;

    emf.read(reinterpret_cast<char *>(&record.Extent->cx), 4);
    emf.read(reinterpret_cast<char *>(&record.Extent->cy), 4);

    EmfRecord *retRecord = &record;
    return retRecord;
}



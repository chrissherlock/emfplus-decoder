#include <fstream>
#include <iostream>

#include "emfstate.hxx"
#include "defs.hxx"

using namespace std;

EmfRecord *ReadStateRecord(ifstream &emfFile, unsigned int type) {
    EmfRecord *record;

    switch (type) {
        case EMR_SETWINDOWORGEX:
            record = ReadSetWindowOrgExRecord(emfFile);
            break;

        case EMR_SETVIEWPORTEXTEX:
            record = ReadSetViewportExtExRecord(emfFile);
            break;

        case EMR_SETVIEWPORTORGEX:
            record = ReadSetViewportOrgExRecord(emfFile);
            break;

        case EMR_SETBRUSHORGEX:
            record = ReadSetBrushOrgExRecord(emfFile);
            break;

        case EMR_SETPIXELV:
            record = ReadSetPixelVRecord(emfFile);
            break;

        case EMR_SETMAPPERFLAGS:
            record = ReadSetMapperFlagsRecord(emfFile);
            break;

        case EMR_SETMAPMODE:
            record = ReadSetMapModeRecord(emfFile);
            break;

        case EMR_SETBKMODE:
            record = ReadSetBkModeRecord(emfFile);
            break;

        case EMR_SETPOLYFILLMODE:
            record = ReadSetPolyfillModeRecord(emfFile);
            break;

        case EMR_SETROP2:
            record = ReadSetRop2Record(emfFile);
            break;

        case EMR_SETSTRETCHBLTMODE:
            record = ReadSetStretchBltModeRecord(emfFile);
            break;

        case EMR_SETTEXTALIGN:
            record = ReadSetTextAlignRecord(emfFile);
            break;

        case EMR_SETCOLORADJUSTMENT:
            record = ReadSetColorAdjustmentRecord(emfFile);
            break;

        case EMR_SETTEXTCOLOR:
            record = ReadSetTextColorRecord(emfFile);
            break;

        case EMR_SETBKCOLOR:
            record = ReadSetBkColorRecord(emfFile);
            break;

        case EMR_OFFSETCLIPRGN:
            record = ReadOffsetClipRgnRecord(emfFile);
            break;

        case EMR_MOVETOEX:
            record = ReadMoveToExRecord(emfFile);
            break;

        case EMR_SETMETARGN:
            record = ReadSetMetaRgnRecord(emfFile);
            break;

        case EMR_EXCLUDECLIPRECT:
            record = ReadExcludeClipRectRecord(emfFile);
            break;

        case EMR_INTERSECTCLIPRECT:
            record = ReadIntersectClipRectRecord(emfFile);
            break;

        case EMR_SCALEVIEWPORTEXTEX:
            record = ReadViewportExtExRecord(emfFile);
            break;

        case EMR_SCALEWINDOWEXTEX:
            record = ReadScaleWindowExtExRecord(emfFile);
            break;

        case EMR_SAVEDC:
            record = ReadSaveDCRecord(emfFile);
            break;

        case EMR_RESTOREDC:
            record = ReadRestoreDCRecord(emfFile);
            break;

        case EMR_RESIZEPALETTE:
            record = ReadResizePaletteRecord(emfFile);
            break;

        case EMR_REALIZEPALETTE:
            record = ReadRealizePaletteRecord(emfFile);
            break;

        case EMR_SETARCDIRECTION:
            record = ReadSetArcDirectionRecord(emfFile);
            break;

        case EMR_SETMITERLIMIT:
            record = ReadSetMiterLimitRecord(emfFile);
            break;

        case EMR_INVERTRGN:
            record = ReadInvertRgnRecord(emfFile);
            break;

        case EMR_SETICMMODE:
            record = ReadSetICMModeRecord(emfFile);
            break;

        case EMR_PIXELFORMAT:
            record = ReadPixelFormatRecord(emfFile);
            break;

        case EMR_FORCEUFIMAPPING:
            record = ReadForceUFIMappingRecord(emfFile);
            break;

        case EMR_SETICMPROFILEA:
            record = ReadSetICMProfileARecord(emfFile);
            break;

        case EMR_SETICMPROFILEW:
            record = ReadSetICMProfileWRecord(emfFile);
            break;

        case EMR_SETLAYOUT:
            record = ReadSetLayoutRecord(emfFile);
            break;

        case EMR_SETLINKEDUFIS:
            record = ReadSetLinkedUFIsRecord(emfFile);
            break;

        case EMR_SETTEXTJUSTIFICATION:
            record = ReadSetTextJustificationRecord(emfFile);
            break;

        case EMR_COLORMATCHTOTARGETW:
            record = ReadColorMatchToTargetWRecord(emfFile);
            break;

        default:
            cerr << "There is no way we should have got here..." << endl;
    }

    record->type = type;

    return record;
}

EmfRecord *ReadSetWindowOrgExRecord(ifstream &emfFile) {
    EmfSetWindowOrgExRecord record;

    emfFile.read(reinterpret_cast<char *>(&record.Origin->x), 4);
    emfFile.read(reinterpret_cast<char *>(&record.Origin->y), 4);

    EmfRecord *retRecord = &record;
    return retRecord;
}

EmfRecord *ReadSetViewportExtExRecord(ifstream &emfFile) {
    EmfSetWindowExtExRecord record;

    emfFile.read(reinterpret_cast<char *>(&record.Extent->cx), 4);
    emfFile.read(reinterpret_cast<char *>(&record.Extent->cy), 4);

    EmfRecord *retRecord = &record;
    return retRecord;
}



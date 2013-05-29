#include <iostream>
#include <fstream>
#include <vector>

#include "record.hxx"
#include "defs.hxx"

using namespace std;

EmfRecords ReadRecords(ifstream &emfFile, unsigned int numRecords) {

    EmfRecords records(numRecords+1);

    for (int i=0; i < numRecords; i++) {
        EmfRecord record;

        int currentPos = emfFile.tellg();

        emfFile.read(reinterpret_cast<char *>(&record.type), 4);
        emfFile.read(reinterpret_cast<char *>(&record.size), 4);

        records[i] = record;

        cout << "Offset: " << currentPos << " "
             << "Record " << i << " is of type " 
             << std::hex << std::showbase << record.type
             << " and is " << std::dec << record.size << " bytes long." << endl;

        emfFile.seekg(currentPos + record.size, ios::beg);

        if (isBitmapRecord(record.type)) {
            cerr << "Bitmap parsing not implemented yet" << endl; 
        } else if (isClippingRecord(record.type)) {
            cerr << "Clipping parsing not implemented yet" << endl;
        } else if (isCommentRecord(record.type)) {
            cerr << "Comment parsing not implemented yet" << endl;
        } else if (isControlRecord(record.type)) {
            cerr << "Control parsing not implemented yet" << endl;
        } else if (isDrawingRecord(record.type)) {
            cerr << "Drawing parsing not implemented yet" << endl;
        } else if (isEscapeRecord(record.type)) {
            cerr << "Escape parsing not implemented yet" << endl;
        } else if (isObjectCreationRecord(record.type)) {
            cerr << "Object escape parsing not implemented yet" << endl;
        } else if (isObjectManipulationRecord(record.type)) {
            cerr << "Object manipulation parsing not implemented yet" << endl;
        } else if (isOpenGLRecord(record.type)) {
            cerr << "OpenGL parsing not implemented yet" << endl;
        } else if (isPathBracketRecord(record.type)) {
            cerr << "Path bracket parsing not implemented yet" << endl;
        } else if (isStateRecord(record.type)) {
            cerr << "State parsing not implemented yet" << endl;
        } else if (isTransformRecord(record.type)) {
            cerr << "Transform parsing not implemented yet" << endl;
        }

    }

    return records;
}

int isBitmapRecord(unsigned int type) {
    int isBitmapRecord=0;

    switch (type) {
        case EMR_BITBLT:
        case EMR_STRETCHBLT:
        case EMR_MASKBLT:
        case EMR_PLGBLT:
        case EMR_SETDIBITSTODEVICE:
        case EMR_STRETCHDIBITS:
        case EMR_ALPHABLEND:
        case EMR_TRANSPARENTBLT:
            isBitmapRecord=1;
            break;
    }

    return isBitmapRecord;
}

int isClippingRecord(unsigned int type) {
    int isClippingRecord=0;

    switch (type) {
        case EMR_EXCLUDECLIPRECT:
        case EMR_EXTSELECTCLIPRGN:
        case EMR_INTERSECTCLIPRECT:
        case EMR_OFFSETCLIPRGN:
        case EMR_SELECTCLIPPATH:
            isClippingRecord=1;
            break;
    }

    return isClippingRecord;
}

int isCommentRecord(unsigned int type) {
    int isCommentRecord=0;

    switch (type) {
        case EMR_COMMENT:
        case EMR_COMMENT_EMFPLUS:
        case EMR_COMMENT_EMFSPOOL:
        case EMR_COMMENT_PUBLIC:
            isCommentRecord=1;
            break;
    }

    return isCommentRecord;
}

int isControlRecord(unsigned int type) {
    int isControlRecord=0;

    switch (type) {
        case EMR_EOF:
        case EMR_HEADER:
            isControlRecord=1;
            break;
    }

    return isControlRecord;
}

int isDrawingRecord(unsigned int type) {
    int isDrawingRecord=0;

    switch (type) {
        case EMR_ANGLEARC:
        case EMR_ARC:
        case EMR_ARCTO:
        case EMR_CHORD:
        case EMR_ELLIPSE:
        case EMR_EXTFLOODFILL:
        case EMR_EXTTEXTOUTA:
        case EMR_EXTTEXTOUTW:
        case EMR_FILLPATH:
        case EMR_FILLRGN:
        case EMR_FRAMERGN:
        case EMR_GRADIENTFILL:
        case EMR_LINETO:
        case EMR_PAINTRGN:
        case EMR_PIE:
        case EMR_POLYBEZIER:
        case EMR_POLYBEZIER16:
        case EMR_POLYBEZIERTO:
        case EMR_POLYBEZIERTO16:
        case EMR_POLYDRAW:
        case EMR_POLYDRAW16:
        case EMR_POLYGON:
        case EMR_POLYGON16:
        case EMR_POLYLINE:
        case EMR_POLYLINE16:
        case EMR_POLYLINETO:
        case EMR_POLYLINETO16:
        case EMR_POLYPOLYGON:
        case EMR_POLYPOLYGON16:
        case EMR_POLYPOLYLINE:
        case EMR_POLYPOLYLINE16:
        case EMR_POLYTEXTOUTA:
        case EMR_POLYTEXTOUTW:
        case EMR_RECTANGLE:
        case EMR_ROUNDRECT:
        case EMR_SETPIXELV:
        case EMR_SMALLTEXTOUT:
        case EMR_STROKEANDFILLPATH:
        case EMR_STROKEPATH:
            isDrawingRecord=1;
    }

    return isDrawingRecord;
}

int isEscapeRecord(unsigned int type) {
    int isEscapeRecord=0;

    switch (type) {
        case EMR_DRAWESCAPE:
        case EMR_EXTESCAPE:
        case EMR_NAMEDESCAPE:
            isEscapeRecord=1;
    }

    return isEscapeRecord;
}

int isObjectCreationRecord(unsigned int type) {
    int isObjectCreationRecord=0;

    switch (type) {
        case EMR_CREATEBRUSHINDIRECT:
        case EMR_CREATECOLORSPACE:
        case EMR_CREATECOLORSPACEW:
        case EMR_CREATEDIBPATTERNBRUSHPT:
        case EMR_CREATEMONOBRUSH:
        case EMR_CREATEPALETTE:
        case EMR_CREATEPEN:
        case EMR_EXTCREATEFONTINDIRECTW:
        case EMR_EXTCREATEPEN:
            isObjectCreationRecord=1;
    }

    return isObjectCreationRecord;
}

int isObjectManipulationRecord(unsigned int type) {
    int isObjectManipulationRecord=0;

    switch (type) {
        case EMR_COLORCORRECTPALETTE:
        case EMR_DELETECOLORSPACE:
        case EMR_DELETEOBJECT:
        case EMR_RESIZEPALETTE:
        case EMR_SELECTOBJECT:
        case EMR_SELECTPALETTE:
        case EMR_SETCOLORSPACE:
        case EMR_SETPALETTEENTRIES:
            isObjectManipulationRecord=1;
    }

    return isObjectManipulationRecord;
}

int isOpenGLRecord(unsigned int type) {
    int isOpenGLRecord=0;

    switch (type) {
        case EMR_GLSBOUNDEDRECORD:
        case EMR_GLSRECORD:
            isOpenGLRecord=1;
    }

    return isOpenGLRecord;
}

int isPathBracketRecord(unsigned int type) {
    int isPathBracketRecord=0;

    switch (type) {
        case EMR_BEGINPATH:
        case EMR_ENDPATH:
        case EMR_CLOSEFIGURE:
        case EMR_FLATTENPATH:
        case EMR_WIDENPATH:
        case EMR_ABORTPATH:
            isPathBracketRecord=1;
    }

    return isPathBracketRecord;
}

int isStateRecord(unsigned int type) {
    int isStateRecord=0;

    switch (type) {
        case EMR_COLORMATCHTOTARGETW:
        case EMR_FORCEUFIMAPPING:
        case EMR_INVERTRGN:
        case EMR_MOVETOEX:
        case EMR_PIXELFORMAT:
        case EMR_RESTOREDC:
        case EMR_SCALEVIEWPORTEXTEX:
        case EMR_SCALEWINDOWEXTEX:
        case EMR_SETARCDIRECTION:
        case EMR_SETBKCOLOR:
        case EMR_SETBKMODE:
        case EMR_SETBRUSHORGEX:
        case EMR_SETCOLORADJUSTMENT:
        case EMR_SETICMMODE:
        case EMR_SETICMPROFILEA:
        case EMR_SETICMPROFILEW:
        case EMR_SETLAYOUT:
        case EMR_SETLINKEDUFIS:
        case EMR_SETMAPMODE:
        case EMR_SETMAPPERFLAGS:
        case EMR_SETMITERLIMIT:
        case EMR_SETPOLYFILLMODE:
        case EMR_SETROP2:
        case EMR_SETSTRETCHBLTMODE:
        case EMR_SETTEXTALIGN:
        case EMR_SETTEXTCOLOR:
        case EMR_SETTEXTJUSTIFICATION:
        case EMR_SETVIEWPORTEXTEX:
        case EMR_SETVIEWPORTORGEX:
        case EMR_SETWINDOWEXTEX:
        case EMR_SETWINDOWORGEX:
            isStateRecord=1;
    }

    return isStateRecord;
}

int isTransformRecord(unsigned int type) {
    int isTransformRecord=0;

    switch (type) {
        case EMR_MODIFYWORLDTRANSFORM:
        case EMR_SETWORLDTRANSFORM:
            isTransformRecord=1;
    }

    return isTransformRecord;
}

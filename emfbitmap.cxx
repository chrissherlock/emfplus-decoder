#include <fstream>
#include <iostream>

#include "emfrecord.hxx"
#include "emfbitmap.hxx"
#include "defs.hxx"

using namespace std;

EmfRecord *ReadBitmapRecord(ifstream &emf, unsigned int type) {
    EmfRecord *record;

    switch (type) {
        case EMR_BITBLT:
            record = ReadBitBltRecord(emf, record);
            break;

        case EMR_STRETCHBLT:
            record = ReadStretchBltRecord(emf, record);
            break;

        case EMR_MASKBLT:
            record = ReadMaskBltRecord(emf, record);
            break;

        case EMR_PLGBLT:
            record = ReadPlgBltRecord(emf, record);
            break;

        case EMR_SETDIBITSTODEVICE:
            record = ReadSetDIBitsToDeviceRecord(emf, record);
            break;

        case EMR_STRETCHDIBITS:
            record = ReadStretchDIBitsRecord(emf, record);
            break;

        case EMR_ALPHABLEND:
            record = ReadAlphaBlendRecord(emf, record);
            break;

        case EMR_TRANSPARENTBLT:
            record = ReadTransparentBltRecord(emf, record);
            break;

        default:
            cerr << "There is no way we should have got here..." << endl;
    }

    record->type = type;

    return record;
}

EmfRecord *ReadBitBltRecord(ifstream &emf) {
    EmfBitBlt record;

    emf.read(reinterpret_cast<char *>(&record.Bounds->left), 4);
    emf.read(reinterpret_cast<char *>(&record.Bounds->top), 4);
    emf.read(reinterpret_cast<char *>(&record.Bounds->right), 4);
    emf.read(reinterpret_cast<char *>(&record.Bounds->bottom), 4);
    emf.read(reinterpret_cast<char *>(&record.xDest), 4);
    emf.read(reinterpret_cast<char *>(&record.yDest), 4);
    emf.read(reinterpret_cast<char *>(&record.cxDest), 4);
    emf.read(reinterpret_cast<char *>(&record.cyDest), 4);
    emf.read(reinterpret_cast<char *>(&record.BitBltRasterOperation), 4);
    emf.read(reinterpret_cast<char *>(&record.xSrc), 4);
    emf.read(reinterpret_cast<char *>(&record.ySrc), 4);
    emf.read(reinterpret_cast<char *>(&record.XformSrc->M11), 4);
    emf.read(reinterpret_cast<char *>(&record.XformSrc->M12), 4);
    emf.read(reinterpret_cast<char *>(&record.XformSrc->M21), 4);
    emf.read(reinterpret_cast<char *>(&record.XformSrc->M22), 4);
    emf.read(reinterpret_cast<char *>(&record.XformSrc->Dx), 4);
    emf.read(reinterpret_cast<char *>(&record.XformSrc->Dy), 4);
    emf.read(reinterpret_cast<char *>(&record.BkColorSrc->Red), 4);
    emf.read(reinterpret_cast<char *>(&record.BkColorSrc->Green), 4);
    emf.read(reinterpret_cast<char *>(&record.BkColorSrc->Blue), 4);
    emf.read(reinterpret_cast<char *>(&record.BkColorSrc->Reserved), 4);
    emf.read(reinterpret_cast<char *>(&record.UsageSrc), 4);
    emf.read(reinterpret_cast<char *>(&record.offBmiSrc), 4);
    emf.read(reinterpret_cast<char *>(&record.cbBitsSrc), 4);

    EmfRecord *retRecord = &record;
    return retRecord;
}

EmfRecord *ReadStretchBltRecord(ifstream &emf) {
    EmfStretchBlt record;

    emf.read(reinterpret_cast<char *>(&record.Bounds->left), 4);
    emf.read(reinterpret_cast<char *>(&record.Bounds->top), 4);
    emf.read(reinterpret_cast<char *>(&record.Bounds->right), 4);
    emf.read(reinterpret_cast<char *>(&record.Bounds->bottom), 4);
    emf.read(reinterpret_cast<char *>(&record.xDest), 4);
    emf.read(reinterpret_cast<char *>(&record.yDest), 4);
    emf.read(reinterpret_cast<char *>(&record.cxDest), 4);
    emf.read(reinterpret_cast<char *>(&record.cyDest), 4);
    emf.read(reinterpret_cast<char *>(&record.BitBltRasterOperation), 4);
    emf.read(reinterpret_cast<char *>(&record.xSrc), 4);
    emf.read(reinterpret_cast<char *>(&record.ySrc), 4);
    emf.read(reinterpret_cast<char *>(&record.XformSrc->M11), 4);
    emf.read(reinterpret_cast<char *>(&record.XformSrc->M12), 4);
    emf.read(reinterpret_cast<char *>(&record.XformSrc->M21), 4);
    emf.read(reinterpret_cast<char *>(&record.XformSrc->M22), 4);
    emf.read(reinterpret_cast<char *>(&record.XformSrc->Dx), 4);
    emf.read(reinterpret_cast<char *>(&record.XformSrc->Dy), 4);
    emf.read(reinterpret_cast<char *>(&record.BkColorSrc->Red), 4);
    emf.read(reinterpret_cast<char *>(&record.BkColorSrc->Green), 4);
    emf.read(reinterpret_cast<char *>(&record.BkColorSrc->Blue), 4);
    emf.read(reinterpret_cast<char *>(&record.BkColorSrc->Reserved), 4);
    emf.read(reinterpret_cast<char *>(&record.UsageSrc), 4);
    emf.read(reinterpret_cast<char *>(&record.offBmiSrc), 4);
    emf.read(reinterpret_cast<char *>(&record.cbBitsSrc), 4);

    EmfRecord *retRecord = &record;
    return retRecord;
}

EmfRecord *ReadMaskBltRecord(ifstream &emf) {
    EmfMaskBlt record;

    emf.read(reinterpret_cast<char *>(&record.Bounds->left), 4);
    emf.read(reinterpret_cast<char *>(&record.Bounds->top), 4);
    emf.read(reinterpret_cast<char *>(&record.Bounds->right), 4);
    emf.read(reinterpret_cast<char *>(&record.Bounds->bottom), 4);
    emf.read(reinterpret_cast<char *>(&record.xDest), 4);
    emf.read(reinterpret_cast<char *>(&record.yDest), 4);
    emf.read(reinterpret_cast<char *>(&record.cxDest), 4);
    emf.read(reinterpret_cast<char *>(&record.cyDest), 4);
    emf.read(reinterpret_cast<char *>(&record.ROP4Reserved), 4);
    emf.read(reinterpret_cast<char *>(&record.BackgroundROP3), 4);
    emf.read(reinterpret_cast<char *>(&record.ForegroundROP3), 4);
    emf.read(reinterpret_cast<char *>(&record.xSrc), 4);
    emf.read(reinterpret_cast<char *>(&record.ySrc), 4);
    emf.read(reinterpret_cast<char *>(&record.XformSrc->M11), 4);
    emf.read(reinterpret_cast<char *>(&record.XformSrc->M12), 4);
    emf.read(reinterpret_cast<char *>(&record.XformSrc->M21), 4);
    emf.read(reinterpret_cast<char *>(&record.XformSrc->M22), 4);
    emf.read(reinterpret_cast<char *>(&record.XformSrc->Dx), 4);
    emf.read(reinterpret_cast<char *>(&record.XformSrc->Dy), 4);
    emf.read(reinterpret_cast<char *>(&record.BkColorSrc->Red), 4);
    emf.read(reinterpret_cast<char *>(&record.BkColorSrc->Green), 4);
    emf.read(reinterpret_cast<char *>(&record.BkColorSrc->Blue), 4);
    emf.read(reinterpret_cast<char *>(&record.BkColorSrc->Reserved), 4);
    emf.read(reinterpret_cast<char *>(&record.UsageSrc), 4);
    emf.read(reinterpret_cast<char *>(&record.offBmiSrc), 4);
    emf.read(reinterpret_cast<char *>(&record.cbBmiSrc), 4);
    emf.read(reinterpret_cast<char *>(&record.offBitsSrc), 4);
    emf.read(reinterpret_cast<char *>(&record.cbBitsSrc), 4);
    emf.read(reinterpret_cast<char *>(&record.offBitsMask), 4);
    emf.read(reinterpret_cast<char *>(&record.cbBitsMask), 4);

    EmfRecord *retRecord = &record;
    return retRecord;
}

EmfRecord *ReadPlgBltRecord(ifstream &emf) {
    EmfPlgBlt record;

    emf.read(reinterpret_cast<char *>(&record.Bounds->left), 4);
    emf.read(reinterpret_cast<char *>(&record.Bounds->top), 4);
    emf.read(reinterpret_cast<char *>(&record.Bounds->right), 4);
    emf.read(reinterpret_cast<char *>(&record.Bounds->bottom), 4);
    emf.read(reinterpret_cast<char *>(&record.dstPoint1->x), 4),
    emf.read(reinterpret_cast<char *>(&record.dstPoint1->y), 4),
    emf.read(reinterpret_cast<char *>(&record.dstPoint2->x), 4),
    emf.read(reinterpret_cast<char *>(&record.dstPoint2->y), 4),
    emf.read(reinterpret_cast<char *>(&record.dstPoint3->x), 4),
    emf.read(reinterpret_cast<char *>(&record.dstPoint3->y), 4),
    emf.read(reinterpret_cast<char *>(&record.xSrc), 4);
    emf.read(reinterpret_cast<char *>(&record.ySrc), 4);
    emf.read(reinterpret_cast<char *>(&record.cxSrc), 4);
    emf.read(reinterpret_cast<char *>(&record.cySrc), 4);
    emf.read(reinterpret_cast<char *>(&record.XformSrc->M11), 4);
    emf.read(reinterpret_cast<char *>(&record.XformSrc->M12), 4);
    emf.read(reinterpret_cast<char *>(&record.XformSrc->M21), 4);
    emf.read(reinterpret_cast<char *>(&record.XformSrc->M22), 4);
    emf.read(reinterpret_cast<char *>(&record.XformSrc->Dx), 4);
    emf.read(reinterpret_cast<char *>(&record.XformSrc->Dy), 4);
    emf.read(reinterpret_cast<char *>(&record.BkColorSrc->Red), 4);
    emf.read(reinterpret_cast<char *>(&record.BkColorSrc->Green), 4);
    emf.read(reinterpret_cast<char *>(&record.BkColorSrc->Blue), 4);
    emf.read(reinterpret_cast<char *>(&record.BkColorSrc->Reserved), 4);
    emf.read(reinterpret_cast<char *>(&record.UsageSrc), 4);
    emf.read(reinterpret_cast<char *>(&record.offBmiSrc), 4);
    emf.read(reinterpret_cast<char *>(&record.cbBmiSrc), 4);
    emf.read(reinterpret_cast<char *>(&record.offBitsSrc), 4);
    emf.read(reinterpret_cast<char *>(&record.cbBitsSrc), 4);
    emf.read(reinterpret_cast<char *>(&record.offBitsMask), 4);
    emf.read(reinterpret_cast<char *>(&record.cbBitsMask), 4);

    EmfRecord *retRecord = &record;
    return retRecord;
}

EmfRecord *ReadSetDIBitsToDeviceRecord(ifstream &emf) {
    EmfSetDIBitsToDevice record;

    emf.read(reinterpret_cast<char *>(&record.Bounds->left), 4);
    emf.read(reinterpret_cast<char *>(&record.Bounds->top), 4);
    emf.read(reinterpret_cast<char *>(&record.Bounds->right), 4);
    emf.read(reinterpret_cast<char *>(&record.Bounds->bottom), 4);
    emf.read(reinterpret_cast<char *>(&record.xDest), 4);
    emf.read(reinterpret_cast<char *>(&record.yDest), 4);
    emf.read(reinterpret_cast<char *>(&record.xSrc), 4);
    emf.read(reinterpret_cast<char *>(&record.ySrc), 4);
    emf.read(reinterpret_cast<char *>(&record.cxSrc), 4);
    emf.read(reinterpret_cast<char *>(&record.cySrc), 4);
    emf.read(reinterpret_cast<char *>(&record.offBmiSrc), 4);
    emf.read(reinterpret_cast<char *>(&record.cbBmiSrc), 4);
    emf.read(reinterpret_cast<char *>(&record.offBitsSrc), 4);
    emf.read(reinterpret_cast<char *>(&record.cbBitsSrc), 4);
    emf.read(reinterpret_cast<char *>(&record.UsageSrc), 4);
    emf.read(reinterpret_cast<char *>(&record.iStartScan), 4);
    emf.read(reinterpret_cast<char *>(&record.cScans), 4);

    EmfRecord *retRecord = &record;
    return retRecord;
}

EmfRecord *ReadStretchDIBitsRecord(ifstream &emf) {
    EmfStretchDIBits record;

    emf.read(reinterpret_cast<char *>(&record.Bounds->left), 4);
    emf.read(reinterpret_cast<char *>(&record.Bounds->top), 4);
    emf.read(reinterpret_cast<char *>(&record.Bounds->right), 4);
    emf.read(reinterpret_cast<char *>(&record.Bounds->bottom), 4);
    emf.read(reinterpret_cast<char *>(&record.xDest), 4);
    emf.read(reinterpret_cast<char *>(&record.yDest), 4);
    emf.read(reinterpret_cast<char *>(&record.xSrc), 4);
    emf.read(reinterpret_cast<char *>(&record.ySrc), 4);
    emf.read(reinterpret_cast<char *>(&record.cxSrc), 4);
    emf.read(reinterpret_cast<char *>(&record.cySrc), 4);
    emf.read(reinterpret_cast<char *>(&record.offBmiSrc), 4);
    emf.read(reinterpret_cast<char *>(&record.cbBmiSrc), 4);
    emf.read(reinterpret_cast<char *>(&record.offBitsSrc), 4);
    emf.read(reinterpret_cast<char *>(&record.cbBitsSrc), 4);
    emf.read(reinterpret_cast<char *>(&record.UsageSrc), 4);
    emf.read(reinterpret_cast<char *>(&record.BitBltRasterOperation), 4);
    emf.read(reinterpret_cast<char *>(&record.cxDest), 4);
    emf.read(reinterpret_cast<char *>(&record.cyDest), 4);

    EmfRecord *retRecord = &record;
    return retRecord;
}

EmfRecord *ReadAlphaBlendRecord(ifstream &emf) {
    EmfAlphaBlend record;

    emf.read(reinterpret_cast<char *>(&record.Bounds->left), 4);
    emf.read(reinterpret_cast<char *>(&record.Bounds->top), 4);
    emf.read(reinterpret_cast<char *>(&record.Bounds->right), 4);
    emf.read(reinterpret_cast<char *>(&record.Bounds->bottom), 4);
    emf.read(reinterpret_cast<char *>(&record.xDest), 4);
    emf.read(reinterpret_cast<char *>(&record.yDest), 4);
    emf.read(reinterpret_cast<char *>(&record.cxDest), 4);
    emf.read(reinterpret_cast<char *>(&record.cyDest), 4);
    // start BLENDFUNCTION
    emf.read(reinterpret_cast<char *>(&record.BlendOperation), 1);
    emf.read(reinterpret_cast<char *>(&record.BlendFlags), 1);
    emf.read(reinterpret_cast<char *>(&record.SrcConstantAlpha), 1);
    emf.read(reinterpret_cast<char *>(&record.AlphaFormat), 1);
    // start BLENDFUNCTION
    emf.read(reinterpret_cast<char *>(&record.xSrc), 4);
    emf.read(reinterpret_cast<char *>(&record.ySrc), 4);
    emf.read(reinterpret_cast<char *>(&record.XformSrc->M11), 4);
    emf.read(reinterpret_cast<char *>(&record.XformSrc->M12), 4);
    emf.read(reinterpret_cast<char *>(&record.XformSrc->M21), 4);
    emf.read(reinterpret_cast<char *>(&record.XformSrc->M22), 4);
    emf.read(reinterpret_cast<char *>(&record.XformSrc->Dx), 4);
    emf.read(reinterpret_cast<char *>(&record.XformSrc->Dy), 4);
    emf.read(reinterpret_cast<char *>(&record.BkColorSrc->Red), 4);
    emf.read(reinterpret_cast<char *>(&record.BkColorSrc->Green), 4);
    emf.read(reinterpret_cast<char *>(&record.BkColorSrc->Blue), 4);
    emf.read(reinterpret_cast<char *>(&record.BkColorSrc->Reserved), 4);
    emf.read(reinterpret_cast<char *>(&record.UsageSrc), 4);
    emf.read(reinterpret_cast<char *>(&record.offBmiSrc), 4);
    emf.read(reinterpret_cast<char *>(&record.cbBmsSrc), 4);
    emf.read(reinterpret_cast<char *>(&record.offBitsSrc), 4);
    emf.read(reinterpret_cast<char *>(&record.cbBitsSrc), 4);
    emf.read(reinterpret_cast<char *>(&record.cxSrc), 4);
    emf.read(reinterpret_cast<char *>(&record.cySrc), 4);

    EmfRecord *retRecord = &record;
    return retRecord;
}

EmfRecord *ReadTransparentBltRecord(ifstream &emf) {
    EmfTransparentBlt record;

    emf.read(reinterpret_cast<char *>(&record.Bounds->left), 4);
    emf.read(reinterpret_cast<char *>(&record.Bounds->top), 4);
    emf.read(reinterpret_cast<char *>(&record.Bounds->right), 4);
    emf.read(reinterpret_cast<char *>(&record.Bounds->bottom), 4);
    emf.read(reinterpret_cast<char *>(&record.xDest), 4);
    emf.read(reinterpret_cast<char *>(&record.yDest), 4);
    emf.read(reinterpret_cast<char *>(&record.cxDest), 4);
    emf.read(reinterpret_cast<char *>(&record.cyDest), 4);
    emf.read(reinterpret_cast<char *>(&record.TransparentColorSrc->Red), 4);
    emf.read(reinterpret_cast<char *>(&record.TransparentColorSrc->Green), 4);
    emf.read(reinterpret_cast<char *>(&record.TransparentColorSrc->Blue), 4);
    emf.read(reinterpret_cast<char *>(&record.TransparentColorSrc->Reserved), 4);
    emf.read(reinterpret_cast<char *>(&record.xSrc), 4);
    emf.read(reinterpret_cast<char *>(&record.ySrc), 4);
    emf.read(reinterpret_cast<char *>(&record.XformSrc->M11), 4);
    emf.read(reinterpret_cast<char *>(&record.XformSrc->M12), 4);
    emf.read(reinterpret_cast<char *>(&record.XformSrc->M21), 4);
    emf.read(reinterpret_cast<char *>(&record.XformSrc->M22), 4);
    emf.read(reinterpret_cast<char *>(&record.XformSrc->Dx), 4);
    emf.read(reinterpret_cast<char *>(&record.XformSrc->Dy), 4);
    emf.read(reinterpret_cast<char *>(&record.BkColorSrc->Red), 4);
    emf.read(reinterpret_cast<char *>(&record.BkColorSrc->Green), 4);
    emf.read(reinterpret_cast<char *>(&record.BkColorSrc->Blue), 4);
    emf.read(reinterpret_cast<char *>(&record.BkColorSrc->Reserved), 4);
    emf.read(reinterpret_cast<char *>(&record.UsageSrc), 4);
    emf.read(reinterpret_cast<char *>(&record.offBmiSrc), 4);
    emf.read(reinterpret_cast<char *>(&record.cbBmiSrc), 4);
    emf.read(reinterpret_cast<char *>(&record.offBitsSrc), 4);
    emf.read(reinterpret_cast<char *>(&record.cbBitsSrc), 4);
    emf.read(reinterpret_cast<char *>(&record.cxSrc), 4);
    emf.read(reinterpret_cast<char *>(&record.cySrc), 4);

    EmfRecord *retRecord = &record;
    return retRecord;
}

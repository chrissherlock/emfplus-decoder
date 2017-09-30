#include <fstream>
#include <iostream>

#include "emfrecord.hxx"
#include "emfbitmap.hxx"
#include "defs.hxx"

using namespace std;

EmfRecord *ReadBitmapRecord(ifstream &emfFile, unsigned int type) {
    EmfRecord *record;

    switch (type) {
        case EMR_BITBLT:
            record = ReadBitBltRecord(emfFile, record);
            break;

        case EMR_STRETCHBLT:
            record = ReadStretchBltRecord(emfFile, record);
            break;

        case EMR_MASKBLT:
            record = ReadMaskBltRecord(emfFile, record);
            break;

        case EMR_PLGBLT:
            record = ReadPlgBltRecord(emfFile, record);
            break;

        case EMR_SETDIBITSTODEVICE:
            record = ReadSetDIBitsToDeviceRecord(emfFile, record);
            break;

        case EMR_STRETCHDIBITS:
            record = ReadStretchDIBitsRecord(emfFile, record);
            break;

        case EMR_ALPHABLEND:
            record = ReadAlphaBlendRecord(emfFile, record);
            break;

        case EMR_TRANSPARENTBLT:
            record = ReadTransparentBltRecord(emfFile, record);
            break;

        default:
            cerr << "There is no way we should have got here..." << endl;
    }

    record->type = type;

    return record;
}

EmfRecord *ReadBitBltRecord(ifstream &emfFile) {
    EmfBitBlt bitBltRecord;

    emfFile.read(reinterpret_cast<char *>(&bitBltRecord.Bounds->left), 4);
    emfFile.read(reinterpret_cast<char *>(&bitBltRecord.Bounds->top), 4);
    emfFile.read(reinterpret_cast<char *>(&bitBltRecord.Bounds->right), 4);
    emfFile.read(reinterpret_cast<char *>(&bitBltRecord.Bounds->bottom), 4);
    emfFile.read(reinterpret_cast<char *>(&bitBltRecord.xDest), 4);
    emfFile.read(reinterpret_cast<char *>(&bitBltRecord.yDest), 4);
    emfFile.read(reinterpret_cast<char *>(&bitBltRecord.cxDest), 4);
    emfFile.read(reinterpret_cast<char *>(&bitBltRecord.cyDest), 4);
    emfFile.read(reinterpret_cast<char *>(&bitBltRecord.BitBltRasterOperation), 4);
    emfFile.read(reinterpret_cast<char *>(&bitBltRecord.xSrc), 4);
    emfFile.read(reinterpret_cast<char *>(&bitBltRecord.ySrc), 4);
    emfFile.read(reinterpret_cast<char *>(&bitBltRecord.XformSrc->M11), 4);
    emfFile.read(reinterpret_cast<char *>(&bitBltRecord.XformSrc->M12), 4);
    emfFile.read(reinterpret_cast<char *>(&bitBltRecord.XformSrc->M21), 4);
    emfFile.read(reinterpret_cast<char *>(&bitBltRecord.XformSrc->M22), 4);
    emfFile.read(reinterpret_cast<char *>(&bitBltRecord.XformSrc->Dx), 4);
    emfFile.read(reinterpret_cast<char *>(&bitBltRecord.XformSrc->Dy), 4);
    emfFile.read(reinterpret_cast<char *>(&bitBltRecord.BkColorSrc->Red), 4);
    emfFile.read(reinterpret_cast<char *>(&bitBltRecord.BkColorSrc->Green), 4);
    emfFile.read(reinterpret_cast<char *>(&bitBltRecord.BkColorSrc->Blue), 4);
    emfFile.read(reinterpret_cast<char *>(&bitBltRecord.BkColorSrc->Reserved), 4);
    emfFile.read(reinterpret_cast<char *>(&bitBltRecord.UsageSrc), 4);
    emfFile.read(reinterpret_cast<char *>(&bitBltRecord.offBmiSrc), 4);
    emfFile.read(reinterpret_cast<char *>(&bitBltRecord.cbBitsSrc), 4);

    EmfRecord *retRecord = &bitBltRecord;
    return retRecord;
}

EmfRecord *ReadStretchBltRecord(ifstream &emfFile) {
    EmfStretchBlt stretchBltRecord;

    emfFile.read(reinterpret_cast<char *>(&stretchBltRecord.Bounds->left), 4);
    emfFile.read(reinterpret_cast<char *>(&stretchBltRecord.Bounds->top), 4);
    emfFile.read(reinterpret_cast<char *>(&stretchBltRecord.Bounds->right), 4);
    emfFile.read(reinterpret_cast<char *>(&stretchBltRecord.Bounds->bottom), 4);
    emfFile.read(reinterpret_cast<char *>(&stretchBltRecord.xDest), 4);
    emfFile.read(reinterpret_cast<char *>(&stretchBltRecord.yDest), 4);
    emfFile.read(reinterpret_cast<char *>(&stretchBltRecord.cxDest), 4);
    emfFile.read(reinterpret_cast<char *>(&stretchBltRecord.cyDest), 4);
    emfFile.read(reinterpret_cast<char *>(&stretchBltRecord.BitBltRasterOperation), 4);
    emfFile.read(reinterpret_cast<char *>(&stretchBltRecord.xSrc), 4);
    emfFile.read(reinterpret_cast<char *>(&stretchBltRecord.ySrc), 4);
    emfFile.read(reinterpret_cast<char *>(&stretchBltRecord.XformSrc->M11), 4);
    emfFile.read(reinterpret_cast<char *>(&stretchBltRecord.XformSrc->M12), 4);
    emfFile.read(reinterpret_cast<char *>(&stretchBltRecord.XformSrc->M21), 4);
    emfFile.read(reinterpret_cast<char *>(&stretchBltRecord.XformSrc->M22), 4);
    emfFile.read(reinterpret_cast<char *>(&stretchBltRecord.XformSrc->Dx), 4);
    emfFile.read(reinterpret_cast<char *>(&stretchBltRecord.XformSrc->Dy), 4);
    emfFile.read(reinterpret_cast<char *>(&stretchBltRecord.BkColorSrc->Red), 4);
    emfFile.read(reinterpret_cast<char *>(&stretchBltRecord.BkColorSrc->Green), 4);
    emfFile.read(reinterpret_cast<char *>(&stretchBltRecord.BkColorSrc->Blue), 4);
    emfFile.read(reinterpret_cast<char *>(&stretchBltRecord.BkColorSrc->Reserved), 4);
    emfFile.read(reinterpret_cast<char *>(&stretchBltRecord.UsageSrc), 4);
    emfFile.read(reinterpret_cast<char *>(&stretchBltRecord.offBmiSrc), 4);
    emfFile.read(reinterpret_cast<char *>(&stretchBltRecord.cbBitsSrc), 4);

    EmfRecord *retRecord = &stretchBltRecord;
    return retRecord;
}

EmfRecord *ReadMaskBltRecord(ifstream &emfFile) {
    EmfMaskBlt maskBltRecord;

    emfFile.read(reinterpret_cast<char *>(&maskBltRecord.Bounds->left), 4);
    emfFile.read(reinterpret_cast<char *>(&maskBltRecord.Bounds->top), 4);
    emfFile.read(reinterpret_cast<char *>(&maskBltRecord.Bounds->right), 4);
    emfFile.read(reinterpret_cast<char *>(&maskBltRecord.Bounds->bottom), 4);
    emfFile.read(reinterpret_cast<char *>(&maskBltRecord.xDest), 4);
    emfFile.read(reinterpret_cast<char *>(&maskBltRecord.yDest), 4);
    emfFile.read(reinterpret_cast<char *>(&maskBltRecord.cxDest), 4);
    emfFile.read(reinterpret_cast<char *>(&maskBltRecord.cyDest), 4);
    emfFile.read(reinterpret_cast<char *>(&maskBltRecord.ROP4Reserved), 4);
    emfFile.read(reinterpret_cast<char *>(&maskBltRecord.BackgroundROP3), 4);
    emfFile.read(reinterpret_cast<char *>(&maskBltRecord.ForegroundROP3), 4);
    emfFile.read(reinterpret_cast<char *>(&maskBltRecord.xSrc), 4);
    emfFile.read(reinterpret_cast<char *>(&maskBltRecord.ySrc), 4);
    emfFile.read(reinterpret_cast<char *>(&maskBltRecord.XformSrc->M11), 4);
    emfFile.read(reinterpret_cast<char *>(&maskBltRecord.XformSrc->M12), 4);
    emfFile.read(reinterpret_cast<char *>(&maskBltRecord.XformSrc->M21), 4);
    emfFile.read(reinterpret_cast<char *>(&maskBltRecord.XformSrc->M22), 4);
    emfFile.read(reinterpret_cast<char *>(&maskBltRecord.XformSrc->Dx), 4);
    emfFile.read(reinterpret_cast<char *>(&maskBltRecord.XformSrc->Dy), 4);
    emfFile.read(reinterpret_cast<char *>(&maskBltRecord.BkColorSrc->Red), 4);
    emfFile.read(reinterpret_cast<char *>(&maskBltRecord.BkColorSrc->Green), 4);
    emfFile.read(reinterpret_cast<char *>(&maskBltRecord.BkColorSrc->Blue), 4);
    emfFile.read(reinterpret_cast<char *>(&maskBltRecord.BkColorSrc->Reserved), 4);
    emfFile.read(reinterpret_cast<char *>(&maskBltRecord.UsageSrc), 4);
    emfFile.read(reinterpret_cast<char *>(&maskBltRecord.offBmiSrc), 4);
    emfFile.read(reinterpret_cast<char *>(&maskBltRecord.cbBmiSrc), 4);
    emfFile.read(reinterpret_cast<char *>(&maskBltRecord.offBitsSrc), 4);
    emfFile.read(reinterpret_cast<char *>(&maskBltRecord.cbBitsSrc), 4);
    emfFile.read(reinterpret_cast<char *>(&maskBltRecord.offBitsMask), 4);
    emfFile.read(reinterpret_cast<char *>(&maskBltRecord.cbBitsMask), 4);

    EmfRecord *retRecord = &maskBltRecord;
    return retRecord;
}

EmfRecord *ReadPlgBltRecord(ifstream &emfFile) {
    EmfPlgBlt plgBltRecord;

    emfFile.read(reinterpret_cast<char *>(&plgBltRecord.Bounds->left), 4);
    emfFile.read(reinterpret_cast<char *>(&plgBltRecord.Bounds->top), 4);
    emfFile.read(reinterpret_cast<char *>(&plgBltRecord.Bounds->right), 4);
    emfFile.read(reinterpret_cast<char *>(&plgBltRecord.Bounds->bottom), 4);
    emfFile.read(reinterpret_cast<char *>(&plgBltRecord.dstPoint1->x), 4),
    emfFile.read(reinterpret_cast<char *>(&plgBltRecord.dstPoint1->y), 4),
    emfFile.read(reinterpret_cast<char *>(&plgBltRecord.dstPoint2->x), 4),
    emfFile.read(reinterpret_cast<char *>(&plgBltRecord.dstPoint2->y), 4),
    emfFile.read(reinterpret_cast<char *>(&plgBltRecord.dstPoint3->x), 4),
    emfFile.read(reinterpret_cast<char *>(&plgBltRecord.dstPoint3->y), 4),
    emfFile.read(reinterpret_cast<char *>(&plgBltRecord.xSrc), 4);
    emfFile.read(reinterpret_cast<char *>(&plgBltRecord.ySrc), 4);
    emfFile.read(reinterpret_cast<char *>(&plgBltRecord.cxSrc), 4);
    emfFile.read(reinterpret_cast<char *>(&plgBltRecord.cySrc), 4);
    emfFile.read(reinterpret_cast<char *>(&plgBltRecord.XformSrc->M11), 4);
    emfFile.read(reinterpret_cast<char *>(&plgBltRecord.XformSrc->M12), 4);
    emfFile.read(reinterpret_cast<char *>(&plgBltRecord.XformSrc->M21), 4);
    emfFile.read(reinterpret_cast<char *>(&plgBltRecord.XformSrc->M22), 4);
    emfFile.read(reinterpret_cast<char *>(&plgBltRecord.XformSrc->Dx), 4);
    emfFile.read(reinterpret_cast<char *>(&plgBltRecord.XformSrc->Dy), 4);
    emfFile.read(reinterpret_cast<char *>(&plgBltRecord.BkColorSrc->Red), 4);
    emfFile.read(reinterpret_cast<char *>(&plgBltRecord.BkColorSrc->Green), 4);
    emfFile.read(reinterpret_cast<char *>(&plgBltRecord.BkColorSrc->Blue), 4);
    emfFile.read(reinterpret_cast<char *>(&plgBltRecord.BkColorSrc->Reserved), 4);
    emfFile.read(reinterpret_cast<char *>(&plgBltRecord.UsageSrc), 4);
    emfFile.read(reinterpret_cast<char *>(&plgBltRecord.offBmiSrc), 4);
    emfFile.read(reinterpret_cast<char *>(&plgBltRecord.cbBmiSrc), 4);
    emfFile.read(reinterpret_cast<char *>(&plgBltRecord.offBitsSrc), 4);
    emfFile.read(reinterpret_cast<char *>(&plgBltRecord.cbBitsSrc), 4);
    emfFile.read(reinterpret_cast<char *>(&plgBltRecord.offBitsMask), 4);
    emfFile.read(reinterpret_cast<char *>(&plgBltRecord.cbBitsMask), 4);

    EmfRecord *retRecord = &plgBltRecord;
    return retRecord;
}

EmfRecord *ReadSetDIBitsToDeviceRecord(ifstream &emfFile) {
    EmfSetDIBitsToDevice setDIBitsToDeviceRecord;

    emfFile.read(reinterpret_cast<char *>(&setDIBitsToDeviceRecord.Bounds->left), 4);
    emfFile.read(reinterpret_cast<char *>(&setDIBitsToDeviceRecord.Bounds->top), 4);
    emfFile.read(reinterpret_cast<char *>(&setDIBitsToDeviceRecord.Bounds->right), 4);
    emfFile.read(reinterpret_cast<char *>(&setDIBitsToDeviceRecord.Bounds->bottom), 4);
    emfFile.read(reinterpret_cast<char *>(&setDIBitsToDeviceRecord.xDest), 4);
    emfFile.read(reinterpret_cast<char *>(&setDIBitsToDeviceRecord.yDest), 4);
    emfFile.read(reinterpret_cast<char *>(&setDIBitsToDeviceRecord.xSrc), 4);
    emfFile.read(reinterpret_cast<char *>(&setDIBitsToDeviceRecord.ySrc), 4);
    emfFile.read(reinterpret_cast<char *>(&setDIBitsToDeviceRecord.cxSrc), 4);
    emfFile.read(reinterpret_cast<char *>(&setDIBitsToDeviceRecord.cySrc), 4);
    emfFile.read(reinterpret_cast<char *>(&setDIBitsToDeviceRecord.offBmiSrc), 4);
    emfFile.read(reinterpret_cast<char *>(&setDIBitsToDeviceRecord.cbBmiSrc), 4);
    emfFile.read(reinterpret_cast<char *>(&setDIBitsToDeviceRecord.offBitsSrc), 4);
    emfFile.read(reinterpret_cast<char *>(&setDIBitsToDeviceRecord.cbBitsSrc), 4);
    emfFile.read(reinterpret_cast<char *>(&setDIBitsToDeviceRecord.UsageSrc), 4);
    emfFile.read(reinterpret_cast<char *>(&setDIBitsToDeviceRecord.iStartScan), 4);
    emfFile.read(reinterpret_cast<char *>(&setDIBitsToDeviceRecord.cScans), 4);

    EmfRecord *retRecord = &setDIBitsToDeviceRecord;
    return retRecord;
}

EmfRecord *ReadStretchDIBitsRecord(ifstream &emfFile) {
    EmfStretchDIBits stretchDIBRecord;

    emfFile.read(reinterpret_cast<char *>(&stretchDIBRecord.Bounds->left), 4);
    emfFile.read(reinterpret_cast<char *>(&stretchDIBRecord.Bounds->top), 4);
    emfFile.read(reinterpret_cast<char *>(&stretchDIBRecord.Bounds->right), 4);
    emfFile.read(reinterpret_cast<char *>(&stretchDIBRecord.Bounds->bottom), 4);
    emfFile.read(reinterpret_cast<char *>(&stretchDIBRecord.xDest), 4);
    emfFile.read(reinterpret_cast<char *>(&stretchDIBRecord.yDest), 4);
    emfFile.read(reinterpret_cast<char *>(&stretchDIBRecord.xSrc), 4);
    emfFile.read(reinterpret_cast<char *>(&stretchDIBRecord.ySrc), 4);
    emfFile.read(reinterpret_cast<char *>(&stretchDIBRecord.cxSrc), 4);
    emfFile.read(reinterpret_cast<char *>(&stretchDIBRecord.cySrc), 4);
    emfFile.read(reinterpret_cast<char *>(&stretchDIBRecord.offBmiSrc), 4);
    emfFile.read(reinterpret_cast<char *>(&stretchDIBRecord.cbBmiSrc), 4);
    emfFile.read(reinterpret_cast<char *>(&stretchDIBRecord.offBitsSrc), 4);
    emfFile.read(reinterpret_cast<char *>(&stretchDIBRecord.cbBitsSrc), 4);
    emfFile.read(reinterpret_cast<char *>(&stretchDIBRecord.UsageSrc), 4);
    emfFile.read(reinterpret_cast<char *>(&stretchDIBRecord.BitBltRasterOperation), 4);
    emfFile.read(reinterpret_cast<char *>(&stretchDIBRecord.cxDest), 4);
    emfFile.read(reinterpret_cast<char *>(&stretchDIBRecord.cyDest), 4);

    EmfRecord *retRecord = &stretchDIBRecord;
    return retRecord;
}

EmfRecord *ReadAlphaBlendRecord(ifstream &emfFile) {
    EmfAlphaBlend alphaBlendRecord;

    emfFile.read(reinterpret_cast<char *>(&alphaBlendRecord.Bounds->left), 4);
    emfFile.read(reinterpret_cast<char *>(&alphaBlendRecord.Bounds->top), 4);
    emfFile.read(reinterpret_cast<char *>(&alphaBlendRecord.Bounds->right), 4);
    emfFile.read(reinterpret_cast<char *>(&alphaBlendRecord.Bounds->bottom), 4);
    emfFile.read(reinterpret_cast<char *>(&alphaBlendRecord.xDest), 4);
    emfFile.read(reinterpret_cast<char *>(&alphaBlendRecord.yDest), 4);
    emfFile.read(reinterpret_cast<char *>(&alphaBlendRecord.cxDest), 4);
    emfFile.read(reinterpret_cast<char *>(&alphaBlendRecord.cyDest), 4);
    // start BLENDFUNCTION
    emfFile.read(reinterpret_cast<char *>(&alphaBlendRecord.BlendOperation), 1);
    emfFile.read(reinterpret_cast<char *>(&alphaBlendRecord.BlendFlags), 1);
    emfFile.read(reinterpret_cast<char *>(&alphaBlendRecord.SrcConstantAlpha), 1);
    emfFile.read(reinterpret_cast<char *>(&alphaBlendRecord.AlphaFormat), 1);
    // start BLENDFUNCTION
    emfFile.read(reinterpret_cast<char *>(&alphaBlendRecord.xSrc), 4);
    emfFile.read(reinterpret_cast<char *>(&alphaBlendRecord.ySrc), 4);
    emfFile.read(reinterpret_cast<char *>(&alphaBlendRecord.XformSrc->M11), 4);
    emfFile.read(reinterpret_cast<char *>(&alphaBlendRecord.XformSrc->M12), 4);
    emfFile.read(reinterpret_cast<char *>(&alphaBlendRecord.XformSrc->M21), 4);
    emfFile.read(reinterpret_cast<char *>(&alphaBlendRecord.XformSrc->M22), 4);
    emfFile.read(reinterpret_cast<char *>(&alphaBlendRecord.XformSrc->Dx), 4);
    emfFile.read(reinterpret_cast<char *>(&alphaBlendRecord.XformSrc->Dy), 4);
    emfFile.read(reinterpret_cast<char *>(&alphaBlendRecord.BkColorSrc->Red), 4);
    emfFile.read(reinterpret_cast<char *>(&alphaBlendRecord.BkColorSrc->Green), 4);
    emfFile.read(reinterpret_cast<char *>(&alphaBlendRecord.BkColorSrc->Blue), 4);
    emfFile.read(reinterpret_cast<char *>(&alphaBlendRecord.BkColorSrc->Reserved), 4);
    emfFile.read(reinterpret_cast<char *>(&alphaBlendRecord.UsageSrc), 4);
    emfFile.read(reinterpret_cast<char *>(&alphaBlendRecord.offBmiSrc), 4);
    emfFile.read(reinterpret_cast<char *>(&alphaBlendRecord.cbBmsSrc), 4);
    emfFile.read(reinterpret_cast<char *>(&alphaBlendRecord.offBitsSrc), 4);
    emfFile.read(reinterpret_cast<char *>(&alphaBlendRecord.cbBitsSrc), 4);
    emfFile.read(reinterpret_cast<char *>(&alphaBlendRecord.cxSrc), 4);
    emfFile.read(reinterpret_cast<char *>(&alphaBlendRecord.cySrc), 4);

    EmfRecord *retRecord = &alphaBlendRecord;
    return retRecord;
}

EmfRecord *ReadTransparentBltRecord(ifstream &emfFile) {
    EmfTransparentBlt transparentBltRecord;

    emfFile.read(reinterpret_cast<char *>(&transparentBltRecord.Bounds->left), 4);
    emfFile.read(reinterpret_cast<char *>(&transparentBltRecord.Bounds->top), 4);
    emfFile.read(reinterpret_cast<char *>(&transparentBltRecord.Bounds->right), 4);
    emfFile.read(reinterpret_cast<char *>(&transparentBltRecord.Bounds->bottom), 4);
    emfFile.read(reinterpret_cast<char *>(&transparentBltRecord.xDest), 4);
    emfFile.read(reinterpret_cast<char *>(&transparentBltRecord.yDest), 4);
    emfFile.read(reinterpret_cast<char *>(&transparentBltRecord.cxDest), 4);
    emfFile.read(reinterpret_cast<char *>(&transparentBltRecord.cyDest), 4);
    emfFile.read(reinterpret_cast<char *>(&transparentBltRecord.TransparentColorSrc->Red), 4);
    emfFile.read(reinterpret_cast<char *>(&transparentBltRecord.TransparentColorSrc->Green), 4);
    emfFile.read(reinterpret_cast<char *>(&transparentBltRecord.TransparentColorSrc->Blue), 4);
    emfFile.read(reinterpret_cast<char *>(&transparentBltRecord.TransparentColorSrc->Reserved), 4);
    emfFile.read(reinterpret_cast<char *>(&transparentBltRecord.xSrc), 4);
    emfFile.read(reinterpret_cast<char *>(&transparentBltRecord.ySrc), 4);
    emfFile.read(reinterpret_cast<char *>(&transparentBltRecord.XformSrc->M11), 4);
    emfFile.read(reinterpret_cast<char *>(&transparentBltRecord.XformSrc->M12), 4);
    emfFile.read(reinterpret_cast<char *>(&transparentBltRecord.XformSrc->M21), 4);
    emfFile.read(reinterpret_cast<char *>(&transparentBltRecord.XformSrc->M22), 4);
    emfFile.read(reinterpret_cast<char *>(&transparentBltRecord.XformSrc->Dx), 4);
    emfFile.read(reinterpret_cast<char *>(&transparentBltRecord.XformSrc->Dy), 4);
    emfFile.read(reinterpret_cast<char *>(&transparentBltRecord.BkColorSrc->Red), 4);
    emfFile.read(reinterpret_cast<char *>(&transparentBltRecord.BkColorSrc->Green), 4);
    emfFile.read(reinterpret_cast<char *>(&transparentBltRecord.BkColorSrc->Blue), 4);
    emfFile.read(reinterpret_cast<char *>(&transparentBltRecord.BkColorSrc->Reserved), 4);
    emfFile.read(reinterpret_cast<char *>(&transparentBltRecord.UsageSrc), 4);
    emfFile.read(reinterpret_cast<char *>(&transparentBltRecord.offBmiSrc), 4);
    emfFile.read(reinterpret_cast<char *>(&transparentBltRecord.cbBmiSrc), 4);
    emfFile.read(reinterpret_cast<char *>(&transparentBltRecord.offBitsSrc), 4);
    emfFile.read(reinterpret_cast<char *>(&transparentBltRecord.cbBitsSrc), 4);
    emfFile.read(reinterpret_cast<char *>(&transparentBltRecord.cxSrc), 4);
    emfFile.read(reinterpret_cast<char *>(&transparentBltRecord.cySrc), 4);

    EmfRecord *retRecord = &transparentBltRecord;
    return retRecord;
}

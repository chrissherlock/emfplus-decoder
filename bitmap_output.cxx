#include <iostream>
#include <fstream>
#include <cwchar>

#include "emfrecord.hxx"
#include "record_output.hxx"

using namespace std;

std::ostream& operator << (std::ostream &s, EmfRecord &record) {
    s << "Not implemented" << endl;
    return s;
}

std::ostream& operator << (std::ostream &s, EmfBitBltRecord &record) {
    std::ios_base::fmtflags basefield = s.basefield;

    s << "EmfBitBlt record                  " << endl
      << "==================================" << endl
      << "Type:                     " << std::hex << std::showbase << record.type << endl;

    s.setf(basefield);

    s << "\tBounding rect:          " << record.Bounds
      << "\txDest:                  " << record.xDest << endl
      << "\tyDest:                  " << record.yDest << endl
      << "\tcxDest:                 " << record.cxDest << endl
      << "\tcyDest:                 " << record.cyDest << endl
      << "\tBitBltRasterOperation   " << record.BitBltRasterOperation << endl
      << "\txSrc                    " << record.xSrc << endl
      << "\tySrc                    " << record.ySrc << endl
      << "\tXformSrc                " << record.XformSrc << endl
      << "\tBkColorSrc              " << record.BkColorSrc << endl
      << "\tUsageSrc                " << record.UsageSrc << endl
      << "\toffBmiSrc               " << record.offBmiSrc << endl
      << "\tcbBmiSrc                " << record.cbBmiSrc << endl
      << "\toffBitsSrc              " << record.offBitsSrc << endl
      << "\tcbBitsSrc               " << record.cbBitsSrc << endl
      << "\tBmiSrc                  " << record.BmiSrc << endl
      << "\tBitsSrc                 " << record.BitsSrc << endl;
    return s;
}

std::ostream& operator << (std::ostream &s, EmfStretchBltRecord &record) {
    std::ios_base::fmtflags basefield = s.basefield;

    s << "EmfStretchBlt record              " << endl
      << "==================================" << endl
      << "Type:                     " << std::hex << std::showbase << record.type << endl;

    s.setf(basefield);

    s << "\tBounding rect:          " << record.Bounds
      << "\txDest:                  " << record.xDest << endl
      << "\tyDest:                  " << record.yDest << endl
      << "\tcxDest:                 " << record.cxDest << endl
      << "\tcyDest:                 " << record.cyDest << endl
      << "\tBitBltRasterOperation   " << record.BitBltRasterOperation << endl
      << "\txSrc                    " << record.xSrc << endl
      << "\tySrc                    " << record.ySrc << endl
      << "\tXformSrc                " << record.XformSrc << endl
      << "\tBkColorSrc              " << record.BkColorSrc << endl
      << "\tUsageSrc                " << record.UsageSrc << endl
      << "\toffBmiSrc               " << record.offBmiSrc << endl
      << "\tcbBmiSrc                " << record.cbBmiSrc << endl
      << "\toffBitsSrc              " << record.offBitsSrc << endl
      << "\tcbBitsSrc               " << record.cbBitsSrc << endl
      << "\tBmiSrc                  " << record.BmiSrc << endl;
    return s;
}

std::ostream& operator << (std::ostream &s, EmfMaskBltRecord &record) {
    std::ios_base::fmtflags basefield = s.basefield;

    s << "EmfMaskBlt record                 " << endl
      << "==================================" << endl
      << "Type:                     " << std::hex << std::showbase << record.type << endl;

    s.setf(basefield);

    s << "\tBounding rect:          " << record.Bounds
      << "\txDest:                  " << record.xDest << endl
      << "\tyDest:                  " << record.yDest << endl
      << "\tcxDest:                 " << record.cxDest << endl
      << "\tcyDest:                 " << record.cyDest << endl
      << "\tROP4Reserved:           " << record.ROP4Reserved << endl
      << "\tBackgroundROP3:         " << record.BackgroundROP3 << endl
      << "\tForegroundROP3:         " << record.ForegroundROP3 << endl
      << "\txSrc                    " << record.xSrc << endl
      << "\tySrc                    " << record.ySrc << endl
      << "\tXformSrc                " << record.XformSrc << endl
      << "\tBkColorSrc              " << record.BkColorSrc << endl
      << "\tUsageSrc                " << record.UsageSrc << endl
      << "\toffBmiSrc               " << record.offBmiSrc << endl
      << "\tcbBmiSrc                " << record.cbBmiSrc << endl
      << "\txMask                   " << record.xMask << endl
      << "\tyMask                   " << record.yMask << endl
      << "\tUsageMask               " << record.UsageMask << endl
      << "\toffBmiMask              " << record.offBmiMask << endl
      << "\tcbBmiMask               " << record.cbBmiMask << endl
      << "\tBmiSrc                  " << record.BmiSrc << endl
      << "\tBitsSrc                 " << record.BitsSrc << endl
      << "\tBmiSrc                  " << record.BmiMask << endl
      << "\tBitsSrc                 " << record.BitsMask << endl;
    return s;
}


std::ostream& operator << (std::ostream &s, EmfPlgBltRecord &record) {
    std::ios_base::fmtflags basefield = s.basefield;

    s << "EmfPlgBlt record                  " << endl
      << "==================================" << endl
      << "Type:                     " << std::hex << std::showbase << record.type << endl;


    s.setf(basefield);

    s << "\tBounding rect:          " << record.Bounds
      << "\tPoint 1:                " << record.dstPoint1
      << "\tPoint 2:                " << record.dstPoint2
      << "\tPoint 3:                " << record.dstPoint3
      << "\txSrc                    " << record.xSrc << endl
      << "\tySrc                    " << record.ySrc << endl
      << "\tcxSrc                   " << record.cxSrc << endl
      << "\tcySrc                   " << record.cySrc << endl
      << "\tXformSrc                " << endl << record.XformSrc << endl
      << "\tBkColorSrc              " << endl << record.BkColorSrc << endl
      << "\tUsageSrc                " << std::hex << record.UsageSrc << std::dec << endl
      << "\toffBmiSrc               " << record.offBmiSrc << endl
      << "\tcbBmiSrc                " << record.cbBmiSrc << endl
      << "\txMask                   " << record.xMask << endl
      << "\tyMask                   " << record.yMask << endl
      << "\tUsageMask               " << record.UsageMask << endl
      << "\toffBmiMask              " << record.offBmiMask << endl
      << "\tcbBmiMask               " << record.cbBmiMask << endl
      << "\toffBitsSrc              " << record.offBitsSrc << endl
      << "\tcbBitsSrc               " << record.cbBitsSrc << endl;
    return s;
}

std::ostream& operator << (std::ostream &s, EmfSetDIBitsToDeviceRecord &record) {
    std::ios_base::fmtflags basefield = s.basefield;

    s << "EmfSetDIBitsToDevice record       " << endl
      << "==================================" << endl
      << "Type:                     " << std::hex << std::showbase << record.type << endl;


    s.setf(basefield);

    s << "\tBounding rect:          " << record.Bounds
      << "\txDest:                  " << record.xDest << endl
      << "\tyDest:                  " << record.yDest << endl
      << "\txSrc                    " << record.xSrc << endl
      << "\tySrc                    " << record.ySrc << endl
      << "\tcxSrc:                  " << record.cxSrc << endl
      << "\tcySrc:                  " << record.cySrc << endl
      << "\toffBmiSrc               " << record.offBmiSrc << endl
      << "\tcbBmiSrc                " << record.cbBmiSrc << endl
      << "\toffBitsSrc              " << record.offBitsSrc << endl
      << "\tcbBitsSrc               " << record.cbBitsSrc << endl
      << "\tUsageSrc                " << record.UsageSrc << endl
      << "\tiStartScan              " << record.iStartScan << endl
      << "\tcScans                  " << record.cScans << endl;
    return s;
}

std::ostream& operator << (std::ostream &s, EmfAlphaBlendRecord &record) {
    std::ios_base::fmtflags basefield = s.basefield;

    s << "EmfAlphaBlend record              " << endl
      << "==================================" << endl
      << "Type:                     " << std::hex << std::showbase << record.type << endl;


    s.setf(basefield);

    s << "\tBounding rect:          " << record.Bounds
      << "\txDest:                  " << record.xDest << endl
      << "\tyDest:                  " << record.yDest << endl
      << "\tcxDest:                 " << record.cxDest << endl
      << "\tcyDest:                 " << record.cyDest << endl
      << "\tBLENDFUNCTION:          " << endl
      << "\t\tBlendOperation:       " << std::hex << record.BlendOperation << std::dec << endl
      << "\t\tBlendFlags:           " << std::hex << record.BlendFlags << std::dec << endl
      << "\t\tAlphaFormat:          " << (record.AlphaFormat == 0x00 ? "0x00" : "AC_SRC_ALPHA (0x01)") << endl
      << "\txSrc:                   " << record.xSrc << endl
      << "\tySrc:                   " << record.ySrc << endl
      << "\tXFormSrc:               " << endl << record.XformSrc
      << "\tBkColorSrc:             " << endl << record.BkColorSrc
      << "\tUsageSrc:               " << std::hex << record.UsageSrc << std::dec << endl
      << "\toffBmiSrc               " << record.offBmiSrc << endl
      << "\tcbBmiSrc                " << record.cbBmiSrc << endl
      << "\toffBitsSrc              " << record.offBitsSrc << endl
      << "\tcbBitsSrc               " << record.cbBitsSrc << endl
      << "\tcxSrc                   " << record.cxSrc << endl
      << "\tcySrc                   " << record.cySrc << endl;
    return s;
}

std::ostream& operator << (std::ostream &s, EmfTransparentBltRecord &record) {
    std::ios_base::fmtflags basefield = s.basefield;

    s << "EmfTransparentBlt record          " << endl
      << "==================================" << endl
      << "Type:                     " << std::hex << std::showbase << record.type << endl;


    s.setf(basefield);

    s << "\tBounding rect:          " << record.Bounds
      << "\txDest:                  " << record.xDest << endl
      << "\tyDest:                  " << record.yDest << endl
      << "\tcxDest:                 " << record.cxDest << endl
      << "\tcyDest:                 " << record.cyDest << endl
      << "\tTransparentColor:       " << endl << record.TransparentColor
      << "\txSrc:                   " << record.xSrc << endl
      << "\tySrc:                   " << record.ySrc << endl
      << "\tXFormSrc:               " << endl << record.XformSrc
      << "\tBkColorSrc:             " << endl << record.BkColorSrc
      << "\tUsageSrc:               " << std::hex << record.UsageSrc << std::dec << endl
      << "\toffBmiSrc               " << record.offBmiSrc << endl
      << "\tcbBmiSrc                " << record.cbBmiSrc << endl
      << "\toffBitsSrc              " << record.offBitsSrc << endl
      << "\tcbBitsSrc               " << record.cbBitsSrc << endl
      << "\tcxSrc                   " << record.cxSrc << endl
      << "\tcySrc                   " << record.cySrc << endl;
    return s;
}

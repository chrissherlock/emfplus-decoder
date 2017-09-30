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

std::ostream& operator << (std::ostream &s, EmfBitBlt &record) {
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

std::ostream& operator << (std::ostream &s, EmfStretchBlt &record) {
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

std::ostream& operator << (std::ostream &s, EmfMaskBlt &record) {
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
std::ostream& operator << (std::ostream&, EmfStretchBlt&);
std::ostream& operator << (std::ostream&, EmfMaskBlt&);
std::ostream& operator << (std::ostream&, EmfPlgBlt&);
std::ostream& operator << (std::ostream&, EmfSetDIBitsToDevice&);
std::ostream& operator << (std::ostream&, EmfAlphaBlend&);
std::ostream& operator << (std::ostream&, EmfTransparentBlt&);


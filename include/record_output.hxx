#include <fstream>
#include "defs.hxx"
#include "emfbitmap.hxx"
#include "emfstate.hxx"

#ifndef EMFHEADER_OUTPUT
#define EMFHEADER_OUTPUT

std::ostream& operator << (std::ostream&, EmfRecord&);

// Bitmap records
std::ostream& operator << (std::ostream&, EmfBitBltRecord&);
std::ostream& operator << (std::ostream&, EmfStretchBltRecord&);
std::ostream& operator << (std::ostream&, EmfMaskBltRecord&);
std::ostream& operator << (std::ostream&, EmfPlgBltRecord&);
std::ostream& operator << (std::ostream&, EmfSetDIBitsToDeviceRecord&);
std::ostream& operator << (std::ostream&, EmfAlphaBlendRecord&);
std::ostream& operator << (std::ostream&, EmfTransparentBltRecord&);

// State records
std::ostream& operator << (std::ostream&, EmfSetWindowOrgExRecord&);
std::ostream& operator << (std::ostream&, EmfSetViewportExtExRecord&);
std::ostream& operator << (std::ostream&, EmfSetViewportOrgExRecord&);
std::ostream& operator << (std::ostream&, EmfSetBrushOrgExRecord&);
#endif

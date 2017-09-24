#include <fstream>
#include "defs.hxx"
#include "emfbitmap.hxx"

#ifndef EMFHEADER_OUTPUT
#define EMFHEADER_OUTPUT

std::ostream& operator << (std::ostream&, EmfRecord&);
std::ostream& operator << (std::ostream&, EmfBitBlt&);
std::ostream& operator << (std::ostream&, EmfStretchBlt&);
std::ostream& operator << (std::ostream&, EmfMaskBlt&);
//std::ostream& operator << (std::ostream&, EmfPlgBlt&);
//std::ostream& operator << (std::ostream&, EmfSetDIBitsToDevice&);
//std::ostream& operator << (std::ostream&, EmfAlphaBlend&);
//std::ostream& operator << (std::ostream&, EmfTransparentBlt&);

#endif

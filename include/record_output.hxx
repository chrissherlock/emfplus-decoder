#include <fstream>
#include "defs.hxx"
#include "emfbitmap.hxx"
#include "emfstate.hxx"

#ifndef EMFHEADER_OUTPUT
#define EMFHEADER_OUTPUT

std::ostream& operator << (std::ostream&, EmfRecord&);

// Bitmap records
std::ostream& operator << (std::ostream&, EmfBitBlt&);
std::ostream& operator << (std::ostream&, EmfStretchBlt&);
std::ostream& operator << (std::ostream&, EmfMaskBlt&);
//std::ostream& operator << (std::ostream&, EmfPlgBlt&);
//std::ostream& operator << (std::ostream&, EmfSetDIBitsToDevice&);
//std::ostream& operator << (std::ostream&, EmfAlphaBlend&);
//std::ostream& operator << (std::ostream&, EmfTransparentBlt&);

// State records
std::ostream& operator << (std::ostream&, EmfSetWindowOrgExRecord&);
std::ostream& operator << (std::ostream&, EmfSetViewportExtExRecord&);
std::ostream& operator << (std::ostream&, EmfSetViewportOrgExRecord&);
std::ostream& operator << (std::ostream&, EmfSetBrushOrgExRecord&);
#endif

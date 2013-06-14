#include <fstream>
#include "defs.hxx"
#include "header.hxx"

#ifndef EMFHEADER_OUTPUT
#define EMFHEADER_OUTPUT

std::ostream& operator << (std::ostream&, Header&); 
std::ostream& operator << (std::ostream&, EmfMetafileHeader&);
std::ostream& operator << (std::ostream&, EmfMetafileHeaderExt1&);
std::ostream& operator << (std::ostream&, EmfMetafileHeaderExt2&);
std::ostream& operator << (std::ostream&, EmfMetafileHeaderDesc&);
std::ostream& operator << (std::ostream&, PixelFormatDescriptor&);

#endif

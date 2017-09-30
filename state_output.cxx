#include <iostream>
#include <fstream>
#include <cwchar>

#include "emfrecord.hxx"
#include "record_output.hxx"

using namespace std;

std::ostream& operator << (std::ostream &s, EmfSetWindowOrgExRecord &record) {
    std::ios_base::fmtflags basefield = s.basefield;

    s << "EmfSetWindowOrgEx record          " << endl
      << "==================================" << endl
      << "Type:                     " << std::hex << std::showbase << record.type << endl
      << "Size:                     " << std::dec << record.size << endl << endl;

    s.setf(basefield);

    s << "\tOrigin:                 " << record.Origin;
    return s;
}

std::ostream& operator << (std::ostream &s, EmfSetViewpointExtExRecord &record) {
    std::ios_base::fmtflags basefield = s.basefield;

    s << "EmfSetWindowOrgEx record          " << endl
      << "==================================" << endl
      << "Type:                     " << std::hex << std::showbase << record.type << endl
      << "Size:                     " << std::dec << record.size << endl << endl;

    s.setf(basefield);

    s << "\tExtent:                 " << record.Extent;
    return s;
}

std::ostream& operator << (std::ostream &s, EmfSetViewpointOrgExRecord &record) {
    std::ios_base::fmtflags basefield = s.basefield;

    s << "EmfSetWindowOrgEx record          " << endl
      << "==================================" << endl
      << "Type:                     " << std::hex << std::showbase << record.type << endl
      << "Size:                     " << std::dec << record.size << endl << endl;

    s.setf(basefield);

    s << "\tOrigin:                 " << record.Origin;
    return s;
}

std::ostream& operator << (std::ostream &s, EmfSetBrushOrgExRecord &record) {
    std::ios_base::fmtflags basefield = s.basefield;

    s << "EmfSetWindowOrgEx record          " << endl
      << "==================================" << endl
      << "Type:                     " << std::hex << std::showbase << record.type << endl
      << "Size:                     " << std::dec << record.size << endl << endl;

    s.setf(basefield);

    s << "\tOrigin                  " << record.Origin;
    return s;
}


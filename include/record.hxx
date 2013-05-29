#include <vector>
#include <fstream>

#ifndef EMFRECORD
#define EMFRECORD

using namespace std;

struct EmfRecord {
    unsigned int type;
    unsigned int size;
};

typedef vector<EmfRecord> EmfRecords;

EmfRecords ReadRecords(ifstream&, unsigned int);

#endif

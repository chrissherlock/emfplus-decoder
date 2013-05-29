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

int isBitmapRecord(unsigned int);
int isClippingRecord(unsigned int);
int isCommentRecord(unsigned int);
int isControlRecord(unsigned int);
int isDrawingRecord(unsigned int);
int isEscapeRecord(unsigned int);
int isObjectCreationRecord(unsigned int);
int isObjectManipulationRecord(unsigned int);
int isOpenGLRecord(unsigned int);
int isPathBracketRecord(unsigned int);
int isStateRecord(unsigned int);
int isTransformRecord(unsigned int);

#endif

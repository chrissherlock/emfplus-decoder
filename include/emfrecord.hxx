#include <vector>
#include <fstream>

#ifndef EMFRECORD
#define EMFRECORD

struct EmfRecord {
    unsigned int type;
    std::string  typeName;
    unsigned int size;
};

typedef std::vector<EmfRecord*> EmfRecords;

EmfRecords ReadRecords(std::ifstream&, unsigned int);

EmfRecord *ReadBitmapRecord(std::ifstream&, const EmfRecord&);
EmfRecord *ReadClippingRecord(std::ifstream&, const EmfRecord&);

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

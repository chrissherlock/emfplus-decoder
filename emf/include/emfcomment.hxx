#include "emfrecord.hxx"

#ifndef EMFCOMMENTRECORD
#define EMFCOMMENTRECORD

#define EMF_SPOOLFONTDEFINITION         0x544F4E46

struct EmfCommentRecord : EmfRecord {
    int dataSize;
    int commentIdentifier;
};

struct EmrComment : EmfCommentRecord {
    int commentRecordParm;
    char *privateData;
};

struct EmrCommentEMFPlus : EmfCommentRecord {
    EmfPlusRecord *records;
};

struct EmrCommentEMFSpool : EmfCommentRecord {
    int emfSpoolRecordIdentifier;
    EmfSpoolRecord *records;
};

struct  EmrCommentPublic : EmfCommentRecord {
    int publicCommentIdentifier;
    EmfPublicCommentRecord *records;
};

#endif

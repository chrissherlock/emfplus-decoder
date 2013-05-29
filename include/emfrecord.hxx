#include <fstream>
#include "emfplus_record.hxx"
#include "emfspool_record.hxx"
#include "emfpubcomm_record.hxx"

#ifndef EMFCOMMENTRECORD
#define EMFCOMMENTRECORD

#define EMR_COMMENT_EMFSPOOL            0x00000000
#define EMR_COMMENT_EMFPLUS             0x2B464D45
#define EMR_COMMENT_PUBLIC              0x43494447

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

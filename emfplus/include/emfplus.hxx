#include "emfcomment.hxx"

#ifndef EMFPLUS
#define EMFPLUS

struct EmfPlus : EmrCommentEMFPlus {
    EmfPlusHeader           *header;
    vector<EmfPlusRecord *> records;
}


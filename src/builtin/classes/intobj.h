#define INTOBJECT_H

#ifndef INTEGER_H
#include "integer.h"
#endif

typedef struct {
    size_t csize;
    char * type;

    int64_t MAX;
    int64_t MIN;

    int64 *(newFromInt)(int64_t val);
    int64 *(newFromFloat)(float val);
    int64 *(newFromDouble)(double val);
    int64 *(newFromLong)(long val);
    int64 *(newFromChar)(char val);
    int64 *(newFromString)(char *val);
} IntegerObject;

#define __Integer__ \
    (IntegerObject){\
        .csize = sizeof(IntegerObject),\
        .type = "<class 'type'>",\
        .MAX = INT64_MAX,\
        .MIN = INT64_MIN,\
    }


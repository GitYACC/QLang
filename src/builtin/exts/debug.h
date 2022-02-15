#pragma once

#ifndef TYPES_H
#define TYPES_H
#include "types.h"
#endif

#ifndef INTEGER_H
#define INTEGER_H
#include "../classes/integer.h"
#endif

#define debug(object, query) _Generic(object,           \
    IntegerObject *: debugIntegerObject(object, query), \
    IntegerObject: debugIntegerObject(&object, query)   \
) 

#define error(msg) printf("\033[31m"msg"\033[0m")

typedef enum {
    VALUE,
    SIZE,
    CSIZE,
    CTYPE,
    OVERFLOW_VALS,
    OVERFLOW
} IntegerObjectQueries;

void debugIntegerObject(IntegerObject *object, IntegerObjectQueries T);
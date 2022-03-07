#define QX_INTEGER_H

#ifndef HEADERS
#include "../exts/types.h"
#endif

typedef struct {
    int64_t value;
    char *type;
} QX_Int64;

typedef QX_Int64 QInt;
typedef QX_Int64 * QPInt;
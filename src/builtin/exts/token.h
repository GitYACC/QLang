#define __TOKEN_H

#ifndef QX_INTEGER_H
#include "../classes/integer.h"
#endif

typedef struct {
    int type;
    union data {
        QInt I;
    } data;
    int lineno;
    int column;
} Token;

Token * init_Token(int type, int lineno, int column);

#include "builtin/classes/integer.h"
#include "builtin/exts/debug.h"
#include "../lex.yy.c"


int main() {
    /*
    int txt;
    while((txt = yylex())) {
        printf("%d", txt);
    }
    */

    IntegerObject *new = VA_Integer_FromInt(INT64_MAX, INT64_MAX, INT64_MAX, INT64_MAX);
    debug(new, OVERFLOW_VALS);
}
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

    IntegerObject *new = VA_Integer_FromInt(1, 2, 3, 4, 5, 6, 7);
    debug(new, OVERFLOW_VALS);
}
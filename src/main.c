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

    IntegerObject *new = VA_Integer_FromInt(123, 12354, 132, 43545657875432, 2143536);
    debug(new, OVERFLOW_VALS);
}
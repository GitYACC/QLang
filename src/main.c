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
    char *s = BUILD_FORMAT_STRING(1, 2, 3);
    printf("%s\n", s);
    printf("%d\n", NUMARGS());
}
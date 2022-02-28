#include "builtin/classes/integer.h"
#include "builtin/exts/debug.h"
#include "../lex.yy.c"



int main() {
    int txt;
    while((txt = yylex())) {
        printf("%d", txt);
    }
}
#include "../lex.yy.c"

#ifndef INTEGER_H
#include "builtin/classes/integer.h"
#endif



int main() {
    int txt, idx = 0;
    while((txt = yylex())) {
        
    }
}
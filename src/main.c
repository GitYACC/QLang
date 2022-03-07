#include "../lex.yy.c"

#ifndef QX_INTEGER_H
#include "builtin/classes/integer.h"
#endif

#ifndef __TOKEN_H
#include "builtin/exts/token.h"
#endif


int main() {
    int txt, idx = 0;
    Token tokens[1000];

    while((txt = yylex())) {
        switch(txt) {
            case(1):
                tokens[idx] = *init_Token(1, yylineno, 0);
                tokens[idx].data = (union data){
                    .I = (QInt){
                        .value = atoi(yytext), 
                        .type = "int64"
                    }
                };
                break;
        }
        idx++;
    }

    Token any = tokens[1];
    printf("Token(%d, %d, %d, %d) %s", any.type, any.data.I.value, any.lineno, any.column, any.data.I.type);
}
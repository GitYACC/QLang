#include "../lex.yy.c"



int main() {
    int txt;
    while((txt = yylex())) {
        printf("%d\n", txt);
    }
}
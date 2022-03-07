%{
    #include "src/builtin/exts/defines.h"
%}

FILE *yyin;

%%
[a-zA-Z_][a-zA-Z0-9_]*  return Identifier;
[0-9]+                  return Integer;
[0-9]+\.[0-9]+          return Float;
["].*?["]               return String;
"("                     return LParen;
")"                     return RParen;
" "+                    printf("\033[0;2m%s\033[0m", Whitespace);
","                     return Comma;
%%


int yywrap(void) {
    return 1;
}
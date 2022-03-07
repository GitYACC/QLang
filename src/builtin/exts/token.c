#include "token.h"

Token * init_Token(int type, int lineno, int column) {
    Token *new = malloc(sizeof(Token));
    new->type = type;
    new->lineno = lineno;
    new->column = column;
    return new;
}
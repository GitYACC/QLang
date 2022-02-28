#ifndef EXTENSIONS_H
#define EXTENSIONS_H
#include "extensions.h"
#endif

#ifndef DEBUG_H
#define DEBUG_H
#include "debug.h"
#endif

string itostr(const int64_t num) {
    string val;
    asprintf(&val, "%lli", num);
    return val;
}

string ftostr(const float num) {
    string val;
    asprintf(&val, "%f", num);
    return val;
}

#pragma once
#ifndef TYPES_H
#define TYPES_H
#include "types.h"
#endif

#ifndef EASYREAD_H
#define EASYREAD_H
#include "easyread.h"
#endif

#define nnull_realloc(void_ptr, size)                    \
    typeof(void_ptr) temp = realloc(void_ptr, size);     \
    if(temp == NULL)                                     \
        void_ptr = realloc(void_ptr, size);              \
    else                                                 \
        void_ptr = temp;                                 \
    free(temp);
    

string itostr(const int64_t num);
string ftostr(const float num);
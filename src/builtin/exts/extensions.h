#pragma once
#ifndef TYPES_H
#define TYPES_H
#include "types.h"
#endif

#ifndef EASYREAD_H
#define EASYREAD_H
#include "easyread.h"
#endif


#if __STDC_VERSION__ >= 199901L
#    define VA_N(...) (sizeof((int[]){__VA_ARGS__})/sizeof(int))
#else
#    define VA_N(...) (sizeof((int[]){0, ## __VA_ARGS__})/sizeof(int)-1)
#endif
    

string itostr(const int64_t num);
string ftostr(const float num);
#pragma once

#ifndef EXTENSIONS_H
#define EXTENSIONS_H
#include "../exts/extensions.h"
#endif

#define VA_Integer_FromInt(...) _VA_Integer_FromInt(VA_LENGTH(__VA_ARGS__), __VA_ARGS__)

typedef struct IntegerObject {
    // Q visible attrs
    string value;
    //string _in_file;
    //int line;
    //int column;
    Q_size_t size;

    // Q conditional visibility (module requirment: inspect)
    size_t csize;
    string ctype;

    // Q invisible attrs
    list(string) overflow_vals;
    //list(string) lifetime;
    int overflow;

    // object (IntegerObject) static attrs
    string MAX;
    string MIN;

} IntegerObject;

IntegerObject * init_IntegerObject();
IntegerObject * Integer_FromFloat(const float object);
IntegerObject * Integer_FromInt(const int64_t object);
IntegerObject * _VA_Integer_FromInt(const int amt, ...);
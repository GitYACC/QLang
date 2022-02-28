#pragma once

#ifndef EXTENSIONS_H
#define EXTENSIONS_H
#include "../exts/extensions.h"
#endif

#define VA_Integer_FromInt(...) _VA_Integer_FromInt(VA_N(__VA_ARGS__), __VA_ARGS__)
#define VA_Integer_FromFloat(...) _VA_Integer_FromFloat(VA_N(__VA_ARGS__), __VA_ARGS__)
#define VA_Integer_FromDouble(...) _VA_Integer_FromDouble(VA_N(__VA_ARGS__), __VA_ARGS__)
#define VA_Integer_FromLong(...) _VA_Integer_FromLong(VA_N(__VA_ARGS__), __VA_ARGS__)
#define VA_Integer_FromLongLong(...) _VA_Integer_FromLongLong(VA_N(__VA_ARGS__), __VA_ARGS__)

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
IntegerObject * Integer_FromDouble(const double object);
IntegerObject * Integer_FromLongLong(const long long object);
IntegerObject * Integer_FromLong(const long object);
IntegerObject * _VA_Integer_FromInt(const int amt, ...);
IntegerObject * _VA_Integer_FromFloat(const int amt, ...);
IntegerObject * _VA_Integer_FromDouble(const int amt, ...);
IntegerObject * _VA_Integer_FromLong(const int amt, ...);
IntegerObject * _VA_Integer_FromLongLong(const int amt, ...);
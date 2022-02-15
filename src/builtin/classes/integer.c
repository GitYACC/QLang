#ifndef INTEGER_H
#define INTEGER_H
#include "integer.h"
#endif

#ifndef DEBUG_H
#define DEBUG_H
#include "../exts/debug.h"
#endif

static void basic_c_init_IntegerObject(IntegerObject *object) {
    object->csize = sizeof(int64_t);
    object->size = sizeof(IntegerObject);
    object->ctype = "int64_t";
    object->MAX = itostr(INT64_MAX);
    object->MIN = itostr(INT64_MIN);
}

IntegerObject * init_IntegerObject() {
    IntegerObject *temp = malloc(sizeof(IntegerObject));
    temp->overflow_vals = malloc(sizeof(string));
    return temp;
}

IntegerObject * Integer_FromDouble(const double object) {
    IntegerObject *new = init_IntegerObject();
    string val = itostr((int)object);
    basic_c_init_IntegerObject(new);
    new->value = val;
    return new;
}

IntegerObject * Integer_FromLongLong(const long long object) {
    return Integer_FromDouble((double)object);
}

IntegerObject * Integer_FromLong(const long object) {
    return Integer_FromDouble((double)object);
}


IntegerObject * Integer_FromFloat(const float object) {
    return Integer_FromDouble((double)object);
}

IntegerObject * Integer_FromInt(const int64_t object) {
    IntegerObject *new = init_IntegerObject();
    string val = itostr(object);
    basic_c_init_IntegerObject(new);
    new->value = val;
    return new;
}

//– ≠ « » ‹ › — ± ≤ ≥ ÷

IntegerObject * _VA_Integer_FromInt(const int amt, ...) {
    va_list args;
    va_start(args, amt);

    __int128_t total = 0;

    IntegerObject *new = init_IntegerObject();
    basic_c_init_IntegerObject(new);
    for(int i = 0; i < amt; i++) {
        __int128_t temp = va_arg(args, int64_t);
        if(total <= INT64_MAX && total + temp <= INT64_MAX)
            total += temp;
        else {
            new->overflow++;
            list(string) temp = realloc(new->overflow_vals, sizeof(string) * (new->overflow + 1));
            if(temp != NULL)
                new->overflow_vals = temp;
            new->overflow_vals[new->overflow - 1] = itostr(total);
            total = temp;
        }
    }

    if(total) {
        new->overflow++;
        list(string) temp = realloc(new->overflow_vals, sizeof(string) * (new->overflow + 1));
        if(temp != NULL)
            new->overflow_vals = temp;
        new->overflow_vals[new->overflow - 1] = itostr(total);
    }

    va_end(args);
    return new;
}

IntegerObject * _VA_Integer_FromFloat(const int amt, ...) {
    va_list args;
    va_start(args, amt);

    float total = 0;

    IntegerObject *new = init_IntegerObject();
    basic_c_init_IntegerObject(new);
    for(int i = 0; i < amt; i++) {
        float temp = va_arg(args, float);
        if(total <= INT64_MAX && total + temp <= INT64_MAX)
            total += (int)temp;
        else {
            new->overflow++;
            list(string) temp = realloc(new->overflow_vals, sizeof(string) * (new->overflow + 1));
            if(temp != NULL)
                new->overflow_vals = temp;
            new->overflow_vals[new->overflow - 1] = itostr(total);
        }

        va_end(args);
        return new;
    }
}

IntegerObject * _VA_Integer_FromDouble(const int amt, ...) {
    va_list args;
    va_start(args, amt);

    double total = 0;

    IntegerObject *new = init_IntegerObject();
    basic_c_init_IntegerObject(new);
    for(int i = 0; i < amt; i++) {
        double temp = va_arg(args, double);
        if(total <= INT64_MAX && total + temp <= INT64_MAX)
            total += (int)temp;
        else {
            new->overflow++;
            list(string) temp = realloc(new->overflow_vals, sizeof(string) * (new->overflow + 1));
            if(temp != NULL)
                new->overflow_vals = temp;
            new->overflow_vals[new->overflow - 1] = itostr(total);
        }

        va_end(args);
        return new;
    }
}

IntegerObject * _VA_Integer_FromLong(const int amt, ...) {
    va_list args;
    va_start(args, amt);

    long total = 0;

    IntegerObject *new = init_IntegerObject();
    basic_c_init_IntegerObject(new);
    for(int i = 0; i < amt; i++) {
        long temp = va_arg(args, long);
        if(total <= INT64_MAX && total + temp <= INT64_MAX)
            total += (int)temp;
        else {
            new->overflow++;
            list(string) temp = realloc(new->overflow_vals, sizeof(string) * (new->overflow + 1));
            if(temp != NULL)
                new->overflow_vals = temp;
            new->overflow_vals[new->overflow - 1] = itostr(total);
        }

        va_end(args);
        return new;
    }
}

IntegerObject * _VA_Integer_FromLongLong(const int amt, ...) {
    va_list args;
    va_start(args, amt);

    long long total = 0;

    IntegerObject *new = init_IntegerObject();
    basic_c_init_IntegerObject(new);
    for(int i = 0; i < amt; i++) {
        long long temp = va_arg(args, long long);
        if(total <= INT64_MAX && total + temp <= INT64_MAX)
            total += (int)temp;
        else {
            new->overflow++;
            list(string) temp = realloc(new->overflow_vals, sizeof(string) * (new->overflow + 1));
            if(temp != NULL)
                new->overflow_vals = temp;
            new->overflow_vals[new->overflow - 1] = itostr(total);
        }

        va_end(args);
        return new;
    }
}
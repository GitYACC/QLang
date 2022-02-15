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

IntegerObject * Integer_FromFloat(const float object) {
    IntegerObject *new = init_IntegerObject();
    string val = ftostr(object);
    basic_c_init_IntegerObject(new);
    new->value = val;
    return new;
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
            nnull_realloc(new->overflow_vals, sizeof(string) * (new->overflow + 1));
            new->overflow_vals[new->overflow - 1] = itostr(total);
            total = temp;
        }
    }

    if(total) {
        new->overflow++;
        nnull_realloc(new->overflow_vals, sizeof(string) * (new->overflow + 1));
        new->overflow_vals[new->overflow - 1] = itostr(total);
    }

    va_end(args);
    return new;
}
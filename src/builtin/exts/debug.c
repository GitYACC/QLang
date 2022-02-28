#ifndef DEBUG_H
#define DEBUG_H
#include "debug.h"
#endif


void debugIntegerObject(IntegerObject *object, IntegerObjectQueries T) {
    switch(T) {
        case VALUE:
            printf("%s\n", object->value);
            break;
        case SIZE:
            printf("%lld\n", object->size);
            break;
        case CSIZE:
            printf("%zu\n", object->csize);
            break;
        case OVERFLOW_VALS:
            printf("[");
            for(int i = 0; i < object->overflow; i++) {
                printf("%s ", object->overflow_vals[i]);
            }
            printf("\b]\n");
            break;
        case OVERFLOW:
            printf("%d\n", object->overflow);
            break;
        default:
            error("(debugIntegerObject) invalid query type\n");
            exit(1);
            break;
    }
}

int ctoi(const char num) {
    return (int)num - 48;
}

char itoc(const int num) {
    if(num > 9) {
        error("invalid integer target for itoc");
        exit(1);
    }

    return (char)(num + 48);
}
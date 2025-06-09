#include <stdio.h>
#include <stdlib.h>
#include "Float.h"
#include "RingInfo.h"

void *sumFloat(void *x, void *y) {
    float ix = ((Float *) x)->real;
    float iy = ((Float *) y)->real;
    float res = ix + iy;
    return collectFloat(res);
}

void *minusFloat(void *x) {
    float ix = ((Float *) x)->real;
    float res = ix * (-1);
    return collectFloat(res);
}

void *multiFloat(void *x, void *y) {
    float ix = ((Float *) x)->real;
    float iy = ((Float *) y)->real;
    float res = ix * iy;
    return collectFloat(res);
}

void printFloat(void *integer) {
    float value = ((Float *) integer)->real;
    printf("%7.3f", value);
}

void *randomFloat() {
    return (void *) collectFloat((rand() % 4299) / 43.0 + 1);
}

void *zeroFloat() {
    return (void *) collectFloat(0);
}

void *oneFloat() {
    return (void *) collectFloat(1);
}

void *getFloat(float value) {
    return collectFloat(value);
}

void *collectFloat(float value) {
    Float *real = (Float *) malloc(sizeof(Float));
    real->ringInfo = Create(&sumFloat,
                            &zeroFloat,
                            &minusFloat,
                            &multiFloat,
                            &printFloat,
                            &randomFloat,
                            getFloat,
                            &oneFloat);
    real->real = value;
    return real;
}
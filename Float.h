#ifndef FLOAT_H
#define FLOAT_H

#include "RingInfo.h"

typedef struct Float {
    RingInfo *ringInfo;
    float real;
} Float;


void *sumFloat(void *x, void *y);

void *minusFloat(void *x);

void *multiFloat(void *x, void *y);

void printFloat(void *integer);

void *randomFloat();

void *zeroFloat();

void *oneFloat();

void *collectFloat(float value);

void *getFloat(float value);

#endif
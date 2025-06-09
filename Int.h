#ifndef INT_H
#define INT_H

#include "RingInfo.h"

typedef struct Int {
    RingInfo *ringInfo;
    int integer;
} Int;

void *sumInt(void *x, void *y);

void *minusInt(void *x);

void *multiInt(void *x, void *y);

void printInt(void *integer);

void *zeroInt();

void *oneInt();

void *collectInt(int value);

void *getInt(int value);

#endif

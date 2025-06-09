#include <stdio.h>
#include <stdlib.h>
#include "Int.h"
#include "RingInfo.h"

void *sumInt(void *x, void *y) {
    int ix = ((Int *) x)->integer;
    int iy = ((Int *) y)->integer;
    int res = ix + iy;
    return collectInt(res);
}

void *minusInt(void *x) {
    int ix = ((Int *) x)->integer;
    int res = ix * (-1);
    return collectInt(res);
}

void *multiInt(void *x, void *y) {
    int ix = ((Int *) x)->integer;
    int iy = ((Int *) y)->integer;
    int res = ix * iy;
    return collectInt(res);
}

void *randomInt() {
    return (void *) collectInt(rand() % 99 + 1);
}

void printInt(void *integer) {
    int value = ((Int *) integer)->integer;
    printf("%5d", value);
}

void *zeroInt() {
    return (void *) collectInt(0);
}

void *oneInt() {
    return (void *) collectInt(1);
}

void *getInt(int value) {
    return collectInt(value);
}

void *collectInt(int value) {
    Int *integer = (Int *) malloc(sizeof(Int));
    integer->ringInfo = Create(&sumInt,
                               &zeroInt,
                               &minusInt,
                               &multiInt,
                               &printInt,
                               &randomInt,
                               &getInt,
                               &oneInt);
    integer->integer = value;
    return integer;
}
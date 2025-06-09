#ifndef RINGINFO_H
#define RINGINFO_H

#include <stddef.h>
#include <stdlib.h>

typedef struct RingInfo {
    void *(*sum)(void *, void *);

    void *(*zero)();

    void *(*minus)(void *);

    void *(*multi)(void *, void *);

    void (*printValue)(void *);

    void *(*randomValue)();

    void *(*getType)();

    void *(*one)();
} RingInfo;



RingInfo *Create(void *(*sum)(void *, void *),
                 void *(*zero)(),
                 void *(*minus)(void *),
                 void *(*multi)(void *, void *),
                 void (*printValue)(void *),
                 void *(*randomValue)(),
                 void *(*getType)(void),
                 void *(*one)());

#endif

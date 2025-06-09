#include "RingInfo.h"

RingInfo *Create(void *(*sum)(void *, void *),
                 void *(*zero)(),
                 void *(*minus)(void *),
                 void *(*multi)(void *, void *),
                 void (*printValue)(void *),
                 void *(*randomValue)(),
                 void *(*getType)(void),
                 void *(*one)()) {
    RingInfo *ringInfo = (RingInfo *) malloc(sizeof(RingInfo));
    ringInfo->sum = sum;
    ringInfo->zero = zero;
    ringInfo->minus = minus;
    ringInfo->multi = multi;
    ringInfo->printValue = printValue;
    ringInfo->randomValue = randomValue;
    ringInfo->getType = getType;
    ringInfo->one = one;
    return ringInfo;
}
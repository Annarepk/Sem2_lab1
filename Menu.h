#ifndef MENU_H
#define MENU_H

#include <stdio.h>
#include "RingInfo.h"

void selectType() {
    printf("Select the type of values:\n"
           "1. integer\n"
           "2. real\n"
           ">");
}

void selectAction() {
    printf("What do you want to do?\n"
           "1. Random unit matrix\n"
           "2. Get line\n"
           "3. Get column\n"
           "4. Sum matrices\n"
           "5. Multiply matrices\n"
           "6. Multiply the matrix by a scalar\n"
           "7. Add a linear combination of another string to a string\n"
           ">");
}

#endif

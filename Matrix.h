#ifndef MATRIX_H
#define MATRIX_H

#include "RingInfo.h"

typedef struct Element {
    RingInfo *ringInfo;
    void *value;
} Element;


typedef struct Matrix {
    Element **data;
    int size;
} Matrix;


//1. Creat

Matrix *randomMatrix(RingInfo *ringInfo, int size);

Matrix *E(RingInfo *ringInfo, int size);

Element *collectElement(RingInfo *ringInfo, void *value);

//2. Decomposition

Element **getLine(int lineNumber, Matrix *matrix);

Element **getColumn(int columnNumber, Matrix *matrix);

//3. Operations

Matrix *sumMatrix(Matrix *matrix1, Matrix *matrix2);

Matrix *multiMatrix(Matrix *matrix1, Matrix *matrix2);

Matrix *multiScalar(Matrix *matrix, void *multiplier);

Matrix *sumLine(Matrix *matrix, int line1, int line2, void *multiplier);  // completed

void printMatrix(Matrix *matrix);

void printLine(Element **line, int size);

void printColumn(Element **column, int size);

#endif

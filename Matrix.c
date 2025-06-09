#include "Matrix.h"
#include <stdio.h>


//1. Creat

Matrix *randomMatrix(RingInfo *ringInfo, int size) {
    Matrix *matrix = (Matrix *) malloc(sizeof(Matrix));
    Element **data = (Element **) malloc(size * size * sizeof(Element *));
    matrix->size = size;
    matrix->data = data;
    for (int i = 0; i < size * size; i++) {
        data[i] = collectElement(ringInfo, ringInfo->randomValue());
    }
    return matrix;
}

Matrix *E(RingInfo *ringInfo, int size) {
    Matrix *matrix = (Matrix *) malloc(sizeof(Matrix));
    matrix->size = size;
    Element **data = (Element **) malloc(size * size * sizeof(Element *));
    int checker = 0;
    for (int i = 0; i < size * size; i++) {
        if (i % size == checker) {
            data[i] = collectElement(ringInfo, ringInfo->one());
        }
        else {
            data[i] = collectElement(ringInfo, ringInfo->zero());
        }
        if ((i + 1) % size == 0) checker++;

    }
    matrix->data = data;
    return matrix;
}

Element *collectElement(RingInfo *ringInfo, void *value) {
    Element *elem = (Element *) malloc(sizeof(Element));
    elem->ringInfo = ringInfo;
    elem->value = value;
    return elem;
}

//2. Decomposition

Element **getLine(int lineNumber, Matrix *matrix) {
    if (!matrix || lineNumber > matrix->size) {
        printf("Error (false number or matrix not exist)\n");
        return NULL;
    }
    int len = matrix->size;
    Element **line = (Element **) malloc(len * sizeof(Element *));
    for (int i = len * (lineNumber - 1); i < len * lineNumber; i++) {
        line[i - len * (lineNumber - 1)] = matrix->data[i];
    }
    return line;
}

Element **getColumn(int columnNumber, Matrix *matrix) {
    if (!matrix || columnNumber > matrix->size) {
        printf("Error (false number or matrix not exist)\n");
        return NULL;
    }
    int counter = 0, len = matrix->size;
    Element **column = (Element **) malloc(len * sizeof(Element *));
    for (int i = columnNumber - 1; i < len * len; i += len) {
        column[counter] = matrix->data[i];
        counter++;
    }
    return column;
}

//3. Operations

Matrix *sumMatrix(Matrix *matrix1, Matrix *matrix2) {
    if (!matrix1 || !matrix2 || matrix1->size != matrix2->size) {
        printf("Error\n");
        return NULL;
    }
    Element **data1 = matrix1->data;
    Element **data2 = matrix2->data;
    RingInfo *ringInfo = data1[0]->ringInfo;
    int len = matrix1->size;
    Element **result = (Element **) malloc(len * len * sizeof(Element *));
    for (int i = 0; i < len * len; i++) {
        result[i] = collectElement(ringInfo, ringInfo->sum(data1[i]->value, data2[i]->value));
    }
    matrix1->data = result;
    return matrix1;
}

Matrix *multiMatrix(Matrix *matrix1, Matrix *matrix2) {
    if (!matrix1 || !matrix2 || matrix1->size != matrix2->size) {
        printf("Error\n");
        return NULL;
    }
    int len = matrix1->size;
    RingInfo *ringInfo = matrix1->data[0]->ringInfo;
    Element *tmp;
    Element **result = (Element **) malloc(len * len * sizeof(Element *));
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            tmp = collectElement(ringInfo, ringInfo->zero());
            for (int k = 0; k < len; k++) {
                tmp = collectElement(ringInfo, ringInfo->sum(tmp->value,
                                    ringInfo->multi(getLine(i + 1, matrix1)[k]->value,
                                                    getColumn(j + 1, matrix2)[k]->value)));
            }
            result[i * len + j] = tmp;
        }
    }
    matrix1->data = result;
    return matrix1;
}

Matrix *multiScalar(Matrix *matrix, void *multiplier) {
    if (!matrix) {
        printf("Error\n");
        return NULL;
    }
    int len = matrix->size;
    RingInfo *ringInfo = matrix->data[0]->ringInfo;
    Element *alpha = collectElement(ringInfo, multiplier);
    Element **values = matrix->data;
    Element **result = malloc(len * len * sizeof(Element *));
    for (int i = 0; i < len * len; i++) {
        result[i] = collectElement(ringInfo, ringInfo->multi(values[i]->value, alpha));
    }
    matrix->data = result;
    return matrix;
}

Matrix *sumLine(Matrix *matrix, int line1, int line2, void *multiplier) {
    if (!matrix || line1 > matrix->size || line2 > matrix->size) {
        printf("Error");
        return NULL;
    }
    int len = matrix->size;
    RingInfo *ringInfo = matrix->data[0]->ringInfo;
    Element *alpha = collectElement(ringInfo, multiplier);
    Element **value = matrix->data;
    Element **result = malloc(len * len * sizeof(Element *));
    for (int i = 0; i < len * len; i++) {
        if (i < len * (line1 - 1) || i >= len * (line1)) {
            result[i] = value[i];
        }
        else {
            result[i] = collectElement(ringInfo, ringInfo->sum(getLine(line1 + 1, matrix)[i - len * (line1 - 1)]->value,
                                      ringInfo->multi(getLine(line2 + 1, matrix)[i - len * (line2 - 1)]->value,
                                                      alpha->value)));
        }
    }
    matrix->data = result;
    return matrix;
}

void printMatrix(Matrix *matrix) {
    int n = matrix->size;
    for (int i = 0; i < n * n; i++) {
        Element *elem = matrix->data[i];
        elem->ringInfo->printValue(elem->value);
        if ((i + 1) % n == 0) printf("\n");
        else printf(" ");
    }
}

void printLine(Element **line, int size) {
    for (int i = 0; i < size; i++) {
        Element *elem = line[i];
        elem->ringInfo->printValue(elem->value);
        printf(" ");
    }
    printf("\n");
}

void printColumn(Element **column, int size) {
    for (int i = 0; i < size; i++) {
        Element *elem = column[i];
        elem->ringInfo->printValue(elem->value);
        printf("\n");
    }
    printf("\n");
}
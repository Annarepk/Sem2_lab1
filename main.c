#include <stdio.h>
#include "Int.h"
#include "Float.h"
#include "Menu.h"
#include "Matrix.h"


int main() {
    int rubbish = 0, smallerRubbish = 0, smallestRubbish = 0, menuChoice = 0, randomSize = rand() % 5 + 2;
    Int *matrix;

    selectType();
    scanf("%d", &menuChoice);
    switch (menuChoice) {
        case 1:
            matrix = collectInt(2);
            break;
        case 2:
            matrix = (Float *) matrix;
            matrix = collectFloat(2.34);
            break;
        default:
            matrix = collectInt(2);
            break;
    }
    selectAction();
    scanf("%d", &menuChoice);
    Matrix *matrix1, *matrix2;
    switch (menuChoice) {
        case 1:
            printf("Unit matrix:\n");
            matrix1 = E(matrix->ringInfo, randomSize);
            printMatrix(matrix1);
            break;
        case 2:
            printf("Matrix:\n");
            matrix1 = randomMatrix(matrix->ringInfo, randomSize);
            printMatrix(matrix1);
            printf("Select the line number\n"
                   ">");
            scanf("%d", &rubbish);
            Element **line = getLine(rubbish, matrix1);
            printf("line:");
            printLine(line, randomSize);
            break;
        case 3:
            printf("Matrix:\n");
            matrix1 = randomMatrix(matrix->ringInfo, randomSize);
            printMatrix(matrix1);
            printf("Select the column number\n"
                   ">");
            scanf("%d", &rubbish);
            Element **column = getColumn(rubbish, matrix1);
            printf("Column:\n");
            printColumn(column, randomSize);
            break;
        case 4:
            matrix1 = randomMatrix(matrix->ringInfo, randomSize);
            matrix2 = randomMatrix(matrix->ringInfo, randomSize);
            printf("First matrix:\n");
            printMatrix(matrix1);
            printf("\n");
            printf("Second matrix:\n");
            printMatrix(matrix2);
            matrix1 = sumMatrix(matrix1, matrix2);
            printf("Result:\n");
            printMatrix(matrix1);
            break;
        case 5:
            matrix1 = randomMatrix(matrix->ringInfo, randomSize);
            matrix2 = randomMatrix(matrix->ringInfo, randomSize);
            printf("First matrix:\n");
            printMatrix(matrix1);
            printf("\n");
            printf("Second matrix:\n");
            printMatrix(matrix2);
            printf("\n");
            matrix1 = multiMatrix(matrix1, matrix2);
            printf("Result:\n");
            printMatrix(matrix1);
            break;
        case 6:
            matrix1 = randomMatrix(matrix->ringInfo, randomSize);
            printf("Matrix:\n");
            printMatrix(matrix1);
            printf("Enter the number by which you want to multiply the matrix\n"
                   ">");
            scanf("%d", &rubbish);
            matrix1 = multiScalar(matrix1, collectElement(matrix->ringInfo, rubbish)->value);
            printf("Result:\n");
            printMatrix(matrix1);
            break;
        case 7:
            matrix1 = randomMatrix(matrix->ringInfo, randomSize);
            printf("Matrix:\n");
            printMatrix(matrix1);
            printf("Enter the line numbers to make a linear combination:\n"
                   ">");
            scanf("%d%d", &rubbish, &smallerRubbish);
            printf("Enter the number by which you want to multiply the second line\n"
                   ">");
            scanf("%d", &smallestRubbish);
            matrix1 = sumLine(matrix1, rubbish, smallerRubbish, smallestRubbish);
            printf("Result:\n");
            printMatrix(matrix1);
            break;
        default:
            break;
    }
    return 0;

}
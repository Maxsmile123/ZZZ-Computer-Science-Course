#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef int32_t** Matrix;

Matrix MatrixCreate(int32_t lines, int32_t columns) {
    Matrix matrix = (int32_t**)malloc(lines * sizeof(int32_t*));
    for (int i = 0; i < lines; ++i) {
        matrix[i] = (int32_t*)malloc(columns * sizeof(int32_t));
    }
    return matrix;
}

Matrix MatrixFill(Matrix matrix) {
    matrix[0][0] = 1;
    matrix[0][1] = 2;
    matrix[0][2] = 9;
    matrix[0][3] = 10;
    matrix[1][0] = 4;
    matrix[1][1] = 3;
    matrix[1][2] = 8;
    matrix[1][3] = 11;
    matrix[2][0] = 5;
    matrix[2][1] = 6;
    matrix[2][2] = 7;
    matrix[2][3] = 12;
    matrix[3][0] = 16;
    matrix[3][1] = 15;
    matrix[3][2] = 14;
    matrix[3][3] = 13;
    return matrix;
}

int32_t* MatrixLin(Matrix matrix, int32_t lines, int32_t* arr) {
    int8_t invert = -1;
    int32_t matrix_order = 1;
    int32_t index_for_answer = 0;
    for (int32_t i = 0; i < lines; ++i) {
        if (invert > 0) {
            for (int32_t j = 0; j < matrix_order; ++j) {
                arr[index_for_answer] = matrix[j][matrix_order - 1];
                index_for_answer += 1;
            }
            for (int32_t j = matrix_order - 2; j >= 0; --j) {
                arr[index_for_answer] = matrix[matrix_order - 1][j];
                index_for_answer += 1;
            }
        } else if (invert < 0) {
            for (int32_t j = 0; j < matrix_order; ++j) {
                arr[index_for_answer] = matrix[matrix_order - 1][j];
                index_for_answer += 1;
            }
            for (int32_t j = matrix_order - 2; j >= 0; --j) {
                arr[index_for_answer] = matrix[j][matrix_order - 1];
                index_for_answer += 1;
            }
        }
        invert *= -1;
        matrix_order += 1;
    }
    return arr;
}

void MatrixPrint(Matrix matrix, int32_t* arr, int32_t lines, int32_t columns) {
    printf("Исходная матрица:\n");
    for (int32_t i = 0; i < lines; ++i) {
        for (int32_t j = 0; j < columns; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("Линеризованная матрица:\n");
    for (int32_t i = 0; i < lines * columns; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void MatrixFree(Matrix matrix, int32_t lines) {
    for (int32_t i = 0; i < lines; ++i) {
        free(matrix[i]);
    }
    free(matrix);
}

int Task() {
    int32_t lines = 4;
    int32_t columns = 4;
    int32_t* arr = (int32_t*)malloc(lines * columns * sizeof(int32_t));

    Matrix matrix = MatrixCreate(lines, columns);
    matrix = MatrixFill(matrix);
    arr = MatrixLin(matrix, lines, arr);

    MatrixPrint(matrix, arr, lines, columns);
    MatrixFree(matrix, lines);
    free(arr);

    return 0;
}

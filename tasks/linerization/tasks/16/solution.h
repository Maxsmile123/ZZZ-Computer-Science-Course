#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef int32_t** Matrix;

Matrix CreateMatrix(int rows, int cols) {
    Matrix matrix = (Matrix)malloc(rows * sizeof(int32_t*));
    for (int i = 0; i < rows; ++i) {
        matrix[i] = (int32_t*)malloc(cols * sizeof(int32_t));
    }

    return matrix;
}

void InitializeMatrix(Matrix matrix) {
    matrix[0][0] = 4;
    matrix[0][1] = 5;
    matrix[0][2] = 11;
    matrix[0][3] = 15;
    matrix[1][0] = 10;
    matrix[1][1] = 3;
    matrix[1][2] = 6;
    matrix[1][3] = 12;
    matrix[2][0] = 14;
    matrix[2][1] = 9;
    matrix[2][2] = 2;
    matrix[2][3] = 7;
    matrix[3][0] = 16;
    matrix[3][1] = 13;
    matrix[3][2] = 8;
    matrix[3][3] = 1;
}

int32_t* LinearizeMatrix(int32_t** matrix, int rows, int cols) {
    int32_t* linear_array = (int32_t*)malloc(rows * cols * sizeof(int32_t));
    int top = 1;
    int bottom = cols - 1;
    int linear_index = 0;
    int operation_number = 1;
    while (true) {
        if (operation_number == 1) {
            for (int i = bottom; i >= 0; --i) {
                linear_array[linear_index] = matrix[(cols - 1) - (bottom - i)][i];
                linear_index += 1;
            }
            bottom -= 1;
            operation_number = 2;
            if (bottom < 0) {
                break;
            }
        } else {
            for (int i = top; i <= cols - 1; ++i) {
                linear_array[linear_index] = matrix[i - top][i];
                linear_index += 1;
            }
            top += 1;
            operation_number = 1;
        }
    }
    return linear_array;
}

void FreeMatrix(Matrix matrix, int rows) {
    for (int i = 0; i < rows; ++i) {
        free(matrix[i]);
    }
    free(matrix);
}

int Task() {
    int rows = 4;
    int cols = 4;
    Matrix matrix = CreateMatrix(rows, cols);
    InitializeMatrix(matrix);
    int32_t* linear_array = LinearizeMatrix(matrix, rows, cols);
    for (int i = 0; i < rows * cols; ++i) {
        printf("%d ", linear_array[i]);
    }
    printf("\n");
    free(linear_array);
    FreeMatrix(matrix, rows);
    return 0;
}

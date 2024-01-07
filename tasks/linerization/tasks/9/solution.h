#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef int32_t **Matrix;

Matrix CreateMatrix(int rows, int cols) {
    Matrix matrix = (Matrix)malloc(rows * sizeof(int32_t *));
    for (int i = 0; i < rows; ++i) {
        matrix[i] = (int32_t *)malloc(cols * sizeof(int32_t));
    }

    return matrix;
}

void FreeMatrix(Matrix matrix, int rows) {
    for (int i = 0; i < rows; ++i) {
        free(matrix[i]);
    }
    free(matrix);
}

void InitMatrix(Matrix matrix) {
    matrix[0][0] = 7;
    matrix[0][1] = 13;
    matrix[0][2] = 14;
    matrix[0][3] = 16;
    matrix[1][0] = 6;
    matrix[1][1] = 8;
    matrix[1][2] = 12;
    matrix[1][3] = 15;
    matrix[2][0] = 2;
    matrix[2][1] = 5;
    matrix[2][2] = 9;
    matrix[2][3] = 11;
    matrix[3][0] = 1;
    matrix[3][1] = 3;
    matrix[3][2] = 4;
    matrix[3][3] = 10;
}

int32_t *DiagonalLinearizeMatrixFromTopLeft(Matrix matrix, int rows, int cols) {
    int32_t *linear_array = (int32_t *)malloc(rows * cols * sizeof(int32_t));
    int linear_index = 0;
    int total_diagonal_quantity = rows + cols - 1;
    int left_row = 0;
    int right_row = 0;
    int col = 0;

    for (int diagonal = 1; diagonal <= total_diagonal_quantity; ++diagonal) {
        if (diagonal <= cols) {
            right_row = rows;
        } else {
            right_row = 2 * rows - diagonal;
        }

        if (diagonal <= rows) {
            left_row = rows - diagonal + 1;
        } else {
            left_row = 1;
        }

        if (diagonal % 2 == 0) {
            for (int row = left_row; row <= right_row; ++row) {
                if (diagonal == 4) {
                    col = row;
                } else {
                    col = diagonal + row - rows;
                }
                linear_array[linear_index++] = matrix[row - 1][col - 1];
            }
        } else {
            for (int row = right_row; row >= left_row; --row) {
                col = diagonal + row - rows;
                linear_array[linear_index++] = matrix[row - 1][col - 1];
            }
        }
    }

    return linear_array;
}

int Task() {
    // write your solution here
    int rows = 4;
    int cols = 4;

    Matrix matrix = CreateMatrix(rows, cols);
    InitMatrix(matrix);

    int32_t *linear_array = DiagonalLinearizeMatrixFromTopLeft(matrix, rows, cols);

    for (int i = 0; i < rows * cols; ++i) {
        printf("%d ", linear_array[i]);
    }
    printf("\n");

    free(linear_array);
    FreeMatrix(matrix, rows);

    return 0;
}
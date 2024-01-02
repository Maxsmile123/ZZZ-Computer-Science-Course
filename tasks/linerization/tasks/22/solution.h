#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef int32_t** Matrix;

Matrix CreateMatrix(int32_t height, int32_t width) {
    Matrix matrix = (Matrix)malloc(height * sizeof(int32_t*));
    for (int32_t i = 0; i < height; ++i) {
        matrix[i] = (int32_t*)malloc(width * sizeof(int32_t));
    }

    return matrix;
}

void MatrixFree(Matrix matrix, int32_t height) {
    for (int32_t i = 0; i < height; ++i) {
        free(matrix[i]);
    }
    free(matrix);
}

void MatrixInitiate(Matrix matrix) {
    matrix[0][0] = 1;
    matrix[0][1] = 12;
    matrix[0][2] = 11;
    matrix[0][3] = 10;
    matrix[1][0] = 2;
    matrix[1][1] = 13;
    matrix[1][2] = 16;
    matrix[1][3] = 9;
    matrix[2][0] = 3;
    matrix[2][1] = 14;
    matrix[2][2] = 15;
    matrix[2][3] = 8;
    matrix[3][0] = 4;
    matrix[3][1] = 5;
    matrix[3][2] = 6;
    matrix[3][3] = 7;
}

int32_t* LinealMatrix(int32_t** matrix, int32_t height, int32_t width) {
    int32_t* lineal_matrix = (int32_t*)malloc(height * width * sizeof(int32_t));
    int32_t top = 0;
    int32_t bottom = height - 1;
    int32_t left = 0;
    int32_t right = width - 1;
    int32_t index_of_lineal = 0;
    int32_t direction = 0;

    while (top <= bottom && left <= right) {
        if (direction == 0) {
            for (int32_t i = top; i <= bottom; i++) {
                lineal_matrix[index_of_lineal] = matrix[i][left];
                ++index_of_lineal;
            }
            left++;
        } else if (direction == 1) {
            for (int32_t i = left; i <= right; i++) {
                lineal_matrix[index_of_lineal] = matrix[bottom][i];
                ++index_of_lineal;
            }
            bottom--;
        } else if (direction == 2) {
            for (int32_t i = bottom; i >= top; i--) {
                lineal_matrix[index_of_lineal] = matrix[i][right];
                ++index_of_lineal;
            }
            right--;
        } else if (direction == 3) {
            for (int32_t i = right; i >= left; i--) {
                lineal_matrix[index_of_lineal] = matrix[top][i];
                ++index_of_lineal;
            }
            top++;
        }
        direction = (direction + 1) % 4;
    }
    return lineal_matrix;
}

int Task() {
    int32_t height = 4;
    int32_t width = 4;
    Matrix matrix = CreateMatrix(height, width);
    MatrixInitiate(matrix);

    for (int32_t i = 0; i < height; ++i) {
        for (int32_t j = 0; j < width; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    int32_t* lineal_matrix = LinealMatrix(matrix, height, width);
    for (int32_t i = 0; i < width * height; ++i) {
        printf("%d ", lineal_matrix[i]);
    }
    free(lineal_matrix);
    MatrixFree(matrix, height);
    return 0;
}

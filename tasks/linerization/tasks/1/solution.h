#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef int32_t **Matrix;

Matrix CreateMatrix(int32_t height, int32_t width) {
    Matrix matrix = (Matrix)malloc(height * sizeof(int32_t *));
    for (int32_t i = 0; i < height; ++i) {
        matrix[i] = (int32_t *)malloc(width * sizeof(int32_t));
    }

    return matrix;
}

typedef struct {
    size_t x;
    size_t y;
} Point;

void MatrixFree(Matrix matrix, int32_t height) {
    for (int32_t i = 0; i < height; ++i) {
        free(matrix[i]);
    }
    free(matrix);
}

void MatrixInitiate(Matrix matrix) {
    matrix[0][0] = 7;
    matrix[0][1] = 11;
    matrix[0][2] = 14;
    matrix[0][3] = 16;
    matrix[1][0] = 4;
    matrix[1][1] = 8;
    matrix[1][2] = 12;
    matrix[1][3] = 15;
    matrix[2][0] = 2;
    matrix[2][1] = 5;
    matrix[2][2] = 9;
    matrix[2][3] = 13;
    matrix[3][0] = 1;
    matrix[3][1] = 3;
    matrix[3][2] = 6;
    matrix[3][3] = 10;
}

int32_t *LinealMatrix(int32_t **matrix, size_t height, size_t width) {
    int32_t *lineal_matrix = (int32_t *)malloc(height * width * sizeof(int32_t));
    Point start = {0, height - 1};
    Point end = {0, height - 1};
    size_t index_of_lineal = 0;

    while (index_of_lineal < height * width) {
        size_t i = start.y;
        size_t j = start.x;
        while (i <= end.y && j <= end.x) {
            lineal_matrix[index_of_lineal] = matrix[i][j];
            ++i;
            ++j;
            ++index_of_lineal;
        }

        if (start.y > 0) {
            --start.y;
        } else {
            ++start.x;
        }

        if (end.x + 1 < width) {
            ++end.x;
        } else {
            --end.y;
        }
    }
    return lineal_matrix;
}

int Task() {
    // write your solution here
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

    int32_t *lineal_matrix = LinealMatrix(matrix, height, width);
    for (int32_t i = 0; i < width * height; ++i) {
        printf("%d ", lineal_matrix[i]);
    }
    free(lineal_matrix);
    MatrixFree(matrix, height);
    return 0;
}
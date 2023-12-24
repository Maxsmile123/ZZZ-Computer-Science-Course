#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef int32_t** Matrix;

Matrix CreateMatrix(int32_t n, int32_t m) {
    Matrix matrix = (int32_t**)malloc(sizeof(int32_t*) * n);
    for (int32_t i = 0; i < n; ++i) {
        matrix[i] = (int32_t*)malloc(sizeof(int32_t) * m);
    }
    return matrix;
}

void MatrixInitialization(Matrix matrix, int32_t n, int32_t m) {
    for (int32_t i = 0; i < n; ++i) {
        for (int32_t j = 0; j < m; ++j) {
            matrix[i][j] = j + m * i;
        }
    }
}

bool CanMoveBottomLeft(int32_t i, int32_t j, int32_t n) {
    return (((i + 1) < n) & ((j - 1) > -1));
}

bool CanMoveTopRight(int32_t i, int32_t j, int32_t m) {
    return (((i - 1) > -1) & ((j + 1) < m));
}

bool CanMoveBottom(int32_t i, int32_t n) {
    return (i + 1) < n;
}

bool CanMoveRight(int32_t j, int32_t m) {
    return (j + 1) < m;
}

int32_t* MatrixLinerization(Matrix matrix, int32_t n, int32_t m) {
    int32_t* linearized_matrix = (int32_t*)malloc(sizeof(int32_t) * n * m);
    int32_t k = 0;
    int32_t i = 0;
    int32_t j = 0;
    linearized_matrix[k] = matrix[i][j];
    while (k < (n * m) + 1) {
        if (CanMoveRight(j, m)) {
            ++j;
            ++k;
            linearized_matrix[k] = matrix[i][j];
        } else if (CanMoveBottom(i, n)) {
            ++i;
            ++k;
            linearized_matrix[k] = matrix[i][j];
        } else {
            break;
        }
        while (CanMoveBottomLeft(i, j, n)) {
            ++i;
            --j;
            ++k;
            linearized_matrix[k] = matrix[i][j];
        }
        if (CanMoveBottom(i, n)) {
            ++i;
            ++k;
            linearized_matrix[k] = matrix[i][j];
        } else if (CanMoveRight(j, m)) {
            ++j;
            ++k;
            linearized_matrix[k] = matrix[i][j];
        } else {
            break;
        }
        while (CanMoveTopRight(i, j, m)) {
            --i;
            ++j;
            ++k;
            linearized_matrix[k] = matrix[i][j];
        }
    }
    return linearized_matrix;
}

void PrintMatrix(Matrix matrix, int32_t n, int32_t m) {
    for (int32_t i = 0; i < n; ++i) {
        for (int32_t j = 0; j < m; ++j) {
            printf("%i ", matrix[i][j]);
        }
        printf("\n");
    }
}

void PrintLinearizedMatrix(const int32_t* linearized_matrix, int32_t n, int32_t m) {
    for (int32_t i = 0; i < (n * m); ++i) {
        printf("%i ", linearized_matrix[i]);
    }
    printf("\n");
}

void FreeMemory(Matrix matrix, int32_t* linearized_matrix, int32_t n) {
    for (int32_t i = 0; i < n; ++i) {
        free(matrix[i]);
    }
    free(matrix);
    free(linearized_matrix);
}

int Task() {
    int32_t n = 4;  // for example
    int32_t m = 4;  // for example
    int32_t* linearized_matrix = NULL;
    Matrix matrix = NULL;
    // For check
    // scanf("%i%i", &n, &m);
    matrix = CreateMatrix(n, m);
    MatrixInitialization(matrix, n, m);
    PrintMatrix(matrix, n, m);
    linearized_matrix = MatrixLinerization(matrix, n, m);
    PrintLinearizedMatrix(linearized_matrix, n, m);
    FreeMemory(matrix, linearized_matrix, n);
    return 0;
}
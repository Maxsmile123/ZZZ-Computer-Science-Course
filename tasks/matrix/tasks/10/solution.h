#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef int32_t **Matrix;

Matrix AllocateMatrix(int32_t rows, int32_t cols) {
    Matrix matrix = (Matrix)malloc(rows * sizeof(int32_t *));
    for (int32_t i = 0; i < rows; i++) {
        matrix[i] = (int32_t *)malloc(cols * sizeof(int32_t));
    }
    return matrix;
}

void FreeMatrix(Matrix matrix, int32_t rows) {
    for (int32_t i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void CyclicShift(Matrix matrix, int32_t rows, int32_t cols, int32_t n) {
    for (int32_t group = 0; group < cols; group += n) {
        for (int32_t i = 0; i < rows; i++) {
            int32_t temp = matrix[i][group];
            for (int32_t j = group; j < group + n - 1; j++) {
                matrix[i][j] = matrix[i][j + 1];
            }
            matrix[i][group + n - 1] = temp;
        }
    }
}

int Task() {
    FILE *file = fopen("../tasks/matrix/tasks/10/matrix.txt", "r");
    int32_t rows = 0;
    int32_t cols = 0;
    int32_t n = 0;
    fscanf(file, "%d%d%d", &rows, &cols, &n);
    Matrix matrix = AllocateMatrix(rows, cols);
    for (int32_t i = 0; i < rows; i++) {
        for (int32_t j = 0; j < cols; j++) {
            fscanf(file, "%d", &matrix[i][j]);
        }
    }
    CyclicShift(matrix, rows, cols, n);
    printf("Updated Matrix:\n");
    for (int32_t i = 0; i < rows; i++) {
        for (int32_t j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    fclose(file);
    FreeMatrix(matrix, rows);
    return 0;
}

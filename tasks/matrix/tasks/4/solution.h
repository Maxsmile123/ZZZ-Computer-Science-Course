#pragma once

#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef int32_t** Matrix;

Matrix MemoryAllocate(size_t matrix_order, Matrix matrix) {
    matrix = (Matrix)malloc(sizeof(int32_t*) * matrix_order);
    for (size_t i = 0; i < matrix_order; ++i) {
        matrix[i] = (int32_t*)malloc(sizeof(int32_t) * matrix_order);
    }
    return matrix;
}

void Swap(int32_t* a, int32_t* b) {
    *a = *a ^ *b;
    *b = *b ^ *a;
    *a = *a ^ *b;
}

Matrix SwapRows(Matrix matrix, const size_t* matrix_order, size_t index1, size_t index2) {
    for (size_t i = 0; i < *matrix_order; ++i) {
        Swap(&matrix[index1][i], &matrix[index2][i]);
    }
    return matrix;
}

Matrix ReadMatrix(const char* file_name, size_t* matrix_order, Matrix matrix) {
    FILE* file = NULL;
    if ((file = fopen(file_name, "r")) == NULL) {
        abort();
    }
    fscanf(file, "%lu", matrix_order);
    matrix = MemoryAllocate(*matrix_order, matrix);
    for (size_t i = 0; i < *matrix_order; ++i) {
        for (size_t j = 0; j < *matrix_order; ++j) {
            fscanf(file, "%d", &matrix[i][j]);
        }
    }
    fclose(file);
    return matrix;
}
void PrintBeforeMatrix(Matrix matrix, size_t matrix_order) {
    printf("\n\nMatrix Before\n\n");
    for (size_t i = 0; i < matrix_order; ++i) {
        for (size_t j = 0; j < matrix_order; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
Matrix Procedure(Matrix matrix, const size_t* matrix_order) {
    size_t max_index_min_composition = 0;
    size_t max_index_max_composition = 0;
    int32_t max = INT_MIN;
    int32_t min = INT_MAX;
    if (*matrix_order == 1) {
        printf("\n Not availible");
        return matrix;
    }
    int32_t string_composition = 1;
    for (size_t i = 0; i < *matrix_order; ++i) {
        for (size_t j = 0; j < *matrix_order; ++j) {
            string_composition *= matrix[i][j];
        }
        if (string_composition >= max) {
            max = string_composition;
            max_index_max_composition = i;
        }
        if (string_composition <= min) {
            min = string_composition;
            max_index_min_composition = i;
        }
        string_composition = 1;
    }
    SwapRows(matrix, matrix_order, max_index_min_composition, max_index_max_composition);
    return matrix;
}
void PrintAfterMatrix(Matrix matrix, size_t matrix_order) {
    printf("\n\nMatrix After\n\n");
    for (size_t i = 0; i < matrix_order; ++i) {
        for (size_t j = 0; j < matrix_order; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
Matrix DeleteMatrix(Matrix matrix, size_t matrix_order) {
    for (size_t i = 0; i < matrix_order; ++i) {
        free(matrix[i]);
    }
    free(matrix);
    matrix = NULL;
    return matrix;
}

int Task() {
    Matrix matrix = NULL;
    const char* file_name = "../tasks/matrix/tasks/4/matrix.txt";
    size_t matrix_order = 0;
    matrix = ReadMatrix(file_name, &matrix_order, matrix);
    PrintBeforeMatrix(matrix, matrix_order);
    Procedure(matrix, &matrix_order);
    PrintAfterMatrix(matrix, matrix_order);
    DeleteMatrix(matrix, matrix_order);
    return 0;
}
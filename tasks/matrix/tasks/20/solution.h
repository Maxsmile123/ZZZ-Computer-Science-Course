#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef int32_t** Matrix;

Matrix CreateMatrix(uint32_t size) {
    Matrix matrix = (int32_t**)malloc(sizeof(int32_t*) * size);
    for (uint32_t i = 0; i < size; ++i) {
        matrix[i] = (int32_t*)malloc(sizeof(int32_t) * size);
    }
    return matrix;
}

Matrix ReadMatrixFromFile(const char* file_name, uint32_t size) {
    FILE* file = fopen(file_name, "r");
    Matrix matrix = CreateMatrix(size);
    if (file != NULL) {
        for (uint32_t i = 0; i < size; ++i) {
            for (uint32_t j = 0; j < size; ++j) {
                fscanf(file, "%i", &matrix[i][j]);
            }
        }
        fclose(file);
    } else {
        printf("Все ***** давай по новой");
    }
    return matrix;
}

int32_t MinElement(Matrix matrix, uint32_t size) {
    int32_t min_element = INT32_MAX;
    for (uint32_t i = 0; i < size; ++i) {
        for (uint32_t j = 0; j < size; ++j) {
            if (min_element > matrix[i][j]) {
                min_element = matrix[i][j];
            }
        }
    }
    return min_element;
}

int32_t ColumnSum(Matrix matrix, uint32_t j, uint32_t size) {
    int32_t column_sum = 0;
    for (uint32_t i = 0; i < size; ++i) {
        column_sum += matrix[i][j];
    }
    return column_sum;
}

Matrix Solution(Matrix matrix_old, int32_t min_element, uint32_t size) {
    Matrix matrix_new = CreateMatrix(size);
    for (uint32_t i = 0; i < size; ++i) {
        for (uint32_t j = 0; j < size; ++j) {
            if (matrix_old[i][j] == min_element) {
                matrix_new[i][j] = ColumnSum(matrix_old, j, size);
            } else {
                matrix_new[i][j] = matrix_old[i][j];
            }
        }
    }
    return matrix_new;
}

void PrintMatrix(Matrix matrix, uint32_t size) {
    for (uint32_t i = 0; i < size; ++i) {
        for (uint32_t j = 0; j < size; ++j) {
            printf("%i ", matrix[i][j]);
        }
        printf("\n");
    }
}

void ClearMemory(Matrix matrix, uint32_t size) {
    for (uint32_t i = 0; i < size; ++i) {
        free(matrix[i]);
    }
    free(matrix);
}

int Task() {
    uint32_t size = 2;  // for example
    const char* file_name = "../tasks/matrix/tasks/20/Matrix2x2.md";
    Matrix matrix_from_file = ReadMatrixFromFile(file_name, size);
    int32_t min_element = MinElement(matrix_from_file, size);
    Matrix matrix_new = Solution(matrix_from_file, min_element, size);
    printf("Matrix from file :\n");
    PrintMatrix(matrix_from_file, size);
    printf("Min Element = %i\n", min_element);
    printf("Result Matrix:\n");
    PrintMatrix(matrix_new, size);
    ClearMemory(matrix_from_file, size);
    ClearMemory(matrix_new, size);
    return 0;
}
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
        printf("Что-то с файликом нетак -_-");
    }
    return matrix;
}

int32_t MaxElement(Matrix matrix, uint32_t i, uint32_t size) {
    int32_t max_element = INT32_MIN;
    for (uint32_t j = 0; j < size; ++j) {
        if (max_element < matrix[i][j]) {
            max_element = matrix[i][j];
        }
    }
    return max_element;
}

Matrix Solution(Matrix matrix_old, uint32_t size) {
    Matrix matrix_new = CreateMatrix(size);
    for (uint32_t i = 0; i < size; ++i) {
        for (uint32_t j = 0; j < size; ++j) {
            if (i == j) {
                matrix_new[i][j] = MaxElement(matrix_old, i, size);
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
    uint32_t size = 3;  // размер матрицы
    const char* file_name = "../tasks/matrix/tasks/19/Matrix3x3.md";
    Matrix matrix_from_file = ReadMatrixFromFile(file_name, size);
    Matrix matrix_new = Solution(matrix_from_file, size);
    printf("Matrix from file :\n");
    PrintMatrix(matrix_from_file, size);
    printf("Result Matrix:\n");
    PrintMatrix(matrix_new, size);
    ClearMemory(matrix_from_file, size);
    ClearMemory(matrix_new, size);
    return 0;
}
#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef int32_t** Matrix;

Matrix CreatingMatrix(int32_t matrix_size) {
    Matrix matrix = (Matrix)malloc(sizeof(int32_t*) * matrix_size);
    for (int32_t i = 0; i < matrix_size; ++i) {
        matrix[i] = (int32_t*)malloc(matrix_size * sizeof(int32_t*));
    }
    return matrix;
}

void AddMatrixValues(FILE* file_matrix, Matrix matrix, int32_t matrix_size) {
    for (int32_t i = 0; i < matrix_size; ++i) {
        for (int32_t j = 0; j < matrix_size; ++j) {
            fscanf(file_matrix, "%d", &matrix[i][j]);
        }
    }
}

void Swap(int32_t* element_1, int32_t* element_2) {
    int32_t tmp = *element_1;
    *element_1 = *element_2;
    *element_2 = tmp;
}

void ReversalMatrix(Matrix matrix, int32_t matrix_size) {
    for (int32_t i = 0; i < matrix_size / 2; ++i) {
        for (int32_t j = i; j < matrix_size - i - 1; ++j) {
            // Чтобы проще было понять, какие элементы матрицы я беру
            // int32_t element_1 = matrix[i][j];
            // int32_t element_2 = matrix[j][matrix_size - i - 1];
            // int32_t element_3 = matrix[matrix_size - i - 1][matrix_size - j - 1];
            // int32_t element_4 = matrix[matrix_size - j - 1][i];
            Swap(&matrix[i][j], &matrix[matrix_size - j - 1][i]);
            Swap(&matrix[matrix_size - j - 1][i], &matrix[matrix_size - i - 1][matrix_size - j - 1]);
            Swap(&matrix[matrix_size - i - 1][matrix_size - j - 1], &matrix[j][matrix_size - i - 1]);
        }
    }
}

void PrintMatrix(Matrix matrix, int32_t matrix_size) {
    for (int i = 0; i < matrix_size; ++i) {
        for (int j = 0; j < matrix_size; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void FreeingMemory(Matrix matrix, int32_t matrix_size) {
    for (int32_t i = 0; i < matrix_size; ++i) {
        free(matrix[i]);
    }
    free(matrix);
}

int Task() {
    FILE* file_matrix = nullptr;
    if ((file_matrix = fopen("../tasks/matrix/tasks/34/matrix.txt", "r")) == NULL) {
        printf("Could not open the file");
        return 0;
    }
    int32_t matrix_size = 0;
    fscanf(file_matrix, "%d", &matrix_size);
    Matrix matrix = CreatingMatrix(matrix_size);
    AddMatrixValues(file_matrix, matrix, matrix_size);
    PrintMatrix(matrix, matrix_size);
    ReversalMatrix(matrix, matrix_size);
    PrintMatrix(matrix, matrix_size);
    FreeingMemory(matrix, matrix_size);
    fclose(file_matrix);
    return 0;
}
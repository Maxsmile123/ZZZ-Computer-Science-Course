#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef int32_t** Matrix;

const int32_t SHIFT = 7;

Matrix CreateMatrix(int32_t n) {
    Matrix matrix = (Matrix)malloc(n * sizeof(int32_t*));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int32_t*)malloc(n * sizeof(int32_t));
    }
    return matrix;
}

void MatrixFree(Matrix matrix, int32_t n) {
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}
// Считываем матрицу и сразу начинаем решать задачу, считывая (n * n - SHIFT) элементы в массив, остальным элементами
// заполняя матрицу
Matrix InitializeMatrixAndShift(const char* filename, int32_t* n) {
    int32_t shift = SHIFT;
    if (shift < 0) {
        printf("Invalid input\n");
        abort();
    }
    FILE* file = fopen(filename, "r");
    fscanf(file, "%d", n);
    int32_t matrix_size = (*n) * (*n);
    if (shift > matrix_size) {
        shift = shift % matrix_size;
    }
    Matrix matrix = CreateMatrix(*n);
    int32_t* start_elements = (int32_t*)malloc((matrix_size - shift) * sizeof(int32_t));
    int32_t reading_elements_matrix_counter = matrix_size;
    int32_t new_elements_count = 0;
    for (int i = 0; i < matrix_size - shift; ++i) {
        fscanf(file, "%d", &start_elements[i]);
    }
    for (int i = 0; i < *n; ++i) {
        for (int j = 0; j < *n; ++j) {
            if (reading_elements_matrix_counter > matrix_size - shift) {
                fscanf(file, "%d", &matrix[i][j]);
            } else if (reading_elements_matrix_counter <= matrix_size - shift) {
                matrix[i][j] = start_elements[new_elements_count];
                ++new_elements_count;
            }
            --reading_elements_matrix_counter;
        }
    }
    fclose(file);
    free(start_elements);
    return matrix;
}

int Task() {
    int32_t n = 0;
    const char* filename = "../tasks/matrix/tasks/9/matrix.txt";
    Matrix matrix = InitializeMatrixAndShift(filename, &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    MatrixFree(matrix, n);
    return 0;
}

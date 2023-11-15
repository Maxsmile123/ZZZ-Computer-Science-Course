#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef int32_t** Matrix;

Matrix MatrixGeneration(Matrix matrix, size_t len, size_t width) {
    for (size_t i = 0; i < width; ++i) {
        for (size_t j = 0; j < len; ++j) {
            matrix[i][j] = rand() % 1000;
        }
    }
    return matrix;
}

void Print(Matrix matrix, size_t len, size_t width) {
    printf("\nMatrix Before\n\n");
    for (size_t i = 0; i < width; ++i) {
        for (size_t j = 0; j < len; ++j) {
            printf("%u ", matrix[i][j]);
        }
        printf("\n");
    }
}

bool AvailibleIterations(size_t now_iteration, size_t maximum) {
    return now_iteration >= maximum;
}

int32_t* SpiralMatrix(Matrix matrix, int32_t* new_massive, size_t len, size_t width) {
    printf("\n\nMatrix after");
    size_t start_1 = 0;
    size_t finish_1 = len;
    size_t string_1 = 0;
    size_t start_2 = 1;
    size_t finish_2 = width;
    size_t column_2 = len - 1;
    size_t start_3 = len - 2;
    size_t finish_3 = 0;
    size_t string_3 = width - 1;
    size_t start_4 = width - 1;
    size_t finish_4 = 0;
    size_t column_4 = 0;
    size_t count = 0;
    while (count < len * width) {
        for (size_t i = start_1; i < finish_1; ++i) {
            if (AvailibleIterations(count, len * width)) {
                break;
            }
            new_massive[count] = matrix[string_1][i];
            ++count;
        }
        ++start_1;
        --finish_1;
        ++string_1;
        for (size_t i = start_2; i < finish_2; ++i) {
            if (AvailibleIterations(count, len * width)) {
                break;
            }
            new_massive[count] = matrix[i][column_2];
            ++count;
        }
        ++start_2;
        --finish_2;
        --column_2;
        for (size_t i = start_3; i > finish_3; --i) {
            if (AvailibleIterations(count, len * width)) {
                break;
            }
            new_massive[count] = matrix[string_3][i];
            ++count;
        }
        --start_3;
        ++finish_3;
        --string_3;
        for (size_t i = start_4; i > finish_4; --i) {
            if (AvailibleIterations(count, len * width)) {
                break;
            }
            new_massive[count] = matrix[i][column_4];
            ++count;
        }
        --start_4;
        ++finish_4;
        ++column_4;
    }
    return new_massive;
}

void PrintMassive(int32_t* new_massive, size_t len) {
    for (size_t i = 0; i < len; ++i) {
        printf("%d ", new_massive[i]);
    }
}

void MemoryCleaner(Matrix matrix, size_t width, int32_t* new_massive) {
    for (size_t i = 0; i < width; ++i) {
        free(matrix[i]);
    }
    free(matrix);
    free(new_massive);
    matrix = NULL;
    new_massive = NULL;
}

int Task() {
    size_t len_matrix = 0;
    scanf("%lu", &len_matrix);
    size_t width_matrix = 0;
    scanf("%lu", &width_matrix);
    Matrix matrix = (int32_t**)malloc(sizeof(int32_t*) * width_matrix);
    for (size_t i = 0; i < width_matrix; ++i) {
        matrix[i] = (int32_t*)malloc(sizeof(int32_t) * len_matrix);
    }
    MatrixGeneration(matrix, len_matrix, width_matrix);
    Print(matrix, len_matrix, width_matrix);
    int32_t* new_massive = (int32_t*)malloc(sizeof(int32_t) * width_matrix * len_matrix);
    SpiralMatrix(matrix, new_massive, len_matrix, width_matrix);
    printf("\n\n\n");
    PrintMassive(new_massive, len_matrix * width_matrix);
    MemoryCleaner(matrix, width_matrix, new_massive);
    return 0;
}
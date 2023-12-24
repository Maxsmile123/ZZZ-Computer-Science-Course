#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef int32_t** Matrix;

Matrix MatrixGeneration(Matrix matrix, size_t height, size_t width) {
    for (size_t i = 0; i < width; ++i) {
        for (size_t j = 0; j < height; ++j) {
            matrix[i][j] = rand() % 1000;
        }
    }
    return matrix;
}

void Print(Matrix matrix, size_t height, size_t width) {
    printf("\nMatrix Before\n\n");
    for (size_t i = 0; i < width; ++i) {
        for (size_t j = 0; j < height; ++j) {
            printf("%u ", matrix[i][j]);
        }
        printf("\n");
    }
}

bool IsIterationAvailible(size_t it, size_t max) {
    return it >= max;
}

int32_t* SpiralMatrix(Matrix matrix, int32_t* lin_matrix, size_t height, size_t width) {
    printf("\n\nMatrix after\n\n");
    // sorry, i cant use lower variables
    // this variable help me saving start to go right and copy matrix elements on array
    size_t go_right_start = 0;
    // this variable help me saving finish to go right and copy matrix elements in array
    size_t right_finish = height;
    // this variable help me saving number string to go right and copy matrix elements
    size_t num_str_to_right = 0;
    size_t go_down_start = 1;
    size_t down_finish = width;
    size_t num_column_to_down = height - 1;
    size_t go_left_start = height - 2;
    size_t left_finish = 0;
    size_t num_str_to_left = width - 1;
    size_t go_up_start = width - 1;
    size_t up_finish = 0;
    size_t num_column_to_up = 0;
    // others - analogous
    size_t count = 0;
    while (count < height * width) {
        for (size_t i = go_right_start; i < right_finish; ++i) {
            if (IsIterationAvailible(count, height * width)) {
                break;
            }
            lin_matrix[count] = matrix[num_str_to_right][i];
            ++count;
        }
        ++go_right_start;
        --right_finish;
        ++num_str_to_right;
        for (size_t i = go_down_start; i < down_finish; ++i) {
            if (IsIterationAvailible(count, height * width)) {
                break;
            }
            lin_matrix[count] = matrix[i][num_column_to_down];
            ++count;
        }
        ++go_down_start;
        --down_finish;
        --num_column_to_down;
        for (size_t i = go_left_start; i > left_finish; --i) {
            if (IsIterationAvailible(count, height * width)) {
                break;
            }
            lin_matrix[count] = matrix[num_str_to_left][i];
            ++count;
        }
        --go_left_start;
        ++left_finish;
        --num_str_to_left;
        for (size_t i = go_up_start; i > up_finish; --i) {
            if (IsIterationAvailible(count, height * width)) {
                break;
            }
            lin_matrix[count] = matrix[i][num_column_to_up];
            ++count;
        }
        --go_up_start;
        ++up_finish;
        ++num_column_to_up;
    }
    return lin_matrix;
}

void PrintLinMatrix(int32_t* lin_matrix, size_t height) {
    for (size_t i = 0; i < height; ++i) {
        printf("%d ", lin_matrix[i]);
    }
}

void DeleteMatrixs(Matrix matrix, size_t width, int32_t* lin_matrix) {
    for (size_t i = 0; i < width; ++i) {
        free(matrix[i]);
    }
    free(matrix);
    free(lin_matrix);
    matrix = NULL;
    lin_matrix = NULL;
}

int Task() {
    size_t height_matrix = 5;
    size_t width_matrix = 4;
    Matrix matrix = (int32_t**)malloc(sizeof(int32_t*) * width_matrix);
    for (size_t i = 0; i < width_matrix; ++i) {
        matrix[i] = (int32_t*)malloc(sizeof(int32_t) * height_matrix);
    }
    MatrixGeneration(matrix, height_matrix, width_matrix);
    Print(matrix, height_matrix, width_matrix);
    int32_t* lin_matrix = (int32_t*)malloc(sizeof(int32_t) * width_matrix * height_matrix);
    SpiralMatrix(matrix, lin_matrix, height_matrix, width_matrix);
    printf("\n\n\n");
    PrintLinMatrix(lin_matrix, height_matrix * width_matrix);
    DeleteMatrixs(matrix, width_matrix, lin_matrix);
    return 0;
}
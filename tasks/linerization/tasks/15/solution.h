#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

const int32_t NUMBER_ROWS = 4;
const int32_t NUMBER_COLUMS = 4;

typedef int32_t** Matrix;

Matrix CreatingMatrix() {
    Matrix matrix = (Matrix)malloc(sizeof(int32_t*) * NUMBER_ROWS);
    for (int32_t i = 0; i < NUMBER_ROWS; ++i) {
        matrix[i] = (int32_t*)malloc(sizeof(int32_t*) * NUMBER_COLUMS);
    }
    return matrix;
}

void AddMatrixValues(Matrix matrix) {
    matrix[0][0] = 16;
    matrix[0][1] = 14;
    matrix[0][2] = 10;
    matrix[0][3] = 4;
    matrix[1][0] = 13;
    matrix[1][1] = 9;
    matrix[1][2] = 3;
    matrix[1][3] = 5;
    matrix[2][0] = 8;
    matrix[2][1] = 2;
    matrix[2][2] = 6;
    matrix[2][3] = 11;
    matrix[3][0] = 1;
    matrix[3][1] = 7;
    matrix[3][2] = 12;
    matrix[3][3] = 15;
}

void Linerization(Matrix matrix, int32_t* linear_array) {
    int32_t current_row = NUMBER_ROWS - 1;
    int32_t current_colum = 0;
    int32_t row_step = 0;
    int32_t colum_step = 0;
    int32_t count_steps = NUMBER_COLUMS;
    int32_t array_index = 0;
    while (true) {
        if ((row_step + colum_step) % 2 == 0) {
            for (int32_t i = 0; i < count_steps; ++i) {
                linear_array[array_index + i] = matrix[current_row - i][current_colum + i];
            }
            array_index += count_steps;
            current_row -= count_steps - 1;
            current_colum += count_steps - 1;
            count_steps -= 1;
            row_step += 1;
        }
        current_row += row_step;
        current_colum += colum_step;
        if ((row_step + colum_step) % 2 != 0) {
            for (int32_t i = 0; i < count_steps; ++i) {
                linear_array[array_index + i] = matrix[current_row + i][current_colum - i];
            }
            array_index += count_steps;
            current_row += count_steps - 1;
            current_colum -= count_steps - 1;
            colum_step += 1;
        }
        current_row -= row_step;
        current_colum -= colum_step;
        if (current_colum == 0 && current_row == 0) {
            linear_array[NUMBER_COLUMS * NUMBER_ROWS - 1] = matrix[0][0];
            break;
        }
    }
}

void FreeingMemory(Matrix matrix, int32_t* linear_array) {
    for (int32_t i = 0; i < NUMBER_ROWS; ++i) {
        free(matrix[i]);
    }
    free(matrix);
    free(linear_array);
}

int Task() {
    Matrix matrix = CreatingMatrix();
    int32_t* linear_array = (int32_t*)malloc(sizeof(int32_t*) * NUMBER_ROWS * NUMBER_COLUMS);
    AddMatrixValues(matrix);
    Linerization(matrix, linear_array);
    for (int32_t i = 0; i < NUMBER_ROWS; ++i) {
        for (int32_t j = 0; j < NUMBER_COLUMS; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    for (int32_t i = 0; i < NUMBER_ROWS * NUMBER_COLUMS; ++i) {
        printf("%d ", linear_array[i]);
    }
    FreeingMemory(matrix, linear_array);
    return 0;
}
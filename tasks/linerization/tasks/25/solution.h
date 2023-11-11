#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef int32_t** Matrix;

// Функция для создания матрицы
Matrix CreateMatrix(int rows, int cols) {
    Matrix matrix = (Matrix)malloc(rows * sizeof(int32_t*));
    for (int i = 0; i < rows; ++i) {
        matrix[i] = (int32_t*)malloc(cols * sizeof(int32_t));
    }

    return matrix;
}

// Функция для инициализации матрицы
void InitializeMatrix(Matrix matrix) {
    matrix[0][0] = 7;
    matrix[0][1] = 6;
    matrix[0][2] = 5;
    matrix[0][3] = 4;
    matrix[1][0] = 8;
    matrix[1][1] = 15;
    matrix[1][2] = 14;
    matrix[1][3] = 3;
    matrix[2][0] = 9;
    matrix[2][1] = 16;
    matrix[2][2] = 13;
    matrix[2][3] = 2;
    matrix[3][0] = 10;
    matrix[3][1] = 11;
    matrix[3][2] = 12;
    matrix[3][3] = 1;
}

// Функция для линеаризации матрицы
int32_t* LinearizeMatrix(int32_t** matrix, int rows, int cols) {
    int32_t* linear_array = (int32_t*)malloc(rows * cols * sizeof(int32_t));
    int top = 0;
    int bottom = rows - 1;
    int left = 0;
    int right = cols - 1;
    int linear_index = 0;
    int operation_number = 1;
    while (top <= bottom || left <= right) {
        if (operation_number == 1) {
            for (int i = bottom; i >= top; --i) {
                linear_array[linear_index] = matrix[i][right];
                linear_index += 1;
            }
            right -= 1;
            operation_number += 1;
        } else if (operation_number == 2) {
            for (int i = right; i >= left; --i) {
                linear_array[linear_index] = matrix[top][i];
                linear_index += 1;
            }
            top += 1;
            operation_number += 1;
        } else if (operation_number == 3) {
            for (int i = top; i <= bottom; ++i) {
                linear_array[linear_index] = matrix[i][left];
                linear_index += 1;
            }
            left += 1;
            operation_number += 1;
        } else {
            for (int i = left; i <= right; ++i) {
                linear_array[linear_index] = matrix[bottom][i];
                linear_index += 1;
            }
            bottom -= 1;
            operation_number = 1;
        }
    }
    return linear_array;
}

// Функция для освобождения памяти, выделенной для матрицы
void FreeMatrix(Matrix matrix, int rows) {
    for (int i = 0; i < rows; ++i) {
        free(matrix[i]);
    }
    free(matrix);
}

int Task() {
    int rows = 4;
    int cols = 4;
    Matrix matrix = CreateMatrix(rows, cols);
    InitializeMatrix(matrix);
    int32_t* linear_array = LinearizeMatrix(matrix, rows, cols);
    // Вывод линеаризации матрицы
    for (int i = 0; i < rows * cols; ++i) {
        printf("%d ", linear_array[i]);
    }
    printf("\n");
    // Освобождаем выделенную память
    free(linear_array);
    FreeMatrix(matrix, rows);
    return 0;
}
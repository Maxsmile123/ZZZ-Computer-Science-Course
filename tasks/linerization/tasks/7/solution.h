#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef int32_t **Matrix;

// Функция для создания матрицы
Matrix CreateMatrix(int rows, int cols) {
    Matrix matrix = (Matrix)malloc(rows * sizeof(int32_t *));
    for (int i = 0; i < rows; ++i) {
        matrix[i] = (int32_t *)malloc(cols * sizeof(int32_t));
    }

    return matrix;
}

// Функция для инициализации матрицы
void InitializeMatrix(Matrix matrix) {
    matrix[0][0] = 16;
    matrix[0][1] = 14;
    matrix[0][2] = 13;
    matrix[0][3] = 7;
    matrix[1][0] = 15;
    matrix[1][1] = 12;
    matrix[1][2] = 8;
    matrix[1][3] = 6;
    matrix[2][0] = 11;
    matrix[2][1] = 9;
    matrix[2][2] = 5;
    matrix[2][3] = 2;
    matrix[3][0] = 10;
    matrix[3][1] = 4;
    matrix[3][2] = 3;
    matrix[3][3] = 1;
}

bool CanMoveBottomLeft(int32_t i, int32_t j, int32_t cols) {
    return (((i + 1) < cols) & ((j - 1) > -1));
}

bool CanMoveTopRight(int32_t i, int32_t j, int32_t rows) {
    return (((i - 1) > -1) & ((j + 1) < rows));
}

bool CanMoveLeft(int32_t i) {
    return (i - 1) > -1;
}

bool CanMoveTop(int32_t i) {
    return (i - 1) > -1;
}

// Функция для линеаризации матрицы
int32_t *LinearizeMatrix(int32_t **matrix, int rows, int cols) {
    int32_t *linear_array = (int32_t *)malloc(rows * cols * sizeof(int32_t));
    int linear_index = 0;
    int i = cols - 1;
    int j = rows - 1;
    linear_array[linear_index] = matrix[i][j];
    while (linear_index <= (rows * cols)) {
        if (CanMoveTop(i)) {
            i--;
            linear_index++;
            linear_array[linear_index] = matrix[i][j];
        } else if (CanMoveLeft(j)) {
            j--;
            linear_index++;
            linear_array[linear_index] = matrix[i][j];
        } else {
            break;
        }
        while (CanMoveBottomLeft(i, j, cols)) {
            ++i;
            --j;
            ++linear_index;
            linear_array[linear_index] = matrix[i][j];
        }
        if (CanMoveLeft(j)) {
            j--;
            linear_index++;
            linear_array[linear_index] = matrix[i][j];
        } else if (CanMoveTop(i)) {
            i--;
            linear_index++;
            linear_array[linear_index] = matrix[i][j];
        } else {
            break;
        }
        while (CanMoveTopRight(i, j, rows)) {
            --i;
            ++j;
            ++linear_index;
            linear_array[linear_index] = matrix[i][j];
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
    int32_t *linear_array = LinearizeMatrix(matrix, rows, cols);
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

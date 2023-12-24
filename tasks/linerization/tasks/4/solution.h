#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef int32_t **Matrix;

// создаем матрицу
Matrix CreateMatrix(int rows, int cols) {
    Matrix matrix = (Matrix)malloc(rows * sizeof(int32_t *));
    for (int i = 0; i < rows; ++i) {
        matrix[i] = (int32_t *)malloc(cols * sizeof(int32_t));
    }

    return matrix;
}
// функция освобождения памяти
void FreeMatrix(Matrix matrix, int rows) {
    for (int i = 0; i < rows; ++i) {
        free(matrix[i]);
    }
    free(matrix);
}

// инициализация матрицы по условию варианта
void InitMatrix(Matrix matrix) {
    matrix[0][0] = 1;
    matrix[0][1] = 3;
    matrix[0][2] = 6;
    matrix[0][3] = 10;
    matrix[1][0] = 2;
    matrix[1][1] = 5;
    matrix[1][2] = 9;
    matrix[1][3] = 13;
    matrix[2][0] = 4;
    matrix[2][1] = 8;
    matrix[2][2] = 12;
    matrix[2][3] = 15;
    matrix[3][0] = 7;
    matrix[3][1] = 11;
    matrix[3][2] = 14;
    matrix[3][3] = 16;
}

// Функция линеаризации матрицы
// буду использовать диагональную линеаризацию, согласно расположению чисел в матрице (по условию)
// начиная с левого верхнего угла проходим по каждой диагонали снизу вверх
int32_t *DiagonalLinearizeMatrixFromTopLeft(Matrix matrix, int rows, int cols) {
    int32_t *linear_array = (int32_t *)malloc(rows * cols * sizeof(int32_t));
    int linear_index = 0;                           // Индекс для линейного массива
    int total_diagonal_quantity = rows + cols - 1;  // Общее количество диагоналей
    int start_row = 0;
    int end_row = 0;
    int col = 0;

    // Перебор диагоналей, начиная с 1
    for (int diagonal = 1; diagonal <= total_diagonal_quantity; ++diagonal) {
        // Определение начальной и конечной строки для текущей диагонали
        // пока не дошли до 5 диагонали - начало считывания с первого столбца
        // иначе вычисляем номер столбца
        if (diagonal <= cols) {
            start_row = 1;
        } else {
            start_row = diagonal - cols + 1;
        }

        if (diagonal <= rows) {
            end_row = diagonal;
        } else {
            end_row = rows;
        }

        // Перебор элементов в диагонали
        for (int row = end_row; row >= start_row; --row) {
            col = diagonal - row + 1;  // Вычисление столбца для текущего элемента
            linear_array[linear_index++] = matrix[row - 1][col - 1];  // Добавление элемента в линейный массив
        }
    }
    return linear_array;
}

// Основная функция
int Task() {
    int rows = 4;
    int cols = 4;
    Matrix matrix = CreateMatrix(rows, cols);
    InitMatrix(matrix);

    // Линеаризация матрицы
    int32_t *linear_array = DiagonalLinearizeMatrixFromTopLeft(matrix, rows, cols);

    // Вывод линеаризованного массива
    for (int i = 0; i < rows * cols; ++i) {
        printf("%d ", linear_array[i]);
    }
    printf("\n");

    // Освобождение памяти
    free(linear_array);
    FreeMatrix(matrix, rows);
    return 0;
}

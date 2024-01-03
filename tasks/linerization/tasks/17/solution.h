#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef int32_t** Matrix;

int32_t Abs(int32_t n) {
    if (n < 0) {
        return -n;
    }
    return n;
}

int32_t Min(int32_t a, int32_t b) {
    if (a < b) {
        return a;
    }
    return b;
}

int32_t AltSign(int32_t n) {
    n = n % 2;
    if (n == 0) {
        return 1;
    }
    return -1;
}

Matrix CreateMatrix(const int32_t rows, const int32_t columns) {
    Matrix matrix = (Matrix)malloc(rows * sizeof(int32_t*));
    for (int32_t i = 0; i < rows; ++i) {
        matrix[i] = (int32_t*)malloc(columns * sizeof(int32_t));
    }
    return matrix;
}

void FreeMatrix(Matrix matrix, const int32_t rows) {
    for (int32_t i = 0; i < rows; ++i) {
        free(matrix[i]);
    }
    free(matrix);
}

void InitMatrix(Matrix matrix) {
    matrix[0][0] = 7;
    matrix[0][1] = 6;
    matrix[0][2] = 5;
    matrix[0][3] = 16;
    matrix[1][0] = 8;
    matrix[1][1] = 1;
    matrix[1][2] = 4;
    matrix[1][3] = 15;
    matrix[2][0] = 9;
    matrix[2][1] = 2;
    matrix[2][2] = 3;
    matrix[2][3] = 14;
    matrix[3][0] = 10;
    matrix[3][1] = 11;
    matrix[3][2] = 12;
    matrix[3][3] = 13;
}

void InitMatrixSimple(Matrix matrix, const int32_t rows, const int32_t columns) {
    for (int32_t i = 0; i < rows; ++i) {
        for (int32_t j = 0; j < columns; ++j) {
            matrix[i][j] = i * columns + j;
        }
    }
}

int32_t* LinearMatrix(int32_t** matrix, const int32_t rows, const int32_t columns) {
    // Рабоает только для квадратной матрицы четного порядка, т.к. начальная позиция выбирается специфично
    int32_t* linear_matrix = (int32_t*)malloc(rows * columns * sizeof(int32_t));
    int32_t linear_index = 0;
    const int32_t square_order = Min(rows, columns);
    const int32_t linear_square_size = square_order * square_order;

    // Cтартовая позиция
    int32_t row = (rows - 1) / 2;
    int32_t column = (columns - 1) / 2;
    int32_t step_length = 0;
    int32_t step_border = 0;

    // Обход квадратной матрицы, выделенной из данной
    // d, r,  u, u, l, l,   d, d, d, r, r, r,  u, u, u, u, l, l, l, l ....
    while (linear_index < linear_square_size) {
        step_length += 1;
        // Вниз
        for (step_border = linear_index + step_length; linear_index < step_border; ++linear_index) {
            linear_matrix[linear_index] = matrix[row][column];
            row += 1;
        }
        if (step_length >= square_order) {
            break;
        }
        // Вправо
        for (step_border = linear_index + step_length; linear_index < step_border; ++linear_index) {
            linear_matrix[linear_index] = matrix[row][column];
            column += 1;
        }
        step_length += 1;
        // Вверх
        for (step_border = linear_index + step_length; linear_index < step_border; ++linear_index) {
            linear_matrix[linear_index] = matrix[row][column];
            row -= 1;
        }
        if (step_length >= square_order) {
            break;
        }
        // Влево
        for (step_border = linear_index + step_length; linear_index < step_border; ++linear_index) {
            linear_matrix[linear_index] = matrix[row][column];
            column -= 1;
        }
    }
    // Обход лент (оставшиеся либо строки, либо столбцы)
    if (rows > square_order) {
        // Подгоняем начальные условия
        step_length = (square_order)*AltSign(square_order + 1);
        row = row - step_length;
        for (int32_t i = 0; i < rows - square_order; ++i) {
            step_length = (square_order + i) * AltSign(square_order + 1 + i);
            row = row + step_length;
            if (Abs(step_length) % 2 == 0) {
                // Строка снизу
                for (int32_t j = columns - 1; j >= 0; --j) {
                    linear_matrix[linear_index++] = matrix[row][j];
                }
            } else {
                // Строка сверху
                for (int32_t j = 0; j < columns; ++j) {
                    linear_matrix[linear_index++] = matrix[row][j];
                }
            }
        }
    } else if (columns > square_order) {
        for (int32_t i = 0; i < columns - square_order; ++i) {
            step_length = (square_order + i) * AltSign(square_order + 1 + i);
            column = column + step_length;
            if ((Abs(step_length) - 1) % 2 == 0) {
                // Столбец справа
                for (int32_t j = rows - 1; j >= 0; --j) {
                    linear_matrix[linear_index++] = matrix[j][column];
                }
            } else {
                // Столбец слева
                for (int32_t j = 0; j < rows; ++j) {
                    linear_matrix[linear_index++] = matrix[j][column];
                }
            }
        }
    }
    return linear_matrix;
}

int Task() {
    // Инициализация матрицы
    int32_t rows = 4;
    int32_t columns = 4;
    Matrix matrix = CreateMatrix(rows, columns);
    InitMatrix(matrix);
    // InitMatrixSimple(matrix, rows, columns);
    // Преобразование в линейную матрицу
    int32_t* linear_matrix = LinearMatrix(matrix, rows, columns);
    // Вывод
    // Исходная
    for (int32_t i = 0; i < rows; ++i) {
        for (int32_t j = 0; j < columns; ++j) {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    // Линеризованная
    for (int32_t i = 0; i < rows * columns; ++i) {
        printf("%d ", linear_matrix[i]);
    }
    printf("\n");
    // Освобождаем память
    free(linear_matrix);
    FreeMatrix(matrix, rows);
    return 0;
}
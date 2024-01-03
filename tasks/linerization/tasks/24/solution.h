#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef int32_t** Matrix;
typedef int32_t* Row;

typedef struct {
    size_t start;
    size_t end;
} Slice;

#define Sign(x) ((x >= 0) ? 1 : -1)

void Swap(size_t* n, size_t* m) {
    size_t t = *n;
    *n = *m;
    *m = t;
}

// Заполняет матрицу входными значениями
void Fill(Matrix matrix) {
    matrix[0][0] = 4;
    matrix[0][1] = 5;
    matrix[0][2] = 6;
    matrix[0][3] = 7;
    matrix[1][0] = 3;
    matrix[1][1] = 14;
    matrix[1][2] = 15;
    matrix[1][3] = 8;
    matrix[2][0] = 2;
    matrix[2][1] = 13;
    matrix[2][2] = 16;
    matrix[2][3] = 9;
    matrix[3][0] = 1;
    matrix[3][1] = 12;
    matrix[3][2] = 11;
    matrix[3][3] = 10;
}

// Линеризует матрицу, обходя её по спирали, начиная с левого нижнего угла (по часовой стрелке)
void Linerization(Matrix matrix, Row lin_matrix, size_t n, size_t m) {
    size_t element = 0;

    Slice y_axis = {n - 1, 0};
    Slice x_axis = {m - 1, 0};

    int32_t is_horizontal = 0;
    int32_t step = Sign((int32_t)y_axis.end - (int32_t)y_axis.start);

    while (element < n * m) {
        if (is_horizontal) {
            for (size_t j = x_axis.start; j != x_axis.end + step; j += step) {
                lin_matrix[element++] = matrix[y_axis.end][j];
            }
            Swap(&y_axis.start, &y_axis.end);
            step = Sign((int32_t)y_axis.end - (int32_t)y_axis.start);
            y_axis.start += step;
        } else {
            for (size_t i = y_axis.start; i != y_axis.end + step; i += step) {
                lin_matrix[element++] = matrix[i][x_axis.end];
            }
            Swap(&x_axis.start, &x_axis.end);
            step = Sign((int32_t)x_axis.end - (int32_t)x_axis.start);
            x_axis.start += step;
        }

        is_horizontal = !is_horizontal;
    }
}

void PrintMatrix(Matrix matrix, size_t n, size_t m) {
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void PrintRow(Row row, size_t n) {
    for (size_t i = 0; i < n; ++i) {
        printf("%d ", row[i]);
    }
    printf("\n");
}

const size_t N = 4;
const size_t M = 4;

int Task() {
    // Инициализируем матрицу
    Row lin_matrix = (Row)calloc(N * M, sizeof(Row));
    Matrix matrix = (Matrix)calloc(N, sizeof(Row));
    for (size_t i = 0; i < N; ++i) {
        matrix[i] = (Row)calloc(M, sizeof(Row));
    }

    // Заполняем матрицу
    Fill(matrix);

    // Решаем задачу
    Linerization(matrix, lin_matrix, N, M);

    // Выводим результат
    PrintMatrix(matrix, N, M);
    printf("\n");
    PrintRow(lin_matrix, N * M);

    // Освобождаем память
    for (size_t i = 0; i < N; ++i) {
        free(matrix[i]);
    }
    free(matrix);
    free(lin_matrix);

    return 0;
}

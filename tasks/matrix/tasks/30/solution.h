#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef int32_t** Matrix;

// Функция для создания матрицы
Matrix CreateMatrix(int32_t n) {
    Matrix matrix = (Matrix)malloc(n * sizeof(int32_t*));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int32_t*)malloc(n * sizeof(int32_t));
    }
    return matrix;
}

// Функция для освобождения памяти, выделенной для матрицы
void FreeMatrix(Matrix matrix, int32_t n) {
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Функция для инициализации матрицы и её размера из файла
Matrix InitializeMatrixFromFile(const char* filename, int32_t* n) {
    FILE* file = fopen(filename, "r");
    fscanf(file, "%d", n);
    Matrix matrix = CreateMatrix(*n);
    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *n; j++) {
            fscanf(file, "%d", &matrix[i][j]);
        }
    }
    fclose(file);
    return matrix;
}

// Функция преобразования матрицы
Matrix MatrixWithModifiedCols(Matrix matrix, int32_t n) {
    int32_t min_value = INT32_MAX;
    int32_t max_value = INT32_MIN;
    int32_t last_col_with_max_value = -1;

    // Проходим по столбцам, ищем минимум, максимум и нужный столбец
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[j][i] >= max_value) {
                max_value = matrix[j][i];
                last_col_with_max_value = j;
            }
            if (matrix[j][i] < min_value) {
                min_value = matrix[j][i];
            }
        }
    }

    // Производим замену столбцов
    if (min_value != max_value) {
        bool has_min_value = false;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[j][i] == min_value) {
                    has_min_value = true;
                    break;
                }
            }
            if (has_min_value) {
                for (int j = 0; j < n; ++j) {
                    matrix[j][i] = matrix[j][last_col_with_max_value];
                }
                has_min_value = false;
            }
        }
    }

    return matrix;
}

int Task() {
    int32_t n = 0;

    // Вводим сюда путь к файлу
    const char* filename = "../tasks/matrix/tasks/30/matrix.txt";
    Matrix matrix = InitializeMatrixFromFile(filename, &n);

    // Вывод исходной матрицы
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Преобразуем матрицу
    matrix = MatrixWithModifiedCols(matrix, n);

    // Вывод итоговой матрицы и освобождение памяти
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    FreeMatrix(matrix, n);
    return 0;
}
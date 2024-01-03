#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef int32_t **Matrix;

// Функция для создания матрицы
Matrix CreateMatrix(int32_t n) {
    Matrix matrix = (Matrix)malloc(n * sizeof(int32_t *));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int32_t *)malloc(n * sizeof(int32_t));
    }
    return matrix;
}

// Функция для чтения матрицы из файла
Matrix ReadMatrixFromFile(const char *file_path, int32_t *n) {
    FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        perror("Не удается открыть файл");
        exit(EXIT_FAILURE);
    }

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

// Функция вывода матрицы
void MatrixOutput(Matrix matrix, int32_t n, bool *rows_to_remove) {
    for (int i = 0; i < n; i++) {
        if (!rows_to_remove[i]) {
            for (int j = 0; j < n; j++) {
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }
    }
    printf("\n");
}

// Функция для освобождения памяти матрицы
void FreeMatrix(Matrix matrix, int32_t n) {
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Функция для удаления строк, которые содержат минимальное значение
bool *RemovingRowsWithMinValue(Matrix matrix, int32_t n) {
    int32_t min_value = INT32_MAX;
    bool *rows_to_remove = (bool *)malloc(n * sizeof(bool));

    for (int i = 0; i < n; i++) {
        rows_to_remove[i] = false;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] < min_value) {
                min_value = matrix[i][j];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == min_value) {
                rows_to_remove[i] = true;
                break;
            }
        }
    }

    return rows_to_remove;
}

int Task() {
    int32_t n = 0;
    Matrix matrix = NULL;

    // указываю путь к файлу с заданной матрицей
    const char *file_path = "../tasks/matrix/tasks/25/matrix25.txt";
    matrix = ReadMatrixFromFile(file_path, &n);

    // Создаем временный массив, в котором все значения false
    bool *temp_rows_to_remove = (bool *)calloc(n, sizeof(bool));

    // Выводим исходную матрицу
    printf("Исходная матрица:\n");
    MatrixOutput(matrix, n, temp_rows_to_remove);

    // Освобождаем временный массив
    free(temp_rows_to_remove);

    // Меняем матрицу, удаляем ненужные строки
    bool *rows_to_remove = RemovingRowsWithMinValue(matrix, n);

    // Выводим преобразованную матрицу
    printf("Преобразованная матрица:\n");
    MatrixOutput(matrix, n, rows_to_remove);

    FreeMatrix(matrix, n);
    free(rows_to_remove);
    return 0;
}

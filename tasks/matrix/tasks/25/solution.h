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
void ReadMatrixFromFile(const char *file_path, Matrix *matrix, int32_t *n) {
    // открытие файла
    FILE *file = fopen(file_path, "r");
    // учитываем ошибку, когда невозможно открыть файл
    if (file == NULL) {
        perror("Не удается открыть файл");
        exit(EXIT_FAILURE);
    }
    // считываем размер матрицы
    fscanf(file, "%d", n);
    *matrix = CreateMatrix(*n);
    // заполняем матрицу числами из файла
    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *n; j++) {
            fscanf(file, "%d", &(*matrix)[i][j]);
        }
    }
    fclose(file);
}

// Функция вывода матрицы
void MatrixOutput(Matrix matrix, int32_t n, bool *rows_to_remove) {
    for (int i = 0; i < n; i++) {
        // пропускаем строки, которые помечены (содержат минимальный эл.)
        if (rows_to_remove != NULL && rows_to_remove[i]) {
            continue;
        }

        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Функция для освобождения памяти, занятой матрицей
void FreeMatrix(Matrix matrix, int32_t n) {
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Функция для удаления строк, которые содержат минимальное значение
bool *RemovingRowsWithMinValue(Matrix matrix, int32_t n) {
    int32_t min_value = INT32_MAX;
    // создаем массив, где будем отслеживать строки с минимальным эл.
    bool *rows_to_remove = (bool *)malloc(n * sizeof(bool));

    for (int i = 0; i < n; i++) {
        rows_to_remove[i] = false;  // по умолчанию пока нет таких строк
    }
    // поиск минимального элемента в строке
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
                rows_to_remove[i] = true;  // если нашлась строка с минимальным элементом
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
    const char *file_path = "../tasks/matrix/tasks/25/matrix.txt";
    // считываем матрицу из файла
    ReadMatrixFromFile(file_path, &matrix, &n);

    // Выводим исходную матрицу
    printf("Исходная матрица:\n");
    MatrixOutput(matrix, n, NULL);  // Т.К. нам нужно вывести все строки

    // Меняем матрицу, удаляем ненужные строки
    bool *rows_to_remove = RemovingRowsWithMinValue(matrix, n);

    // Выводим преобразованную матрицу
    printf("Преобразованная матрица:\n");
    MatrixOutput(matrix, n, rows_to_remove);

    FreeMatrix(matrix, n);
    free(rows_to_remove);
    return 0;
}

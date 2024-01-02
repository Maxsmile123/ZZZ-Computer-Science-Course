#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef int32_t** Matrix;

// Cоздание матрицы
Matrix CreateMatrix(int32_t n) {
    Matrix matrix = (Matrix)malloc(n * sizeof(int32_t*));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int32_t*)malloc(n * sizeof(int32_t));
    }
    return matrix;
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
Matrix MatrixWithRearrangedLines(Matrix matrix, int32_t n) {
    int32_t first_line_with_max_value = -1;

    // Ищем максимальный элемент в матрице и первую строку его вхождения
    int32_t max_value = INT32_MIN;
    for (int i = n - 1; i > 0; --i) {
        for (int j = n - 1; j > 0; --j) {
            if (matrix[i][j] >= max_value) {
                max_value = matrix[i][j];
                first_line_with_max_value = i;
            }
        }
    }

    // Складываем строки, имеющие максимальный элемент
    bool has_max_value = false;
    int32_t sum_of_lines_with_max_value = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == max_value) {
                has_max_value = true;
                break;
            }
        }
        if (has_max_value) {
            for (int j = 0; j < n; ++j) {
                sum_of_lines_with_max_value = sum_of_lines_with_max_value + matrix[i][j];
            }
            has_max_value = false;
        }
    }
    // Заменяем первую строку, содержащую максимальный элемент на сумму строк, содержащих максимальный элемент
    for (int j = 0; j < n; ++j) {
        matrix[first_line_with_max_value][j] = sum_of_lines_with_max_value;
    }

    return matrix;
}

// Печать матрицы
void PrintMatrix(Matrix matrix, int32_t n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Освобождения памяти
void FreeMatrix(Matrix matrix, int32_t n) {
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int Task() {
    // write your solution here
    int32_t n = 0;

    // Вводим путь к файлу
    const char* filename = "../tasks/matrix/tasks/5/matrix.txt";
    Matrix matrix = InitializeMatrixFromFile(filename, &n);

    // Вывод исходной матрицы
    PrintMatrix(matrix, n);

    // Преобразуем матрицу
    matrix = MatrixWithRearrangedLines(matrix, n);

    // Вывод итоговой матрицы
    PrintMatrix(matrix, n);

    FreeMatrix(matrix, n);
    return 0;
}

#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef int32_t** Matrix;

size_t Max(size_t a, size_t b) {
    if (a > b) {
        return a;
    }
    return b;
}

Matrix CreateSquareMatrix(const size_t order) {
    Matrix matrix = (Matrix)malloc(order * sizeof(int32_t*));
    for (size_t i = 0; i < order; ++i) {
        matrix[i] = (int32_t*)malloc(order * sizeof(int32_t));
    }
    return matrix;
}

void FreeSquareMatrix(Matrix matrix, const size_t order) {
    for (size_t i = 0; i < order; ++i) {
        free(matrix[i]);
    }
    free(matrix);
}

// Возведение квадратной матрицы в квадрат
Matrix SquareMatrixSquared(Matrix matrix, const size_t order) {
    Matrix result = CreateSquareMatrix(order);
    for (size_t i = 0; i < order; ++i) {
        for (size_t j = 0; j < order; ++j) {
            result[i][j] = 0;
            for (size_t k = 0; k < order; ++k) {
                result[i][j] += matrix[i][k] * matrix[k][j];
            }
        }
    }
    return result;
}

// Ретурн уже занят указателем на матрицу, поэтому ее порядок записывается по указателю в аргумент order
Matrix ReadSquareMatrixFromFile(const char* filename, size_t* order) {
    FILE* fileptr = nullptr;
    fileptr = fopen(filename, "r");
    if (fileptr) {
        // Порядок квадратной матрицы
        fscanf(fileptr, "%zu", order);
        // Заполнение матрицы
        Matrix matrix = CreateSquareMatrix(*order);
        for (size_t i = 0; i < *order; ++i) {
            for (size_t j = 0; j < *order; ++j) {
                fscanf(fileptr, "%d", &matrix[i][j]);
            }
        }
        fclose(fileptr);
        return matrix;
    } else {
        printf("File not found\n");
        abort();
    }
}

size_t NumberLength(int32_t n) {
    size_t res = 1;
    if (n < 0) {
        ++res;
        n = -n;
    }
    n /= 10;
    while (n > 0) {
        ++res;
        n /= 10;
    }
    return res;
}

// Распечатать в консоль квадратную матрицу
void PrintSquareMatrix(Matrix matrix, const size_t order) {
    size_t elem_width = 0;
    for (size_t i = 0; i < order; ++i) {
        for (size_t j = 0; j < order; ++j) {
            elem_width = Max(NumberLength(matrix[i][j]), elem_width);
        }
    }
    printf("%zu\n", order);
    for (size_t i = 0; i < order; ++i) {
        for (size_t j = 0; j < order; ++j) {
            printf("%*d ", (int32_t)elem_width, matrix[i][j]);
        }
        printf("\n");
    }
}

// Запись квадратной матрцы в файл
void WriteSquareMatrixToFile(const char* filename, Matrix matrix, const size_t order) {
    size_t elem_width = 0;
    for (size_t i = 0; i < order; ++i) {
        for (size_t j = 0; j < order; ++j) {
            elem_width = Max(NumberLength(matrix[i][j]), elem_width);
        }
    }
    FILE* fileptr = nullptr;
    fileptr = fopen(filename, "w");
    fprintf(fileptr, "%zu\n", order);
    for (size_t i = 0; i < order; ++i) {
        for (size_t j = 0; j < order; ++j) {
            fprintf(fileptr, "%*d ", (int32_t)elem_width, matrix[i][j]);
        }
        fprintf(fileptr, "\n");
    }
}

int Task() {
    // Инициализация матрицы
    size_t order = 0;
    const char* filename = "../tasks/matrix/tasks/15/in.txt";
    Matrix matrix = ReadSquareMatrixFromFile(filename, &order);
    // Возведение в квадрат
    Matrix result = SquareMatrixSquared(matrix, order);
    // Вывод
    PrintSquareMatrix(result, order);
    // Если хочется в файл, то
    // WriteSquareMatrixToFile("../tasks/matrix/tasks/15/out.txt", result, order);
    // Освобождаем память
    FreeSquareMatrix(matrix, order);
    FreeSquareMatrix(result, order);
    return 0;
}
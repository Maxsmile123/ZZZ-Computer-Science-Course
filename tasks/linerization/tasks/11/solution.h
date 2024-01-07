#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef int32_t** Matrix;

// создание матрицы заданных размеров
Matrix CreatingMatrix(int32_t n, int32_t m) {
    Matrix matrix = (int32_t**)malloc(n * sizeof(int32_t*));

    for (int32_t i = 0; i < n; ++i) {
        matrix[i] = (int32_t*)malloc(m * sizeof(int32_t));
    }
    return matrix;
}

// заполнение матрицы исходными значениями
Matrix OriginalMatrix(Matrix matrix) {
    matrix[0][0] = 16;
    matrix[0][1] = 15;
    matrix[0][2] = 11;
    matrix[0][3] = 10;
    matrix[1][0] = 14;
    matrix[1][1] = 12;
    matrix[1][2] = 9;
    matrix[1][3] = 4;
    matrix[2][0] = 13;
    matrix[2][1] = 8;
    matrix[2][2] = 5;
    matrix[2][3] = 3;
    matrix[3][0] = 7;
    matrix[3][1] = 6;
    matrix[3][2] = 2;
    matrix[3][3] = 1;
    return matrix;
}

// преобразовние двумерной матрицы в одномерный массив
int32_t* OneDimensionalArray(Matrix matrix, int32_t n, int32_t m) {
    int32_t* linearized_matrix = (int32_t*)malloc(n * m * sizeof(int32_t));

    for (int32_t i = 0; i < n; ++i) {
        for (int32_t j = 0; j < m; ++j) {
            linearized_matrix[i * m + j] = matrix[i][j];
        }
    }

    return linearized_matrix;
}

// вывод матриц
void AnsweringMatrix(Matrix matrix, int32_t* arr, int32_t n, int32_t m) {
    printf("матрица в двумерном массиве\n");
    for (int32_t i = 0; i < n; ++i) {
        for (int32_t j = 0; j < m; ++j) {
            printf("%2d ", matrix[i][j]); // %2d для выравнивания двузначных чисел
        }
        printf("\n");
    }

    printf("матрица в одномерном массиве\n");
    for (int32_t i = 0; i < n * m; ++i) {
        printf("%2d ", arr[i]);
    }
    printf("\n");
}

// освобождение памяти, выделенной под матрицу
void MatrixFree(Matrix matrix, int32_t n) {
    for (int32_t i = 0; i < n; ++i) {
        free(matrix[i]);
    }
    free(matrix);
}

int Task() {
    // параметры размера матрицы
    int32_t n = 4;
    int32_t m = 4;

    Matrix matrix = CreatingMatrix(n, m);
    matrix = OriginalMatrix(matrix);
    int32_t* arr = OneDimensionalArray(matrix, n, m);

    AnsweringMatrix(matrix, arr, n, m);
    MatrixFree(matrix, n);

    // освобождение выделенной памяти
    free(arr);

    return 0;
}

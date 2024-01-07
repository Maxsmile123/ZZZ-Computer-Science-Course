#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef int32_t** Matrix;

// создание матрицы заданных размеров
Matrix creatingMatrix(int32_t n, int32_t m) {
    Matrix matrix = (int32_t**)malloc(n * sizeof(int32_t*));

    for (int32_t i = 0; i < n; ++i) {
        matrix[i] = (int32_t*)malloc(m * sizeof(int32_t));
    }
    return matrix;
}

// заполнение матрицы исходными значениями
Matrix originalMatrix(Matrix matrix) {
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

// преобразование двумерной матрицы в одномерный массив с числами от 1 до n*m
int32_t* oneDimensionalArray(Matrix matrix, int32_t n, int32_t m) {
    int32_t* linearizedMatrix = (int32_t*)malloc(n * m * sizeof(int32_t));

    int32_t counter = 1;
    for (int32_t i = 0; i < n; ++i) {
        for (int32_t j = 0; j < m; ++j) {
            linearizedMatrix[i * m + j] = counter++;
        }
    }

    return linearizedMatrix;
}

// вывод матрицы и одномерного массива
void answeringMatrix(Matrix matrix, int32_t* arr, int32_t n, int32_t m) {

    printf("матрица в двумерном массиве\n");
    for (int32_t i = 0; i < n; ++i) {
        for (int32_t j = 0; j < m; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("матрица в одномерном массиве\n");
    for (int32_t i = 0; i < n * m; ++i) {
        printf("%d ", arr[i]);
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

int main() {
    // параметры размера матрицы
    int32_t n = 4;
    int32_t m = 4;

    Matrix matrix = creatingMatrix(n, m);
    matrix = originalMatrix(matrix);
    int32_t* arr = oneDimensionalArray(matrix, n, m);

    answeringMatrix(matrix, arr, n, m);
    MatrixFree(matrix, n);

    // освобождение выделенной памяти
    free(arr);

    return 0;
}

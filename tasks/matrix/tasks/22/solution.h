#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef int32_t** Matrix;

Matrix CreateMatrix(int32_t order_of_matrix) {
    Matrix matrix = (Matrix)malloc(order_of_matrix * sizeof(int32_t*));
    for (int32_t i = 0; i < order_of_matrix; ++i) {
        matrix[i] = (int32_t*)malloc(order_of_matrix * sizeof(int32_t));
    }
    return matrix;
}

Matrix FillFromFile(const char* filename, int32_t* order_of_matrix) {
    FILE* file = fopen(filename, "r");

    fscanf(file, "%d", order_of_matrix);

    Matrix matrix = CreateMatrix(*order_of_matrix);

    for (int32_t i = 0; i < *order_of_matrix; ++i) {
        for (int32_t j = 0; j < *order_of_matrix; ++j) {
            fscanf(file, "%d", &matrix[i][j]);
        }
    }

    fclose(file);
    return matrix;
}

int32_t MinElem(int32_t a, int32_t b) {
    if (b < a) {
        return b;
    } else {
        return a;
    }
}

int32_t MinInd(int32_t a, int32_t b, int32_t a_i, int32_t b_i) {
    if (b < a) {
        return a_i;
    } else {
        return b_i;
    }
}

int32_t MiniOfMatrix(Matrix matrix, int32_t order_of_matrix) {
    int32_t mini = matrix[0][0];
    int32_t mini_x = 0;
    for (int32_t i = 0; i < (int32_t)(order_of_matrix); ++i) {
        for (int32_t j = 0; j < (int32_t)(order_of_matrix); ++j) {
            mini = MinElem(mini, matrix[i][j]);
            mini_x = MinInd(mini, matrix[i][j], i, mini_x);
        }
    }
    return mini_x;
}

void Swap(int32_t* a, int32_t* b) {
    int32_t temp = *a;
    *a = *b;
    *b = temp;
}

Matrix ModifiedMatrix(Matrix matrix, int32_t mini_x, int32_t order_of_matrix) {
    for (int32_t j = 0; j < order_of_matrix / 2; ++j) {
        Swap(&matrix[mini_x][j], &matrix[mini_x][order_of_matrix - 1 - j]);
    }
    return matrix;
}

void MatrixPrint(Matrix matrix, int32_t order_of_matrix, char time) {
    if (time == 'o') {  // o: old
        printf("Изначальная матрица:\n");
    } else if (time == 'n') {  // n: new
        printf("Изменённая матрица:\n");
    }
    for (int32_t i = 0; i < order_of_matrix; ++i) {
        for (int32_t j = 0; j < order_of_matrix; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void MatrixFree(Matrix matrix, int32_t order_of_matrix) {
    for (int32_t i = 0; i < order_of_matrix; ++i) {
        free(matrix[i]);
    }
    free(matrix);
}

int Task() {
    // write your solution here
    const char* filename = "../tasks/matrix/tasks/22/file.txt";
    int32_t order_of_matrix = 0;
    Matrix matrix = FillFromFile(filename, &order_of_matrix);
    MatrixPrint(matrix, order_of_matrix, 'o');

    int32_t mini_x = MiniOfMatrix(matrix, order_of_matrix);
    matrix = ModifiedMatrix(matrix, mini_x, order_of_matrix);
    MatrixPrint(matrix, order_of_matrix, 'n');

    MatrixFree(matrix, order_of_matrix);
    return 0;
}
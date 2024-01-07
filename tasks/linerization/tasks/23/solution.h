#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef int32_t** Matrix;

int Task() {
    // write your solution here
    FILE* matr = nullptr;
    const char* path = "../tasks/linerization/tasks/23/matr.txt";
    matr = fopen(path, "r");
    const int n = 4;
    const int m = 4;
    Matrix matrix = (int32_t**)malloc(sizeof(int32_t*) * n);
    for (int i = 0; i < n; ++i) {
        matrix[i] = (int32_t*)malloc(sizeof(int32_t) * m);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            fscanf(matr, "%d", &matrix[i][j]);
        }
    }
    printf("Двумерный массив:\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    int32_t* mas = (int32_t*)malloc(sizeof(int32_t) * m * n);
    int k = 0;
    for (int j = 3; j >= 0; --j) {
        mas[k] = matrix[0][j];
        ++k;
    }
    for (int i = 1; i < n; ++i) {
        mas[k] = matrix[i][0];
        ++k;
    }
    for (int j = 1; j <= (n - 1); ++j) {
        mas[k] = matrix[3][j];
        ++k;
    }
    for (int i = (m - 2); i >= 1; --i) {
        mas[k] = matrix[i][3];
        ++k;
    }
    for (int j = (n - 2); j >= 1; --j) {
        mas[k] = matrix[1][j];
        ++k;
    }
    for (int j = 1; j <= (n - 2); ++j) {
        mas[k] = matrix[2][j];
        ++k;
    }
    printf("Одномерный массив:\n");
    for (int i = 0; i < k; ++i) {
        printf("%d ", mas[i]);
    }
    printf("\n");
    fclose(matr);
    free(mas);
    for (int i = 0; i < n; ++i) {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}

#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct Matrix {
    int32_t** data;
    size_t size;
};

struct Matrix CreateMatrix(const size_t size) {

    struct Matrix matrix;

    matrix.data = (int32_t**)malloc(size * sizeof(int32_t*));
    matrix.size = size;

    for (size_t i = 0; i < size; ++i) {
        matrix.data[i] = (int32_t*)malloc(size * sizeof(int32_t));
    }

    return matrix;
}

void CleanMatrix(struct Matrix matrix) {

    for (size_t i = 0; i < matrix.size; ++i) {
        free(matrix.data[i]);
    }
    free(matrix.data);
}

void PrintMatrix(struct Matrix matrix) {

    for (size_t i = 0; i < matrix.size; ++i) {
        for (size_t j = 0; j < matrix.size; ++j) {
            printf("%d\t", matrix.data[i][j]);
        }

        printf("\n");
    }
}

struct Matrix MatrixFromFile(FILE* file) {

    size_t n = 0;
    fscanf(file, "%zu", &n);
    struct Matrix matrix = CreateMatrix(n);

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            fscanf(file, "%d", &matrix.data[i][j]);
        }
    }

    return matrix;
}

void ReplacingElements(struct Matrix* matrix) {

    int32_t sum = 0;
    int32_t x = 0;
    int32_t y = 0;

    for (size_t i = 0; i < (*matrix).size; ++i) {

        sum = (*matrix).data[i][i];

        x = (int32_t)i;
        y = (int32_t)i;

        while (true) {
            x -= 1;
            y += 1;

            if (!(0 <= x && x < (int32_t)(*matrix).size && 0 <= y && y < (int32_t)(*matrix).size)) {
                break;
            }
            sum += (*matrix).data[x][y];
        }

        x = (int32_t)i;
        y = (int32_t)i;

        while (true) {
            x += 1;
            y -= 1;

            if (!(0 <= x && x < (int32_t)(*matrix).size && 0 <= y && y < (int32_t)(*matrix).size)) {
                break;
            }
            sum += (*matrix).data[x][y];
        }

        (*matrix).data[i][i] = sum;
    }
}

int Task() {

    FILE* file = fopen("matrix.txt", "r");

    if (file == NULL) {
        printf("Файл не открылся\n");
        return 0;
    }

    struct Matrix matrix = MatrixFromFile(file);

    // PrintMatrix(matrix);
    // printf("\n");

    ReplacingElements(&matrix);

    PrintMatrix(matrix);

    CleanMatrix(matrix);
    fclose(file);

    return 0;
}

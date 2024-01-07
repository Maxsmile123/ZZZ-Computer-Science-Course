#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef int32_t **Matrix;
typedef int32_t *Row;

#define Max(x, y) ((x > y) ? x : y)

Matrix InitializeMatrix(size_t n) {
    Matrix matrix = (Matrix)calloc(n * n, sizeof(Row));
    for (size_t i = 0; i < n; ++i) {
        matrix[i] = (Row)calloc(n, sizeof(int32_t));
    }
    return matrix;
}

Matrix CreateFromFile(const char *filename, size_t *n) {
    FILE *fp = fopen(filename, "r");
    if (fp) {

        fscanf(fp, "%lu", n);
        if (n == 0) {
            printf("Invalid input\n");
            abort();
        }

        Matrix matrix = InitializeMatrix(*n);

        for (size_t i = 0; i < *n; ++i) {
            for (size_t j = 0; j < *n; ++j) {
                fscanf(fp, "%d", &matrix[i][j]);
            }
        }

        fclose(fp);

        return matrix;
    } else {
        printf("No such file\n");
        abort();
    }
}

size_t NumberLen(int32_t number) {
    size_t length = (size_t)(number < 0);
    while (number) {
        number /= 10;
        ++length;
    }
    return length;
}

void PrintMatrix(Matrix matrix, size_t n) {
    size_t length = 0;

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            length = Max(length, NumberLen(matrix[i][j]) + 1);
        }
    }

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            printf("%*d", (int32_t)length, matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void FreeMatrix(Matrix matrix, size_t n) {
    for (size_t i = 0; i < n; ++i) {
        free(matrix[i]);
    }
    free(matrix);
}

void Solution(Matrix matrix, size_t n) {
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = i + 1; j < n; ++j) {
            if (matrix[i][j] == matrix[j][i]) {
                matrix[i][j] = 0;
                matrix[j][i] = 0;
            }
        }
    }
}

int Task() {
    const char *filename = "../tasks/matrix/tasks/32/Matrix.txt";
    size_t n = 0;
    Matrix matrix = CreateFromFile(filename, &n);
    PrintMatrix(matrix, n);

    Solution(matrix, n);
    PrintMatrix(matrix, n);

    FreeMatrix(matrix, n);

    return 0;
}

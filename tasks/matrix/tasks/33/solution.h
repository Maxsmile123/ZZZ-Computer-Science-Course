#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef int32_t **Matrix;
typedef int32_t *Row;

#define Max(x, y) ((x > y) ? x : y)

Matrix InitializeMatrix(size_t size) {
    Matrix matrix = (Matrix)calloc(size * size, sizeof(Row));
    for (size_t i = 0; i < size; ++i) {
        matrix[i] = (Row)calloc(size, sizeof(int32_t));
    }
    return matrix;
}

Matrix CreateFromFile(const char *filename, size_t *size) {
    FILE *fp = fopen(filename, "r");
    if (fp) {

        fscanf(fp, "%lu", size);
        if (size == 0) {
            printf("Invalid input\n");
            abort();
        }
        Matrix matrix = InitializeMatrix(*size);

        for (size_t i = 0; i < *size; ++i) {
            for (size_t j = 0; j < *size; ++j) {
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

void PrintMatrix(Matrix matrix, size_t size) {
    size_t length = 0;

    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < size; ++j) {
            length = Max(length, NumberLen(matrix[i][j]) + 1);
        }
    }

    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < size; ++j) {
            printf("%*d", (int32_t)length, matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void FreeMatrix(Matrix matrix, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        free(matrix[i]);
    }
    free(matrix);
}

void CheckingSkewSymmetry(Matrix matrix, size_t size) {
    bool skew_symmetry = true;
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = i + 1; j < size; ++j) {
            if (matrix[i][j] != -matrix[j][i]) {
                skew_symmetry = false;
            }
        }
    }
    if (skew_symmetry) {
        printf("The matrix is skew-symmetric\n");
    } else {
        printf("The matrix is not skew-symmetric\n");
    }
    printf("\n");
}

void Replacement(Matrix matrix, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = i + 1; j < size; ++j) {
            if (matrix[i][j] == -matrix[j][i]) {
                matrix[i][j] = 0;
                matrix[j][i] = 0;
            }
        }
    }
}

int Task() {
    // write your solution here
    const char *filename = "../tasks/matrix/tasks/33/matrix.txt";
    size_t size = 0;
    Matrix matrix = CreateFromFile(filename, &size);
    PrintMatrix(matrix, size);
    CheckingSkewSymmetry(matrix, size);
    Replacement(matrix, size);
    PrintMatrix(matrix, size);

    FreeMatrix(matrix, size);
    return 0;
}
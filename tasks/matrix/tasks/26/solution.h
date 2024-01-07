#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef int32_t **Matrix;

Matrix CreateMatrix(int32_t n) {
    Matrix matrix = (Matrix)malloc(n * sizeof(int32_t *));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int32_t *)malloc(n * sizeof(int32_t));
    }
    return matrix;
}

int CountLines(const char *file_path) {
    int count = 0;
    int c = 0;
    FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        perror("Can't open this file");
        exit(EXIT_FAILURE);
    }
    for (c = getc(file); c != EOF; c = getc(file)) {
        if (c == '\n') {
            count += 1;
        }
    }
    fclose(file);
    count += 1;
    return count;
}

Matrix ReadMatrix(const char *file_path, int32_t *n) {
    FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        perror("Can't open this file");
        exit(EXIT_FAILURE);
    }

    Matrix matrix = CreateMatrix(*n);
    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *n; j++) {
            fscanf(file, "%d", &matrix[i][j]);
        }
    }
    fclose(file);
    return matrix;
}

void MatrixOutput(Matrix matrix, int32_t n, bool *columns_to_remove) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!columns_to_remove[j]) {
                printf("%d ", matrix[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

void FreeMatrix(Matrix matrix, int32_t n) {
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

bool *RemoveColumns(Matrix matrix, int32_t n) {
    int32_t max_value = INT32_MIN;
    bool *columns_to_remove = (bool *)malloc(n * sizeof(bool));

    for (int j = 0; j < n; j++) {
        columns_to_remove[j] = false;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] > max_value) {
                max_value = matrix[i][j];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == max_value) {
                columns_to_remove[j] = true;
            }
        }
    }
    return columns_to_remove;
}

int Task() {
    const char *file = "../tasks/matrix/tasks/26/test.txt";
    int32_t n = CountLines(file);
    Matrix matrix = NULL;
    matrix = ReadMatrix(file, &n);

    bool *temp_columns_to_remove = (bool *)calloc(n, sizeof(bool));

    printf("Исходная матрица:\n");
    MatrixOutput(matrix, n, temp_columns_to_remove);
    free(temp_columns_to_remove);

    bool *columns_to_remove = RemoveColumns(matrix, n);

    printf("Преобразованная матрица:\n");
    MatrixOutput(matrix, n, columns_to_remove);
    FreeMatrix(matrix, n);
    free(columns_to_remove);
    return 0;
}
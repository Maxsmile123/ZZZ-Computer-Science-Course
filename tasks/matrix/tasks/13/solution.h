#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef int32_t** Matrix;

Matrix InputMatrix(int32_t size) {
    int32_t** input_matrix = (int32_t**)malloc(sizeof(int32_t*) * size);
    for (int32_t i = 0; i < size; ++i) {
        input_matrix[i] = (int32_t*)malloc(sizeof(int32_t) * size);
    }
    return input_matrix;
}

int32_t MatrixSize(const char* path) {
    int32_t size = 0;
    FILE* file = fopen(path, "r");
    fscanf(file, "%d", &size);
    fclose(file);
    return size;
}

Matrix ReadMatrix(int32_t size, Matrix input_matrix, const char* path) {
    FILE* file = fopen(path, "r");
    if (file == NULL) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }
    printf("Input matrix\n");
    printf("---------------\n");
    fscanf(file, "%*s");  //пропускает первую строку файла
    for (int32_t i = 0; i < size && !feof(file); ++i) {
        for (int32_t j = 0; j < size && !feof(file); ++j) {
            fscanf(file, "%d", &input_matrix[i][j]);
            printf("%d ", input_matrix[i][j]);
        }
        printf("\n");
    }
    fclose(file);
    return input_matrix;
}

int32_t MaxElement(Matrix input_matrix, int32_t size) {
    int32_t max = input_matrix[0][0];
    for (int32_t line = 1; line < size; ++line) {
        for (int32_t collumn = 0; collumn <= line; ++collumn) {
            if (max < input_matrix[line][collumn]) {
                max = input_matrix[line][collumn];
            }
        }
    }
    return max;
}

Matrix SubmatrixMul(Matrix input_matrix, int32_t size, int32_t max) {
    for (int32_t line = 0; line < size; ++line) {
        for (int32_t collumn = line; collumn < size; ++collumn) {
            input_matrix[line][collumn] = input_matrix[line][collumn] * max;
        }
    }
    return input_matrix;
}

void PrintResult(Matrix result, int32_t size) {
    printf("---------------\n");
    printf("Result matrix\n");
    printf("---------------\n");
    for (int32_t i = 0; i < size; ++i) {
        for (int32_t j = 0; j < size; ++j) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

int Task() {
    const char* path = "../tasks/matrix/tasks/13/test.txt";
    int32_t size = MatrixSize(path);
    Matrix input_matrix = InputMatrix(size);
    input_matrix = ReadMatrix(size, input_matrix, path);
    int32_t max = MaxElement(input_matrix, size);
    input_matrix = SubmatrixMul(input_matrix, size, max);
    PrintResult(input_matrix, size);
    for (int32_t i = 0; i < size; ++i) {
        free(input_matrix[i]);
    }
    free(input_matrix);
    return 0;
}
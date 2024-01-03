#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef int32_t** Matrix;

Matrix CreateMatrix(int32_t height, int32_t width) {
    Matrix matrix = (Matrix)malloc(sizeof(int32_t*) * height);
    for (int32_t i = 0; i < height; ++i) {
        matrix[i] = (int32_t*)malloc(sizeof(int32_t) * width);
    }
    return matrix;
}

void MatrixInitialization(Matrix matrix) {
    matrix[0][0] = 7;
    matrix[0][1] = 4;
    matrix[0][2] = 2;
    matrix[0][3] = 1;
    matrix[1][0] = 11;
    matrix[1][1] = 8;
    matrix[1][2] = 5;
    matrix[1][3] = 3;
    matrix[2][0] = 14;
    matrix[2][1] = 12;
    matrix[2][2] = 9;
    matrix[2][3] = 6;
    matrix[3][0] = 16;
    matrix[3][1] = 15;
    matrix[3][2] = 13;
    matrix[3][3] = 10;
}

void FreeMatrix(Matrix matrix, int32_t height) {
    for (int32_t i = 0; i < height; ++i) {
        free(matrix[i]);
    }
    free(matrix);
}

bool CanMoveRightDown(int32_t height, int32_t width, int32_t temp_x, int32_t temp_y) {
    return ((temp_x <= width - 1) || (temp_y <= height - 1));
}

bool TouchesMatrixBounds(int32_t height, int32_t width, int32_t temp_x, int32_t temp_y) {
    return (temp_x == width || temp_y == height);
}

int32_t* MatrixLinearization(Matrix matrix, int32_t height, int32_t width) {
    int32_t* linearized_matrix = (int32_t*)malloc(sizeof(int32_t) * width * height);
    int32_t y_pos = 0;
    int32_t x_pos = width - 1;
    int32_t item_counter = 0;
    int32_t temp_y = 0;
    int32_t temp_x = 0;
    while (item_counter < height * width) {
        temp_y = y_pos;
        temp_x = x_pos;
        while (CanMoveRightDown(height, width, temp_x, temp_y)) {
            linearized_matrix[item_counter] = matrix[temp_y][temp_x];
            ++temp_y;
            ++temp_x;
            ++item_counter;
            if (TouchesMatrixBounds(height, width, temp_x, temp_y)) {
                if (x_pos != 0) {
                    --x_pos;
                } else {
                    ++y_pos;
                }
                break;
            }
        }
    }
    return linearized_matrix;
}

void PrintMatrix(const Matrix matrix, int32_t height, int32_t width) {
    for (int32_t i = 0; i < height; ++i) {
        for (int32_t j = 0; j < width; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void PrintLinearizedMatrix(const int32_t* linearized_matrix, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        printf("%d ", linearized_matrix[i]);
    }
}

int Task() {
    int32_t height = 4;
    int32_t width = 4;

    Matrix matrix = CreateMatrix(height, width);
    MatrixInitialization(matrix);
    printf("Just a regular 4 by 4 matrix:\n");
    PrintMatrix(matrix, height, width);

    int32_t* linearized_matrix = MatrixLinearization(matrix, height, width);

    printf("Successfuly linearized matrix:\n");
    PrintLinearizedMatrix(linearized_matrix, height * width);

    free(linearized_matrix);
    FreeMatrix(matrix, height);
    return 0;
}
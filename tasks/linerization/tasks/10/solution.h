#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef int32_t** Matrix;
typedef int32_t* Row;

void FillMatrix(Matrix matrix) {
    matrix[0][0] = 7;
    matrix[0][1] = 6;
    matrix[0][2] = 2;
    matrix[0][3] = 1;
    matrix[1][0] = 13;
    matrix[1][1] = 8;
    matrix[1][2] = 5;
    matrix[1][3] = 3;
    matrix[2][0] = 14;
    matrix[2][1] = 12;
    matrix[2][2] = 9;
    matrix[2][3] = 4;
    matrix[3][0] = 16;
    matrix[3][1] = 15;
    matrix[3][2] = 11;
    matrix[3][3] = 10;
}

void Linerization(Matrix matrix, Row lin_matrix, size_t n, size_t m) {
    size_t element = 0;
    size_t quantity_elements_on_diagonal = 1;
    size_t i = m - 4;
    size_t j = n - 1;

    while (quantity_elements_on_diagonal <= 4) {
        for (size_t counter = 0; counter < quantity_elements_on_diagonal; ++counter) {
            lin_matrix[element++] = matrix[i][j];
            if (counter != quantity_elements_on_diagonal - 1) {
                if (quantity_elements_on_diagonal % 2 == 0) {
                    ++i;
                    ++j;
                } else {
                    --i;
                    --j;
                }
            }
        }
        if (quantity_elements_on_diagonal % 2 == 0) {
            ++i;
        } else {
            --j;
        }
        ++quantity_elements_on_diagonal;
    }

    --i;
    --j;
    quantity_elements_on_diagonal -= 2;

    while (quantity_elements_on_diagonal > 0) {
        for (size_t counter = 0; counter < quantity_elements_on_diagonal; ++counter) {
            lin_matrix[element++] = matrix[i][j];
            if (counter != quantity_elements_on_diagonal - 1) {
                if (quantity_elements_on_diagonal % 2 == 0) {
                    ++i;
                    ++j;
                } else {
                    --i;
                    --j;
                }
            }
        }

        if (quantity_elements_on_diagonal % 2 == 0) {
            --j;
        } else {
            ++i;
        }
        --quantity_elements_on_diagonal;
    }
}

void PrintMatrix(Matrix matrix, size_t n, size_t m) {
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void PrintRow(Row row, size_t n) {
    for (size_t i = 0; i < n; ++i) {
        printf("%d ", row[i]);
    }
    printf("\n");
}

const size_t N = 4;
const size_t M = 4;

int Task() {
    Row lin_matrix = (Row)calloc(N * M, sizeof(Row));
    Matrix matrix = (Matrix)calloc(N, sizeof(Row));
    for (size_t i = 0; i < N; ++i) {
        matrix[i] = (Row)calloc(M, sizeof(Row));
    }

    FillMatrix(matrix);
    Linerization(matrix, lin_matrix, N, M);

    PrintMatrix(matrix, N, M);
    printf("\n");
    PrintRow(lin_matrix, N * M);

    for (size_t i = 0; i < N; ++i) {
        free(matrix[i]);
    }
    free(matrix);
    free(lin_matrix);

    return 0;
}

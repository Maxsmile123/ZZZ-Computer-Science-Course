#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef int32_t** Matrix;

Matrix CreateMatrix(int32_t size) {
    Matrix matrix = (Matrix)malloc(size * sizeof(int32_t*));
    for (int32_t i = 0; i < size; ++i) {
        matrix[i] = (int32_t*)malloc(size * sizeof(int32_t));
    }
    return matrix;
}

Matrix CopyMatrix(const Matrix matrix, int32_t size) {
    Matrix new_matrix = CreateMatrix(size);
    for (int32_t i = 0; i < size; ++i) {
        for (int32_t j = 0; j < size; ++j) {
            new_matrix[i][j] = matrix[i][j];
        }
    }
    return new_matrix;
}

int32_t ReadMatrixFromFile(const char* file_name, Matrix matrix, int32_t size) {
    FILE* file = fopen(file_name, "r");
    if (file != NULL) {
        for (int32_t i = 0; i < size; ++i) {
            for (int32_t j = 0; j < size; ++j) {
                fscanf(file, "%i", &matrix[i][j]);
            }
        }
        fclose(file);
        return 1;
    } else {
        printf("File opening error!\n");
        return 0;
    }
}

void PrintMatrix(const Matrix matrix, int32_t size) {
    for (int32_t i = 0; i < size; ++i) {
        for (int32_t j = 0; j < size; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void FreeMatrix(Matrix matrix, int32_t size) {
    for (int32_t i = 0; i < size; ++i) {
        free(matrix[i]);
    }
    free(matrix);
}

int32_t MaxElemOfMatrix(const Matrix matrix, int32_t size) {
    int32_t max_elem = INT32_MIN;
    for (int32_t i = 0; i < size; ++i) {
        for (int32_t j = 0; j < size; ++j) {
            if (matrix[i][j] > max_elem) {
                max_elem = matrix[i][j];
            }
        }
    }
    return max_elem;
}

int32_t MinElemOfRow(const int32_t* row, int32_t size) {
    int32_t min_elem = INT32_MAX;
    for (int32_t i = 0; i < size; ++i) {
        if (row[i] < min_elem) {
            min_elem = row[i];
        }
    }
    return min_elem;
}

bool IsRowContainsElem(const int32_t* row, int32_t size, int32_t elem) {
    for (int32_t i = 0; i < size; ++i) {
        if (row[i] == elem) {
            return true;
        }
    }
    return false;
}

bool AreTwoRowsEqual(const int32_t* f_row, const int32_t* s_row, int32_t size) {
    for (int32_t i = 0; i < size; ++i) {
        if (f_row[i] != s_row[i]) {
            return false;
        }
    }
    return true;
}

int32_t* FindRowContainsElem(const Matrix matrix, int32_t size, int32_t elem, int32_t* exception) {
    for (int32_t i = 0; i < size; ++i) {
        if (IsRowContainsElem(matrix[i], size, elem) && !AreTwoRowsEqual(exception, matrix[i], size)) {
            return matrix[i];
        }
    }
    return NULL;
}

void ReplaceRow(int32_t* row_to_replace, const int32_t* replacement_row, int32_t size) {
    for (int32_t i = 0; i < size; ++i) {
        row_to_replace[i] = replacement_row[i];
    }
}

void ReplaceMatrixRows(Matrix original, Matrix copy, int32_t size) {
    int32_t max_elem = MaxElemOfMatrix(original, size);
    for (int32_t i = 0; i < size; ++i) {
        if (IsRowContainsElem(copy[i], size, max_elem)) {
            int32_t min_elem = MinElemOfRow(copy[i], size);
            int32_t* replacement_row = FindRowContainsElem(original, size, min_elem, copy[i]);
            if (replacement_row != NULL) {
                ReplaceRow(copy[i], replacement_row, size);
            } else {
                printf("No rows to replace\n");
            }
        }
    }
}

int Task() {
    int32_t size_of_matrix = 4;
    const char* file_path = "../tasks/matrix/tasks/29/matrix.txt";

    Matrix matrix = CreateMatrix(size_of_matrix);
    if (ReadMatrixFromFile(file_path, matrix, size_of_matrix) != 0) {
        printf("Default matrix:\n");
        PrintMatrix(matrix, size_of_matrix);
    } else {
        FreeMatrix(matrix, size_of_matrix);
        exit(EXIT_FAILURE);
    }

    Matrix new_matrix = CopyMatrix(matrix, size_of_matrix);
    ReplaceMatrixRows(matrix, new_matrix, size_of_matrix);
    printf("Updated matrix:\n");
    PrintMatrix(new_matrix, size_of_matrix);

    FreeMatrix(new_matrix, size_of_matrix);
    FreeMatrix(matrix, size_of_matrix);
    return 0;
}
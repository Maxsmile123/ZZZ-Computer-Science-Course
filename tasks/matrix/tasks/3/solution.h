#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef int32_t **Matrix;

int FindMax(Matrix matrix, int n, int m) {
    int count = 0;
    int maximal = 0;
    int max_summ = 0;
    for (int32_t i = 0; i < m; i++) {
        count = 0;
        for (int32_t j = 0; j < n; j++) {
            count += matrix[j][i];
        }
        if (count > max_summ) {
            max_summ = count;
            maximal = i;
        }
    }
    return maximal;
}

int FindMin(Matrix matrix, int n, int m) {
    int count = 0;
    int minimal = 0;
    int min_summ = 9999;
    for (int32_t i = 0; i < m; i++) {
        count = 0;
        for (int32_t j = 0; j < n; j++) {
            count = count + matrix[j][i];
        }
        if (count < min_summ) {
            min_summ = count;
            minimal = i;
        }
    }
    return minimal;
}

Matrix AllocateMatrix(int32_t rows, int32_t cols) {
    Matrix matrix = (Matrix)malloc(rows * sizeof(int32_t *));
    for (int32_t i = 0; i < rows; i++) {
        matrix[i] = (int32_t *)malloc(cols * sizeof(int32_t));
    }
    return matrix;
}

int Task() {
    FILE *file = fopen("../tasks/matrix/tasks/10/matrix.txt", "r");
    int n = 0;
    int m = 0;
    fscanf(file, "%d %d", &n, &m);
    Matrix matrix = AllocateMatrix(n, m);
    for (int32_t i = 0; i < n; i++) {
        for (int32_t j = 0; j < m; j++) {
            fscanf(file, "%d", &matrix[i][j]);
        }
    }
    int min = FindMin(matrix, n, m);
    int max = FindMax(matrix, n, m);
    int count = 0;
    printf("Updated Matrix:\n");
    for (int32_t i = 0; i < n; i++) {
        count = matrix[i][min];
        matrix[i][min] = matrix[i][max];
        matrix[i][max] = count;
    }
    for (int32_t i = 0; i < n; i++) {
        for (int32_t j = 0; j < m; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    fclose(file);
    return 0;
}

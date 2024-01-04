#pragma once

#include<stdio.h> 
#include<stdint.h> 
#include <stdlib.h>


struct Matrix {
    int32_t** data;
    size_t size;
};


struct Matrix create_matrix(const size_t size) {

    struct Matrix matrix;

    matrix.data = (int32_t**)malloc(size * sizeof(int32_t*));
    matrix.size = size;

    for(size_t i = 0; i < size; ++i) {
        matrix.data[i] = (int32_t*)malloc(size * sizeof(int32_t));
    }

    return matrix;

}


void clean_matrix(struct Matrix matrix) {

    for (size_t i = 0; i < matrix.size; ++i) {
        free(matrix.data[i]);
    }
    free(matrix.data);

}


void print_matrix(struct Matrix matrix) {

    for(size_t i = 0; i < matrix.size; ++i) {
        for(size_t j = 0; j < matrix.size; ++j) {
            printf("%d\t", matrix.data[i][j]);
        }

        printf("\n");
    }
}


struct Matrix matrix_from_file(FILE* file) {

    size_t n;
    fscanf(file, "%zu", &n);
    struct Matrix matrix = create_matrix(n);

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            fscanf(file, "%d", &matrix.data[i][j]);
        }
    }

    return matrix;
}


void replacing_elements(struct Matrix *matrix) {

    int32_t sum; 
    int32_t x;
    int32_t y;

    for (size_t i = 0; i < (*matrix).size; ++i) {

        sum = (*matrix).data[i][i];

        x = i;
        y = i;

        while (1) {
            x -= 1;
            y += 1;

            if (!(0 <= x && x < (int32_t)(*matrix).size && 0 <= y && y < (int32_t)(*matrix).size)) {
                break;
            }
            sum += (*matrix).data[x][y];
        }

        x = i;
        y = i;

        while (1) {
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

    FILE *file = fopen("matrix.txt", "r");

    if (file == NULL) {
        printf("Файл не открылся\n");
        return 0;
    }

    struct Matrix matrix = matrix_from_file(file); 

    replacing_elements(&matrix);

    print_matrix(matrix);

    clean_matrix(matrix);
    fclose(file);

    return 0; 
}

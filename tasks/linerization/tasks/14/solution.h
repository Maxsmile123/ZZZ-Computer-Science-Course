#pragma once

#include<stdio.h>
#include<stdint.h>
#include <stdlib.h>


const size_t N = 4;
const size_t M = 4;


struct Point {
    int32_t x;
    int32_t y;
}; 


struct Matrix {
    int32_t** data;
    size_t row;
    size_t line;
};


void fill_matrix(struct Matrix matrix) {
    matrix.data[0][0] = 1;
    matrix.data[1][1] = 2;
    matrix.data[2][2] = 3;
    matrix.data[3][3] = 4;
    matrix.data[2][3] = 5;
    matrix.data[1][2] = 6;
    matrix.data[0][1] = 7;
    matrix.data[3][2] = 8;
    matrix.data[2][1] = 9;
    matrix.data[1][0] = 10;
    matrix.data[2][0] = 11;
    matrix.data[3][1] = 12;
    matrix.data[0][2] = 13;
    matrix.data[1][3] = 14;
    matrix.data[0][3] = 15;
    matrix.data[3][0] = 16;
}


void print_matrix(struct Matrix matrix) {

    for(size_t i = 0; i < matrix.line; ++i) {

        for(size_t j = 0; j < matrix.row; ++j) {
            printf("%d\t", matrix.data[i][j]);
        }

        printf("\n");
    }
}


void print_arr(int32_t* arr, size_t size) {

    for (size_t i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }

    printf("\n");

}


struct Matrix create_matrix(size_t rows, size_t line) {

    struct Matrix matrix;

    matrix.data = (int32_t**)malloc(rows * sizeof(int32_t*));
    matrix.line = N;
    matrix.row = M;

    for(size_t i = 0; i < line; ++i) {
        matrix.data[i] = (int32_t*)malloc(line * sizeof(int32_t));
    }

    return matrix;

}


void clean_matrix(struct Matrix matrix) {

    for (size_t i = 0; i < matrix.line; ++i) {
        free(matrix.data[i]);
    }

    free(matrix.data);
    
}


void fooR(struct Matrix matrix, int32_t* arr, int32_t *pos, struct Point *a) {

    while ((*a).x < (int32_t)matrix.row && (*a).y < (int32_t)matrix.line) {
        arr[*pos] = matrix.data[(*a).x][(*a).y];
        (*a).x += 1;
        (*a).y += 1;
        *pos += 1;
    }

    (*a).y -= 1;
    (*a).x -= 2;

    while ((*a).x >= 0 && (*a).y >= 0) {
        arr[*pos] = matrix.data[(*a).x][(*a).y];
        (*a).x -= 1;
        (*a).y -= 1;
        *pos += 1;
    }

    (*a).y += 2;
    (*a).x += 1;

}


void fooL(struct Matrix matrix, int32_t* arr, int32_t *pos, struct Point *a) {

    while ((*a).x >= 0 && (*a).y >= 0) {
        arr[*pos] = matrix.data[(*a).x][(*a).y];
        (*a).x -= 1;
        (*a).y -= 1;
        *pos += 1;
    }

    (*a).y += 1;
    (*a).x += 2;

    while ((*a).x < (int32_t)matrix.row && (*a).y < (int32_t)matrix.line) {
        arr[*pos] = matrix.data[(*a).x][(*a).y];
        (*a).x += 1;
        (*a).y += 1;
        *pos += 1;
    }

    (*a).y -= 2;
    (*a).x -= 1;

}


int32_t* lin(struct Matrix matrix) {

    int32_t* arr = (int32_t*)malloc(matrix.row * matrix.line * sizeof(int32_t));
    int32_t k = 0;

    struct Point right = {0, 0};
    struct Point left = {(int32_t)(matrix.row - 1), (int32_t)(matrix.line - 2)};


    while (k < (int32_t)(matrix.row * matrix.line)) {
        fooR(matrix, arr, &k, &right);
        fooL(matrix, arr, &k, &left);
    }

    return arr;

}


int Task() {

    struct Matrix matrix = create_matrix(N, M);
    fill_matrix(matrix); 
    // print_matrix(matrix);

    int32_t* arr = lin(matrix);
    print_arr(arr, matrix.row * matrix.line);

    clean_matrix(matrix);
    free(arr);

    return 0;

}

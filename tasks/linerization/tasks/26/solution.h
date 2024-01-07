#pragma once

#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void Left(int *x, int *y, int *posx, int *posy, int mtr[4][4]) {
    for (int i = 0; i < *x; ++i) {
        *posx -= 1;
        printf("%d ", mtr[*posy][*posx]);
    }
    *y -= 1;
}

void Up(int *x, int *y, int *posx, int *posy, int mtr[4][4]) {
    for (int i = 0; i < *y; i++) {
        *posy -= 1;
        printf("%d ", mtr[*posy][*posx]);
    }
    *x -= 1;
}

void Right(int *x, int *y, int *posx, int *posy, int mtr[4][4]) {
    for (int i = 0; i < *x; i++) {
        *posx += 1;
        printf("%d ", mtr[*posy][*posx]);
    }
    *y -= 1;
}

void Down(int *x, int *y, int *posx, int *posy, int mtr[4][4]) {
    for (int i = 0; i < *y; i++) {
        *posy += 1;
        printf("%d ", mtr[*posy][*posx]);
    }
    *x -= 1;
}

int Task() {
    int mtr[4][4] = {{7, 8, 9, 10}, {6, 15, 16, 11}, {5, 14, 13, 12}, {4, 3, 2, 1}};
    for (size_t i = 0; i < (sizeof(mtr) / sizeof(mtr[0])); ++i) {
        for (size_t j = 0; j < (sizeof(mtr[0]) / sizeof(int)); ++j) {
            printf("%d ", mtr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    int posx = (sizeof(mtr[0]) / sizeof(int));
    int posy = ((sizeof(mtr) / sizeof(mtr[0])) - 1);
    int x = (sizeof(mtr[0]) / sizeof(int));
    int y = (sizeof(mtr) / sizeof(mtr[0]));
    while (x > 0 && y > 0) {
        Left(&x, &y, &posx, &posy, mtr);
        if (x == 0 || y == 0) {
            break;
        }
        Up(&x, &y, &posx, &posy, mtr);
        if (x == 0 || y == 0) {
            break;
        }
        Right(&x, &y, &posx, &posy, mtr);
        if (x == 0 || y == 0) {
            break;
        }
        Down(&x, &y, &posx, &posy, mtr);
        if (x == 0 || y == 0) {
            break;
        }
    }
    printf("\n \n");
    return 0;
}

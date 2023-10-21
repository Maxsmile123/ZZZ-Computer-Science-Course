#pragma once

#include <stdio.h>

// block constants

const int MAX_ITERATIONS = 50;
const int CORD_X1 = -10;
const int CORD_Y1 = -10;
const int CORD_X2 = -20;
const int CORD_Y2 = -20;
const int RAD = 10;

typedef struct {
    int x;
    int y;
} Point;

int CheckZone(Point p) {
    int first_x = (p.x - CORD_X1) * (p.x - CORD_X1);
    int first_y = (p.y - CORD_Y1) * (p.y - CORD_Y1);
    int rad_square = RAD * RAD;
    int second_x = (p.x - CORD_X2) * (p.x - CORD_X2);
    int second_y = (p.y - CORD_Y2) * (p.y - CORD_Y2);
    if ((first_x + first_y <= rad_square) && (second_x + second_y <= rad_square)) {
        return 1;
    } else {
        return 2;
    }
}

// This Function find maximum of two numbers

int Max(int first_number, int second_number) {
    return (first_number > second_number) ? first_number : second_number;
}

// This Function return sign of number

int Sign(int number) {
    if (number < 0) {
        return -1;
    } else if (number > 0) {
        return 1;
    }
    return 0;
}

int Module(int number) {
    return (number >= 0) ? number : number * (-1);
}

int Task() {
    const int i_start = 5;
    const int j_start = 5;
    const int l_start = 4;
    const int chiclo_3 = 3;
    const int chiclo_10 = 10;
    const int chiclo_5 = 5;
    int i_0 = i_start;
    int j_0 = j_start;
    int l_0 = l_start;
    int i_1 = 0;
    int j_1 = 0;
    int l_1 = 0;
    for (int i = 0; i < MAX_ITERATIONS; ++i) {
        Point p;
        p.x = i_0;
        p.y = j_0;
        if (CheckZone(p) == 1) {
            printf("x = %d, y = %d\n", i_0, j_0);
        } else {
            printf("Point out of range");
        }
        i_1 = i_0 / chiclo_3 - Module(i_0 - i) * Sign(l_0 - j_0);
        j_1 = j_0 % chiclo_10 - Max(i_0, l_0) % (i + 1);
        l_1 = i_0 + (j_0 * i) % chiclo_5 + l_0 / chiclo_5 + chiclo_3;
        i_0 = i_1;
        l_0 = l_1;
        j_0 = j_1;
    }
    return 0;
}
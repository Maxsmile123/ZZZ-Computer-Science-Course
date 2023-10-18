#pragma once

#include <stdio.h>

// block constants

const int ITERATIONS = 50;
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
    int cord_x = p.x;
    int cord_y = p.y;
    int first_x = (cord_x - CORD_X1) * (cord_x - CORD_X1);
    int first_y = (cord_y - CORD_Y1) * (cord_y - CORD_Y1);
    int rad_square = RAD * RAD;
    int second_x = (cord_x - CORD_X2) * (cord_x - CORD_X2);
    int second_y = (cord_y - CORD_Y2) * (cord_y - CORD_Y2);
    if ((first_x + first_y <= rad_square) && (second_x + second_y <= rad_square)) {
        return 1;
    } else {
        return 2;
    }
}

// This Function find maximum of two numbers

int Max(int first_chiclo, int second_chiclo) {
    return (first_chiclo > second_chiclo) ? first_chiclo : second_chiclo;
}

// This Function returning sign of number

int Sign(int chiclo) {
    if (chiclo < 0) {
        return -1;
    } else if (chiclo > 0) {
        return 1;
    }
    return 0;
}

// This Function return module number

int Module(int chiclo) {
    return (chiclo >= 0) ? chiclo : chiclo * (-1);
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
    for (int i = 0; i < ITERATIONS; ++i) {
        Point p;
        p.x = i_0;
        p.y = j_0;
        int i_1 = 0;
        int j_1 = 0;
        if (CheckZone(p) == 1) {
            printf("x = %d, y = %d\n", i_0, j_0);
        }
        if (i_0 >= i) {
            i_1 = i_0 / chiclo_3 - (i_0 - i) * Sign(l_0 - j_0);
        } else {
            i_1 = i_0 / chiclo_3 + (i_0 - i) * Sign(l_0 - j_0);
        }
        j_1 = Module(j_0) % chiclo_10 - Module(Max(i_0, l_0)) % (i + 1);
        int l_1 = i_0 + Module((j_0 * i)) % chiclo_5 + l_0 / chiclo_5 + chiclo_3;
        i_0 = i_1;
        l_0 = l_1;
        j_0 = j_1;
    }
    return 0;
}
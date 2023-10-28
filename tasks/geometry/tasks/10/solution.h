#pragma once
#include <stdio.h>

const int ONE = 1;
const int TWENTY_FVIE = 25;
const int THIRTY = 30;
const int INITUAL_I = 24;
const int INITUAL_J = -14;
const int INITUAL_L = 9;
const int ITERATIONS = 50;
const int X_MIN = 5;
const int X_MAX = 15;
const int Y_MIN = 5;
const int Y_MAX = 15;

typedef struct {
    int x;
    int y;
} Point;

int Mod(int number_1, int number_2) {
    if (number_2 != 0) {
        if (number_1 * number_2 > 0) {
            return number_1 % number_2;
        } else {
            return number_2 + (number_1 % number_2);
        }
    } else {
        return 0;
    }
}

int Abs(int number) {
    if (number < 0) {
        return -number;
    } else {
        return number;
    }
}

int Max(int number_1, int number_2) {
    if (number_1 > number_2) {
        return number_1;
    } else {
        return number_2;
    }
}

int Min(int number_1, int number_2) {
    if (number_1 < number_2) {
        return number_1;
    } else {
        return number_2;
    }
}

int Sign(int number) {
    if (number > 0) {
        return 1;
    } else if (number < 0) {
        return -1;
    } else {
        return 0;
    }
}

int CheckZone(Point p) {
    return (p.y >= Y_MIN) && (p.y <= Y_MAX) && (p.x >= X_MIN) && (p.x <= Y_MAX);
}

int Task() {
    Point p;
    int i = INITUAL_I;
    int j = INITUAL_J;
    int l = INITUAL_L;
    p.x = i;
    p.y = j;
    int point_in_zone_count = 0;
    for (int k = ONE; k <= ITERATIONS; ++k) {
        i = Mod((p.x + k) * (p.y - k) * (l + k), TWENTY_FVIE);
        j = Mod(Min((p.y + k), Max((p.y - k), (l - k))), THIRTY);
        l = Abs(p.y - l) * Sign(p.x) - Abs(p.x - l) * Sign(p.y);
        p.x = i;
        p.y = j;
        if (CheckZone(p)) {
            ++point_in_zone_count;
        }
        printf("k = %d, x = %d, y = %d, l = %d passed = %d \n", k, p.x, p.y, l, CheckZone(p));
    }
    if (point_in_zone_count == 0) {
        printf("The point did not fall into the area beyond 50 iterations\n");
    } else {
        printf("Number of points belonging to the zone: %d\n", point_in_zone_count);
    }
    return 0;
}
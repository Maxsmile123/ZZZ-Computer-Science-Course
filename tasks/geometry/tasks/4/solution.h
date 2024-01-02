#pragma once

#include <stdio.h>

typedef struct {
    int x;
    int y;
} Point;

const Point CENTER = {10, 10};
const int RADIUS_OF_INNER = 5;
const int RADIUS_OF_OUTER = 10;
const int I0 = 26;
const int J0 = 8;
const int L0 = -3;
const int MAX_ITERATIONS = 50;
const int ONE = 1;
const int TEN = 10;
const int TWENTY = 20;
const int THIRTY = 30;

int Sign(int num) {
    return num > 0 ? 1 : num < 0 ? -1 : 0;
}

int Max(int first, int second, int third) {
    return first > second ? first > third ? first : third : second > third ? second : third;
}

int Min(int first, int second) {
    return first < second ? first : second;
}

int Mod(int num, int del) {
    return (num % del + del) % del;
}

int Abs(int num) {
    return num * Sign(num);
}

int CheckZone(Point p) {
    int projection_on_x = Abs(p.x - CENTER.x);
    int projection_on_y = Abs(p.y - CENTER.y);
    int square_of_distance = projection_on_x * projection_on_x + projection_on_y * projection_on_y;
    return (square_of_distance <= RADIUS_OF_OUTER * RADIUS_OF_OUTER &&
            square_of_distance >= RADIUS_OF_INNER * RADIUS_OF_INNER);
}

int Task() {
    int is_inside = 0;
    int is_not_inside = 1;
    int i = 0;
    int j = 0;
    int l = L0;
    Point p = {I0, J0};
    for (int k = 1; k <= MAX_ITERATIONS; ++k) {
        i = Mod((Min(p.x + p.y, p.x + l) * (k + ONE)), THIRTY);
        j = p.y + Mod(l * Sign(p.y), TWENTY) + Mod(k * Sign(p.x), TEN);
        l = Mod(Max(p.x * p.y, p.x * l, p.y * l), THIRTY);
        p.x = i;
        p.y = j;
        is_inside = CheckZone(p);
        if (is_inside) {
            printf("The point fell into the specified area at x = %d, y = %d, l = %d, iteration = %d\n", p.x, p.y, l,
                   k);
            is_not_inside = 0;
        } else {
            printf("iteration = %i, x = %i, y = %i, l = %i, result = %i\n", k, p.x, p.y, l, is_inside);
        }
    }
    if (is_not_inside) {
        printf("The point did not hit the area in 50 iterations");
    }
    return 0;
}

#include <stdio.h>

const int I = -22;
const int J = 14;
const int L = -14;
const int STEPS = 50;
const int COND_1 = -10;
const int COND_2 = -20;
const int ONE = 1;
const int TWENTY = 20;
const int TWENTY_FIVE = 25;
const int TEN = 10;
const int ZERO = 0;
const int MINUS_ONE = -1;

int Mod(int x, int y) {
    if (y != ZERO) {
        return x % y;
    } else {
        return 0;
    }
}

int Pow2(int a) {
    return ONE << a;
}

int Sign(int a) {
    if (a > ZERO) {
        return 1;
    } else if (a < ZERO) {
        return MINUS_ONE;
    } else {
        return 0;
    }
}

int Max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int Min(int a, int b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

typedef struct {
    int x;
    int y;
} Point;

int CheckZone(Point p) {
    return (p.x + p.y >= COND_1 && p.x + p.y <= COND_2);
}

int Task() {
    int counter = ZERO;
    int i = I;
    int j = J;
    int l = L;
    Point p;
    p.x = i;
    p.y = j;
    for (int k = ONE; k <= STEPS; ++k) {
        i = Mod((p.x * Min(p.y, l) + p.y * Min(p.x, l) + Pow2(k)), TWENTY);
        j = Mod((Mod(p.x, TEN - k) * (Mod(p.y, TEN + k)) * (Mod(l, TEN - k))), TWENTY_FIVE);
        l = Max(Mod(Min(p.x + p.y, p.x + l), TWENTY_FIVE), Mod(Max(p.x + l, p.y + k), TWENTY)) + TEN;
        if (CheckZone(p)) {
            counter += ONE;
        }
    }
    if (counter > ZERO) {
        printf("Number of points belonging to the zone: %d\n", counter);
    } else {
        printf("The point didn't fall into the area beyond 50 iterations\n");
    }
    return 0;
}

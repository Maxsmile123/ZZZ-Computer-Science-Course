#include <stdio.h>

const int MINUS_TEN = -10;
const int TEN = 10;
const int TWENTY = 20;
const int INITIAL_I = 8;
const int INITIAL_J = 15;
const int INITIAL_L = 10;
const int Y_0 = 10;
const int X_0 = -10;
const int ITERATIONS = 50;
const int ONE = 1;
const int MINUS_ONE = -1;
const int THITRY = 30;


int Abs(int number) {
    return (number >= 0) ? number : -number;
}


// Function return mod of numbers
int Mod(int number_1, int number_2) {
    if (number_2 != 0) {
        return (Abs(number_1 % number_2));
    } else {
        return 0;
    }
}


// Function of return sign of numbers
int Sign(int number_1) {
    if (number_1 > 0) {
        return 1;
    } else if (number_1 < 0) {
        return -1;
    } else {
        return 0;
    }
    
}

// Function for maximum of numbers
int Max(int number_1, int number_2) {
    return (number_1 >= number_2) ? number_1 : number_2;
}

// Function minimen of numbers
int Min(int number_1, int number_2) {
    return (number_1 >= number_2) ? number_2 : number_1;
}
int Module(int number_1) {
    return (number_1 >= 0) ? number_1 : number_1 * MINUS_ONE;
}

typedef struct {
    int x;
    int y;
} Point;

int CheckZone(Point p) {
    return ((p.x + Y_0 <= p.y) && ((MINUS_ONE * p.x) + Y_0 >= p.y) && (p.x >= X_0));
}

int Task() {
    int i = INITIAL_I;
    int j = INITIAL_J;
    int l = INITIAL_L;
    Point p;
    p.x = i;
    p.y = j;
    int in_zone_counter = 0;
    for (int k = ONE; k <= ITERATIONS; ++k) {
        i = Mod(Mod((p.x + p.y), ((Module(Min(p.y - l, l - k)) + ONE) - k)), TWENTY) + TEN;
        j = Max((p.x + p.y) / (2 + Sign((p.y * k) - (p.x * k))), (p.y + l) / (2 + Sign((p.x * p.y) - (l * k)))) - TEN;
        l = Mod(Max(p.x, p.y) * Min(p.x, l), THITRY);
        p.x = i;
        p.y = j;
        if (CheckZone(p)) {
            ++in_zone_counter;
        }
        printf("k = %d, x = %d, y = %d, l = %d passed = %d \n", k, p.x, p.y, l, CheckZone(p));

    }
    if (in_zone_counter == 0) {
        printf("The point did not fall into the area beyond 50 iterations\n");
    } else {
        printf("Number of points belonging to the zone: %d\n", in_zone_counter);
    }
    return 0;
}
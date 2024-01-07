#pragma once

#include <float.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <tgmath.h>

long double Func1(long double x) {
    return (sinl(logl(x)) - cosl(logl(x)) + 2.0 * logl(x));
}

long double Fi(long double x) {
    return (x - 2.0 + sinl(1.0 / x));
}

int Task() {
    long double x0 = 1.0;
    long double x1 = 3.0;
    long double eps = DBL_EPSILON;
    long double center_x = abs(x0 + x1) / 2.0;
    long double f_center_x = Func1(center_x);
    while (abs(f_center_x) >= eps) {
        if (f_center_x > 0) {
            x1 = center_x;
        } else {
            x0 = center_x;
        }
        center_x = abs(x0 + x1) / 2.0;
        f_center_x = Func1(center_x);
    }
    printf("%Lf\n", center_x);
    x0 = 1.2;
    x1 = (1.2 + 2.0) / 2.0;
    while (abs((Fi(x1) - x1) / (1 - ((Fi(x1) - x1) / (x1 - x0)))) >= eps) {
        x0 = x1;
        x1 = x1 - Fi(x1);
    }
    printf("%Lf\n", x1 - Fi(x1));
    return 0;
}

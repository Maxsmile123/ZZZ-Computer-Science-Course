#pragma once

#include <float.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>

double Func1(double x) {
    return (sqrt(1 - x) - tan(x));
}

double Func2(double x) {
    return (-cos(pow(x, 0.52) + 2));
}

double Dich(double a, double b, double (*func)(double)) {
    double mdl = NAN;
    while ((b - a) > DBL_EPSILON) {
        mdl = (a + b) / 2;
        if ((func(a) < 0 && func(mdl) > 0) || (func(a) > 0 && func(mdl) < 0)) {
            b = mdl;
        } else {
            a = mdl;
        }
    }
    return ((b + a) / 2);
}

double Iter(double a, double b, double (*func)(double)) {
    double value0 = (a + b) / 2;
    double value1 = NAN;
    double value2 = NAN;
    value1 = func(value0);
    value2 = func(value1);
    double stop = fabs((value2 - value1) / (1 - ((value2 - value1) / (value1 - value0))));
    while (stop > DBL_EPSILON) {
        value0 = value1;
        value1 = value2;
        value2 = func(value1);
        stop = fabs((value2 - value1) / (1 - ((value2 - value1) / (value1 - value0))));
    }
    return value2;
}

int Task() {
    // write your solution here
    printf("Корень 1ого уравнения, полученный методом дихотомии: %.4f\n", Dich(0, 1, Func1));
    printf("Корень 2ого уравнения, полученный методом итераций: %.4f\n", Iter(0.5, 1, Func2));
    return 0;
}

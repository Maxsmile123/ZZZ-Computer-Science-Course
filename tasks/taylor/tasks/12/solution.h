#pragma once

#include <float.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>

#define ld long double

long double Func(long double x) {
    return powl(3, x);
}

void TableLinePrinter() {
    printf("=========================================================================\n");
}

void TableHeaderPrinter() {
    TableLinePrinter();
    printf("                 Machine epsilon for long double type:\n");
    printf("   %.64Lf\n", LDBL_EPSILON);
    printf("\n");
    printf("             Table of values of the Taylor series and the\n");
    printf("         standard function for f(x) = 3^x\n");
    TableLinePrinter();
    printf("      x     |       Taylor        |       Function      |   Iterations\n");
    TableLinePrinter();
}

void TableFiller(ld x_val, ld tailor, ld func, int32_t iter_num) {
    printf("  %Lf  |  %.15Lf  |  %.15Lf  |       %d\n", x_val, tailor, func, iter_num);
}

int Task() {
    double a = 0.0;
    double b = 1.0;
    int32_t n = 5;
    int32_t k = 50;
    ld factorial = 0;
    ld tailor = 0;
    ld func = 0;
    if (n <= 1 || k < 1 || k > LDBL_MANT_DIG) {
        printf("Incorrect values have been entered.");
    } else {
        TableHeaderPrinter();
        ld step = (b - a) / (double)(n - 1);
        ld precision = LDBL_EPSILON * k;
        ld x_value = a;
        for (int i = 0; i < n; ++i) {
            factorial = 1.0;
            tailor = 1.0;
            func = Func(x_value);
            int32_t iteration_num = 0;
            ld extension = LDBL_MAX;
            while (fabsl(extension) >= precision) {
                iteration_num += 1;
                factorial *= iteration_num;
                extension = powl(log(3), iteration_num) / factorial * powl(x_value, iteration_num);
                tailor += extension;
            }
            TableFiller(x_value, tailor, func, iteration_num);
            x_value += step;
        }
        TableLinePrinter();
    }
    return 0;
}

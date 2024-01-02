#pragma once

#include <float.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>

const double EPSILON = DBL_EPSILON * 100000.0;

// МЕТОД ПРОСТЫХ ИТЕРАЦИЙ
double IterationMethod(double left, double right, double (*phi)(double xn)) {
    double x_last = 0.0;
    double x_current = (left + right) / 2;
    while (fabs(x_current - x_last) >= EPSILON) {
        x_last = x_current;
        x_current = phi(x_last);
    }
    return x_current;
}

// МЕТОД НЬЮТОНА
double NewtonMethod(double left, double right, double (*func)(double xn), double (*dfunc)(double xn)) {
    double x_last = 0.0;
    double x_current = (left + right) / 2;
    while (fabs(x_current - x_last) >= EPSILON) {
        x_last = x_current;
        x_current = x_last - func(x_last) / dfunc(x_last);
    }
    return x_current;
}

// дальше функции из условия

// возведение в целую степень
double Bpow(double n, int m) {
    double answer = 1.0;
    double a = n;
    while (m != 0) {
        if (m % 2) {
            answer *= a;
        }
        a *= a;
        m /= 2;
    }
    return answer;
}

// мне стало интересно, как возводить в нецелую степень
// (но я не нашёл, как это делается для иррациональных степеней)

// возведение в нецелую степень
double ToPower052(double a) {
    double x_last = 0.0;
    double x_current = (a < 1) ? a : a / 2;  // насчёт оптимального предположения идей нет

    // 0.52 = 13 / 25
    a = Bpow(a, 13);
    int n = 25;

    // здесь должен быть критерий остановки, который написан на гитхабе, но мне кажется это немного избыточным,
    // потому что суть одна и та же, а лишнее считать не хочется (к тому же придётся хранить ещё одну переменную)
    while (fabs(x_last - x_current) >= EPSILON) {
        x_last = x_current;
        x_current = (1.0 / n) * ((n - 1) * x_last + a / Bpow(x_last, n - 1));
    }
    return x_current;
}

// функция для итеративного метода
double Phi(double x) {
    return -cos(ToPower052(x) + 2);
}

// функция для метода Ньютона
double Function(double x) {
    double ln_x = log(x);
    return 3 * Bpow(ln_x, 2) + 6 * ln_x - 5;
}

// производная функции для метода Ньютона
double DerivativeFunction(double x) {
    return 6.0 * (log(x) + 1) / x;
}

const double ANSWER_ITERATION_METHOD = 0.9892;
const double ANSWER_NEWTON_METHOD = 1.8832;

int Task() {
    printf("Equation:  x + cos(x ^ 0.52 + 2) = 0: \n(iteration method) %.10lf, answer: %.4lf\n",
           IterationMethod(0.5, 1.0, Phi), ANSWER_ITERATION_METHOD);
    printf("\n");
    printf("Equation:  3 * ln^2(x) + 6 * ln(x) - 5: \n(Newton method) %.10lf, answer: %.4lf\n",
           NewtonMethod(1.0, 3.0, Function, DerivativeFunction), ANSWER_NEWTON_METHOD);
    return 0;
}
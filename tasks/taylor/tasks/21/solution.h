#pragma once

#include <stdint.h>
#include <stdio.h>
#include <float.h>
#include <math.h>

long double Func(long double x) {
    return (((x * x) / 4) + (x / 2) + 1) * expl(x / 2);
}

long double Factorial(int32_t x) {
    if (x == 0 || x == 1) {
        return 1.0;
    }
    return x * Factorial(x - 1);
}

// функция для вывода заголовка таблицы
void tableTitle() {
    printf("       Taylor series values table for f(x) = ((x^2 / 4) + (x / 2) + 1) * e^x/2\n");
    printf(" ----------------------------------------------------------------------------------\n");
    printf("|    X   |    Taylor series    |      Function       | Iters |      Difference     |\n");
    printf("---------+---------------------+---------------------+-------+----------------------\n");
}

// функция вывода строки в таблицу для заданных значений "x"
void lineOutput(long double x, long double seriesSum, int iter) {
    printf("| %6.2Lf | % 19.15Lf | % 19.15Lf | %5d | % 19.15Lf |\n", x, seriesSum, Func(x), iter, fabsl(Func(x) - seriesSum));
}

int main() {
    // данные границы из условия
    const long double startA = 0.1;
    const long double endB = 0.6;

    // задаем кол-во итераций для n
    int32_t n = 10;
    // задаем значение для m
    int32_t m = 50;

    // точность вычислений
    const long double calculationAccuracy = LDBL_EPSILON * m;
    // шаг итераций
    const long double iterationStep = (endB - startA) / n;

    // вывод заголовка таблицы
    tableTitle();

    for (long double x = startA; x <= endB; x += iterationStep) {
        // сумма ряда
        long double seriesSum = 0;
        // кол-во итераций
        int iterations = 0;

        // вычисление ряда Тейлора
        while (fabsl(seriesSum - Func(x)) >= calculationAccuracy) {
            long double current_term = (powl(iterations, 2) + 1) / Factorial(iterations) * powl((x / 2), iterations);
            seriesSum += current_term;
            ++iterations;
        }
        // вывод получившихся значений
        lineOutput(x, seriesSum, iterations);
    }

    return 0;
}

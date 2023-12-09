#pragma once

#include <float.h>
#include <math.h>
#include <stdio.h>

// Итерационная функция для первого уравнения
double FirstEquation(double x) {
    return 0.4 + atan(sqrt(x));
}

// Итерационная функция для второго уравнения
double SecondEquation(double x) {
    return (3.8 - 3 * sin(sqrt(x))) / 0.35;
}

// Функция для выполнения итерационного процесса с критерием остановки
double EquationSolve(double (*equation_func)(double), double initial_approximation, const int max_iterations) {
    double x = initial_approximation;  // Начальное приближение
    double prev_x = 0.0;  // Переменная для хранения предыдущего значения x

    for (int iteration = 0; iteration < max_iterations; iteration++) {
        prev_x = x;            // Сохраняем текущее значение x
        x = equation_func(x);  // Обновляем значение x

        if (fabs(x - prev_x) < DBL_EPSILON)  // Проверяем, меньше ли разница между итерациями DBL_EPSILON
        {
            break;  // Если да, прерываем итерационный процесс
        }
    }

    return x;  // Возвращаем значение x после всех итераций или при достижении критерия остановки
}

int Task() {
    const double initial_approximation_1 = 1.5;  // Начальное приближение для первого уравнения
    const double initial_approximation_2 = 2.5;  // Начальное приближение для второго уравнения
    const int max_iterations = 100;  // Максимальное количество итераций

    // Решение первого уравнения
    double solution_1 = EquationSolve(FirstEquation, initial_approximation_1, max_iterations);
    printf("Ожидалось для первого уравнения: x = 1.2388\n");
    printf("Решение первого уравнения: x = %f\n", solution_1);

    // Решение второго уравнения
    double solution_2 = EquationSolve(SecondEquation, initial_approximation_2, max_iterations);
    printf("Ожидалось для второго уравнения: x = 2.2985\n");
    printf("Решение второго уравнения: x = %f\n", solution_2);

    return 0;
}

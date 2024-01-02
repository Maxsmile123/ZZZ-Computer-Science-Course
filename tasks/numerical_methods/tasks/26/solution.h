#pragma once

#include "constants.h"
#include "dichotomy_realization.h"
#include "nyuton_realization.h"

void Output(double_t nyuton_result, double_t dichotomy_result) {
    printf("|                Уравнение                | Отрезок  |   Метод   | Результат  |\n");
    for (int i = 0; i < 79; ++i) {
        printf("-");
    }
    printf("\n");
    printf("|          e^x - e^(-x) - 2 = 0           |  [0, 1]  |  Ньютона  |   %.4f   |\n", nyuton_result);
    for (int i = 0; i < 79; ++i) {
        printf("-");
    }
    printf("\n");
    printf("| sin(ln(x)) - cos(ln(x)) + 2 * ln(x) = 0 |  [1, 3]  | Дихотомии |   %.4f   |\n", dichotomy_result);
}

int Task() {
    double_t first_num = (A_N + B_N) / 2;
    double_t nyuton_second_num = first_num - (NyutonFunc(first_num) / NyutonDerivative(first_num, 1));
    double_t nyuton_result = Nyuton(nyuton_second_num, first_num, NyutonDerivative, NyutonFunc);
    double_t dichotomy_result = Dychotomy(A_D, B_D, DychotomyFunc);
    Output(nyuton_result, dichotomy_result);
    return 0;
}
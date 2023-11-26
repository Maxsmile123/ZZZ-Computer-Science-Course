#include <stdio.h>
 
typedef enum {
    S0, S1, S2, S3
} State;
 
int is_minus_or_plus(char c)
{ 
    if (c == '-' || c == '+') {
        return 1;
    }
    return 0;
}
 
int is_rubbish(char c)
{
    if ((c < '0' && c >= '!') || (c <= '~' && c > '9')) {
        return 1;
    }
    return 0;
}
 
int is_number(char c)
{
    if (c <= '9' && c >= '0') {
        return 1;
    }
    return 0;
}
 
int is_space(char c)
{
    if (c == ' ') {
        return 1;
    }
    return 0;
}
 
int is_n(char c)
{
    if (c == '\n') {
        return 1;
    }
    return 0;
}
 

int main(void)
{
    char c;
    int sum1, sum2, sum3;
    sum1 = sum2 = sum3 = -1;
    State state = S0;
 
    while ((c = getchar()) != EOF) {
        switch (state) {
            case S0: // Начинается обработка нового слова
                if (is_minus_or_plus(c)) {
                    state = S2;
                } else if (is_rubbish(c)) {
                    state = S1;
                } else if (is_number(c)) {
                    state = S3;
                    sum3 = sum2;
                    sum2 = sum1;
                    sum1 = 0;
                    sum1 += c - '0';
                } else if (is_n(c)) {
                    if (sum1 != -1 && sum2 != -1) {
                        printf("%d\n", sum2);
                    }
                    sum1 = sum2 = sum3 = -1;
                    state = S0;
                }
                break;
            case S1: // Пропускает слово, ибо оно не число
                if (is_rubbish(c) || is_number(c)) {
                    state = S1;
                } else if (is_space(c)) {
                    state = S0;
                } else if (is_n(c)) {
                    if (sum1 != -1 && sum2 != -1) {
                        printf("%d\n", sum2);
                    }
                    sum1 = sum2 = sum3 = -1;
                    state = S0;
                }
                break;
            case S2: // Проверка, что + или - знаки числа, а не мусор
                if (is_number(c)) {
                    sum3 = sum2;
                    sum2 = sum1;
                    sum1 = 0;
                    sum1 += c - '0';
                    state = S3;
                } else if (is_space(c)) {
                    state = S0;
                } else if (is_rubbish(c)) {
                    state = S1;
                } else if (is_n(c)) {
                    if (sum1 != -1 && sum2 != -1) {
                        printf("%d\n", sum2);
                    }
                    sum1 = sum2 = sum3 = -1;
                    state = S0;
                }
                break;
            case S3: // Обработка числа
                if (is_number(c)) {
                    sum1 += c - '0';
                    state = S3;
                } else if (is_rubbish(c)) {
                    sum1 = sum2;
                    sum2 = sum3;
                    state = S1;
                } else if (is_space(c)) {
                    state = S0;
                } else if (is_n(c)) {
                    if (sum1 != -1 && sum2 != -1) {
                        printf("%d\n", sum2);
                    }
                    sum1 = sum2 = sum3 = -1;
                    state = S0;
                }
                break;
        }
    }
    return 0;
}
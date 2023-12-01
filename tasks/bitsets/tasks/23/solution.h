#pragma once

#include <stdint.h>
#include <stdio.h>
#include <string.h>

typedef uint32_t Bitset;
const Bitset VOICED_CONSONANTS = 35797066;
const Bitset VOWELS = 17842449;

// объяснение полученных констант
// char voiced_c[] = {'b', 'd', 'g', 'l', 'm', 'n', 'r', 'v', 'z'};
// Bitset voiced_consonants = 0;
// for (int i = 0; i < VOICED_CONSONANTS_COUNT; ++i) ,учитывая (VOICED_CONSONANTS_COUNT = 9)
//{
//     voiced_consonants |= (1 << (voiced_c[i] - 'a'));
// }
// char only_vowels[] = {'a', 'e', 'i', 'o', 'u', 'y'};
// Bitset vowels = 0;
// for (int i = 0; i < VOWELS_COUNT; ++i) (VOWELS_COUNT = 6)
//{
//    vowels |= (1 << (only_vowels[i] - 'a'));
//}

int Task() {
    Bitset word = 0;
    char input[] = "td lol dd ";  // здесь замена на scanf

    for (size_t i = 0; i <= strlen(input); ++i)  // используем <= для обработки последнего слова
    {
        if (input[i] >= 'a' && input[i] <= 'z')  // просмотр каждого слова отдельно
        {
            word |= (1u << (input[i] - 'a'));  // заполнение на основе каждой буквы
        } else {
            // Проверяем, что в слове есть только звонкие согласные
            // условно: (согласные) & (глухие согласные) == 0 и есть звонкая(-ие) согласная(-ые) хотя бы одна
            if (((word & ~VOWELS) & ~VOICED_CONSONANTS) == 0 && (word & VOICED_CONSONANTS) != 0) {
                printf("Есть слово, включающее только звонкие согласные\n");
                return 0;
            }
            word = 0;  // обнуление и переход для подсчета нового слова
        }
    }
    printf("Нет таких слов\n");
    return 0;
}

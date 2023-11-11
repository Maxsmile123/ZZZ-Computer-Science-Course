#pragma once

#include <stdint.h>
#include <stdio.h>

typedef uint32_t Bitset;

const Bitset VOWELS = 17842449u;  // посчитал вручную для aeiouy

int Task() {
    // две переменные для считывания данных
    char letter = ' ';
    Bitset word = 0u;

    // УДАЛИТЬ СЛЕДУЮЩИЕ ДВЕ СТРОЧКИ, ЕСЛИ ВВОД БУДЕТ ИЗ КОНСОЛИ
    char input[] = "word-234wooooord 394 woaueioiuyd    812098897  aaaeiouyuy \0";
    int i = 0;

    // читаем ввод и параллельно решаем задачу
    while (input[i] != '\0') {  // ЗАМЕНИТЬ ЭТО УСЛОВИЕ НА (scanf("%c", &letter) != EOF) ЕСЛИ ВВОД БУДЕТ ИЗ КОНСОЛИ
        letter = input[i];  // УДАЛИТЬ ЭТУ СТРОЧКУ, ЕСЛИ ВВОД БУДЕТ ИЗ КОНСОЛИ
        if (letter >= 'a' && letter <= 'z') {
            // пока мы считываем латинские буквы из слова
            // будем формировать маску множества букв этого слова
            word = word | (1u << (letter - 'a'));
        } else {
            // Как только мы встретили знак не латинского алфавита,
            // проверяем, имеет ли слово все гласные,
            // обнуляем множество, чтобы потом начать читать новое слово
            if ((word & VOWELS) == VOWELS) {
                printf("Yes, There is a word that has all vowels\n");
                return 0;
            }
            word = 0u;
        }

        ++i;  // УДАЛИТЬ ЭТУ СТРОЧКУ, ЕСЛИ ВВОД БУДЕТ ИЗ КОНСОЛИ
    }

    printf("No, Word that has all vowels not found\n");

    return 0;
}
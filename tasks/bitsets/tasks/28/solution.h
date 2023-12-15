#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

typedef uint32_t Bitset;

// Проверка на присутствие буквы в слове
bool WordContainsOnlyVowels(Bitset num, Bitset a, Bitset b) {
    if ((num & a) > 0 && (num & b) == 0) {
        return true;
    }
    return false;
}

int Task() {
    // Вводим последовательность слов
    char input[] = "aye kjgafdj oiie oooooo kfdjgoi";
    int i = 0;
    Bitset vowels = (1 << ('e' - 'a')) + (1 << ('y' - 'a')) + (1 << ('u' - 'a')) + (1 << ('i' - 'a')) +
                    (1 << ('o' - 'a')) + (1 << ('a' - 'a'));
    Bitset consonants = ~vowels;
    Bitset set = 0;

    // Счётчик слов
    uint16_t counter = 0;
    char letter = ' ';
    while (input[i] != '\0') {
        letter = input[i];
        if (letter >= 'a' && letter <= 'z') {
            set = set | (1 << (letter - 'a'));
        } else {
            if (WordContainsOnlyVowels(set, vowels, consonants)) {
                counter++;
            }
            set = 0;
        }
        ++i;
    }
    if (WordContainsOnlyVowels(set, vowels, consonants)) {
        counter++;
    }
    if (counter > 0) {
        printf("Да, %d подходит.", counter);
    } else {
        printf("Нет слов, состоящих только из гласных букв.");
    }
    return 0;
}

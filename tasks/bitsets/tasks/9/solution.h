#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// функция для сравнения символов
int CompareChars(const void *a, const void *b) {
    return *(const char *)a - *(const char *)b;
}

// функция для проверки (есть ли соседние слова, состоящие из одного и того же набора(ов) букв?)
int AreAnagrams(char *word1, char *word2) {
    // создаем копии слов
    char *copy1 = strdup(word1);
    char *copy2 = strdup(word2);
    // сортируем символы в копиях
    qsort(copy1, strlen(copy1), sizeof(char), CompareChars);
    qsort(copy2, strlen(copy2), sizeof(char), CompareChars);
    // сравниваем отсортированные строки
    int result = strcmp(copy1, copy2) == 0;

    // освобождаем выделенную память под копии слов
    free(copy1);
    free(copy2);

    return result;
}

int Task() {
    // пример входных данных
    char data[] = "janclana nbser ersnb acvjv";

    char *words[50];
    char *token = strtok(data, " ");

    int i = 0;
    while (token != NULL) {
        words[i] = token;
        token = strtok(NULL, " ");
        i++;
    }

    // проверяем соседние слова
    int found_anagrams = 0;
    size_t num_words = sizeof(words) / sizeof(words[0]);  // calculate the number of words

    for (size_t i = 1; i < num_words; i++) {
        if (AreAnagrams(words[i - 1], words[i])) {
            found_anagrams = 1;
            break;
        }
    }

    // получаем ответ
    if (found_anagrams) {
        printf("YES");
    } else {
        printf("NO");
    }

    return 0;
}

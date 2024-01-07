#pragma once

#include <regex.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "fsm_structs.h"

// Проверяем слово на правильность (является ли оно идентификатором языка Си или Паскаль) при помощи регулярок

bool IsValidCIdentifier(const char* word) {
    regex_t regex;
    regcomp(&regex, "^[a-zA-Z_][a-zA-Z0-9_]*$", REG_EXTENDED);
    int match = regexec(&regex, word, 0, NULL, 0);  // Сравниваем word с требованиями
    regfree(&regex);
    printf("%s - %d\n", word, match == 0);  // Выводим слово, которое проверяли и 1 - если оно подходит, 0 - если нет
    return (match == 0);                    // Аналогично возвращаем 0 или 1
}

void Transition(Machine* machine, FILE* file) {
    int32_t count = 0;  // Счетчик кол-ва слов, являющихся правильными идентификаторами языка Си или Паскаль
    while (machine->current_state != END) {
        char word[255] = {0};  // Явно инициализируем массив, в который будем записывать слова длиной < 255 букв
        if (machine->current_state == SCAN) {
            char symbol =
                ' ';  // Используем symbol чтобы сравнить введенное значение с ' ' и '\n' и не записывать их в word
            char is_eof = 0;  // При EOF проверяем последнее слово, если оно есть, и завершаем работу машины
            for (int i = 0; i < 255; ++i) {
                symbol = (char)fgetc(file);
                if (symbol != EOF) {
                    if (symbol == ' ' || symbol == '\n') {
                        break;
                    } else {
                        word[i] = symbol;
                    }
                } else {
                    is_eof = 1;
                    break;
                }
            }
            if (strlen(word)) {  // Слово ненулевое
                if (is_eof) {    // Слово окончилось на EOF
                    machine->current_state = LAST_CHECK;  // LAST_CHECK - проверит слово и перейдет в состояние OUTPUT
                } else {                                  // Слово не заканчивалось EOF
                    machine->current_state = CHECK;  // CHECK - проверит слово и вернется в SCAN
                }
            } else if (is_eof) {  // Слово нулевое, дошли до конца файла
                machine->current_state = OUTPUT;
            }
        }
        if (machine->current_state == CHECK) {
            if (IsValidCIdentifier(word)) {
                ++count;
            }
            machine->current_state = SCAN;
            continue;
        }
        if (machine->current_state == LAST_CHECK) {
            if (IsValidCIdentifier(word)) {
                ++count;
            }
            machine->current_state = OUTPUT;
        }
        if (machine->current_state == OUTPUT) {
            printf("The number of correct identifiers of the C or Pascal languages: %d\n", count);
            machine->current_state = END;
        }
    }
}
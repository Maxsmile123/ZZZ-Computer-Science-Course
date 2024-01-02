#pragma once

#include "shared_header.h"

StateName Start(StateMachine *sm __attribute__((unused))) {
    // Здесь, наверное, можно что-то другое, просто надо инициализировать старт
    printf("The program has now started. Transitioning to data reading...\n");
    return READ_CHAR;
}

StateName ReadChar(StateMachine *sm) {
    // Проверка на двоичное число
    if (sm->current_char == '0' || sm->current_char == '1') {
        // Если символ является частью двоичного числа, добавляем его к числу
        sm->current_binary_state[sm->current_length++] = sm->current_char;
        sm->current_binary_state[sm->current_length] = '\0';
    } else {
        // Если символ не является частью двоичного числа
        if (sm->current_length > 0) {
            // Увеличиваем счетчик двоичных чисел только если текущее число является полностью двоичным
            // Здесь проверка на разделительные символы
            if (sm->current_char == ' ' || sm->current_char == '\n' || sm->current_char == '\t') {
                sm->binary_counter++;
                if (sm->binary_counter % 3 == 0) {
                    // Если это каждое третье двоичное число, переходим к его печати
                    sm->current_length = 0;
                    return PRINT_BINARY;
                }
            }
            // Сброс текущего двоичного числа для следующего
            sm->current_length = 0;
        }
    }
    return READ_CHAR;  // Возвращаемся к чтению следующего символа
}

StateName PrintBinary(StateMachine *sm) {
    printf("Binary #%d: %s\n", sm->binary_counter, sm->current_binary_state);
    sm->current_length = 0;
    return READ_CHAR;
}

StateName ErrorState(StateMachine *sm __attribute__((unused))) {
    printf("An error has occurred during processing.\n");
    return END;
}

StateName End(StateMachine *sm __attribute__((unused))) {
    printf("Program has successfully completed its execution.\n");
    return END;
}

// Функция для инициализации состояния
void InitState(State *state, StateName name, StateName (*action)(StateMachine *)) {
    state->name = name;
    state->action = action;
}

State *MakeStates() {
    State *st = (State *)malloc(sizeof(State) * STATECOUNT);

    InitState(&st[START], START, &Start);
    InitState(&st[READ_CHAR], READ_CHAR, &ReadChar);
    InitState(&st[PRINT_BINARY], PRINT_BINARY, &PrintBinary);
    InitState(&st[END], END, &End);
    InitState(&st[ERROR_STATE], ERROR_STATE, &ErrorState);

    return st;
}

void DeleteStates(State *pipeline) {
    free(pipeline);
}

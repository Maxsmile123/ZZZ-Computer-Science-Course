#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#include "shared_header.h"

bool IsHexDigit(char c) {
    return (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f') || (c >= '0' && c <= '9');
}

bool IsX(char c) {
    return c == 'x' || c == 'X';
}

// Ищем ноль, так как числа вида 0x.....
StateName Zero(StateMachine* sm) {
    if (sm->current_char == '0') {
        return PREFIX;
    }
    return ZERO;
}

// Проверяем, что после нуля стоит x
StateName Prefix(StateMachine* sm) {
    if (IsX(sm->current_char)) {
        return SKIP;
    }
    return Zero(sm);
}

// Теперь парами проверяем знаки. Будем пропускать первый знак в каждой паре
StateName Skip(StateMachine* sm) {
    if (IsHexDigit(sm->current_char)) {
        ++sm->length_count;
        return HEX;
    }
    sm->length_count = 0;
    return Zero(sm);
}

// Проверяем второй знак. Если это тоже hex цифра, увеличиваем счётчик длины
StateName Hex(StateMachine* sm) {
    if (IsHexDigit(sm->current_char)) {
        // Проверяем, чтобы пара не была предпоследней. Пары нумеруются с 1
        if (sm->length_count < HEX_LENGTH - 1) {
            return SKIP;
        }
        return LASTSKIP;
    }

    // Может случиться такое: 0x0x..., Тогда машина начнёт проверять начало слова как пару, а это нам не нужно
    if (IsX(sm->current_char) && (sm->last_char == '0')) {
        sm->length_count = 0;
        return SKIP;
    }

    sm->length_count = 0;
    return Zero(sm);
}

StateName LastSkip(StateMachine* sm) {
    if (IsHexDigit(sm->current_char)) {
        return SIGN;
    }
    sm->length_count = 0;
    return Zero(sm);
}

StateName Sign(StateMachine* sm) {
    if (IsHexDigit(sm->current_char) && (sm->last_char >= '8')) {
        sm->length_count = 0;
        ++sm->numbers_count;
        return ZERO;
    }
    sm->length_count = 0;
    return Zero(sm);
}

State* MakeStates() {
    State* st = (State*)malloc(sizeof(State) * STATECOUNT);

    StateName (*actions[STATECOUNT])(StateMachine*) = {&Zero, &Prefix, &Skip, &Hex, &LastSkip, &Sign};
    for (size_t i = 0; i < STATECOUNT; ++i) {
        st[i].name = (StateName)i;
        st[i].action = actions[i];
    }
    return st;
}

void DeleteStates(State* pipeline) {
    free(pipeline);
}
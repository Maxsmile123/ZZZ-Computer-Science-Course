#pragma once

#include <stdio.h>
#include <stdlib.h>

#include "shared_header.h"

bool IsDigit(char c) {
    return ((c >= '0') && (c <= '9'));
}

StateName MemorizeNumber(StateMachine* sm) {
    if (sm->cur_char == EOF) {
        return RESULT;
    }
    if (IsDigit(sm->cur_char)) {
        sm->cur_number *= 10;
        sm->cur_number += (int32_t)(sm->cur_char - '0');
        return MEMORIZENUMBER;
    }
    return SKIP;
}

StateName Skip(StateMachine* sm) {
    if (sm->cur_char == '$') {
        return RESULT;
    }
    if (IsDigit(sm->cur_char)) {
        sm->prev_number = sm->cur_number;
        sm->cur_number = 0;
        return MemorizeNumber(sm);
    }
    return SKIP;
}

StateName Result(StateMachine* sm) {
    int32_t number = sm->prev_number;
    int32_t sum = 0;
    while (number != 0) {
        sum += number % 10;
        number /= 10;
    }
    printf("Previous number: %i\nSum of digits  : %i\n", sm->prev_number, sum);
    return END;
}

State* MakeStates() {
    State* st = (State*)malloc(sizeof(State) * STATECOUNT);
    StateName (*actions[STATECOUNT])(StateMachine*) = {&Skip, &MemorizeNumber, &Result};
    for (size_t i = 0; i < STATECOUNT; ++i) {
        st[i].name = (StateName)i;
        st[i].action = actions[i];
    }
    return st;
}

void DeleteStates(State* st) {
    free(st);
}
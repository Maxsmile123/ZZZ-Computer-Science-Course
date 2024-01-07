#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "shared_header.h"

// Function to check if number is less than INT_MAX
bool CheckNumberValue(int number) {
    return number < INT_MAXS;
}

// Functions for each state
StateName FindNumber(StateMachine* sm) {
    if (sm->current_char >= '0' && sm->current_char <= '9') {
        sm->current_number = sm->current_char - '0';
        return VALUE_FORMING;
    } else if (sm->current_char == EOF) {
        return END;
    } else {
        return FIND_NUMBER;
    }
}

StateName ValueForming(StateMachine* sm) {
    if (sm->current_char == ' ') {
        return COMPARE_VALUES;
    } else if (sm->current_char >= '0' && sm->current_char <= '9') {
        sm->current_number = sm->current_number * 10 + (sm->current_char - '0');
        return VALUE_FORMING;
    } else if (sm->current_char == EOF) {
        return END;
    } else {
        sm->current_number = 0;
        return FIND_NUMBER;
    }
}

StateName CompareValues(StateMachine* sm) {
    if (CheckNumberValue(sm->current_number)) {
        printf("%d ", sm->current_number);
        sm->current_number = 0;
        return FIND_NUMBER;
    } else if (CheckNumberValue(sm->current_char - '0')) {
        sm->current_number = sm->current_char - '0';
        return VALUE_FORMING;
    } else if (sm->current_char >= '0' && sm->current_char <= '9') {
        sm->current_number = sm->current_char - '0';
        return VALUE_FORMING;
    } else if (sm->current_char == EOF) {
        return END;
    } else {
        sm->current_number = 0;
        return FIND_NUMBER;
    }
}

// Function to create an array of states with corresponding actions
State* MakeStates() {
    State* states = (State*)malloc(sizeof(State) * COUNT);
    StateName (*actions[END])(StateMachine*) = {&FindNumber, &ValueForming, &CompareValues};
    for (int a = 0; a < END; ++a) {
        states[a].name = (StateName)a;
        states[a].action = actions[a];
    }
    return states;
}

// Function to delete the array of states
void DeleteStates(State* states) {
    free(states);
}

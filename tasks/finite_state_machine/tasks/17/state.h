#pragma once

#include "shared_header.h"

StateName Start(StateMachine *sm __attribute__((unused))) {
    printf("The program has been started. Please wait.\n");
    return READ_CHAR;
}

StateName ReadChar(StateMachine *sm) {
    if (sm->current_char == '0' || sm->current_char == '1' || sm->current_char == '2') {
        sm->current_ternary_state[sm->current_length++] = sm->current_char;
        sm->current_ternary_state[sm->current_length] = '\0';
        if (sm->current_char == '0') {
            sm->last_char = 0;
        } else if (sm->current_char == '1') {
            sm->last_char = 1;
        } else {
            sm->last_char = 2;
        }
    } else {
        if (sm->current_length > 0) {
            if (sm->current_char == ' ' || sm->current_char == '\n' || sm->current_char == '\t') {
                if (sm->last_char == 0) {
                    sm->current_length = 0;
                    sm->last_char = 1;
                    return PRINT_TERNARY;
                }
            }
            sm->current_length = 0;
        }
    }
    return READ_CHAR;
}

StateName PrintTernary(StateMachine *sm) {
    printf("Ternary: %s\n", sm->current_ternary_state);
    sm->current_length = 0;
    return READ_CHAR;
}

StateName End(StateMachine *sm __attribute__((unused))) {
    printf("Program has successfully completed.\n");
    return END;
}

void InitState(State *state, StateName name, StateName (*action)(StateMachine *)) {
    state->name = name;
    state->action = action;
}

State *MakeStates() {
    State *st = (State *)malloc(sizeof(State) * STATECOUNT);
    InitState(&st[START], START, &Start);
    InitState(&st[READ_CHAR], READ_CHAR, &ReadChar);
    InitState(&st[PRINT_TERNARY], PRINT_TERNARY, &PrintTernary);
    InitState(&st[END], END, &End);

    return st;
}

void DeleteStates(State *pipeline) {
    free(pipeline);
}
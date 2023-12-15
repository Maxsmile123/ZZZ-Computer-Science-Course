#pragma once

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "shared_header.h"
#include "state.h"

StateMachine* MakeStateMachine() {
    StateMachine* sm = (StateMachine*)malloc(sizeof(StateMachine));
    sm->pipeline = MakeStates();
    sm->cur_state = NUMCHECK;
    sm->octal_number = 0;
    sm->digit = 0;
    sm->reversed_number = 0;
    return sm;
}

int Step(StateMachine* sm, char c) {
    StateName next = sm->pipeline[(int)sm->cur_state].action(sm);
    sm->ch = c;
    if (next == END) {
        return 1;
    }
    sm->cur_state = next;
    return 0;
}

void DeleteStateMachine(StateMachine* sm) {
    DeleteStates(sm->pipeline);
    free(sm);
}

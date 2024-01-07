#pragma once

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "shared_header.h"
#include "state.h"

StateMachine* MakeStateMachine() {
    StateMachine* sm = (StateMachine*)malloc(sizeof(StateMachine));
    sm->activeState = SEARCH;
    sm->pipeline = MakeStates();
    sm->cnt = 0;
    return sm;
}

int Step(StateMachine* sm, char c) {
    StateName next = sm->pipeline[(int)sm->activeState].action(sm);
    sm->cur_char = c;
    if (next == END) {
        return 0;
    }
    sm->activeState = next;
    return 1;
}

void DeleteStateMachine(StateMachine* sm) {
    DeleteStates(sm->pipeline);
    free(sm);
}
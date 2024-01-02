#pragma once

#include <stdlib.h>

#include "shared_header.h"
#include "state.h"

StateMachine* MakeStateMachine() {
    StateMachine* sm = (StateMachine*)malloc(sizeof(StateMachine));
    sm->cur_number = 0;
    sm->prev_number = 0;
    sm->pipeline = MakeStates();
    sm->cur_state = SKIP;
    return sm;
}

int Step(StateMachine* sm, char c) {
    sm->cur_char = c;
    StateName next = sm->pipeline[(int)sm->cur_state].action(sm);
    if (next == END) {
        return false;
    }
    sm->cur_state = next;
    return true;
}

void DeleteStateMachine(StateMachine* sm) {
    DeleteStates(sm->pipeline);
    free(sm);
}
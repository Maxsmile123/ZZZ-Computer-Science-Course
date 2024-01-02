#pragma once

#include "shared_header.h"
#include "state.h"

StateMachine* CreateStateMachine() {
    StateMachine* sm = (StateMachine*)malloc(sizeof(StateMachine));
    sm->pipeline = MakeStates();
    sm->cur_state = ZERO;
    sm->length_count = 0;
    sm->numbers_count = 0;

    return sm;
}

void Step(StateMachine* sm, char c) {
    sm->current_char = c;
    StateName next = sm->pipeline[sm->cur_state].action(sm);
    sm->cur_state = next;
    sm->last_char = sm->current_char;
}

void DeleteStateMachine(StateMachine* sm) {
    DeleteStates(sm->pipeline);
    free(sm);
}
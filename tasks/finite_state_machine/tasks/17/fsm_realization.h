#pragma once

#include "shared_header.h"
#include "state.h"

StateMachine *CreateStateMachine() {
    StateMachine *sm = (StateMachine *)malloc(sizeof(StateMachine));
    sm->pipeline = MakeStates();
    sm->cur_state = START;
    sm->last_char = 1;
    sm->current_length = 0;
    return sm;
}

void Step(StateMachine *sm, char c) {
    if (sm->cur_state != END) {
        sm->current_char = c;
        sm->cur_state = sm->pipeline[sm->cur_state].action(sm);
    }
}

void DeleteStateMachine(StateMachine *sm) {
    DeleteStates(sm->pipeline);
    free(sm);
}
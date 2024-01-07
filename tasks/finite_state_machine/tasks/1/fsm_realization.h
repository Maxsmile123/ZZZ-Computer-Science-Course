#pragma once

#include "shared_header.h"
#include "state.h"

StateMachine* CreateStateMachine() {
    StateMachine* sm = (StateMachine*)malloc(sizeof(StateMachine));
    sm->pipeline = MakeStates();
    sm->cur_state = START;
    sm->slash_count = 0;
    sm->word_count = 0;
    sm->check_word = false;
    sm->current_char = ' ';

    return sm;
}

void Step(StateMachine* sm, char c) {
    sm->current_char = c;
    StateName next = sm->pipeline[sm->cur_state].action(sm);
    sm->cur_state = next;
}

void DeleteStateMachine(StateMachine* sm) {
    DeleteStates(sm->pipeline);
    free(sm);
}

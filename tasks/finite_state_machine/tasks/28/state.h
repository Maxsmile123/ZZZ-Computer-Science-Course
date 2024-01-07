#pragma once

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "shared_header.h"

StateName AddNum(StateMachine* sm) {
    if (isdigit(sm->cur_char)) {
        sm->cur_num *= 10;
        sm->cur_num += (int32_t)(sm->cur_char - '0');
        return ADD_NUM;
    }
    return SAVE_NUM;
}

StateName Search(StateMachine* sm) {
    if (sm->cur_char == EOF) {
        return RESULT;
    }
    if (isdigit(sm->cur_char)) {
        return AddNum(sm);
    }
    return SEARCH;
}

StateName SaveNum(StateMachine* sm) {
    if (sm->first_num == -1 && sm->last_num == -1) {
        sm->first_num = sm->cur_num;
        sm->last_num = sm->cur_num;
        sm->cur_num = 0;
        return SEARCH;
    }
    sm->last_num = sm->cur_num;
    sm->cur_num = 0;
    return SEARCH;
}

StateName Result(StateMachine* sm) {
    printf("First number: %d\n", sm->first_num);
    printf("Last number: %d\n", sm->last_num);
    return END;
}

State* MakeStates() {
    State* st = (State*)malloc(sizeof(State) * STATECOUNT);
    StateName (*actions[STATECOUNT])(StateMachine*) = {&Search, &AddNum, &SaveNum, &Result};
    for (int i = 0; i < STATECOUNT; ++i) {
        st[i].name = (StateName)i;
        st[i].action = actions[i];
    }
    return st;
}

void DeleteStates(State* st) {
    free(st);
}
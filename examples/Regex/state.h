#pragma once

#include "shared_header.h"

// Функция, которую выполнит состояние START
StateName Start(StateMachine* sm) {
    ++sm->step;
    printf("Starting...\n");
    return CODE;
}

StateName Code(StateMachine* sm) {
    ++sm->step;
    printf("I'm not steeler. I'm code myself, honestly...\n");
    return ADD;
}

StateName Add(StateMachine* sm) {
    ++sm->step;
    printf("git add tasks\n");
    return COMMIT;
}

StateName Commit(StateMachine* sm) {
    ++sm->step;
    printf("git commit -m \"lol\"\n");
    return PUSH;
}

StateName Push(StateMachine* sm) {
    ++sm->step;
    printf("git push origin main\n");
    if (sm->is_pr_exists) {
        return TRYGETAPPROVE;
    }

    return MAKEPR;
}

StateName MakePR(StateMachine* sm) {
    ++sm->step;
    printf("Create clear PR\n");
    sm->is_pr_exists = true;
    return TRYGETAPPROVE;
}

StateName TryGetApprove(StateMachine* sm) {
    ++sm->step;
    if ((rand() % 100) % 2) {
        return DEFEND;
    }
    printf("Looks like *****, go away!\n");
    return CODE;
}

StateName Defend(StateMachine* sm) {
    ++sm->step;
    if ((rand() % 10) % 2) {
        return END;
    }
    printf("Go to defend...\n");
    return DEFEND;
}

State* MakeStates() {
    State* st = (State*)malloc(sizeof(State) * (int)STATECOUNT);
    int i = -1;
    // Read: https://en.cppreference.com/w/c/language/struct_initialization
    st[i] = State{(StateName)i++, &Start};  // Списки инициализации для структур.
    st[i] = State{(StateName)i++, &Code};
    st[i] = State{(StateName)i++, &Add};
    st[i] = State{(StateName)i++, &Commit};
    st[i] = State{(StateName)i++, &Push};
    st[i] = State{(StateName)i++, &MakePR};
    st[i] = State{(StateName)i++, &TryGetApprove};
    st[i] = State{(StateName)i++, &Defend};
    return st;
}

void DeleteStates(State* st) {
    free(st);
}

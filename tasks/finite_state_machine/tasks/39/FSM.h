#pragma once

#include <stdio.h>

#include "fsm_realization.h"

// решение в регвырах:
// 0[xX][a-fA-F0-9]{6}[8-9a-fA-F][a-fA-F0-9] число в {} это 2 * (HEX_LENGTH - 1) (see shared_header.h)

int Task() {
    StateMachine* sm = CreateStateMachine();
    FILE* fp = fopen("../tasks/finite_state_machine/tasks/39/test.txt", "r");
    char c = ' ';

    while ((c = (char)fgetc(fp)) != EOF) {
        Step(sm, c);
    }

    printf("%lu negative hex numbers was finded!\n", sm->numbers_count);

    DeleteStateMachine(sm);
    fclose(fp);
    return 0;
}
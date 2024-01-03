#include <stdbool.h>
#include <stdio.h>

#include "fsm.h"

int main(void) {
    StateMachine* sm = MakeStateMachine();

    char c;
    int res;
    while ((c = getchar()) != EOF) {
        res = Step(sm);
        if (res) {
            printf("Finish\n");
            break;
        }
    }
    printf("Number of steps = %d\n", sm->step);
    DeleteStateMachine(sm);
    return 0;
}
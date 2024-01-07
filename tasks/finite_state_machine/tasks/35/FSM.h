#include <stdio.h>

#include "fsm_work.h"
#include "shared_header.h"

// (?<!\d)[1-7]\d(?!\d)

int Task() {

    FILE* file = fopen("input.txt", "r");

    if (file == NULL) {
        printf("Файл не открылся\n");
        return 0;
    }

    struct Machine machine;

    Start(&machine, file);

    fclose(file);

    return 0;
}

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

// c f h s x - свистящие согласные

typedef uint32_t BitSet;

int CheckingLetters(BitSet *letters) {

    *letters = *letters & (31324125u);

    if (*letters == 0) {
        return 0;
    }

    *letters = *letters & (57409403u);

    if (*letters == 0) {
        return 1;
    }
    return 0;
}

void MarkLetter(BitSet *letters, char character) {

    if ('a' <= character && character <= 'z') {
        *letters = *letters | (1 << (character - 'a'));
    } else if (('A' <= character && character <= 'Z')) {
        *letters = *letters | (1 << (character - 'A'));
    }
}

int Task() {

    BitSet letters = 0;
    char character = 0;

    while (true) {

        character = (char)getchar();

        if (('a' <= character && character <= 'z') || ('A' <= character && character <= 'Z')) {

            MarkLetter(&letters, character);

        } else {
            if (CheckingLetters(&letters)) {
                printf("Есть слово, все согласные которого свистящие.\n");
                return 0;
            }
            letters = 0;
        }

        if (character == EOF) {
            break;
        }
    }

    printf("Нет слова, все согласные которого свистящие.\n");

    return 0;
}

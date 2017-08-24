// Comments

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char input = getchar();
    while (input != EOF) {
        putchar(input);
        input = getchar();
    }


    return EXIT_SUCCESS;
}

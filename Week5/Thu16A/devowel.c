// Comments

#include <stdio.h>
#include <stdlib.h>

void devowel(char *string);

int main(int argc, char *argv[]) {
    char string[7] = "Hello!";
    devowel(string);
    
    return EXIT_SUCCESS;
}

void devowel(char *string) {
    int i = 0;
    while (string[i] != '\0') {
        if (string[i] != 'a' && string[i] != 'e') {
            putchar(string[i]);
        }
        i++;
    }
}

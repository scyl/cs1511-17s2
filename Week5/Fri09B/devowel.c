// Comments

#include <stdio.h>
#include <stdlib.h>

void devowel(char *string);

int main(int argc, char *argv[]) {
    char *line1 = "Hello, World!";
    char line2[3] = {'H', 'i', '\0'};
    
    devowel(line1);
    devowel(line2);
    
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

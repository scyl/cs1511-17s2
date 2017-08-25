// Comments

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char input = 0;
    
    input = getchar();
    while (input != EOF) {
        //printf("%c", input);
        putchar(input);
        
        //scanf("%c", &input);
        input = getchar(); 
    }
    
    
    return EXIT_SUCCESS;
}

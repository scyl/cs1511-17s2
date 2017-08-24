// Comments

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char myChar = 0;
    myChar = getchar();

    while (myChar != EOF) {
        putchar(myChar);
        //printf("%c", myChar);
        
        myChar = getchar();
        //scanf("%c", myChar);
    }
    
    return EXIT_SUCCESS;
}

// Comments

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int *myMemory = calloc(1, sizeof(int));
    
    *myMemory = 5;
    
    printf("%d\n", *myMemory);
    
    free(myMemory);
    
    

    return EXIT_SUCCESS;
}

// Comments

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int *memory = calloc(1, sizeof(int));
    
    *memory = 7;
    *memory = *memory + 7;
    
    printf("%d\n", *memory);
    
    free(memory);
    
    return EXIT_SUCCESS;
}

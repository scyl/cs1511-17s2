// Comments

#include <stdio.h>
#include <stdlib.h>

int *stuff();

int main(int argc, char *argv[]) {
    int *memory = calloc(1, sizeof(int));
    
    *memory = 6;
    *memory = *memory + 3;
    
    printf("%d\n", *memory);
    
    free(memory);
    
    int *array1 = stuff();
    printf("%d\n", array1[1]);
    
    free(array1);

    return EXIT_SUCCESS;
}

int *stuff() {
    int *array = calloc(5, sizeof(int));
    array[0] = 4;
    array[1] = 54;
    
    return array; 
}

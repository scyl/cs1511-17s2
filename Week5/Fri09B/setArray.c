// Comments

#include <stdio.h>
#include <stdlib.h>

void setArrayValues(int length, int array[], int value);

int main(int argc, char *argv[]) {
    int numbers[8] = {2, 5, 254, 53, 213, 254};
    
    int i = 0;
    while (i < 8) {
        printf("%d, ", numbers[i]);
        i++;
    }
    printf("\n");
    
    setArrayValues(8, numbers, 99);
    
    i = 0;
    while (i < 8) {
        printf("%d, ", numbers[i]);
        i++;
    }
    printf("\n");
    
    return EXIT_SUCCESS;
}

void setArrayValues(int length, int array[], int value) {
    int i = 0;
    while (i < length) {
        array[i] = value;
        i++;
    }
    printf("\n");
}

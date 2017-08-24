// Comments

#include <stdio.h>
#include <stdlib.h>

void setArrayValues(int length, int array[], int value);

int main(int argc, char *argv[]) {
    int myArray[26] = {0};
    
    int i = 0;
    while (i < 26) {
        printf("%d, ", myArray[i]);
        i++;
    }
    putchar('\n');
    
    setArrayValues(26, myArray, 5);
    
    i = 0;
    while (i < 26) {
        printf("%d, ", myArray[i]);
        i++;
    }
    putchar('\n');
    
    return EXIT_SUCCESS;
}

void setArrayValues(int length, int array[], int value) {
    int counter = 0;
    while (counter < length) {
        array[counter] = value;
        counter++;
    }
}

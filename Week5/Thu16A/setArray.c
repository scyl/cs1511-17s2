// Comments

#include <stdio.h>
#include <stdlib.h>

void setArrayValues(int len, int array[], int value);

int main(int argc, char *argv[]) {
    int myArray[8] = {1, 2, 3, 4, 5};
    
    int i = 0;
    while(i < 8) {
        printf("%d, ", myArray[i]);
        i++;
    }
    printf("\n");
    
    setArrayValues(8, myArray, 99);
    
    i = 0;
    while(i < 8) {
        printf("%d, ", myArray[i]);
        i++;
    }
    printf("\n");
    
    return EXIT_SUCCESS;
}

void setArrayValues(int len, int array[], int value) {
    int i = 0;
    while (i < len) {
        array[i++] = value;
        //i++;
    }
}

// Comments

#include <stdio.h>
#include <stdlib.h>

void oneRow(int size);

int main(int argc, char *argv[]) {
    int size = 7;
    /*
    int counter = 0;
    while (counter < size) {
        oneRow(size);
        counter++;
    }*/
    unsigned int row = 0;
    int col = 0;
    while (row < size) {
        while (col < size) {
            printf("#");
            col++;
        }
        printf("\n");
        row++;
        col = 0;
    }
    
    printf("%d\n", sizeof(float));
    
    return EXIT_SUCCESS;
}

void oneRow(int size) {
    int counter = 0;
    while (counter < size) {
        printf("#");
        counter++;
    }
    printf("\n");
}


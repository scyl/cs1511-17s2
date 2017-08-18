// Comments

#include <stdio.h>
#include <stdlib.h>

void oneLine(int size);

int main(int argc, char *argv[]) {
    int size = 4;
    
    /*
    int counter = 0;
    while (counter < size) {
        oneLine(size);
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
    
    printf("%d\n", sizeof(int));
    
    return EXIT_SUCCESS;
}

void oneLine(int size) {
    int counter = 0;
    while (counter < size) {
        printf("#");
        counter++;
    }
    printf("\n");
}

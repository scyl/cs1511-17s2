// Comments

#include <stdio.h>
#include <stdlib.h>

void oneLine(int size);

int main(int argc, char *argv[]) {
    printf("Enter a number: ");
    int size = 0;
    scanf("%d", &size);
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

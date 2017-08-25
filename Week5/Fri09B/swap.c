// Comments

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);

int main(int argc, char *argv[]) {
    int a = 5;
    int b = 7;
    
    int *c = &a;
    
    swap(&a, &b);
    
    return EXIT_SUCCESS;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

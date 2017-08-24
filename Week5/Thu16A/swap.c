// Comments

#include <stdio.h>
#include <stdlib.h>

void swap(int *c, int *d);

int main(int argc, char *argv[]) {
    int a = 5;
    int b = 12;
    
    swap(&a, &b);
    
    return EXIT_SUCCESS;
}

void swap(int *c, int *d) {
    int temp = *c;
    *c = *d;
    *d = temp;
}

// Comments

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);

int main(int argc, char *argv[]) {
    int a = 6;
    int b = 26;
    
    
    printf("a: %d, b:%d\n", a, b);
    swap(&a, &b);
    printf("a: %d, b:%d\n", a, b);
    
    return EXIT_SUCCESS;
}

void swap(int *c, int *d) {
    int temp = *c;
    *c = *d;
    *d = temp;
}

// Comments

#include <stdio.h>
#include <stdlib.h>

void square(int num);
int multiply (int a, int b);

int main(int argc, char *argv[]) {
    int num = 4;
    square(num);
    printf("%d\n", num);
    {
        int x = 0;
    }
    printf("%d\n", x);
    
    return EXIT_SUCCESS;
}

void square(int num) {
    num = num * num;
}

int multiply (int a, int b) {
    return a * b;
}

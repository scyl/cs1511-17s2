// Comments

#include <stdio.h>
#include <stdlib.h>

int square(int n);
int multiply(int a, int b);

int main(int argc, char *argv[]) {
    int n = 2;
    int a = 5;
    int b = 73;
    
    n = square(n);
    int mul = multiply(a, b);
    
    printf("sq = %d\n", n);
    printf("mul = %d\n", mul);
    
    return EXIT_SUCCESS;
}

int square(int n) {
    int result = n * n;
    return result;
}

int multiply(int a, int b) {
    int result = a * b;
    return result;
}

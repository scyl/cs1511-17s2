// Comments

#include <stdio.h>
#include <stdlib.h>

int square (int n);
int multiply (int a, int b);

int main(int argc, char *argv[]) {
    int n = 4;
    int a = 2;
    int b = 3;
    
    int mul = multiply(b, a);
    
    printf("squared = %d\n", square(n));
    
    printf("mul = %d\n", mul);
    
    return EXIT_SUCCESS;
}
int square (int n) {
    int result = n * n;
    return result;
}

int multiply (int a, int b) {
    int result = a * b;
    return result;
}

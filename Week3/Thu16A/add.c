#include <stdio.h>
#include <stdlib.h>

int add(int in1, int in2);

int main(int argc, char *argv[]) {
    int num1 = 6;
    int num2 = 3;
    printf("%d\n", add(num1, num2));
    return EXIT_SUCCESS;
}

int add(int in1, int in2) {
    return in1 + in2;
}

// Add two numbers
// 11/08/17

#include<stdio.h>
#include<stdlib.h>

int add(int number2, int number1);

int main(int argc, char *argv[]) {
    int number1 = -5;
    int number2 = 4;
    int result = add(number1, number2);
    int x = printf("%d\n", result);
    printf("%d\n", x);
    return EXIT_SUCCESS;
}

int add(int number2, int number1) {
    return number2 + number1;
}

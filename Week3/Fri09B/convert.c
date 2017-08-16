// Convert number to words
// 11/08/17

#include<stdio.h>
#include<stdlib.h>

void convertNumToWord(int input);
void printWord(int input);

int main(int argc, char *argv[]) {
    int number = -5;
    convertNumToWord(number);
    return EXIT_SUCCESS;
}

void convertNumToWord(int input) {
    if (input < 0) {
        printf("-");
        input = input * -1;
    }
    printWord(input);
}

void printWord(int input) {
    if (input == 0) {
        printf("Zero\n");
    } else if (input == 1) {
        printf("1Zero\n");
    } else if (input == 2) {
        printf("2Zero\n");
    } else if (input == 3) {
        printf("3Zero\n");
    } else if (input == 4) {
        printf("4Zero\n");
    } else if (input == 5) {
        printf("5Zero\n");
    } else if (input == 6) {
        printf("6Zero\n");
    } else if (input == 7) {
        printf("7Zero\n");
    } else if (input == 8) {
        printf("8Zero\n");
    } else if (input == 9) {
        printf("9Zero\n");
    } else if (input == 10) {
        printf("10Zero\n");
    }
}

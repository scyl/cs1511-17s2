// Convert number to words
// Stephen
// Today

#include <stdio.h>
#include <stdlib.h>

void convert(int input);
void printWord(int input);

int main(int argc, char *argv[]) {
    int num = 6;
    convert(num);
    return EXIT_SUCCESS;
}

void convert(int input) {
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
        printf("1\n");
    } else if (input == 2) {
        printf("2\n");
    } else if (input == 3) {
        printf("3\n");
    } else if (input == 4) {
        printf("4\n");
    } else if (input == 5) {
        printf("5\n");
    } else if (input == 6) {
        printf("6\n");
    } else if (input == 7) {
        printf("7\n");
    } else if (input == 8) {
        printf("8\n");
    } else if (input == 9) {
        printf("9\n");
    } else if (input == 10) {
        printf("10\n");
    }
}

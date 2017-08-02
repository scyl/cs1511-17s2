// weekday.c
// Stephen
// Determine if a day is a weekday

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int num = 0;
    printf("Enter a number from 0 to 6:");
    scanf("%d", &num);
    
    if(num == 0 || num == 6) {
        printf("%d is a weekend.\n", num);
    } else {
        printf("%d is not a weekend.\n", num);
    }
    
    
    return EXIT_SUCCESS;
}

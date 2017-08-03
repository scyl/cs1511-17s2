// Comments

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]) {
    printf("Enter a number from 0 to 6: ");
    int day = 0;
    scanf("%d", &day);
    
    if ((day == 0) || (day == 6)) {
        printf("yes\n");
    } else {
        printf("no\n");
    }
    
    
    return EXIT_SUCCESS;
}

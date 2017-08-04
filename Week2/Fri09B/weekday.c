// Stephen
// weekday

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    printf("Enter a number between 0 to 6: ");
    int day = 0;
    scanf("%d", &day);
    
    if (day == 0 || day == 6) {
        printf("%d is a weekend\n", day);
    } else if ((day <= 5) && (day >= 1)) {
        printf("%d is not a weekend\n", day);
    } else {
        printf("you suck\n");
    }
    
    return EXIT_SUCCESS;
}

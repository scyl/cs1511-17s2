// Write a C function that determines
// whether a string contains uppercase letters.
//
// Your function should return
// TRUE if the string contains uppercase letters,
// and FALSE if it does not.
//
// Your function should take one parameter: the string to check.
// 
// Your function should return either TRUE or FALSE, depending on
// whether the string contains uppercase letters.
//
// For example, if the input string was: "Hello!",
// your function should return TRUE, as the string contained
// an uppercase letter: 'H'.

// Do not change these #defines, or your program will fail the autotests!
#define TRUE 1
#define FALSE !(TRUE)

int containsUppercase (char *string) {
    int upper = FALSE;
    int counter = 0;
    
    while (string[counter] != '\0') {
        if (string[counter] >= 'A' && string[counter] <= 'Z') {
           upper = TRUE; 
        }
        counter++;
    }
    
    return upper;
}


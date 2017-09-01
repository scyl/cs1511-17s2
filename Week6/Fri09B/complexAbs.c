// Calculate the magnitude of a complex number
// By ... (z0000000)
// Written on 2017-0?-??
// Tutor (dayHH-lab)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// DO NOT CHANGE THIS STRUCT
typedef struct _complex {
    double real;
    double imaginary;
} complex;

//typedef int card;

double complexAbsolute(complex c);

// DO NOT CHANGE THIS MAIN FUNCTION
int main (int argc, char *argv[]) {
    //struct _complex x;

    // getting the complex number
    complex c;

    printf("Enter the real part: ");
    scanf("%lf", &c.real);

    printf("Enter the imaginary part: ");
    scanf("%lf", &c.imaginary);

    // get the absolute value
    double absoluteValue = complexAbsolute(c);

    // print the value
    printf("The absolute value is %.2lf.\n", absoluteValue);

    return EXIT_SUCCESS;
}
// END OF MAIN FUNCTION

// this function returns the magnitude (absolute value)
// of a complex number
double complexAbsolute(complex c) {
    double realSqu = pow(c.real, 2);
    double imgSqu = pow(c.imaginary, 2);
    double result = sqrt(realSqu + imgSqu);

    return result;
}

// Write a C function that finds the duplicate value in array,
// if one exists.
//
// The array will either contain no duplicate values,
// or a single value in the array will be duplicated,
// i.e will occur more than once.
//
//
// Your function should take two parameters:
// the length of source array, and the source array itself.
//
// Your function should return a single integer:
// the value in the array that occurs more than once, if one exists.
// If there are no values that occur more than once, your function
// should return NO_DUPLICATE.
//
// For example, if the `source` array contained the following 6 elements:
//     3, 1, 4, 1, 5, 9
// Your function should return the integer `1`, as this is the element
// that occurred more than once.
//
// As another example, if the `source` array contained the following
// 6 elements:
//     1, 2, 3, 4, 5, 6
// Your function should return NO_DUPLICATE, as none of the elements
// in the array occurred more than once.
//
// You can assume the array only contains positive integers.

// Do not change this #define, or your program will fail the autotests!
#define NO_DUPLICATE -1

int findDuplicate (int length, int array[]) {
    int i = 0;
    int j = 0;
    int dup = 0;
    
    while (j < length) {
        while (i < length) {
            if (i != j) {
                if (array[i] == array[j]) {
                    dup++;
                }
            }
            
            i++;
        }
        i = 0;
        j++;
    }
    
    if (dup == 0) {
        dup = NO_DUPLICATE;
    } else {
        dup /= 2;
    }

    return dup;
}


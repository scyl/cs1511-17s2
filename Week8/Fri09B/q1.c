// Write a C function which counts the number of values in the array
// that are multiples of my favourite number: seventeen.
//
// Your function should take two parameters:
// the length of the array, and the array.
//
// Your function should return a single integer:
// the number of values in the array that are multiples of seventeen.
//
// For example if the array contains these 8 elements:
//   16, 7, 18, 12, 13, 17, 21, 34
// Your function should return `2`, because these 4 elements are even: 
//   17, 34
//
// You can assume the array contains only positive integers.


int countFavourite (int length, int array[]) {
    int favCounter = 0;
    int counter = 0;
    
    while (counter < length) {
        if (array[counter] % 17 == 0) {
            favCounter++;
        }
        counter++;
    }
    
    return favCounter;
}

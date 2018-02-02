/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int *foo() {
    int i;
    int array[SIZE]; // Local array

//    printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
        array[i] = 42;
    }
    return array;
}

void bar() {
    int i;
    int array[SIZE]; // Also local array

//    printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
        array[i] = i;
    }
}

int main()
{
    int i;
    int *array = foo(); // Trying to assign a pointer to a function's local array
    bar();

    for (i=0; i<SIZE; i++) {
        printf("%d\n", array[i]); // Likely where the segmentation fault occurs
    }

    return 0;
}

/* The arrays initialized in `foo()` and then `bar()` are
 * both located at the same address.
 * This is because both arrays were local variables that
 * were only stored in the stack while their respective
 * functions were running.
 */
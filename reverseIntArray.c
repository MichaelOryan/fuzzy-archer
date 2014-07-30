/*********************************************************************
 * Functions for Reversing an array of ints with an arbutrary length *
 * and printing out an array of integers                             *
 *********************************************************************/

#include <stdio.h>

void printIntArray(int *nums, unsigned int size);
void printIntArrayLn(int nums[], unsigned int size);
void printIntArrayMemory(int *first, int *last);
void printIntArrayPfix(char prefix[], int nums[], unsigned int size, char postfix[]);
void printReverseIntArray(int nums[], unsigned int size);
void reverseIntMemory(int *first, int *last);
void reverseIntArray(int nums[], unsigned int size);
void swapInt(int *a, int *b);


/* Driver */

main()
{
    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    unsigned int len = sizeof(nums)/sizeof(int);
    
    printIntArrayPfix("Original Array\n", nums, len, "\n");
    
    reverseIntArray(nums, len);
    
    printIntArrayPfix("Reverse Array\n", nums, len, "\n");
    
    printf("Reverse of the reverse array\n");
    printReverseIntArray(nums, len);
    
    return 0;
}


/*******************************
 * Swapping elements functions *
 *******************************/

/* Swaps the values of two integers given their memory locations */

void swapInt(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/* Reverses all memory between two memory addresses as ints */

void reverseIntMemory(int *first, int *last)
{
    const int direction = first < last ? 1 : -1;

    while(first != last)
    {
        swapInt(first, last);
        first += direction;
        last -= direction;
    }    

}

/* Reverses an array of integers given the first element and total number of elements */

void reverseIntArray(int nums[], unsigned int size)
{
    if(size > 0)
    {
        reverseIntMemory(nums, &nums[size-1]);
    }
}


/*******************************
 * Printing an array functions *
 *******************************/

/* Prints all memory locations from the first to the last memory addresses as integers separted by a comma and space */

void printIntArrayMemory(int *first, int *last)
{
    const int direction = first < last ? 1 : -1;
    while(first != last)
    {
        printf("%d,", *first);
        first += direction;
    }

    printf("%d", *first);
}


/* Prints the reverse order of all integer values of an array separating each value by a comma and space. */

void printReverseIntArray(int nums[], unsigned int size)
{
    unsigned int i = 0;
    
    if(size > 0)
    {
        printIntArrayMemory(&nums[size-1], nums);
    }
}


/* Prints all integer values of an array separating each value by a comma and space. */

void printIntArray(int nums[], unsigned int size)
{
    unsigned int i = 0;
    
    if(size > 0)
    {
        printIntArrayMemory(nums, &nums[size-1]);
    }
}

/* Prints an array with text before and after the array. Note: not per element */

void printIntArrayPfix(char prefix[], int nums[], unsigned int size, char postfix[])
{
    printf("%s", prefix);
    printIntArray(nums, size);
    printf("%s", postfix);
}

/* Prints an array and then a newline character */

void printIntArrayLn(int nums[], unsigned int size)
{
    printIntArrayPfix("", nums, size, "\n");
}

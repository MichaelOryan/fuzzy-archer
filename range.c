/*

Set some ranges of buckets, get some values, print how many fall into each bucket

Ranges start from some value, have the same size as each other.
Except the last one can catch all values larger than it.

TODO:
Remove -1 as the sentinal value and have an alternative
Make it so the smallest one can hold all values smaller than it.
Make it so you can add multiple of values. eg; input the expression 124 * 12 add 12 values of 124 to the count
Binary search algorithm for finding correct range so it's more efficient for large numbers of ranges.
    I wonder if starting from the average bucket might improve the search further.
    Obviously be careful of large numbers.
    Maybe use the index of the buckets holding values rather than the values entered.


*/

#ifndef RANGE_C
#define RANGE_C

#include <stdio.h>
#include <limits.h>

/*  Number of ranges */
#ifndef NUM_OF_RANGES
#define NUM_OF_RANGES 6
#endif // NUM_OF_RANGES


/*  Size of ranges */
#ifndef SIZE_OF_RANGES
#define SIZE_OF_RANGES 100
#endif // SIZE_OF_RANGES

/*  Define our boolean values */
typedef enum {false, true} bool;

/*  Holds the frequency of numbers entered between r_min and r_max */
typedef struct Range{
    int r_min;
    int r_max;
    int r_count;
}Range;

/*  Stores our list of Ranges */
typedef struct Records{
    int r_size;
    Range ranges[NUM_OF_RANGES];
}Records;

/*  Prototype Functions */

Range setRange(int r_min, int r_max, int start_count);
Records setStartingRecords(int r_start, int spacing, bool unlimited_end_value);
Records countFrequencies(Records recs);
void displayRanges(Records records);


/* Set some ranges of buckets, get some values, print how many fall into each bucket */

int main()
{
    Records records = setStartingRecords(0, SIZE_OF_RANGES, true);
    records = countFrequencies(records);
    displayRanges(records);
    return 0;
}

/*  Makes a Records structure with ranges starting from r_start and covering int spacing numbers afterwards.
 *  Ranges do not overlap.
 *  unlimited_end value signifies that the last range should capture all values above it's minimum. */

Records setStartingRecords(int r_start, int spacing, bool unlimited_end_value){
    Records new_records = {};
    new_records.r_size = NUM_OF_RANGES;
    int i = 0;
    
    /* Populate ranges */
    for(i = 0; i < NUM_OF_RANGES; i++){
        new_records.ranges[i] = setRange(r_start, r_start + spacing - 1, 0);
        r_start += spacing;
    }
    
    /* Make the last range a greater than the minimum value if required */
    if(unlimited_end_value){
        new_records.ranges[NUM_OF_RANGES - 1].r_max = INT_MAX;
    }
    return new_records;
}

/*  Creates and returns a Range struct */
Range setRange(int r_min, int r_max, int start_count){
    Range range = {r_min, r_max, start_count};
    return range;
}

/*  Gets user input for the values. Increments the Range count that the inputed number falls in. */

Records countFrequencies(Records recs){
    int nextNum = 0;
    printf("Enter values or -1 to end:\n");
    /* Check for -1 sentinal value */
    while(nextNum != -1){
        scanf(" %d", &nextNum);
        int i = 0;
        /* Increment range that the number fall in. */
        for(i = 0; i < recs.r_size; i++)
        {
            if(recs.ranges[i].r_min <= nextNum && recs.ranges[i].r_max >= nextNum){
                recs.ranges[i].r_count++;
            }
        }
    }
    return recs;

}

/*  Outputs the frequency of each range in records */

void displayRanges(Records records){
    printf("\n Range Frequency");
    int i = 0;
    for(i = 0; i < NUM_OF_RANGES; i++){
            Range range = records.ranges[i];
        if(range.r_max == INT_MAX){
            printf("\n %d and above\t%d", range.r_min, range.r_count);
        }
        else if (range.r_max < 100){
            printf("\n %d - %d\t\t%d", range.r_min, range.r_max, range.r_count);
        }
        else{
            printf("\n %d - %d\t%d", range.r_min, range.r_max, range.r_count);
        }

    }
}

#endif // RANGE

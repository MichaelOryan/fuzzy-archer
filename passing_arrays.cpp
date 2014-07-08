/*

I think this was just some example code I wrote after someone was trying to pass arrays around
and return them from functions. Possibly with pointers.

There doesn't appear to be much I can salvage from this code it's more an example of passes
data by value and returns data by value for arrays rather than using pointers or pass by reference.


*/

#include <iostream>

const int SIZE = 6;

struct Numbers{
    int num[SIZE];
};

void printNumbers(Numbers);
Numbers addToNumbers(Numbers);
Numbers getNumbers();

int main(){
    Numbers myNumbers = {1, 2, 1, 2, 1, 2};
    std::cout << "myNumbers: ";
    printNumbers(myNumbers);

    /* Maintain the value of myNumbers and return an array */
    /* of data with one added to each value                */
    
    std::cout << "Add one to every number for changedNumbers: ";
    Numbers changedNumbers = addToNumbers(myNumbers);
    printNumbers(changedNumbers);

    /* Show that the original numbers are still there */
    std::cout << "Original myNumbers: ";
    printNumbers(myNumbers);

    /* Get an array of data from a function */
    std::cout << "Numbers from a function changedNumbers: ";
    changedNumbers = getNumbers();
    printNumbers(changedNumbers);

    return 0;
}

void printNumbers(Numbers someNumbers){
    for(int i = 0; i < SIZE; i++)
        std::cout << someNumbers.num[i] << " ";
    std::cout << std::endl;
}

Numbers getNumbers(){
    Numbers nums = {6,5,4,3,2,1};
    return nums;
}

Numbers addToNumbers(Numbers someNumbers){
    for(int i = 0; i < SIZE; i++)
        someNumbers.num[i]++;
    return someNumbers;
}

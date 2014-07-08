/*
  Calculates the Hamming distance between two user entered DNA strands.
  Idea from a question on r/learnprogramming about hamming distances.
  http://en.wikipedia.org/wiki/Hamming_distance

  When compiling you can define the type of text asked for by defining NAME_OF_STRING as a string literal. "text in here"
  And the range of possible letters by defining VALID_RANGE of a string literal of all valid characters. "valid range"

  TODO:

  Make a library for the functions I can just plop it into other projects rather than recode.
    - The #defines will need to be removed from the library code to ensure no collisions.
      Which is ok because we can just pass them as variables as we won't be recompiling the library
      each time we want a different set of values for NAME_OF_STRING or VALID_RANGE

*/

#include <string>
#include <iostream>

#ifndef NAME_OF_STRING
#define NAME_OF_STRING "DNA strand"
#endif // NAME_OF_STRING

#ifndef VALID_RANGE
#define VALID_RANGE "ACGT"
#endif // VALID_RANGE

const int NOT_SAME_SIZE = -1;

std::string getString(const std::string &s_valid);
int calcHamming(const std::string &s_first, const std::string &s_second);

int main()
{
    /* Define valid letters */
    const std::string s_valid = VALID_RANGE;

    /* Get our DND strands */
    std::cout << "First Strand.\n" << std::flush;
    std::string s_first = getString(s_valid);

    std::cout << "Second Strand.\n" << std::flush;
    std::string s_second = getString(s_valid);

    /* Check length. Hamming Distance Calculation requires equal length strings */
    int h_distance = calcHamming(s_first, s_second);
    if(h_distance != NOT_SAME_SIZE){
      std::cout << "Hamming Distance of " << h_distance << std::endl;
    }
    else{
        std::cout << "Strings differ in length. Not able to calculate hamming distance." << std::endl;
    }
}

/* Get a valid sequence of DNA letters that only contains the characters defined in s_valid */
std::string getString(const std::string &s_valid){
    std::string input;

    std::cout << "Enter a " << NAME_OF_STRING << ". Valid letters " << s_valid << ":" << std::flush;
    std::getline(std::cin, input);

    while(input.find_first_not_of(s_valid) != std::string::npos){
        std::cout << "Invalid letter entered.\n";
        std::cout << "Enter a " << NAME_OF_STRING << ". Valid letters " << s_valid << ":" << std::flush;
        std::getline(std::cin, input);
    }
    return input;
}

/* Calculate and return the Hamming distance of two strings of the same length or return NOT_SAME_SIZE */
int calcHamming(const std::string &s_first, const std::string &s_second){
    int count = 0;
    if(s_first.size() != s_second.size()){
      count = NOT_SAME_SIZE;
    }
    else{
        for(unsigned int i = 0; i < s_first.size() && i < s_second.size(); i++){
            count += s_first.at(i) == s_second.at(i) ? 0 : 1;
        }
    }
    return count;
}

/*
  Calculates the Hamming distance between two user entered DNA strands.
  Idea from a question on r/learnprogramming about hamming distances.
  http://en.wikipedia.org/wiki/Hamming_distance
*/

#include <string>
#include <iostream>

std::string getString(std::string s_valid);
int calcHamming(std::string s_first, std::string s_second);

int main()
{
    /* Define valid letters */
    const std::string s_valid = "ACGT";

    /* Get our DND strands */
    std::cout << "First Strand.\n" << std::flush;
    std::string s_first = getString(s_valid);

    std::cout << "Second Strand.\n" << std::flush;
    std::string s_second = getString(s_valid);

    /* Check length. Hamming Distance Calculation requires equal length strings */
    if(s_first.size() == s_second.size()){
        int h_distance = calcHamming(s_first, s_second);
        std::cout << "Hamming Distance of " << h_distance << std::endl;
    }
    else{
        std::cout << "Strings differ in length. Not able to calculate hamming distance." << std::endl;
    }
}

/* Get a valid sequence of DNA letters that only contains the characters defined in s_valid */
std::string getString(std::string s_valid){
    std::string input;

    std::cout << "Enter a DNA strand. Valid letters " << s_valid << ":" << std::flush;
    std::cin >> input;

    while(input.find_first_not_of(s_valid) != std::string::npos){
        std::cout << "Invalid letter entered.\n";
        std::cout << "Enter a DNA strand. Valid letters " << s_valid << ":" << std::flush;
        std::cin >> input;
    }
    return input;
}

/* Calculate the Hamming distance of two strings only looking at upto the length of the shortest */
int calcHamming(std::string s_first, std::string s_second){
    int count = 0;
    for(unsigned int i = 0; i < s_first.size() && i < s_second.size(); i++){
        count += s_first.at(i) == s_second.at(i) ? 0 : 1;
    }
    return count;
}

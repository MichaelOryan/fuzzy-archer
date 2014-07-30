#include <iostream>
#include <string>

/* Takes a string type and prints to std output the reverse of that string */
void printReverse(const std::string &to_reverse){

    /* Get the number of characters to print */
    unsigned int characters_remaining = to_reverse.length();

    /* While we have characters to print */
    while(characters_remaining > 0)
    {
        /* Calculate the position of our last character */
        unsigned int last_character_index = characters_remaining - 1;

        /* Print the last character to std output */
        std::cout << to_reverse.at(last_character_index);

        /* We are done with that character so we now have one less character to worry about */
        characters_remaining = characters_remaining - 1;
    }

    /* Flush output stream. Only requires one of the below */

    /* Flush without newline */
    std::cout << std::flush;

    /* Flush with a new line */
    std::cout << std::endl;
}

void printReverse(const char to_reverse[], const unsigned int &array_size){

    /* Get the number of characters to print */
    unsigned int characters_remaining = array_size;

    /* While we have characters to print */
    while(characters_remaining > 0)
    {
        /* Calculate the position of our last character */
        unsigned int last_character_index = characters_remaining - 1;

        /* Print the last character to std output */
        std::cout << to_reverse[last_character_index];

        /* We are done with that character so we now have one less character to worry about */
        characters_remaining = characters_remaining - 1;
    }

    /* Flush output stream. Only requires one of the below */

    /* Flush without newline */
    std::cout << std::flush;

    /* Flush with a new line */
    std::cout << std::endl;
}

void printReverseRecursive(const char to_reverse[], const unsigned int &number_of_characters){
    
    /* Check that we have characters to print */
    if(number_of_characters >= 1){
    
        /* Print the next character first */
        printReverse(&to_reverse[1], number_of_characters - 1);
    
        /* Print the current character */
        cout << to_reverse[0];
    }
}

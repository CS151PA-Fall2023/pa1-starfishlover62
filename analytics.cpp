/**
 * @file analytics.cpp
 * @author Josh Gillum
 * @brief Definitions of functions used throughout the program
 * @version 0.1
 * @date 2023-08-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "analytics.h"

/**
 * @brief Opens a file for reading
 * 
 * @param file, ifstream object for opening the file
 * @param path, string of the path to the file
 */
void openFile(std::ifstream &file, std::string path){
    file.open(path);
    if(!file){ // Checks if file was opened successfully
        std::cout << "File at path /'" << path << "/' could not be opened."
        << " Terminating program..." << std::endl;
        exit(1);
    }
}


/**
 * @brief Opens a file for writing
 * 
 * @param file, ofstream object for opening the file
 * @param path, string of the path to the file
 */
void openFile(std::ofstream &file, std::string path){
    file.open(path);
    if(!file){ // Checks if file was opened successfully
        std::cout << "File at path /'" << path << "/' could not be opened."
        << " Terminating program..." << std::endl;
        exit(1);
    }
}


/**
 * @brief Converts the string data type into the unsigned int type.
 * Since the output is unsigned, this function will simply skip over negative signs
 * (Ex: -3 = 3). This function will stop reading the string once it encounters a
 * decimal as well.
 * 
 * @param str, the string to be converted
 * @return unsigned, the number as an unsigned int
 */
unsigned stringToUnsignedInt(std::string str){
    unsigned num = 0; // Stores value to be returned
    // Below loop repeats so long as the value at the index is not a decimal, and
    // the index is less than length of the string
    for(unsigned i = 0; str[i] != '.' && (i < str.length()); ++i){
        if(str[i] >= '0' && str[i] <= '9'){
            num *= 10; // Multiplies the working number by 10 to increase its place by one to the left
            num += (str[i] - '0'); // Adds the current number to the working number
        }
    }
    return num;
}


/**
 * @brief Converts the string data type into the double data type. Supports
 * negatives and decimals(obviously)
 * 
 * @param str, the string to be converted
 * @return double, the number as a double
 */
double stringToDouble(std::string str){
    double num = 0; // Stores value to be returned
    double decimalMultiplier = 0.1; // Value multiplied to numbers after the decimal
    unsigned index = 0; // Index for use in accessing elements of the string
    bool negative; // Whether the number is negative or not

    // Checks if the number is negative (has a negative sign as first character)
    if(str.length() > 0 && str[0] == '-'){
        negative = true;
    } else {
        negative = false;
    }
    // Loops through string until a decimal or the end of the string is encountered
    for(; str[index] != '.' && (index < str.length()); ++index){
        if(str[index] >= '0' && str[index] <= '9'){
            num *= 10; // Moves the working number to the left a digit
            num += (str[index] - '0'); // Adds the current number
        }
    }
    if(index < str.length()){ // If a decimal was encountered
        ++index; // Moves index to character following decimal
        for(; index < str.length(); ++index){
            if(str[index] >= '0' && str[index] <= '9'){
                num += ((str[index] - '0') * decimalMultiplier); // Divides the number by the decimal multiplier
                decimalMultiplier *= 0.1; // Decimal multiplier gets divided by 10 each iteration
            }
        }
    }
    // If the number is negative, returns the negative version of it, otherwise just returns the number
    if(negative){
        return -num;
    }
    return num;
}


/**
 * @brief Removes all single (') and double ("") quotes from a string
 * 
 * @param str, the string to have the quotes removed from
 * @return std::string, the string without the quotes
 */
std::string removeQuotes(std::string str){
    std::string newString; // The string to be returned
    // This loop simply checks if the current character is one of the quotes.
    // If it is not, then it adds it to the new string, otherwise it will skip it
    for(unsigned i = 0; i < str.length(); ++i){
        if(str[i] != 34 && str[i] != 39){ // 34 is double quote, 39 is single quote
            newString += str[i];
        }
    }
    return newString;
}


// Returns whether a string only contains whitespace characters
// These are spaces " ", tabs "\t", carriage returns "\r", and newlines "\n"

/**
 * @brief Returns whether a string only contains whitespace characters. Whitespace characters
 * are defined in this function as spaces " ", tabs "\t", carriage returns "\r", and newlines "\n"
 * 
 * @param str, the string to be checked
 * @return true, the string only contains whitespace
 * @return false, the string has other characters
 */
bool stringOnlyWhitespace(std::string str){
    if(str.length() <= 0){
        return true;
    }
    // Loops through each character and checks if it is one other
    // than the whitespace characters. If it is, returns false
    for(unsigned i = 0; i < str.length(); ++i){
        if(str[i] != ' ' && str[i] != '\t' && str[i] != '\r' && str[i] != '\n'){
            return false;
        }
    }

    // If the loop finishes without finding a non-whitespace character,
    // true will be returned
    return true;
}
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


void keepOnlyLetters(std::string & str){
    std::string newString = "";
    for(unsigned i = 0; i < str.length(); ++i){
        if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')){
            newString += str[i];
        }
    }
    str = newString;
}


// Returns whether a string only contains whitespace characters
// These are spaces " ", tabs "\t", carriage returns "\r", and newlines "\n"

/**
 * @brief Returns whether a string only contains whitespace characters. Whitespace characters
 * are defined in this function as spaces " ", tabs "\t", vertical tabs "\v", carriage returns "\r", and newlines "\n"
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
        if(str[i] != ' ' && str[i] != '\t' && str[i] != '\v' && str[i] != '\r' && str[i] != '\n'){
            return false;
        }
    }

    // If the loop finishes without finding a non-whitespace character,
    // true will be returned
    return true;
}

void convertStringToLower(std::string &str){
    for(unsigned i = 0; i < str.length(); ++i){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            str[i] = str[i] - 'A' + 'a';
        }
    }
}

void readData(std::vector<career> &vec, std::ifstream &file){
    std::string line;
    std::string section;
    int dataPiece;
    bool inQuotes = false;
    // Skips the first non-blank line, as well as all the blank ones that came before it
    do {
        getline(file,line);
    } while(stringOnlyWhitespace(line));
    while(file.peek() != EOF){
        line = "";
        inQuotes = false;
        dataPiece = 0;
        std::getline(file,line);
        if(!stringOnlyWhitespace(line)){
            career currentCareer;
            section = "";
            for(unsigned i = 0; i < line.length(); ++i){
                if((line[i] == ',' || i == line.length()-1) && !inQuotes ){
                    if(i == line.length()-1){
                        section += line[i];
                    }
                    ++dataPiece;
                    if(dataPiece == 1){
                        currentCareer.totalPopulation = stringToUnsignedInt(section);
                    } else if(dataPiece == 2){
                        currentCareer.name = section;
                    } else if(dataPiece == 3){
                        currentCareer.meanSalary = stringToDouble(section);
                    } else if(dataPiece == 4){
                        currentCareer.medianSalary = stringToDouble(section);
                    } else if(dataPiece == 5){
                        currentCareer.numAsians = stringToUnsignedInt(section);
                    } else if(dataPiece == 6){
                        currentCareer.numMinorities = stringToUnsignedInt(section);
                    } else if(dataPiece == 7){
                        currentCareer.numWhites = stringToUnsignedInt(section);
                    } else if(dataPiece == 8){
                        currentCareer.numFemales = stringToUnsignedInt(section);
                    } else if(dataPiece == 9){
                        currentCareer.numMales = stringToUnsignedInt(section);
                    } else if(dataPiece == 10){
                        currentCareer.numBachelors = stringToUnsignedInt(section);
                    } else if(dataPiece == 11){
                        currentCareer.numDoctorate = stringToUnsignedInt(section);
                    } else if(dataPiece == 12){
                        currentCareer.numMasters = stringToUnsignedInt(section);
                    } 
                    section = "";
                } else if(line[i] == '"'){
                    inQuotes = !inQuotes;
                } else {
                    section += line[i];
                }
            }
            vec.push_back(currentCareer);
        }
    }
}

/**
 * @brief Will display a career's name and its specified info. Info should be a character
 * that represents a piece of data to display.
 * 'p' = population
 * 's' = mean salary
 * 'S' = median salary
 * 'A' = num asians
 * 'M' = num minorities
 * 'W' = num whites
 * 'm' = num males
 * 'f' = num females
 * 'k' = ration of females to total population
 * 'b' = num bachelors
 * 'd' = num doctorate
 * 'g' = num masters (graduate school)
 * 
 * @param data 
 * @param info 
 */
void displayCareer(career * data, char info){
    std::cout << std::fixed << std::setprecision(2);
    std::cout << std::setw(36) << std::left << data->name << " ";
    if(info == 'p'){
        std::cout << "#" << std::setw(11) << std::right << data->totalPopulation;
    } else if(info == 's'){
        std::cout << "\033[38;5;46m" << '$' << "\033[0m" << std::setw(11) << std::right << data->meanSalary;
    } else if(info == 'S'){
        std::cout << "\033[38;5;46m" << '$' << "\033[0m" << std::setw(11) << std::right << data->medianSalary;
    } else if(info == 'A'){
        std::cout << "#" << std::setw(11) << std::right << data->numAsians;
    } else if(info == 'M'){
        std::cout << "#" << std::setw(11) << std::right << data->numMinorities;
    } else if(info == 'W'){
        std::cout << "#" << std::setw(11) << std::right << data->numWhites;
    } else if(info == 'm'){
        std::cout << "#" << std::setw(11) << std::right << data->numMales;
    } else if(info == 'f'){
        std::cout << "#" << std::setw(11) << std::right << data->numFemales;
    } else if(info == 'b'){
        std::cout << "#" << std::setw(11) << std::right << data->numBachelors;
    } else if(info == 'd'){
        std::cout << "#" << std::setw(11) << std::right << data->numDoctorate;
    } else if(info == 'g'){
        std::cout << "#" << std::setw(11) << std::right << data->numMasters;
    } else if(info == 'k'){
        std::cout << std::setw(4) << std::right << std::fixed << std::setprecision(1) 
            << std::endl << std::setw(7) << "Females" << std::setw(32) 
            << (static_cast<double>(data->numFemales)/data->totalPopulation)*100
            << "% Female" << std::right << std::setw(33) << "Males" << std::endl;
            std::cout << std::setw(8) << std::left << data->numFemales;
        
        for(unsigned i = 0; i < 64; ++i){
            if(i < 64*(static_cast<double>(data->numFemales)/data->totalPopulation)){
                std::cout << "\033[38;5;200m" << '#' << "\033[0m" << std::flush;
            } else {
                std::cout << "\033[38;5;27m" << '@' << "\033[0m" << std::flush;
            }
        }
        std::cout << std::setw(8) << std::right << data->numMales << std::endl;
    }

    std::cout << std::endl;
}


void displayCareer(career * data){
    unsigned dataWidth = 23;
    std::cout << std::endl << "\033[4m" << data->name << "\033[0m" << ":" << std::endl;
    std::cout << std::setw(dataWidth) << std::left <<  "Population:" 
        << "#" << std::setw(11) << std::right << data->totalPopulation << std::endl;
    std::cout << std::setw(dataWidth) << std::left <<  "Mean Salary:" 
        << "\033[38;5;46m" << '$' << "\033[0m" << std::setw(11) << std::right << data->meanSalary << std::endl;
    std::cout << std::setw(dataWidth) << std::left <<  "Median Salary:" 
        << "\033[38;5;46m" << '$' << "\033[0m" << std::setw(11) << std::right << data->medianSalary << std::endl;
    std::cout << std::setw(dataWidth) << std::left <<  "Number of Asians:" 
        << "#" << std::setw(11) << std::right << data->numAsians << std::endl;
    std::cout << std::setw(dataWidth) << std::left <<  "Number of Minorities:" 
        << "#" << std::setw(11) << std::right << data->numMinorities << std::endl;
    std::cout << std::setw(dataWidth) << std::left <<  "Number of Whites:" 
        << "#" << std::setw(11) << std::right << data->numWhites << std::endl;

    std::cout << std::setw(4) << std::right << std::fixed << std::setprecision(1) 
        << std::endl << std::setw(7) << "Females" << std::setw(32) 
        << (static_cast<double>(data->numFemales)/data->totalPopulation)*100
        << "% Female" << std::right << std::setw(33) << "Males" << std::endl;
        std::cout << std::setw(8) << std::left << data->numFemales;
    
    for(unsigned i = 0; i < 64; ++i){
        if(i < 64*(static_cast<double>(data->numFemales)/data->totalPopulation)){
            std::cout << "\033[38;5;200m" << '#' << "\033[0m" << std::flush;
        } else {
            std::cout << "\033[38;5;27m" << '@' << "\033[0m" << std::flush;
        }
    }
    std::cout << std::setw(8) << std::right << data->numMales << std::endl << std::endl;

    std::cout << std::setw(dataWidth) << std::left <<  "Number of Bachelor's:" 
        << "#" << std::setw(11) << std::right << data->numBachelors << std::endl;
    std::cout << std::setw(dataWidth) << std::left <<  "Number of Masters:" 
        << "#" << std::setw(11) << std::right << data->numMasters << std::endl;
    std::cout << std::setw(dataWidth) << std::left <<  "Number of Doctorate's:" 
        << "#" << std::setw(11) << std::right << data->numDoctorate << std::endl;
}



void pointToVectorElements(std::vector<career> &original, std::vector<career *> &pointers){
    pointers.clear();
    for(unsigned i = 0; i < original.size(); ++i){
        pointers.push_back(&original[i]);
    }
}


void displayMultipleCareers(const std::vector<career *> &pointers, char info, unsigned num){
    std::cout << std::endl;
    for(unsigned i = 0; i < num && i < pointers.size(); ++i){
        std::cout << std::setw(2) << std::right << i+1 << std::setw(2) << ". ";
        displayCareer(pointers[i], info);
    }
}

void displayMultipleCareers(const std::vector<career *> &pointers, char info){
    for(unsigned i = 0; i < pointers.size(); ++i){
        std::cout << std::setw(2) << std::right << i+1 << std::setw(2) << ". ";
        displayCareer(pointers[i], info);
    }
}

void displayMultipleCareers(const std::vector<career *> &pointers){
    unsigned end = pointers.size()/2;
    if(end != static_cast<double>(pointers.size())/2){
        end++;
    }
    for(unsigned i = 0; i < end; ++i){
        std::cout << std::setw(2) << std::right << i+1 << std::setw(1) << "." << std::setw(36) << std::left
        << pointers[i]->name;
        if(end+i < pointers.size()){
            std::cout << std::setw(2) << std::right << end+i+1 << std::setw(1) << "."
            << std::setw(36) << std::left << pointers[end+i]->name;
        }
        std::cout << std::endl;
    }
}

/**
 * @brief Sorts the vector of pointers that point to the vector of careers
 * 
 * @param pointers, The vector of pointers that point to the vector of careers
 * @param info, A character of the list below, which will determine what criteria to sort by
 * 'n' = name of the career
 * 'p' = population
 * 's' = mean salary
 * 'S' = median salary
 * 'A' = num asians
 * 'M' = num minorities
 * 'W' = num whites
 * 'm' = num males
 * 'f' = num females
 * 'k' = percentage females to total population
 * 'b' = num bachelors
 * 'd' = num doctorate
 * 'g' = num masters (graduate school)
 * Note: the vector will not be sorted if the argument is not one of these characters
 * @param direction, a character, either 'a' to sort in ascending order (low to high), or 
 * 'd' to sort in descending order (high to low). If the argument is neither of these
 * characters, the vector will be sorted in ascending order
 */
void sortPointerVector(std::vector<career *> &pointers, const char info, const char direction){
    unsigned swapIndex;
    career * tempPtr;
    bool ascending = true;
    if(direction == 'd' || direction == 'D'){
        ascending = false;
    }
    for(unsigned startIndex = 0;startIndex < pointers.size(); ++startIndex){
        tempPtr = nullptr;
        swapIndex = startIndex;
        for(unsigned currentIndex = startIndex + 1; currentIndex < pointers.size(); ++currentIndex){
            if(info == 'n'){
                std::string swapWorkString = pointers[swapIndex]->name;
                convertStringToLower(swapWorkString);
                keepOnlyLetters(swapWorkString);
                std::string currentWorkString = pointers[currentIndex]->name;
                convertStringToLower(currentWorkString);
                keepOnlyLetters(currentWorkString);

                if(!ascending){
                    for(unsigned i = 0; i < swapWorkString.length() && i < currentWorkString.length(); ++i){
                        if(currentWorkString[i] > swapWorkString[i]){
                            swapIndex = currentIndex;
                            break;
                        } else if(swapWorkString[i] > currentWorkString[i]){
                            break;
                        }
                    }
                } else {
                    for(unsigned i = 0; i < swapWorkString.length() && i < currentWorkString.length(); ++i){
                        if(currentWorkString[i] < swapWorkString[i]){
                            swapIndex = currentIndex;
                            break;
                        } else if(swapWorkString[i] < currentWorkString[i]){
                            break;
                        }
                    }
                }
            } else if(info == 'p'){
                if(!ascending){
                    if(pointers[currentIndex]->totalPopulation > pointers[swapIndex]->totalPopulation){
                        swapIndex = currentIndex;
                    }
                } else {
                    if(pointers[currentIndex]->totalPopulation < pointers[swapIndex]->totalPopulation){
                        swapIndex = currentIndex;
                    }
                }
            } else if(info == 's'){
                if(!ascending){
                    if(pointers[currentIndex]->meanSalary > pointers[swapIndex]->meanSalary){
                        swapIndex = currentIndex;
                    }
                } else {
                    if(pointers[currentIndex]->meanSalary < pointers[swapIndex]->meanSalary){
                        swapIndex = currentIndex;
                    }
                }
            } else if(info == 'S'){
                if(!ascending){
                    if(pointers[currentIndex]->medianSalary > pointers[swapIndex]->medianSalary){
                        swapIndex = currentIndex;
                    }
                } else {
                    if(pointers[currentIndex]->medianSalary < pointers[swapIndex]->medianSalary){
                        swapIndex = currentIndex;
                    }
                }
            } else if(info == 'A'){
                if(!ascending){
                    if(pointers[currentIndex]->numAsians > pointers[swapIndex]->numAsians){
                        swapIndex = currentIndex;
                    }
                } else {
                    if(pointers[currentIndex]->numAsians < pointers[swapIndex]->numAsians){
                        swapIndex = currentIndex;
                    }
                }
            } else if(info == 'M'){
                if(!ascending){
                    if(pointers[currentIndex]->numMinorities > pointers[swapIndex]->numMinorities){
                        swapIndex = currentIndex;
                    }
                } else {
                    if(pointers[currentIndex]->numMinorities < pointers[swapIndex]->numMinorities){
                        swapIndex = currentIndex;
                    }
                }
            } else if(info == 'W'){
                if(!ascending){
                    if(pointers[currentIndex]->numWhites > pointers[swapIndex]->numWhites){
                        swapIndex = currentIndex;
                    }
                } else {
                    if(pointers[currentIndex]->numWhites < pointers[swapIndex]->numWhites){
                        swapIndex = currentIndex;
                    }
                }
            } else if(info == 'm'){
                if(!ascending){
                    if(pointers[currentIndex]->numMales > pointers[swapIndex]->numMales){
                        swapIndex = currentIndex;
                    }
                } else {
                    if(pointers[currentIndex]->numMales < pointers[swapIndex]->numMales){
                        swapIndex = currentIndex;
                    }
                }
            } else if(info == 'f'){
                if(!ascending){
                    if(pointers[currentIndex]->numFemales > pointers[swapIndex]->numFemales){
                        swapIndex = currentIndex;
                    }
                } else {
                    if(pointers[currentIndex]->numFemales < pointers[swapIndex]->numFemales){
                        swapIndex = currentIndex;
                    }
                }
            } else if(info == 'b'){
                if(!ascending){
                    if(pointers[currentIndex]->numBachelors > pointers[swapIndex]->numBachelors){
                        swapIndex = currentIndex;
                    }
                } else {
                    if(pointers[currentIndex]->numBachelors < pointers[swapIndex]->numBachelors){
                        swapIndex = currentIndex;
                    }
                }
            } else if(info == 'd'){
                if(!ascending){
                    if(pointers[currentIndex]->numDoctorate > pointers[swapIndex]->numDoctorate){
                        swapIndex = currentIndex;
                    }
                } else {
                    if(pointers[currentIndex]->numDoctorate < pointers[swapIndex]->numDoctorate){
                        swapIndex = currentIndex;
                    }
                }
            } else if(info == 'g'){
                if(!ascending){
                    if(pointers[currentIndex]->numMasters > pointers[swapIndex]->numMasters){
                        swapIndex = currentIndex;
                    }
                } else {
                    if(pointers[currentIndex]->numMasters < pointers[swapIndex]->numMasters){
                        swapIndex = currentIndex;
                    }
                }
            } else if(info == 'k'){
                if(!ascending){
                    if((static_cast<double>(pointers[currentIndex]->numFemales) / pointers[currentIndex]->totalPopulation) 
                    > (static_cast<double>(pointers[swapIndex]->numFemales) / pointers[swapIndex]->totalPopulation)){
                        swapIndex = currentIndex;
                    }
                } else {
                    if((static_cast<double>(pointers[currentIndex]->numFemales) / pointers[currentIndex]->totalPopulation) 
                    < (static_cast<double>(pointers[swapIndex]->numFemales) / pointers[swapIndex]->totalPopulation)){
                        swapIndex = currentIndex;
                    }
                }
            }
        }
        tempPtr = pointers[startIndex];
        pointers[startIndex] = pointers[swapIndex];
        pointers[swapIndex] = tempPtr;
    }
}


unsigned getMenuOption(unsigned min, unsigned max){
    std::cout << "Enter a menu option (" << min << "-" << max << "): ";
    std::string input;
    unsigned output;
    do {
        input = "";
        std::getline(std::cin,input);
        if(!stringOnlyWhitespace(input)){
            output = stringToUnsignedInt(input);
        }
    } while(output < min || output > max);
    return output;
}

void displayMenu(std::vector<career *> &pointers){
    std::cout << std::endl << std::endl;
    std::cout << "2015 National Survey of Recent College Graduates" << std::endl;
    std::cout << "1.  Top 10 Majors with the Highest Mean Salary" << std::endl;
    std::cout << "2.  Top 10 Majors with the Lowest Mean Salary" << std::endl;
    std::cout << "3.  Top 10 Majors with the Highest Median Salary" << std::endl;
    std::cout << "4.  Top 10 Majors with the Lowest Median Salary" << std::endl;
    std::cout << "5.  What are the Top 5 Majors with the Highest Number of Asians" << std::endl;
    std::cout << "6.  What are the Top 5 Majors with the Lowest Number of Asians" << std::endl;
    std::cout << "7.  What are the Top 5 Majors with the Highest Number of Minorities" << std::endl;
    std::cout << "8.  What are the Top 5 Majors with the Lowest Number of Minorities" << std::endl;
    std::cout << "9.  Top 5 Majors with Highest Percentage of Females" << std::endl;
    std::cout << "10. Top 5 Majors with Highest Percentage of Males" << std::endl;
    std::cout << "11. Display Information for a Specific Major" << std::endl;
    std::cout << "12. Exit" << std::endl;
}
/**
 * @file main.cpp
 * @author Josh Gillum
 * @brief Program reads career data from a csv file and provides 
 * an interface for the user to access it.
 * @version 0.1
 * @date 2023-08-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>

#include "analytics.h"

int main(){
    std::string dataPath = "./graduates2015.csv"; // Path to file with data
    std::vector<career> graduateData; // Vector of career objects
    std::ifstream dataFile; // Ifstream object for reading file
    openFile(dataFile, dataPath); // Opens the file for reading
    readData(graduateData, dataFile); // Reads the data from the file, creates career objects and adds them to the vector
    dataFile.close();
    std::vector<career *> graduatePointers; // Vector of pointers. They will each point to an object of the graduateData vector
    pointToVectorElements(graduateData,graduatePointers); // Creates a pointer for each career object and adds them to the pointer vector

    // Menu
    unsigned option;
    do {
        displayMenu(graduatePointers);
        option = getMenuOption(1,13);
        if(option == 1){ // Highest mean salary
            sortPointerVector(graduatePointers,'s','d');
            displayMultipleCareers(graduatePointers,'s', 10);
        } else if(option == 2){ // Lowest mean salary
            sortPointerVector(graduatePointers,'s','a');
            displayMultipleCareers(graduatePointers,'s', 10);
        } else if(option == 3){ // Highest median salary
            sortPointerVector(graduatePointers,'S','d');
            displayMultipleCareers(graduatePointers,'S', 10);
        } else if(option == 4){ // Lowest median salary
            sortPointerVector(graduatePointers,'S','a');
            displayMultipleCareers(graduatePointers,'S', 10);
        } else if(option == 5){ // Highest number of asians
            sortPointerVector(graduatePointers,'A','d');
            displayMultipleCareers(graduatePointers,'A', 5);
        } else if(option == 6){ // Lowest number of asians
            sortPointerVector(graduatePointers,'A','a');
            displayMultipleCareers(graduatePointers,'A', 5);
        } else if(option == 7){ // Highest number of minorities
            sortPointerVector(graduatePointers,'M','d');
            displayMultipleCareers(graduatePointers,'M', 5);
        } else if(option == 8){ // Lowest number of minorities
            sortPointerVector(graduatePointers,'M','a');
            displayMultipleCareers(graduatePointers,'M', 5);
        } else if(option == 9){ // Highest percentage of females
            sortPointerVector(graduatePointers,'k','d');
            displayMultipleCareers(graduatePointers,'k', 5);
        } else if(option == 10){ // Highest percentage of males
            sortPointerVector(graduatePointers,'k','a');
            displayMultipleCareers(graduatePointers,'k', 5);
        } else if(option == 11){ // Lists each major
            sortPointerVector(graduatePointers,'n','a');
            displayMultipleCareers(graduatePointers);
            unsigned choice = getMenuOption(1,graduatePointers.size()) - 1;
            displayCareer(graduatePointers[choice]);
        } else if(option == 12){ // Exits program
            exit(1);
        } else if(option == 13){ // Aggregate Data
            displayTotals(graduatePointers);
        } else { // Should never happen, since getMenuOption will only allow options 1-12, but...
            continue;
        }
        std::cout << std::endl << "Press enter to continue ...";
        std::string temp;
        std::getline(std::cin,temp);
    } while(option != 12);

    return 0;
}
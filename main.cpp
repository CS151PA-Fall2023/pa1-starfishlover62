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
    std::string dataPath = "./graduates2015.csv";
    std::vector<career> graduateData;
    std::ifstream dataFile; 
    openFile(dataFile, dataPath);
    readData(graduateData, dataFile);
    std::vector<career *> graduatePointers;
    pointToVectorElements(graduateData,graduatePointers);

    unsigned option;
    do {
        displayMenu(graduatePointers);
        option = getMenuOption(1,12);
        if(option == 1){
            sortPointerVector(graduatePointers,'s','d');
            displayMultipleCareers(graduatePointers,'s', 10);
        } else if(option == 2){
            sortPointerVector(graduatePointers,'s','a');
            displayMultipleCareers(graduatePointers,'s', 10);
        } else if(option == 3){
            sortPointerVector(graduatePointers,'S','d');
            displayMultipleCareers(graduatePointers,'S', 10);
        } else if(option == 4){
            sortPointerVector(graduatePointers,'S','a');
            displayMultipleCareers(graduatePointers,'S', 10);
        } else if(option == 5){
            sortPointerVector(graduatePointers,'A','d');
            displayMultipleCareers(graduatePointers,'A', 5);
        } else if(option == 6){
            sortPointerVector(graduatePointers,'A','a');
            displayMultipleCareers(graduatePointers,'A', 5);
        } else if(option == 7){
            sortPointerVector(graduatePointers,'M','d');
            displayMultipleCareers(graduatePointers,'M', 5);
        } else if(option == 8){
            sortPointerVector(graduatePointers,'M','a');
            displayMultipleCareers(graduatePointers,'M', 5);
        } else if(option == 9){
            sortPointerVector(graduatePointers,'k','d');
            displayMultipleCareers(graduatePointers,'k', 5);
        } else if(option == 10){
            sortPointerVector(graduatePointers,'k','a');
            displayMultipleCareers(graduatePointers,'k', 5);
        } else if(option == 11){
            sortPointerVector(graduatePointers,'n','a');
            displayMultipleCareers(graduatePointers);
            unsigned choice = getMenuOption(1,graduatePointers.size()) - 1;
            displayCareer(graduatePointers[choice]);
        } else if(option == 12){
            exit(1);
        } else {
            std::cout << "Incorrect menu option... Exiting program" << std::endl;
            exit(1);
        }
        std::cout << std::endl << "Press enter to continue ...";
        std::string temp;
        std::getline(std::cin,temp);
    } while(option != 12);

    return 0;
}
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


    displayMenu(graduatePointers);

    return 0;
}
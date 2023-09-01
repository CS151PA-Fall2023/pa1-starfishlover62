/**
 * @file analytics.h
 * @author Josh Gillum
 * @brief Career structure definition and function prototypes
 * @version 0.1
 * @date 2023-08-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef ANALYTICS_H
#define ANALYTICS_H

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream> 
#include <vector>
#include <cstdlib>


struct career{
    career() : career("",0,0,0,0,0,0,0,0,0,0,0) {
        
    }
    career(std::string fieldName, double meanSal, double medSal,
     unsigned pop, unsigned asian, unsigned minority, 
     unsigned white, unsigned female, unsigned male, unsigned degreeB,
     unsigned degreeM, unsigned degreeD){
        name = fieldName;
        meanSalary = meanSal;
        medianSalary = medSal;
        totalPopulation = pop;
        numAsians = asian;
        numMinorities = minority;
        numWhites = white;
        numFemales = female;
        numMales = male;
        numBachelors = degreeB;
        numMasters = degreeM;
        numDoctorate = degreeD;
    }


    unsigned totalPopulation,
        numAsians,
        numMinorities,
        numWhites,
        numFemales,
        numMales,
        numBachelors,
        numDoctorate,
        numMasters;
    std::string name;
    double meanSalary,
        medianSalary;
};

void openFile(std::ifstream &file, std::string path);
void openFile(std::ofstream &file, std::string path);
void readData(std::vector<career> &vec, std::ifstream &file);
void pointToVectorElements(std::vector<career> &original, std::vector<career *> &pointers);

unsigned stringToUnsignedInt(std::string str);
double stringToDouble(std::string str);
std::string removeQuotes(std::string str);
bool stringOnlyWhitespace(std::string str);
void convertStringToLower(std::string & str);
void keepOnlyLetters(std::string & str);

void displayCareer(career * data, char info);
void displayCareer(career * data);
void displayMultipleCareers(const std::vector<career *> &pointers, char info, unsigned num);
void displayMultipleCareers(const std::vector<career *> &pointers, char info);
void displayMultipleCareers(const std::vector<career *> &pointers);
void displayTotals(std::vector<career *> data);

void sortPointerVector(std::vector<career *> &pointers, const char info, const char direction);

void displayMenu(std::vector<career *> &pointers);
unsigned getMenuOption(unsigned min, unsigned max);


#endif

#ifndef ANALYTICS_H
#define ANALYTICS_H

#include <iostream>
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
unsigned stringToUnsignedInt(std::string str);
double stringToDouble(std::string str);
std::string removeQuotes(std::string str);
bool stringOnlyWhitespace(std::string str);

#endif

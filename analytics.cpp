#include "analytics.h"

void openFile(std::ifstream &file, std::string path){
    file.open(path);
    if(!file){
        std::cout << "File at path /'" << path << "/' could not be opened."
        << " Terminating program..." << std::endl;
        exit(1);
    }
}


void openFile(std::ofstream &file, std::string path){
    file.open(path);
    if(!file){
        std::cout << "File at path /'" << path << "/' could not be opened."
        << " Terminating program..." << std::endl;
        exit(1);
    }
}

// Does not support negative numbers since it is unsigned and
// does not support decimals since it is an integer.
// It will simply skip a negative sign, and stops
// reading when a period is encountered.
unsigned stringToUnsignedInt(std::string str){
    unsigned num = 0;
    for(unsigned i = 0; str[i] != '.' && (i < str.length()); ++i){
        if(str[i] >= '0' && str[i] <= '9'){
            num *= 10;
            num += (str[i] - '0');
        }
    }
    return num;
}

// Supports negative numbers
double stringToDouble(std::string str){
    double num = 0;
    double decimalMultiplier = 0.1;
    unsigned index = 0;
    bool negative;
    if(str.length() > 0 && str[0] == '-'){
        negative = true;
    } else {
        negative = false;
    }
    for(; str[index] != '.' && (index < str.length()); ++index){
        if(str[index] >= '0' && str[index] <= '9'){
            num *= 10;
            num += (str[index] - '0');
        }
    }
    if(index < str.length()){
    ++index;
    for(; index < str.length(); ++index){
        if(str[index] >= '0' && str[index] <= '9'){
            num += ((str[index] - '0') * decimalMultiplier);
            decimalMultiplier *= 0.1;
        }
    }
    }
    if(negative){
        return -num;
    }
    return num;
}

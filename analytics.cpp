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

unsigned stringToUnsignedInt(std::string str){
    unsigned num = 0;
    for(unsigned i = 0; str[i] != '.' && (i < str.length()); ++i){
        std::cout << str[i];
        if(str[i] >= '0' && str[i] <= '9'){
            num *= 10;
            num += (str[i] - '0');
        }
    }
    std::cout << std::endl;
    return num;
}
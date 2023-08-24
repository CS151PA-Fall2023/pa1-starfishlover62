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
#include <iostream>
#include <fstream>
#include <iomanip>

#include "analytics.h"

int main(){

    std::cout << std::fixed << std::setprecision(3);
    std::cout << stringToUnsignedInt("-1586309.374") << std::endl;
    std::cout << stringToDouble("-1586309.374") << std::endl;

    return 0;
}
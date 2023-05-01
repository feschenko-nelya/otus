#include <iostream>
#include "utils/utils.h"

int main(int, char**)
{
    std::cout << "Build: " << globalGetVersion() << std::endl;
    std::cout << "Hello, world!" << std::endl;
    
    return 0;
}
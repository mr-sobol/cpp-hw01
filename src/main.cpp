#include <iostream>

#include "version.h"

int main()
{
    std::cout << "build " << PROJECT_VERSION_PATCH << std::endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

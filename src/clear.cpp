#include "constants.h"
#include <iomanip>
#include <iostream>
#include <string>

void clear(std::string message) {
    std::cout << std::string(32, '\n') << message << std::endl;
    std::cout << std::setw(80) << std::setfill('-') << '\n'
              << std::setfill(' ');
}
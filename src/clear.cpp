#include "constants.h"
#include <iomanip>
#include <iostream>
#include <string>

// Funtkion för att städa upp utskriftsfönstret. Skriver ut en mängd newlines,
// ett meddelande som sänds med som parameter, och avgränsar utskriften från
// nästa utskrift.
void clear(std::string message) {
    std::cout << std::string(32, '\n') << message << std::endl;
    std::cout << std::setw(80) << std::setfill('-') << '-';
    std::cout << std::setfill(' ') << std::endl;
}
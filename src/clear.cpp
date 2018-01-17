#include "constants.h"
#include <iomanip>
#include <iostream>
#include <string>

// Funtkion f�r att st�da upp utskriftsf�nstret. Skriver ut en m�ngd newlines,
// ett meddelande som s�nds med som parameter, och avgr�nsar utskriften fr�n
// n�sta utskrift.
void clear(std::string message) {
    std::cout << std::string(32, '\n') << message << std::endl;
    std::cout << std::setw(80) << std::setfill('-') << '-';
    std::cout << std::setfill(' ') << std::endl;
}
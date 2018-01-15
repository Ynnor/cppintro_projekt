#include "constants.h"
#include <iomanip>
#include <iostream>

void printPerson(Person p) {
    std::cout << std::left << std::setw(10) << p.signature << std::setw(30)
              << p.firstName + " " + p.lastName << std::setw(6) << std::right
              << std::setprecision(2) << std::fixed << p.height << std::endl;
}
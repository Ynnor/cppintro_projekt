#include "constants.h"
#include <iomanip>
#include <iostream>


void printPerson(Person p) {
    std::cout << std::left << std::setw(10) << p.signature << std::setw(30)
              << p.firstName << " " << p.lastName << std::setw(5) << p.height;
}
#include "constants.h"
#include <conio.h>
#include <iomanip>
#include <iostream>
#include <vector>

void print(std::vector<Person> persons) {
    for (unsigned int i = 0; i <= persons.size(); i += 20) {
        std::cout << std::string(32, '\n');
        std::cout << "***** NAME LIST *****" << std::endl
                  << "Antal personer i listan: " << persons.size()
                  << std::string(2, '\n');
        std::cout << std::left << std::setw(4) << "Nr" << std::setw(10)
                  << "Signatur" << std::setw(30) << "Namn" << std::setw(10)
                  << "Längd [m]" << std::endl;
        for (unsigned int j = 0; j < 20 && j + i < persons.size(); j++) {
            std::cout << std::right << std::setw(2) << j + i + 1 << ". ";
            printPerson(persons[i + j]);
        }
        _getch();
    }
    clear("");
}

void printPerson(Person p) {
    std::cout << std::left << std::setw(10) << p.signature << std::setw(30)
              << p.firstName + " " + p.lastName << std::setw(6) << std::right
              << std::setprecision(2) << std::fixed << p.height << std::endl;
}
#include "constants.h"
#include "printPerson.cpp"
#include <iomanip>
#include <iostream>
#include <vector>

void printList(std::vector<Person> persons) {
    for (int i = 0; i <= persons.size() / 20; i++) {
        std::cout << std::string(32, '\n');
        std::cout << "***** NAME LIST *****" << std::endl
                  << "Antal personer i listan: " << persons.size()
                  << std::string(2, '\n');
        std::cout << std::left << std::setw(4) << "Nr" << std::setw(10)
                  << "Signatur" << std::setw(30) << "Namn" << std::setw(10)
                  << "Längd [m]" << std::endl;
        for (int j = 0 + 20 * i; j + 20 * i < persons.size(); j++) {
            std::cout << std::right << std::setw(2) << j + 1 << ". ";
            printPerson(persons[j]);
        }
    }
}
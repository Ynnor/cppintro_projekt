#include "constants.h"
#include <iostream>
#include <string>
#include <vector>

void findPerson(std::vector<Person> persons) {
    bool found = false;
    std::string signature;
    std::cout << "Skriv in signaturen du vill söka efter: ";
    getline(std::cin, signature);
    for (auto p : persons) {
        if (p.signature == signature) {
            std::cout << "Sökningen fann: " << p.firstName << p.lastName;
            found = true;
        }
    }
    if (!found) {
        std::cout << "Personen hittades inte i listan";
    }
}

bool personExist(std::vector<Person> persons, std::string searchString) {
    for (int i = 0; i < persons.size(); i++) {
        if (persons[i].signature == searchString) {
            return true;
        }
    }
    return false;
}
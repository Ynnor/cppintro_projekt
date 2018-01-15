#include "constants.h"
#include <iostream>
#include <string>
#include <vector>

void find(std::vector<Person> persons) {
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
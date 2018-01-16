#include "constants.h"
#include <iostream>

void deletePerson(std::vector<Person> &persons) {
    std::string signature;
    int index = -1;
    std::cout
        << "Skriv in signaturen för den person du vill radera ur listan: ";
    getline(std::cin, signature);

    for (unsigned int i = 0; i < persons.size(); i++) {
        if (persons[i].signature == signature) {
            index = i;
        }
    }
    if (index > -1) {
        clear(persons[index].firstName + " " + persons[index].lastName + " har tagits bort från listan.");
        persons.erase(persons.begin() + index);
    } else {
        clear("Ingen med signaturen " + signature + " finns med i listan.");
    }
}
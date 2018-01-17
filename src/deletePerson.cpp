#include "constants.h"
#include <iostream>

// Funktion som tar bort en person från listan.
void deletePerson(std::vector<Person> &persons) {
    std::string signature;
    clear("Ta bort person.");
    std::cout
        << "Skriv in signaturen för den person du vill radera ur listan: ";
    getline(std::cin, signature);

    // Om personen existerar, tas personen med motsvarande index bort från
    // listan.
    int index = personExist(persons, signature);
    ;
    if (index > -1) {
        clear(persons[index].firstName + " " + persons[index].lastName +
              " har tagits bort från listan.");
        persons.erase(persons.begin() + index);
    } else {
        clear("Ingen med signaturen " + signature + " finns med i listan.");
    }
}
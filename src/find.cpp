#include "constants.h"
#include <iostream>
#include <string>
#include <vector>

// Funktion som s�ker efter en person med hj�lp av signatur. Skriver ut
// resultatet.
void findPerson(std::vector<Person> persons) {
    bool found = false;
    std::string signature;
    clear("Skriv in signaturen du vill s�ka efter");
    getline(std::cin, signature);
    for (auto p : persons) {
        if (p.signature == signature) {
            clear("S�kningen fann: " + p.firstName + " " + p.lastName);
            found = true;
        }
    }
    if (!found) {
        clear("Personen hittades inte i listan");
    }
}

// Funktion som s�ker efter en person med hj�lp av signatur. Returnerar
// personens index i vectorn. returnerar -1 om personen inte hittas.
int personExist(std::vector<Person> persons, std::string searchString) {
    int i;
    for (unsigned int ui = 0; ui < persons.size(); ui++) {
        if (persons[ui].signature == searchString) {
            i = ui;
            return i;
        }
    }
    return -1;
}
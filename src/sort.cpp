#include "constants.h"
#include <algorithm>
#include <iostream>

// Funktion som slumpordnar listan och rensar sk�rmen.
void randomize(std::vector<Person> &persons) {
    std::random_shuffle(persons.begin(), persons.end());
    clear("Listan har slumpordnats!");
}

// Funktion f�r sortering av personer. Anv�nder sig av tre olika
// sorteringsalgoritmer, en f�r namn, en f�r signatur och en f�r l�ngd.
void sort(std::vector<Person> &persons) {

    clear("V�lj sorteringss�tt.");
    SortMode choice = static_cast<SortMode>(printMenu(SORTMENU));
    switch (choice) {
    case name:
        std::sort(persons.begin(), persons.end(), byName);
        clear("Listan har sorterats p� namn.");
        break;
    case signature:
        std::sort(persons.begin(), persons.end(), bySign);
        clear("Listan har sorterats p� signatur.");
        break;
    case height:
        std::sort(persons.begin(), persons.end(), byHeight);
        clear("Listan har sorterats p� l�ngd.");
        break;
    }
}

// Bakar samman efternamn + f�rnamn och omvandlar till gemener.
bool byName(Person i, Person j) {
    std::string name1 = i.lastName + " " + i.firstName;
    std::string name2 = j.lastName + " " + j.firstName;

    for (unsigned int i = 0; i < name1.size(); i++) {
        name1[i] = char(tolower(name1[i]));
    }
    for (unsigned int i = 0; i < name2.size(); i++) {
        name2[i] = char(tolower(name2[i]));
    }
    return name1 < name2;
}
bool bySign(Person i, Person j) { return (i.signature < j.signature); }
bool byHeight(Person i, Person j) { return (i.height > j.height); }
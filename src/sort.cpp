#include "constants.h"
#include <algorithm>
#include <iostream>

bool byName(Person, Person);
bool bySign(Person, Person);
bool byHeight(Person, Person);

void sort(std::vector<Person> &persons) {
    std::vector<std::string> menu{"Sortera på namn", "Sortera på signatur",
                                  "Sortera på längd"};
    std::cout << "Välj sorteringssätt." << std::endl;
    SortMode choice = static_cast<SortMode>(menuChoice(menu));
    switch (choice) {
    case name:
        std::sort(persons.begin(), persons.end(), byName);
        clear("Listan har sorterats på namn.");
        break;
    case signature:
        std::sort(persons.begin(), persons.end(), bySign);
        clear("Listan har sorterats på signatur.");
        break;
    case height:
        std::sort(persons.begin(), persons.end(), byHeight);
        clear("Listan har sorterats på längd.");
        break;
    }
}

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
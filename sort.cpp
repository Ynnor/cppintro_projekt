#include "constants.h"
#include <algorithm>

void sort(std::vector<Person> &persons) {
    std::vector<std::string> menu{"Sortera på namn", "Sortera på signatur",
                                  "Sortera på längd"};
    SortMode choice = static_cast<SortMode>(menuChoice(menu));
    switch (choice) {
    case name:
        std::sort(persons.begin(), persons.end(),byName);
                 break;
    case signature:
        std::sort(persons.begin(),persons.end(),bySign);
        break;
    case height:
        std::sort(persons.begin(),persons.end(),byHeight);
        break;
    }
}

bool byName(Person i, Person j) {
    std::string lastName1 = i.lastName;
    std::string lastName2 = j.lastName;
    std::string firstName1 = i.firstName;
    std::string firstName2 = j.firstName;

    for (auto &c : lastName1) {
        tolower(c);
    }
    for (auto &c : lastName2) {
        tolower(c);
    }
    if (lastName1 == lastName2) {
        for (auto &c : firstName1) {
            tolower(c);
        }
        for (auto &c : firstName2) {
            tolower(c);
        }
        return (firstName1 < firstName2);
    } else {
        return (lastName1 < lastName2);
    }
}
bool bySign(Person i, Person j) { return (i.signature < j.signature); }
bool byHeight(Person i, Person j) { return (i.height < j.height); }
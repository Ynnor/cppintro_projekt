#include "constants.h"
#include "searchFor.cpp"
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>


void addPerson(std::vector<Person> &persons) {
    std::string firstName, lastName, signature;
    float height;
    Person p;
    int counter = 1;
    std::cout << std::string(32, '\n');
    std::cout << "Vad är förnamnet på personen som ska läggas till? ";
    getline(std::cin, firstName);
    std::cout << "Vad är efternamnet på personen som ska läggas till? ";
    getline(std::cin, lastName);
    std::cout << "Hur lång är personen som läggs till? [m.cm] ";
    std::cin >> height;

    p.firstName = firstName;
    p.lastName = lastName;
    p.height = height;

    signature += firstName.substr(0, 3);
    signature += std::string(3 - signature.size(), 'x');
    signature += lastName.substr(0, 3);
    signature += std::string(6 - signature.size(), 'x');
    for (auto &c : signature) {
        c = tolower(c);
    }
    signature += "01";
    while (searchFor(persons, signature)) {
        counter++;
        signature = signature.substr(0, 6);
        if (counter < 10) {
            signature += '0';
            signature += std::to_string(counter);
        } else {
            signature += std::to_string(counter);
        }
    }
    p.signature = signature;
    persons.push_back(p);
    clear(p.firstName + " " + p.lastName + " har lagts till listan.");
}
#include "constants.h"
#include "searchFor.cpp"
#include <iostream>
#include <string>
#include <vector>

Person addPerson(std::vector<Person> persons) {
    std::string firstName, lastName, signature, h;
    Person p;
    int counter = 1;
    std::cout << std::string(20, '\n');

    std::cout << "Vad är förnamnet på personen som ska läggas till? ";
    std::cin.ignore();
    getline(std::cin, firstName);
    std::cout << "Vad är efternamnet på personen som ska läggas till? ";
    getline(std::cin, lastName);
    std::cout << "Hur lång är personen som läggs till? ";
    getline(std::cin, h);

    p.firstName = firstName;
    p.lastName = lastName;
    p.height = h;

    signature += firstName.substr(0, 3);
    signature += std::string(3 - signature.size(), 'x');
    signature += lastName.substr(0, 3);
    signature += std::string(6 - signature.size(), 'x');
    for (auto &c : signature) {
        c = tolower(c);
    }
    signature += "01";
    p.signature = signature;
    // while(!searchFor(persons,signature)){
    //     counter++;
    //     signature = signature.substr(0,6);
    //     if (counter < 10) {
    //         signature += '0';
    //         signature += std::to_string(counter);
    //     } else {
    //         signature += std::to_string(counter);
    //     }
    // }
    return p;
}
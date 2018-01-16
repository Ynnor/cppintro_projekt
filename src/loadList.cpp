#include "constants.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void loadList(std::vector<Person> &persons) {
    std::vector<Person> loaded;
    Person p;
    std::string s, fileName;
    std::string::size_type delim;
    int index;
    std::cout << "Skriv in filnamnet på filen du vill läsa från, inkludera "
                 "filformat! ";
    getline(std::cin, fileName);
    std::ifstream inFile(fileName);

    if (inFile.is_open()) {
        while (getline(inFile, s)) {
            index = 0;
            delim = s.find(',', index);
            p.firstName = s.substr(index, delim - index);
            index = delim + 1;
            delim = s.find(',', index);
            p.lastName = s.substr(index, delim - index);
            index = delim + 1;
            delim = s.find(',', index);
            p.height = std::stof(s.substr(index, delim - index));
            index = delim + 1;
            delim = s.find(',', index);
            p.signature = s.substr(index, delim - index);
            loaded.push_back(p);
        }
        clear(fileName + " har lästs in till programmet.");
        persons = loaded;
        inFile.close();
    } else {
        clear("Något fel vid inläsning av fil!");
    }
}
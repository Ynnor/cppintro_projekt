#include "constants.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void loadList(std::vector<Person> &persons) {
    std::vector<Person> loaded;
    Person p;
    std::string s, fileName;
    std::string::size_type delimPoint;
    int index;
    std::cout << "Skriv in filnamnet på filen du vill läsa från, inkludera "
                 "filformat! ";
    getline(std::cin, fileName);
    std::ifstream inFile(fileName);

    std::cout << "Är filen krypterad? " << std::endl;
    switch (menuChoice(std::vector<std::string>{"Ja", "Nej"})) {
    case 1:
        if (inFile.is_open()) {
            int key;
            std::string encryptedMessage;
            std::cout << "Ange en krypteringsnyckel." << std::endl;
            std::cin >> key;

            while (std::cin.fail()) {
                std::cout << "Mata in ett heltal";
                std::cin.clear();
                std::cin.ignore(256, '\n');
                std::cin >> key;
            }
            while (getline(inFile, encryptedMessage)) {
                index = 0;
                s = decrypt(encryptedMessage, key);
                delimPoint = s.find(DELIM, index);
                p.firstName = s.substr(index, delimPoint - index);
                index = delimPoint + 1;
                delimPoint = s.find(DELIM, index);
                p.lastName = s.substr(index, delimPoint - index);
                index = delimPoint + 1;
                delimPoint = s.find(DELIM, index);
                p.signature = s.substr(index, delimPoint - index);
                index = delimPoint + 1;
                delimPoint = s.find(DELIM, index);
                p.height = std::stof(s.substr(index, delimPoint - index));
                loaded.push_back(p);
            }
            clear(fileName + " har lästs in till programmet.");
            persons = loaded;
            inFile.close();
        } else {
            clear("Något fel vid inläsning av fil!");
        }
        break;
    case 2:
        if (inFile.is_open()) {
            while (getline(inFile, s)) {
                index = 0;
                delimPoint = s.find(DELIM, index);
                p.firstName = s.substr(index, delimPoint - index);
                index = delimPoint + 1;
                delimPoint = s.find(DELIM, index);
                p.lastName = s.substr(index, delimPoint - index);
                index = delimPoint + 1;
                delimPoint = s.find(DELIM, index);
                p.signature = s.substr(index, delimPoint - index);
                index = delimPoint + 1;
                delimPoint = s.find(DELIM, index);
                p.height = std::stof(s.substr(index, delimPoint - index));
                loaded.push_back(p);
            }
            clear(fileName + " har lästs in till programmet.");
            persons = loaded;
            inFile.close();
        } else {
            clear("Något fel vid inläsning av fil!");
        }
        break;
    }
}
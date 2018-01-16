#include "constants.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void saveList(std::vector<Person> persons) {
    std::cout << "Till vilken fil vill du spara listan? ";
    std::string fileName, fileRow;
    getline(std::cin, fileName);
    std::ofstream outFile;
    outFile.open(fileName, std::ofstream::out | std::ofstream::trunc);

    std::cout << "Vill du kryptera filen?" << std::endl;
    switch (menuChoice(std::vector<std::string>{"Ja", "Nej"})) {
    case 1:
        if (outFile.is_open()) {
            int key;
            std::cout << "Ange en krypteringsnyckel." << std::endl;
            std::cin >> key;

            while (std::cin.fail()) {
                std::cout << "Mata in ett heltal";
                std::cin.clear();
                std::cin.ignore(256, '\n');
                std::cin >> key;
            }
            for (auto p : persons) {
                outFile << encrypt(p.firstName + DELIM + p.lastName + DELIM +
                                       p.signature + DELIM +
                                       std::to_string(p.height),
                                   key)
                        << std::endl;
            }
            clear("Listan har sparats till " + fileName);
            outFile.close();
        } else {
            clear("Något gick fel vid sparning av listan.");
        }
        outFile.close();
        return;
    case 2:
        if (outFile.is_open()) {
            for (auto p : persons) {
                outFile << p.firstName << "," << p.lastName << ","
                        << p.signature << "," << p.height << std::endl;
            }
            clear("Listan har sparats till " + fileName);
            outFile.close();
        } else {
            clear("Något gick fel vid sparning av listan.");
        }
        outFile.close();
        return;
    }
}
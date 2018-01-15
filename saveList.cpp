#include "constants.h"
#include <fstream>
#include <iostream>
#include <string>

void saveList(std::vector<Person> persons) {
    std::cout << "Till vilken fil vill du spara listan? ";
    std::string fileName;
    getline(std::cin, fileName);
    std::ofstream outFile;
    outFile.open(fileName, std::ofstream::out | std::ofstream::trunc);
    if (outFile.is_open()) {
        for (auto p : persons) {
            outFile << p.firstName << "," << p.lastName << "," << p.height
                    << "," << p.signature << std::endl;
        }
        clear("Listan har sparats till " + fileName);
        outFile.close();
    } else {
        clear("N�got gick fel vid sparning av listan.");
    }
    outFile.close();
}
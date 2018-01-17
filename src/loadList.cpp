#include "constants.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// Funktion för att läsa in en lista från fil.
void loadList(std::vector<Person> &persons) {
    std::vector<Person> loaded;
    Person p;
    std::string s, fileName;
    std::string::size_type delimPoint;
    int index;
    clear("Skriv in filnamnet på filen du vill läsa från, inkludera "
          "filformat! ");
    getline(std::cin, fileName);
    std::ifstream inFile(fileName);

    // Val kan göras för att dekryptera filen.
    std::cout << "\nÄr filen krypterad? " << std::endl;
    switch (printMenu(YESNO)) {
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
            // Inläsning av filen, rad för rad.
            while (getline(inFile, encryptedMessage)) {
                index = 0;
                s = decrypt(encryptedMessage, key);
                // Om inte fyra tecken av DELIM finns i samtliga rader, så är
                // fel krypteringsnyckel skickad till funktionen
                if (std::count(s.begin(), s.end(), DELIM) == 3) {
                    // Separering av strängen, med hjälp av DELIM
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
                } else {
                    clear("Något gick fel vid dekryptering av fil. Angav du "
                          "rätt nyckel?");
                    inFile.close();
                    return;
                }
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
            // Inläsning av filen, rad för rad.
            while (getline(inFile, s)) {
                index = 0;
                // Separering av strängen med hjälp av DELIM.
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
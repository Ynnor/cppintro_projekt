#include "constants.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// Funktion f�r att l�sa in en lista fr�n fil.
void loadList(std::vector<Person> &persons) {
    std::vector<Person> loaded;
    Person p;
    std::string s, fileName;
    std::string::size_type delimPoint;
    int index;
    clear("Skriv in filnamnet p� filen du vill l�sa fr�n, inkludera "
          "filformat! ");
    getline(std::cin, fileName);
    std::ifstream inFile(fileName);

    // Val kan g�ras f�r att dekryptera filen.
    std::cout << "\n�r filen krypterad? " << std::endl;
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
            // Inl�sning av filen, rad f�r rad.
            while (getline(inFile, encryptedMessage)) {
                index = 0;
                s = decrypt(encryptedMessage, key);
                // Om inte fyra tecken av DELIM finns i samtliga rader, s� �r
                // fel krypteringsnyckel skickad till funktionen
                if (std::count(s.begin(), s.end(), DELIM) == 3) {
                    // Separering av str�ngen, med hj�lp av DELIM
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
                    clear("N�got gick fel vid dekryptering av fil. Angav du "
                          "r�tt nyckel?");
                    inFile.close();
                    return;
                }
            }
            clear(fileName + " har l�sts in till programmet.");
            persons = loaded;
            inFile.close();
        } else {
            clear("N�got fel vid inl�sning av fil!");
        }
        break;
    case 2:
        if (inFile.is_open()) {
            // Inl�sning av filen, rad f�r rad.
            while (getline(inFile, s)) {
                index = 0;
                // Separering av str�ngen med hj�lp av DELIM.
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
            clear(fileName + " har l�sts in till programmet.");
            persons = loaded;
            inFile.close();
        } else {
            clear("N�got fel vid inl�sning av fil!");
        }
        break;
    }
}
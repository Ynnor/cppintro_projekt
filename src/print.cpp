#include "constants.h"
#include <conio.h>
#include <iomanip>
#include <iostream>
#include <vector>

// Funktion som hanterar utskrift av listan.
void print(std::vector<Person> persons) {
    // Första for-loopen. Ser till att alla personer skrivs ut.
    for (unsigned int i = 0; i <= persons.size(); i += 20) {
        std::cout << std::string(32, '\n');
        std::cout << "***** NAME LIST *****" << std::endl
                  << "Antal personer i listan: " << persons.size()
                  << std::string(2, '\n');
        std::cout << std::left << std::setw(4) << "Nr" << std::setw(10)
                  << "Signatur" << std::setw(30) << "Namn" << std::setw(10)
                  << "Längd [m]" << std::endl;
        // inre for-loopen. Ser till att endast 20 personer skrivs ut åt gången.
        for (unsigned int j = 0; j < 20 && j + i < persons.size(); j++) {
            std::cout << std::right << std::setw(2) << j + i + 1 << ". ";
            printPerson(persons[i + j]);
        }
        std::cout << "Tryck på valfri tangent för att fortsätta...";
        _getch();
    }
    clear("");
}

// Funktion som hanterar utskrift av Person-structen.
void printPerson(Person p) {
    std::cout << std::left << std::setw(10) << p.signature << std::setw(30)
              << p.firstName + " " + p.lastName << std::setw(6) << std::right
              << std::setprecision(2) << std::fixed << p.height << std::endl;
}

// printMenu() tar en vektor med strängar, och skriver ut dem som en meny. I
// funktionen sköts även inputvalidering.
// Funktionen returnerar en integer med valet som kan användas med en switch i
// en annan funktion.
int printMenu(std::vector<std::string> menu) {
    unsigned int choice;
    std::cout << '\n';
    for (unsigned int i = 0; i < menu.size(); i++) {
        std::cout << i + 1 << ". " << menu[i] << '\n';
    }
    std::cin >> choice;
    while (std::cin.fail() || choice > menu.size()) {
        std::cout << "Mata in ett giltigt val.";
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cin >> choice;
    }
    std::cin.ignore(256, '\n');
    return choice;
}
#include "constants.h"
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

// addPerson l�gger till en inmatad person till vectorn som skickas in till
// funktionen.
void addPerson(std::vector<Person> &persons) {
    // Initialisering av variabler och rensning av terminalen.
    std::string firstName, lastName, signature;
    float height;
    Person p;
    int counter = 1;
    clear("L�gg till person.");
    std::cout << "Vad �r f�rnamnet p� personen som ska l�ggas till? ";
    getline(std::cin, firstName);
    std::cout << "Vad �r efternamnet p� personen som ska l�ggas till? ";
    getline(std::cin, lastName);
    std::cout << "Hur l�ng �r personen som l�ggs till? [m.cm] ";
    std::cin >> height;

    p.firstName = firstName;
    p.lastName = lastName;
    p.height = height;

    // Kontrollera ifall identisk person finns i listan redan. Om en identisk
    // person existerar, ges valen att skapa en annan person eller att �terg�
    // till huvudmeny.
    for (auto &p2 : persons) {
        if (p.firstName == p2.firstName && p.lastName == p2.lastName &&
            p.height == p2.height) {
            std::cout << "Personen du f�rs�ker l�gga till finn redan i listan. "
                         "V�lj vad du vill g�ra."
                      << std::endl;
            switch (printMenu(std::vector<std::string>{"�ndra inmatning",
                                                       "�terg� till meny"})) {
            case 1:
                addPerson(persons);
                return;
                break;
            case 2:
                clear(
                    "Personen som f�rs�kte l�ggas till fanns redan i listan.");
                return;
                break;
            }
        }
    }

    // Skapande av signatur. F�rst l�ggs de 3 f�rsta bokst�verna fr�n namnen
    // till, och om signaturen �r f�r kort, fylls det ut med x.
    signature += firstName.substr(0, 3);
    signature += std::string(3 - signature.size(), 'x');
    signature += lastName.substr(0, 3);
    signature += std::string(6 - signature.size(), 'x');
    // S�tt alla tecken till gemener.
    for (auto &c : signature) {
        c = char(tolower(c));
    }
    // Ge signaturen ett l�pnummer, och kontrollera ifall en person med
    // signaturen existerar redan. Om det existerar en person med samma
    // signatur, s� �kas l�pnumret i while-loopen.
    signature += "01";
    while (personExist(persons, signature) != -1) {
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

    // l�gg personen till vectorn och rensa sk�rmen.
    persons.push_back(p);
    clear(p.firstName + " " + p.lastName + " har lagts till listan.");
}
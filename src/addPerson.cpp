#include "constants.h"
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

// addPerson lägger till en inmatad person till vectorn som skickas in till
// funktionen.
void addPerson(std::vector<Person> &persons) {
    // Initialisering av variabler och rensning av terminalen.
    std::string firstName, lastName, signature;
    float height;
    Person p;
    int counter = 1;
    clear("Lägg till person.");
    std::cout << "Vad är förnamnet på personen som ska läggas till? ";
    getline(std::cin, firstName);
    std::cout << "Vad är efternamnet på personen som ska läggas till? ";
    getline(std::cin, lastName);
    std::cout << "Hur lång är personen som läggs till? [m.cm] ";
    std::cin >> height;

    p.firstName = firstName;
    p.lastName = lastName;
    p.height = height;

    // Kontrollera ifall identisk person finns i listan redan. Om en identisk
    // person existerar, ges valen att skapa en annan person eller att återgå
    // till huvudmeny.
    for (auto &p2 : persons) {
        if (p.firstName == p2.firstName && p.lastName == p2.lastName &&
            p.height == p2.height) {
            std::cout << "Personen du försöker lägga till finn redan i listan. "
                         "Välj vad du vill göra."
                      << std::endl;
            switch (printMenu(std::vector<std::string>{"Ändra inmatning",
                                                       "Återgå till meny"})) {
            case 1:
                addPerson(persons);
                return;
                break;
            case 2:
                clear(
                    "Personen som försökte läggas till fanns redan i listan.");
                return;
                break;
            }
        }
    }

    // Skapande av signatur. Först läggs de 3 första bokstäverna från namnen
    // till, och om signaturen är för kort, fylls det ut med x.
    signature += firstName.substr(0, 3);
    signature += std::string(3 - signature.size(), 'x');
    signature += lastName.substr(0, 3);
    signature += std::string(6 - signature.size(), 'x');
    // Sätt alla tecken till gemener.
    for (auto &c : signature) {
        c = char(tolower(c));
    }
    // Ge signaturen ett löpnummer, och kontrollera ifall en person med
    // signaturen existerar redan. Om det existerar en person med samma
    // signatur, så ökas löpnumret i while-loopen.
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

    // lägg personen till vectorn och rensa skärmen.
    persons.push_back(p);
    clear(p.firstName + " " + p.lastName + " har lagts till listan.");
}
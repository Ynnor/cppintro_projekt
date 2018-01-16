#include "constants.h"
#include <iostream>
#include <vector>

int main() {
    std::vector<Person> persons;
    bool running = true;
    const std::vector<std::string> menu{
        "L�gg till person", "Skriv ut lista", "S�k i lista",
        "Ta bort person",   "Sortera lista",  "Slumpa lista",
        "Spara lista",      "Ladda lista",    "Avsluta"};

    while (running) {
        std::cout << "Du har nu " << persons.size()
                  << " personer i din lista. Vad vill du g�ra h�rn�st?";
        switch (menuChoice(menu)) {
        case 1:
            addPerson(persons);
            break;
        case 2:
            print(persons);
            break;
        case 3:
            findPerson(persons);
            break;
        case 4:
            deletePerson(persons);
            break;
        case 5:
            sort(persons);
            break;
        case 6:
            randomize(persons);
            break;
        case 7:
            saveList(persons);
            break;
        case 8:
            loadList(persons);
            break;
        case 9:
            running = false;
        };
    };
    return 0;
}
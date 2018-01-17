#include "constants.h"
#include <iostream>
#include <vector>

int main() {
    // Initialisering av variabler.
    std::vector<Person> persons;
    bool running = true;

    // Huvudloopen. Körs till 9 väljs som val, då while loopen kommer att
    // brytas.
    while (running) {
        std::cout << "Du har nu " << persons.size()
                  << " personer i din lista. Vad vill du göra härnäst?";
        switch (printMenu(MAINMENU)) {
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
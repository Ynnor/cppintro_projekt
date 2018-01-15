#include "addPerson.cpp"
#include "constants.h"
#include "deletePerson.cpp"
#include "find.cpp"
#include "loadList.cpp"
#include "menuChoice.cpp"
#include "printList.cpp"
#include "randomize.cpp"
#include "saveList.cpp"
#include <vector>

int main() {
    std::vector<Person> persons;
    bool running = true;
    const std::vector<std::string> menu{
        "Lägg till person", "Skriv ut lista", "Sök i lista",
        "Ta bort person",   "Sortera lista",  "Slumpa lista",
        "Spara lista",      "Ladda lista",    "Avsluta"};
    int choice;

    while (running) {
        switch (menuChoice(menu)) {
        case 1:
            addPerson(persons);
            break;
        case 2:
            printList(persons);
            break;
        case 3:
            find(persons);
            break;
        case 4:
            deletePerson(persons);
            break;
            //     case 5:
            //     sortList();
            //     break;
        case 6:
            randomize(persons);
            break;
        case 7:
            saveList(persons);
            break;
        case 8:
            persons = loadList();
            break;
        case 9:
            running = false;
        };
    };
    return 0;
}
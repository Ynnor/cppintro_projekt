#include "constants.h"
#include <vector>
#include "menuChoice.cpp"
#include "addPerson.cpp"
#include "printList.cpp"
#include "loadList.cpp"

int main (){
    std::vector<Person> persons;
    bool running = true;
    const std::vector<std::string> menu{"L�gg till person","Skriv ut lista","S�k i lista",
    "Ta bort person", "Sortera lista", "Slumpa lista", "Spara lista", "Ladda lista",
    "Avsluta"};
    int choice;

    while (running){
        switch (menuChoice(menu)){
            case 1:
            persons.push_back(addPerson(persons));
            break;
            case 2:
            printList(persons);
            break;
    //     case 3:
    //     find(persons);
    //     break;
    //     deletePerson();
    //     case 4:
    //     sortList();
    //     break;
    //     case 5:
    //     randomize();
    //     break;
    //     case 6:
    //     saveList(persons);
    //     break;
            case 7:
            persons = loadList();
            break;
    //     case 8:
    //     running = false;
        };
    // } else {
        
    // }
    };
    return 0;
}
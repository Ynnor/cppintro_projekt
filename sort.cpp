#include "constants.h"

void sort(std::vector<Person> &persons) {
    std::vector<std::string> menu{"Sortera på namn", "Sortera på signatur", "Sortera på längd"};
    SortMode choice = static_cast<SortMode>(menuChoice(menu));
    switch(choice) {
        case name:

        break;
        case signature:

        break;
        case height:

        break;
    }
}
#include "constants.h"

void sort(std::vector<Person> &persons) {
    std::vector<std::string> menu{"Sortera p� namn", "Sortera p� signatur", "Sortera p� l�ngd"};
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
#include "constants.h"
#include <vector>
#include <string>

bool searthFor(std::vector<Person> persons, std::string searchString){
    for (int i = 0; i < persons.size(); i++) {
        if (persons[i].signature == searchString){
            return true;
        }
    }
    return false;
}
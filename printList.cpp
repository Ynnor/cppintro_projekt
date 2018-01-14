#include "constants.h"
#include <vector>
#include <iostream>
#include <iomanip>

void printList(std::vector<Person> persons) {
    for(int i = 0; i < persons.size(); i++){
        std::cout << persons[i].firstName << '\t';
        std::cout << persons[i].lastName << '\t';
        std::cout << persons[i].height << '\t';
    }
}
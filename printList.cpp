#include "constants.h"
#include "printPerson.cpp"
#include <iomanip>
#include <iostream>
#include <vector>

void printList(std::vector<Person> persons) {
    for (auto p : persons) {
        printPerson(p);
    }
}
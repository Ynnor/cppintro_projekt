#include "constants.h"
#include <algorithm>

void randomize(std::vector<Person> &persons) {
    std::random_shuffle(persons.begin(), persons.end());
}
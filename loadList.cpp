#include "constants.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::vector<Person> loadList() {
    std::vector<Person> returnvect;
    Person p;
    std::ifstream infile("test.txt");
    std::string s;
    std::string::size_type delim;
    int index;

    while (getline(infile, s)) {
        index = 0;
        delim = s.find(',', index);
        p.firstName = s.substr(index, delim - index);
        index = delim + 1;
        delim = s.find(',', index);
        p.lastName = s.substr(index, delim - index);
        index = delim + 1;
        delim = s.find(',', index);
        p.height = s.substr(index, delim - index);
        index = delim + 1;
        delim = s.find(',', index);
        p.signature = s.substr(index, delim - index);
        returnvect.push_back(p);
    }
    return returnvect;
}
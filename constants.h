#ifndef constantsH
#define constantsH
#include <string>
#include <vector>

struct Person {
    std::string firstName;
    std::string lastName;
    std::string signature;
    std::string height;
};

int menuChoice (std::vector<std::string>);
bool validChoice (std::string input);
Person addPerson (std::vector<Person> persons);
void printList(std::vector<Person> persons);
void find(std::vector<Person> persons);
bool searchFor(std::vector<Person> persons, std::string signature);
void deletePerson(std::vector<Person> persons, std::string signature);
void sortList(std::vector<Person> persons);
void randomize(std::vector<Person> persons);
void saveList(std::vector<Person> persons);
std::vector<Person> loadList();
#endif
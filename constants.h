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
enum SortMode {name, signature, height};

void printPerson(Person);
int menuChoice(std::vector<std::string>);
bool validChoice(std::string input);
void addPerson(std::vector<Person> &persons);
void printList(std::vector<Person> persons);
void find(std::vector<Person> persons);
bool searchFor(std::vector<Person> persons, std::string signature);
void deletePerson(std::vector<Person> &persons);
void sort(std::vector<Person> &persons);
void randomize(std::vector<Person> persons);
void saveList(std::vector<Person> persons);
std::vector<Person> loadList();
#endif
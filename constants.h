#ifndef constantsH
#define constantsH
#include <string>
#include <vector>

struct Person {
    std::string firstName;
    std::string lastName;
    std::string signature;
    float height;
};
enum SortMode {name=1, signature, height};

void printPerson(Person);
int menuChoice(std::vector<std::string>);
void addPerson(std::vector<Person> &persons);
void printList(std::vector<Person>);
void find(std::vector<Person>);
bool searchFor(std::vector<Person>, std::string);
void deletePerson(std::vector<Person> &persons);
void sort(std::vector<Person> &persons);
void randomize(std::vector<Person> &persons);
void saveList(std::vector<Person>);
void loadList(std::vector<Person> &persons);
void clear(std::string);
#endif
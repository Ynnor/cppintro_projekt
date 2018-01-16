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
enum SortMode { name = 1, signature, height };
const char DELIM = '|';

int menuChoice(std::vector<std::string>);
void addPerson(std::vector<Person> &persons);
void print(std::vector<Person>);
void printPerson(Person);
void findPerson(std::vector<Person>);
bool personExist(std::vector<Person>, std::string);
void deletePerson(std::vector<Person> &persons);
void sort(std::vector<Person> &persons);
void randomize(std::vector<Person> &persons);
void saveList(std::vector<Person>);
void loadList(std::vector<Person> &persons);
void clear(std::string);
std::string encrypt(std::string, int);
std::string decrypt(std::string, int);
#endif
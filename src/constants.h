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
// Konstanter
const char DELIM = '|';
// Menyer
const std::vector<std::string> MAINMENU{
    "Lägg till person", "Skriv ut lista", "Sök i lista",
    "Ta bort person",   "Sortera lista",  "Slumpa lista",
    "Spara lista",      "Ladda lista",    "Avsluta"};
const std::vector<std::string> SORTMENU{
    "Sortera på namn", "Sortera på signatur", "Sortera på längd"};
const std::vector<std::string> YESNO{"Ja", "Nej"};

// Huvudmeny-program
void addPerson(std::vector<Person> &persons);
void print(std::vector<Person>);
void findPerson(std::vector<Person>);
void deletePerson(std::vector<Person> &persons);
void sort(std::vector<Person> &persons);
void randomize(std::vector<Person> &persons);
void saveList(std::vector<Person>);
void loadList(std::vector<Person> &persons);
// Hjälp-program
int printMenu(std::vector<std::string>);
void printPerson(Person);
int personExist(std::vector<Person>, std::string);
void clear(std::string);
std::string encrypt(std::string, int);
std::string decrypt(std::string, int);
// Sorteringsalgoritmer
bool byName(Person, Person);
bool bySign(Person, Person);
bool byHeight(Person, Person);
#endif
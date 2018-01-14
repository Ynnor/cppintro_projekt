#include <iostream>
#include <iomanip>
#include <vector>
#include <String>

int menuChoice(std::vector<std::string> menu){
    int choice;
    for(int i = 0; i < menu.size(); i++) {
        std::cout << static_cast<char>(i) << ". " << menu[i] << '\n';
    }
    std::cin >> choice;
    while (std::cin.fail() || choice < 0 || choice > 3) {
        std::cout << "Mata in ett giltigt val.";
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cin >> choice;
    }
    return choice;
}
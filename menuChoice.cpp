#include <String>
#include <iomanip>
#include <iostream>
#include <vector>

int menuChoice(std::vector<std::string> menu) {
    int choice;
    std::cout << '\n';
    for (int i = 0; i < menu.size(); i++) {
        std::cout << i + 1 << ". " << menu[i] << '\n';
    }
    std::cin >> choice;
    while (std::cin.fail() || choice < 0 || choice > menu.size()) {
        std::cout << "Mata in ett giltigt val.";
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cin >> choice;
    }
    std::cin.ignore(256,'\n');
    return choice;
}
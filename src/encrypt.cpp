#include "constants.h"
#include <iostream>
#include <string>

std::string encrypt(std::string message, int key) {
    std::string encryptedString;

    for (auto c : message) {
        encryptedString += static_cast<char>(c + key);
    }
    return encryptedString;
}

std::string decrypt(std::string message, int key) {
    std::string decryptedString;

    for (auto c : message) {
        decryptedString += static_cast<char>(c - key);
    }
    return decryptedString;
}
#include "String.h"

#include <cstring>
#include <iostream>
#include <limits>

String::String() : size(80) {
    text = new char[size + 1];
    text[0] = '\0';
}

String::String(int n) : size(n > 0 ? n : 80) {
    text = new char[size + 1];
    text[0] = '\0';
}

String::String(const char* s) : size(static_cast<int>(std::strlen(s))) {
    text = new char[size + 1];
    strcpy_s(text, size + 1, s);
}

String::String(const String& other) : size(other.size) {
    text = new char[size + 1];
    strcpy_s(text, size + 1, other.text);
}

String::~String() {
    delete[] text;
}

void String::input() {
    std::cin.getline(text, size + 1);

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void String::print() const {
    std::cout << text << std::endl;
}

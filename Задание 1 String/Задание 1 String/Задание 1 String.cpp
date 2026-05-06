#include <clocale>
#include <iostream>

#include "String.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    String a; // Строка до 80 символов
    cout << "Введите строку a: ";
    a.input();
    cout << "a = ";
    a.print();

    String b(20); // Строка до 20 символов
    cout << "Введите строку b: ";
    b.input();
    cout << "b = ";
    b.print();

    String c("Готовая строка");
    cout << "c = ";
    c.print();

    String d = c; // Проверка конструктора копирования
    cout << "d = ";
    d.print();

    return 0;
}

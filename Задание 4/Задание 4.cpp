#include <iostream>
#include <limits>
#include <string>
#include "PhoneBook.h"

using namespace std;

// Считываем строку с подсказкой.
string readLine(const string& text)
{
    cout << text;
    string value;
    getline(cin, value);
    return value;
}

// Создаем абонента из данных пользователя.
Contact readContact()
{
    string fio = readLine("ФИО: ");
    string home = readLine("Домашний телефон: ");
    string work = readLine("Рабочий телефон: ");
    string mobile = readLine("Мобильный телефон: ");
    string info = readLine("Дополнительная информация: ");

    return Contact(fio.c_str(), home, work, mobile, info);
}

int main()
{
    setlocale(LC_ALL, "Russian");

    PhoneBook book;
    int choice;

    do
    {
        cout << "\nТелефонная книга\n";
        cout << "1. Добавить абонента\n";
        cout << "2. Удалить абонента по ФИО\n";
        cout << "3. Найти абонента по ФИО\n";
        cout << "4. Показать всех абонентов\n";
        cout << "0. Выход\n";
        cout << "Ваш выбор: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 1)
        {
            book.add(readContact());
        }
        else if (choice == 2)
        {
            string fio = readLine("Введите ФИО: ");
            cout << (book.remove(fio.c_str()) ? "Абонент удален.\n" : "Абонент не найден.\n");
        }
        else if (choice == 3)
        {
            string fio = readLine("Введите ФИО: ");
            Contact* found = book.find(fio.c_str());
            if (found)
                found->show();
            else
                cout << "Абонент не найден.\n";
        }
        else if (choice == 4)
        {
            book.showAll();
        }
    } while (choice != 0);

    return 0;
}

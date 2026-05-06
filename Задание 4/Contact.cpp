#include "Contact.h"
#include <cstring>
#include <iostream>

using namespace std;

void Contact::copyFio(const char* newFio)
{
    delete[] fio;
    fio = new char[strlen(newFio) + 1];
    strcpy_s(fio, strlen(newFio) + 1, newFio);
}

// Конструктор по умолчанию с инициализатором.
Contact::Contact()
    : fio(nullptr), homePhone("-"), workPhone("-"), mobilePhone("-"), info("-")
{
    copyFio("Без имени");
}

// Конструктор с параметрами и списком инициализации.
Contact::Contact(const char* newFio, const string& home, const string& work,
    const string& mobile, const string& newInfo)
    : fio(nullptr), homePhone(home), workPhone(work), mobilePhone(mobile), info(newInfo)
{
    copyFio(newFio);
}

// Копирующий конструктор нужен из-за динамической памяти.
Contact::Contact(const Contact& other)
    : fio(nullptr), homePhone(other.homePhone), workPhone(other.workPhone),
    mobilePhone(other.mobilePhone), info(other.info)
{
    copyFio(other.fio);
}

// Деструктор освобождает память под ФИО.
Contact::~Contact()
{
    delete[] fio;
}

Contact& Contact::operator=(const Contact& other)
{
    if (this != &other)
    {
        copyFio(other.fio);
        homePhone = other.homePhone;
        workPhone = other.workPhone;
        mobilePhone = other.mobilePhone;
        info = other.info;
    }
    return *this;
}

void Contact::show() const
{
    cout << "\nФИО: " << fio << '\n';
    cout << "Домашний телефон: " << homePhone << '\n';
    cout << "Рабочий телефон: " << workPhone << '\n';
    cout << "Мобильный телефон: " << mobilePhone << '\n';
    cout << "Доп. информация: " << info << "\n";
}

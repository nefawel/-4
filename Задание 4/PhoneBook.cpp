#include "PhoneBook.h"
#include <cstring>
#include <iostream>

using namespace std;

void PhoneBook::add(const Contact& contact)
{
    contacts.push_back(contact);
    cout << "Абонент добавлен.\n";
}

bool PhoneBook::remove(const char* fio)
{
    for (int i = 0; i < size(); i++)
    {
        if (strcmp(contacts[i].getFio(), fio) == 0)
        {
            contacts.erase(contacts.begin() + i);
            return true;
        }
    }
    return false;
}

Contact* PhoneBook::find(const char* fio)
{
    for (int i = 0; i < size(); i++)
        if (strcmp(contacts[i].getFio(), fio) == 0)
            return &contacts[i];

    return nullptr;
}

void PhoneBook::showAll() const
{
    if (contacts.empty())
    {
        cout << "Книга пуста.\n";
        return;
    }

    for (const Contact& contact : contacts)
        contact.show();
}

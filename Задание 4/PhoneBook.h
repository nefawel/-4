#pragma once

#include <vector>
#include "Contact.h"

class PhoneBook
{
private:
    std::vector<Contact> contacts;

public:
    // Inline-функция-член: быстро возвращает количество абонентов.
    inline int size() const { return static_cast<int>(contacts.size()); }

    void add(const Contact& contact);
    bool remove(const char* fio);
    Contact* find(const char* fio);
    void showAll() const;
};

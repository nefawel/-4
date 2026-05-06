#pragma once

#include <string>

class Contact
{
private:
    char* fio;              // ФИО хранится в динамической памяти.
    std::string homePhone;
    std::string workPhone;
    std::string mobilePhone;
    std::string info;

    void copyFio(const char* newFio);

public:
    Contact();
    Contact(const char* fio, const std::string& home, const std::string& work,
        const std::string& mobile, const std::string& info);
    Contact(const Contact& other);
    ~Contact();

    Contact& operator=(const Contact& other);

    // Inline-функция: короткий метод написан прямо в заголовке.
    inline const char* getFio() const { return fio; }

    void show() const;
};

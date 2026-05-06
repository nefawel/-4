#pragma once

class String {
private:
    char* text;
    int size;

public:
    String();
    String(int n);
    String(const char* s);
    String(const String& other);
    ~String();

    void input();
    void print() const;
};

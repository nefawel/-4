#pragma once

class Array {
    int size; // размер массива
    int* a;   // динамический массив

public:
    Array(int n = 0);              // конструктор
    Array(const Array& other);     // конструктор копирования
    Array& operator=(Array other); // оператор присваивания
    ~Array();                      // деструктор

    void fill();             // заполнение
    void print() const;      // вывод
    void resize(int newSize);// изменение размера
    void sortArray();        // сортировка
    int minValue() const;    // минимум
    int maxValue() const;    // максимум
};

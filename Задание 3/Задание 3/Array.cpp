#include "Array.h"

#include <algorithm>
#include <iostream>
#include <utility>

using namespace std;

Array::Array(int n) : size(max(0, n)), a(size ? new int[size]{} : nullptr) {}

Array::Array(const Array& other) : Array(other.size) {
    if (size) copy(other.a, other.a + size, a);
}

Array& Array::operator=(Array other) {
    swap(size, other.size);
    swap(a, other.a);
    return *this;
}

Array::~Array() {
    delete[] a;
}

void Array::fill() {
    for (int i = 0; i < size; i++) cin >> a[i];
}

void Array::print() const {
    for (int i = 0; i < size; i++) cout << a[i] << ' ';
    cout << endl;
}

void Array::resize(int newSize) {
    newSize = max(0, newSize);
    int* b = newSize ? new int[newSize]{} : nullptr;

    for (int i = 0; i < min(size, newSize); i++) b[i] = a[i];

    delete[] a;
    a = b;
    size = newSize;
}

void Array::sortArray() {
    if (size) sort(a, a + size);
}

int Array::minValue() const {
    return size ? *min_element(a, a + size) : 0;
}

int Array::maxValue() const {
    return size ? *max_element(a, a + size) : 0;
}

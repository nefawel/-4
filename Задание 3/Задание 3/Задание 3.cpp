#include "Array.h"

#include <clocale>
#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    int n;
    cout << "Size: ";
    cin >> n;

    Array arr(n);
    cout << "Elements: ";
    arr.fill();

    cout << "Array: ";
    arr.print();

    arr.sortArray();
    cout << "Sorted: ";
    arr.print();

    cout << "Min: " << arr.minValue() << endl;
    cout << "Max: " << arr.maxValue() << endl;

    cout << "New size: ";
    cin >> n;
    arr.resize(n);

    cout << "After resize: ";
    arr.print();
}

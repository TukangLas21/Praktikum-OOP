#include <iostream>
#include "Soal2.hpp"

using namespace std;

Point::Point() {
    x = 0;
    y = 0;
}

Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}

void Point::print() {
    cout << "(" << this->x << ", " << this->y << ")" << endl;
}

ostream& operator<<(ostream& os, const Point& p){
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

int main() {
    // Tes integer
    int arrInt[] = {9, 20, 5, 8, 7};
    int nInt = sizeof(arrInt) / sizeof(arrInt[0]);
    PrintArray(arrInt, nInt);

    // Tes double (real)
    double arrDouble[] = {9.5, 28.34, 2.76, 2.75, 19.261};
    int nDouble = sizeof(arrDouble) / sizeof(arrDouble[0]);
    PrintArray(arrDouble, nDouble);

    // Tes char
    char arrChar[] = {'a', 'i', 'u', 'e', 'o'};
    int nChar = sizeof(arrChar) / sizeof(arrChar[0]);
    PrintArray(arrChar, nChar);

    // Tes array 'kosong'
    char arrEmpty[] = {'w'};
    int nEmpty = 0;
    PrintArray(arrEmpty, nEmpty);

    // Tes array Point
    Point arrPoint[] = {Point(28, 19), Point(1, 10), Point(8, 10), Point(6, 9), Point(20, 25)};
    int nPoint = sizeof(arrPoint) / sizeof(arrPoint[0]);
    PrintArray(arrPoint, nPoint);

    return 0;
}
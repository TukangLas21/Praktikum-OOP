#include <iostream>
#include "Soal1.hpp"

using namespace std;

Jam::Jam() {
    j = 0;
    m = 0;
    d = 0;
}

Jam::Jam(int j, int m, int d) {
    this->j = j;
    this->m = m;
    this->d = d;
}

bool Jam::operator<(const Jam& other) const { // Overload operator < untuk memudahkan perbandingan Jam
    if (this->j < other.j) {
        return true;
    } else if (this->j == other.j) {
        if (this->m < other.m) {
            return true;
        } else if (this->m == other.m) {
            if (this->d < other.d) {
                return true;
            }
        }
    }
    return false;
}

void Jam::print() {
    cout << "Waktu (HH:MM:SS) adalah " << j << ":" << m << ":" << d << endl;
}


int main() {
    // Tes array bertipe integer
    int arrInt[] = {9, 20, 5, 8, 7};
    int nInt = sizeof(arrInt) / sizeof(arrInt[0]);
    cout << "Nilai minimum dari array of integer adalah " << MinArray(arrInt, nInt) << endl;

    // Tes array bertipe double (angka real)
    double arrDouble[] = {9.5, 28.34, 2.76, 2.75, 19.261};
    int nDouble = sizeof(arrDouble) / sizeof(arrDouble[0]);
    cout << "Nilai minimum dari array of double adalah " << MinArray(arrDouble, nDouble) << endl;

    // Tes array bertipe Jam
    Jam arrJam[] = {Jam(9, 20, 5), Jam(18, 7, 9), Jam(9, 20, 7)};
    int nJam = sizeof(arrJam) / sizeof(arrJam[0]);
    Jam minJam = MinArray(arrJam, nJam);
    minJam.print();


    return 0;
}

#include "Kompleks.hpp"
#include <iostream>

using namespace std;

Kompleks::Kompleks() {
    this->real = 0.0;
    this->imag = 0.0;
}

Kompleks::Kompleks(double r, double i) {
    this->real = r;
    this->imag = i;
} 

Kompleks::Kompleks(const Kompleks& other) {
    this->real = other.real;
    this->imag = other.imag;
}

double Kompleks::getReal() const {
    return this->real;
}
double Kompleks::getImag() const {
    return this->imag;
}

double Kompleks::setReal(double r) {
    this->real = r;
}

double Kompleks::setImag(double i) {
    this->imag = i;
}

Kompleks Kompleks::operator+(const Kompleks& other) const {
    Kompleks c;
    c.real = this->real + other.real;
    c.imag = this->imag + other.imag;
    return c;
}

Kompleks Kompleks::operator-(const Kompleks& other) const {
    Kompleks c;
    c.real = this->real - other.real;
    c.imag = this->imag - other.imag;
    return c;
}


Kompleks Kompleks::operator*(const Kompleks& other) const {
    Kompleks c;
    c.real = (this->real * other.real) - (this->imag * other.imag);
    c.imag = (this->real * other.imag) + (this->imag * other.real);
    return c;
}


bool Kompleks::operator==(const Kompleks& other) const {
    return this->real == other.real && this->imag == other.imag;
}
// Membandingkan dua bilangan kompleks
// Misal: a = 1 + 2i, b = 3 + 4i;
// a == b = (1==3) && (2==4) = false
// Misal: a = 1 + 2i, b = 1 + 2i;
// a == b = (1==1) && (2==2) = true

Kompleks& Kompleks::operator=(const Kompleks& other) {
    if (this == &other) {
        return *this;
    }
    this->real = other.real;
    this->imag = other.imag;
    return *this;
}
// Menyalin dua bilangan kompleks

ostream& operator<<(ostream& os, const Kompleks& c) {
    if (c.real == 0 && c.imag == 0) {
        os << "0";
    } else if (c.real == 0) {
        os << c.imag << "i";
    } else if (c.imag == 0) {
        os << c.real;
    } else {
        os << c.real << (c.imag < 0 ? " - " : " + ") << (c.imag < 0 ? -c.imag : c.imag) << "i";
    }
    return os;
}
// Menampilkan bilangan kompleks
// Note: Tidak menggunakan endl
// Misal: Kompleks(1, 2)
// cout << a << endl; // Output: 1 + 2i
// Jika imajiner < 0; Misal: Kompleks(1, -2)
// cout << a << endl; // Output: 1 - 2i
// Jika nilai imajiner 0, jangan tampilkan i; Misal: Kompleks(1, 0)
// cout << a << endl; // Output: 1
#ifndef KENDARAAN_HPP
#define KENDARAAN_HPP

#include <iostream>
using namespace std;

class Kendaraan
{
protected:
    int transportID; // nomor unik kendaraan

public:
    Kendaraan(); // ctor
    Kendaraan(int transportID); // ctor user-defined
    Kendaraan(const Kendaraan &transport); // cctor
    Kendaraan& operator= (const Kendaraan &transport);
    ~Kendaraan();

    // Method
    virtual void printInfo() = 0;
    virtual int biayaSewa(int lamaSewa) = 0;
};

#endif
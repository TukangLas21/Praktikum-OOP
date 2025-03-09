#include "KoleksiKendaraan.hpp"
#include <iostream>

using namespace std;

KoleksiKendaraan::KoleksiKendaraan() {
    this->arrKendaraan = new Kendaraan[100];
    this->Neff = 0;
    this->size = 100;
}

KoleksiKendaraan::KoleksiKendaraan(int size) {
    this->arrKendaraan = new Kendaraan[size];
    this->Neff = 0;
    this->size = size;
}

KoleksiKendaraan::KoleksiKendaraan(const KoleksiKendaraan &koleksiKendaraan) {
    this->arrKendaraan = new Kendaraan[koleksiKendaraan.size];
    this->Neff = koleksiKendaraan.Neff;
    for (int i = 0; i < koleksiKendaraan.Neff; i++) {
        this->arrKendaraan[i] = koleksiKendaraan.arrKendaraan[i];
    }
}

KoleksiKendaraan& KoleksiKendaraan::operator= (const KoleksiKendaraan &koleksiKendaraan) {
    delete[] this->arrKendaraan;
    this->arrKendaraan = new Kendaraan[koleksiKendaraan.size];
    this->size = koleksiKendaraan.size;
    this->Neff = koleksiKendaraan.Neff;
    for (int i = 0; i < koleksiKendaraan.Neff; i++) {
        this->arrKendaraan[i] = koleksiKendaraan.arrKendaraan[i];
    }
    return *this;
}

KoleksiKendaraan::~KoleksiKendaraan() {
    delete[] this->arrKendaraan;
}

void KoleksiKendaraan::printAll() {
    cout << "Berikut adalah informasi kendaraan dalam kelompok ini: " << endl;
    for (int i = 0; i < this->Neff; i++) {
        this->arrKendaraan[i].printInfo();
    }
}

void KoleksiKendaraan::operator<<(Kendaraan transport) {
    this->Neff++;
    this->arrKendaraan[this->Neff-1] = transport;
}

void KoleksiKendaraan::operator<<(KoleksiKendaraan koleksiKendaraan) {
    int newNeff = this->Neff + koleksiKendaraan.Neff;
    if (newNeff > this->size) {
        newNeff = this->size;
    }
    
    for (int i = this->Neff; i < newNeff; i++) { // Jika melebihi size, maka ditampung yang bisa saja
        this->arrKendaraan[i] = koleksiKendaraan.arrKendaraan[i - this->Neff];
    }
}
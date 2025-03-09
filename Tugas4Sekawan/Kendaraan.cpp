#include "Kendaraan.hpp"
#include <iostream>

using namespace std;

int Kendaraan::numOfTransport = 0;

// constructor default
Kendaraan::Kendaraan() {
    this->transportID = 0;
    this->transportCategory = "mobil";
    this->transportBrand = "XXX";
    this->releaseYear = 0;
    numOfTransport++;
}

// constructor user-defined
Kendaraan::Kendaraan(int transportID, string transportCategory, string transportBrand, int releaseYear) {
    this->transportID = transportID;
    this->transportCategory = transportCategory;
    this->transportBrand = transportBrand;
    this->releaseYear = releaseYear;
    numOfTransport++;
}

// copy constructor
Kendaraan::Kendaraan(const Kendaraan &transport) {
    this->transportID = numOfTransport;
    this->transportCategory = transport.transportCategory;
    this->transportBrand = transport.transportBrand;
    this->releaseYear = transport.releaseYear;
    numOfTransport++;
}

// operator assignment
Kendaraan& Kendaraan::operator= (const Kendaraan &transport) {
    this->transportCategory = transport.transportCategory;
    this->transportBrand = transport.transportBrand;
    this->releaseYear = transport.releaseYear;
    return *this;
}

// destructor (kosong karena tidak ada alokasi memori dinamis)
Kendaraan::~Kendaraan() {
}

string Kendaraan::getTransportCategory() {
    return this->transportCategory;
}

void Kendaraan::printInfo() {
    cout << "ID Kendaraan: " << this->transportID << endl;
    cout << "Kategori: " << this->transportCategory << endl;
    cout << "Merk: " << this->transportBrand << endl;
    cout << "Tahun Keluaran: " << this->releaseYear << endl;
}

int Kendaraan::biayaSewa(int lamaSewa) {
    if (this->transportCategory == "minibus") {
        if (lamaSewa <= 5) {
            return 5000000;
        } else {
            return 5000000 + 500000 * (lamaSewa - 5);
        }
    } else if (this->transportCategory == "mobil") {
        return 500000 * lamaSewa;
    } else if (this->transportCategory == "bus") {
        return lamaSewa * 1000000;
    } else return 0;
}
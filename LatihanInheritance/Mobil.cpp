#include "Kendaraan.hpp"

class Mobil : public Kendaraan {
private:
    string transportBrand;
    int releaseYear;
    string supir;

public:
    Mobil() : Kendaraan() {
        this->transportBrand = "XXX";
        this->releaseYear = 0;
        this->supir = "XXX";
    }

    Mobil(int transportID, string transportBrand, int releaseYear, string supir) : Kendaraan(transportID) {
        this->transportBrand = transportBrand;
        this->releaseYear = releaseYear;
        this->supir = supir;
    }

    Mobil(const Mobil &mobil) : Kendaraan(mobil) {
        this->transportBrand = mobil.transportBrand;
        this->releaseYear = mobil.releaseYear;
        this->supir = mobil.supir;
    }

    Mobil& operator= (const Mobil &mobil) {
        Kendaraan::operator=(mobil);
        this->transportBrand = mobil.transportBrand;
        this->releaseYear = mobil.releaseYear;
        this->supir = mobil.supir;
        return *this;
    }

    ~Mobil() {}

    void printInfo() {
        cout << "Berikut informasi tentang mobil ini: " << endl;
        cout << "ID Kendaraan: " << this->transportID << endl;
        cout << "Merk: " << this->transportBrand << endl;
        cout << "Tahun Keluaran: " << this->releaseYear << endl;
        cout << "Nama Supir: " << this->supir << endl;
    }

    int biayaSewa(int lamaSewa) {
        return 500000 * lamaSewa;
    }
};
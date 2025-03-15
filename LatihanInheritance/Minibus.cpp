#include "Kendaraan.hpp"

using namespace std;

class Minibus : public Kendaraan {
private:
    string transportBrand;
    int releaseYear;

public:
    Minibus() : Kendaraan() {
        this->transportBrand = "XXX";
        this->releaseYear = 0;
    }

    Minibus(int transportID, string transportBrand, int releaseYear) : Kendaraan(transportID) {
        this->transportBrand = transportBrand;
        this->releaseYear = releaseYear;
    }

    Minibus(const Minibus &minibus) : Kendaraan(minibus) {
        this->transportBrand = minibus.transportBrand;
        this->releaseYear = minibus.releaseYear;
    }

    Minibus& operator= (const Minibus &minibus) {
        Kendaraan::operator=(minibus);
        this->transportBrand = minibus.transportBrand;
        this->releaseYear = minibus.releaseYear;
        return *this;
    }

    ~Minibus() {}

    void printInfo() {
        cout << "Berikut informasi tentang minibus ini: " << endl;
        cout << "ID Kendaraan: " << this->transportID << endl;
        cout << "Merk: " << this->transportBrand << endl;
        cout << "Tahun Keluaran: " << this->releaseYear << endl;
    }

    int biayaSewa(int lamaSewa) {
        if (lamaSewa <= 5) {
            return 5000000;
        } else {
            return 5000000 + 500000 * (lamaSewa - 5);
        }
    }

    int diskon(int lamaSewa) {
        if (lamaSewa > 10) {
            return biayaSewa(lamaSewa) * 0.1;
        } else {
            return 0;
        }
    }
};
#include "Kendaraan.hpp"

using namespace std;

class Bus : public Kendaraan {
private:
    string transportBrand;
    int releaseYear;
    int capacity;

public:
    Bus() : Kendaraan() {
        this->transportBrand = "XXX";
        this->releaseYear = 0;
        this->capacity = 0;
    }

    Bus(int transportID, string transportBrand, int releaseYear, int capacity) : Kendaraan(transportID) {
        this->transportBrand = transportBrand;
        this->releaseYear = releaseYear;
        this->capacity = capacity;
    }

    Bus(const Bus &bus) : Kendaraan(bus) {
        this->transportBrand = bus.transportBrand;
        this->releaseYear = bus.releaseYear;
        this->capacity = bus.capacity;
    }  

    Bus& operator= (const Bus &bus) {
        Kendaraan::operator=(bus);
        this->transportBrand = bus.transportBrand;
        this->releaseYear = bus.releaseYear;
        this->capacity = bus.capacity;
        return *this;
    }

    ~Bus() {}

    void printInfo() {
        cout << "Berikut informasi tentang bus ini: " << endl;
        cout << "ID Kendaraan: " << this->transportID << endl;
        cout << "Merk: " << this->transportBrand << endl;
        cout << "Tahun Keluaran: " << this->releaseYear << endl;
        cout << "Kapasitas: " << this->capacity << " orang" << endl;
    }

    int biayaSewa(int lamaSewa) {
        return 1000000 * lamaSewa;
    }
};
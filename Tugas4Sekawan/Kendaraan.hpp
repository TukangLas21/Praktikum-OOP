#ifndef KENDARAAN_HPP
#define KENDARAAN_HPP

#include <string>
using namespace std;

class Kendaraan
{
private:
    int transportID; // nomor unik kendaraan
    string transportCategory; // kategori kendaraan
    string transportBrand; // merk kendaraan
    int releaseYear; // tahun keluaran
    static int numOfTransport; // jumlah kendaraan yang sudah dibuat
public:
    Kendaraan(); // ctor
    Kendaraan(int transportID, string transportCategory, string transportBrand, int releaseYear); // ctor user-defined
    Kendaraan(const Kendaraan &transport); // cctor
    Kendaraan& operator= (const Kendaraan &transport);
    ~Kendaraan();

    string getTransportCategory();

    // Method
    void printInfo();
    int biayaSewa(int lamaSewa);
};

#endif
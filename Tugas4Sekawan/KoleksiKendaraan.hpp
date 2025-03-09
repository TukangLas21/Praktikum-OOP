#ifndef KOLEKSI_KENDARAAN_HPP
#define KOLEKSI_KENDARAAN_HPP

#include "Kendaraan.hpp"

using namespace std;

class KoleksiKendaraan
{
private:
    Kendaraan* arrKendaraan; // pointer menuju array of Kendaraan
    int Neff; // jumlah Kendaraan
    int size; // ukuran array 

public:
    KoleksiKendaraan();
    KoleksiKendaraan(int size);
    KoleksiKendaraan(const KoleksiKendaraan &koleksiKendaraan);
    KoleksiKendaraan& operator= (const KoleksiKendaraan &koleksiKendaraan);
    ~KoleksiKendaraan();

    void printAll();
    void operator<<(Kendaraan);
    void operator<<(KoleksiKendaraan);

};


#endif
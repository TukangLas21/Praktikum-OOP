#include "Gudang.hpp"
#include "Barang.hpp"
#include "BarangMakanan.hpp"
#include "BarangElektronik.hpp"
#include "Exception.hpp"
#include <iostream>

using namespace std;

Gudang::Gudang() {
    kapasitasTotal = DEFAULT_KAPASITAS;
    kapasitasTerpakai = 0;
    tenagaKerja = DEFAULT_TENAGA_KERJA;
    uang = DEFAULT_UANG;
}

Gudang::Gudang(int kapasitas, int uang, int tenagaKerja) {
    kapasitasTotal = kapasitas;
    kapasitasTerpakai = 0;
    this->tenagaKerja = tenagaKerja;
    this->uang = uang;
}

Gudang::~Gudang() {
}

void Gudang::simpanBarang(Barang *barang) {
    if (barang->getJenis() == "Makanan") {
        BarangMakanan* cur = dynamic_cast<BarangMakanan*>(barang);
        try {
            if (cur->getHariKedaluwarsa() <= 0) {
                throw BarangKedaluwarsaException();
            }
            pakaiKapasitas(cur->getBerat());
            pakaiUang(100);
            pakaiTenagaKerja();

            daftarBarang.push_back(cur);
            cout << "Barang [" << daftarBarang.size() - 1 << "] " << cur->getNama() << " berhasil disimpan" << endl;
        }
        catch (BarangKedaluwarsaException e) {
            cout << e.what() << ", buang dulu." << endl;
        }
        catch (KapasitasPenuhException e) {
            cout << e.what() << ", perluas gudang dulu." << endl;
        }
        catch (UangTidakCukupException e) {
            kapasitasTerpakai -= cur->getBerat();
            cout << e.what() << ", cari pemasukan dulu." << endl;
        }
        catch (TenagaKerjaTidakCukupException e) {
            kapasitasTerpakai -= cur->getBerat();
            tambahUang(100);
            cout << e.what() << ", rekrut dulu." << endl;
        }
    }
    else {
        BarangElektronik* cur = dynamic_cast<BarangElektronik*>(barang);
        try {
            pakaiKapasitas(cur->getBerat());
            pakaiUang(100);
            pakaiTenagaKerja();

            daftarBarang.push_back(cur);
            cout << "Barang [" << daftarBarang.size() - 1 << "] " << cur->getNama() << " berhasil disimpan" << endl;
        }
        catch (KapasitasPenuhException e) {
            cout << e.what() << ", perluas gudang dulu." << endl;
        }
        catch (UangTidakCukupException e) {
            kapasitasTerpakai -= cur->getBerat();
            cout << e.what() << ", cari pemasukan dulu." << endl;
        }
        catch (TenagaKerjaTidakCukupException e) {
            kapasitasTerpakai -= cur->getBerat();
            tambahUang(100);
            cout << e.what() << ", rekrut dulu." << endl;
        }
    }
}

void Gudang::tambahKapasitas(int kg) {
    kapasitasTotal += kg;
}

void Gudang::tambahTenagaKerja(int jumlah) {
    tenagaKerja += jumlah;
}

void Gudang::tambahUang(int jumlah) {
    uang += jumlah;
}

void Gudang::pakaiKapasitas(int kg) {
    if (kapasitasTerpakai + kg > kapasitasTotal) {
        throw KapasitasPenuhException();
    } else {
        kapasitasTerpakai += kg;
    }
}

void Gudang::pakaiUang(int jumlah) {
    if (uang < jumlah) {
        throw UangTidakCukupException();
    } else {
        uang -= jumlah;
    }
}

void Gudang::pakaiTenagaKerja() {
    if (tenagaKerja <= 0) {
        throw TenagaKerjaTidakCukupException();
    } else {
        tenagaKerja--;
    }
}

void Gudang::sebutBarang(int idx) {
    try
    {
        Barang *barang = daftarBarang[idx];
        cout << barang->getNama() << " - " << barang->getJenis() << " - " << barang->getBerat() << "kg" << endl;
    }
    catch(const out_of_range &e)
    {
        cout << e.what() << '\n';
    }
    
}

void Gudang::statusGudang() const {
    cout << "Status gudang:" << endl;
    cout << "  Kapasitas total: " << kapasitasTotal << " kg" << endl;
    cout << "  Kapasitas terpakai: " << kapasitasTerpakai << " kg" << endl;
    cout << "  Uang: " << uang << endl;
    cout << "  Tenaga kerja: " << tenagaKerja << endl;
    cout << "  Barang:" << endl;
    for (int i = 0; i < daftarBarang.size(); i++) {
        cout << "    [" << i << "] ";
        cout << daftarBarang[i]->getNama() << " - " << daftarBarang[i]->getJenis() << " - " << daftarBarang[i]->getBerat() << "kg" << endl;
    }
}
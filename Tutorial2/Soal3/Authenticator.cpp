#include "Authenticator.hpp"
#include <iostream>

using namespace std;

Authenticator :: Authenticator(){
    this->secretResource = "Ini adalah data rahasia!";
    this->userCount = 0;
    this->currentUser = nullptr;
    *this->users = nullptr;
}

void Authenticator :: registerUser (const string &username, const string &password, bool isAdmin) {
    if (this->userCount < MAX_USERS) {
        bool check = true;
        for (int i = 0; i < this->userCount; i++) {
            if (username == this->users[i]->getUsername()) {
                check = false;
                break;
            }
        }
        if (check) {
            if (isAdmin) {
                this->users[this->userCount] = new AdminUser(username, password);
                this->userCount++;
            } else {
                this->users[this->userCount] = new User(username, password);
                this->userCount++;
            }
            cout << "Sukses: User " << username << " berhasil terdaftar!" << endl;
        } else {
            cout << "Gagal: Username sudah digunakan!" << endl;
        }
    } else {
        cout << "Gagal: Kapasitas user penuh!" << endl;
    }
}

void Authenticator :: login(const string &username, const string &password) {
    bool check = false;
    int idx = 0;
    for (int i = 0; i < this->userCount; i++) {
        if (username == this->users[i]->getUsername() && this->users[i]->checkPassword(password)) {
            check = true;
            idx = i;
            break;
        }
    }
    if (check) {
        this->currentUser = users[idx];
        cout << "Sukses: Login berhasil! Selamat datang, " << username << "." << endl;
    } else {
        cout << "Gagal: Username atau password salah!" << endl;
    }
}

void Authenticator :: logout() {
    if (this->currentUser == nullptr) {
        cout << "Gagal: Tidak ada user yang sedang login!" << endl;
    } else {
        cout << "Sukses: User " << this->currentUser->getUsername() << " telah logout." << endl;
        this->currentUser = nullptr;
    }
}

void Authenticator :: accessResource() const {
    if (this->currentUser == nullptr) {
        cout << "Akses ditolak! Silakan login terlebih dahulu." << endl;
    } else {
        cout << "Resource: " << this->secretResource  << endl;
    }
}

void Authenticator :: setResource(const string &newResource) {
    if (this->currentUser == nullptr) {
        cout << "Gagal: Tidak bisa mengubah resource! Silakan login terlebih dahulu." << endl;
    } else if (this->currentUser->isAdmin() == false) {
        cout << "Gagal: Tidak bisa mengubah resource! Hanya admin yang dapat melakukan ini." << endl;
    } else {
        this->secretResource = newResource;
        cout << "Sukses: Resource telah diperbarui oleh  " << this->currentUser->getUsername() << "." << endl;
    }
}

Authenticator::~Authenticator() {
}
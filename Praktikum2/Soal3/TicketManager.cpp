#include "TicketManager.hpp"
#include <iostream>

using namespace std;

TicketManager::TicketManager(string eventName)
/* Constructor default:
    * - Membuat event dengan nama yang diberikan.
    * - Kapasitas default: 5 tiket VIP, 10 tiket Regular.
    * - Tidak ada tiket yang terjual pada awalnya.
    */
{
    *this->tickets = nullptr;
    this->eventName = eventName;
    this->vipCapacity = 5;
    this->regularCapacity = 10;
    this->ticketCount = 0;
    this->currentRegularTickets = 0;
    this->currentVIPTickets = 0;

}

TicketManager::TicketManager(string eventName, int vipCapacity, int regularCapacity)
/* Constructor dengan kapasitas yang ditentukan:
    * - Membuat event dengan kapasitas khusus untuk VIP dan Regular.
    * - Jika total kapasitas melebihi VENUE_CAPACITY, cetak:
    *   "The total capacity you construct is <total>, meanwhile the venue capacity is 15"
    */
{   
    int totCapacity = vipCapacity + regularCapacity;
    if (totCapacity > VENUE_CAPACITY) {
        cout << "The total capacity you construct is " << totCapacity << ", meanwhile the venue capacity is 15" << endl;
    } else {
        *this->tickets = nullptr;
        this->eventName = eventName;
        this->vipCapacity = vipCapacity;
        this->regularCapacity = regularCapacity;
        this->ticketCount = 0;
        this->currentRegularTickets = 0;
        this->currentVIPTickets = 0;
    }
}

TicketManager::~TicketManager()
/* Destructor:
    * - Membersihkan semua tiket yang telah dialokasikan secara dinamis.
    * - Menetapkan pointer tiket menjadi nullptr setelah dihapus.
    */
{

}

string TicketManager::getEventName() const
/* Mengembalikan nama acara yang dikelola oleh TicketManager.
    * Output: Nama acara dalam bentuk string.
    */
{
    return this->eventName;
}

void TicketManager::buyTicket(const string &ownerName, bool isVIP)
/* Membeli tiket untuk pengguna.
* Input:
* - ownerName: Nama pemilik tiket.
* - isVIP: Jika true, membeli tiket VIP; jika false, membeli tiket Regular.
*
* Proses:
* - Jika venue penuh, cetak "Error: All tickets are sold out!".
* - Jika kapasitas VIP penuh, cetak "Error: No VIP tickets left!".
* - Jika kapasitas Regular penuh, cetak "Error: No Regular tickets left!".
*
* - Jika pembelian berhasil, sistem akan membuat **ID tiket unik** berdasarkan jenis tiket:
*   - Jika tiket VIP, ID akan berupa "V" diikuti nomor urut tiket VIP.
*   - Jika tiket Regular, ID akan berupa "R" diikuti nomor urut tiket Regular.
*
* - Contoh penggunaan `to_string()` dalam pembuatan ID:
*   int angka = 5;
*   string hasil = "V" + to_string(angka); // hasil: "V5"
*
* - Jika pembelian berhasil, cetak:
*   "Success: <ownerName> bought a <VIP/Regular> ticket! Ticket ID: <ticketID>"
*/
{
    // Check venue penuh
    if (this->ticketCount == VENUE_CAPACITY) {
        cout << "Error: All tickets are sold out!" << endl;
        return;
    }

    // Check Kapasitas VIP
    if (isVIP) {
        if (this->currentVIPTickets == this->vipCapacity) {
            cout << "Error: No VIP tickets left!" << endl;
            return;
        } else {
            this->currentVIPTickets++;
            string newVIPID = "V" + to_string(this->currentVIPTickets);
            Ticket* newVIPTicket = new VIPTicket(newVIPID, ownerName);
            this->tickets[this->ticketCount] = newVIPTicket;
            ticketCount++;
            cout << "Success: " << ownerName << " bought a VIP ticket! Ticket ID: " << newVIPID << endl;
        }

    } else {  // Check regular capacity 
        if (this->currentRegularTickets == this->regularCapacity) {
            cout << "Error: No Regular tickets left!" << endl;
            return;
        } else {
            this->currentRegularTickets++;
            string newRegID = "R" + to_string(this->currentRegularTickets);
            Ticket* newRegTicket = new RegularTicket(newRegID, ownerName);
            this->tickets[this->ticketCount] = newRegTicket;
            ticketCount++;
            cout << "Success: " << ownerName << " bought a Regular ticket! Ticket ID: " << newRegID << endl;
        }
    }  
}

void TicketManager::checkTicket(const string &ticketID) const
/* Mengecek apakah tiket dengan ID tertentu valid.
    * Input:
    * - ticketID: ID tiket yang ingin diperiksa.
    *
    * Output:
    * - Jika ditemukan, cetak detail tiket menggunakan metode printTicket().
    * - Jika tidak ditemukan, cetak "Ticket ID is invalid!".
    */
{
    for (int i = 0; i < this->ticketCount; i++) {
        if (this->tickets[i]->getTicketID() == ticketID) {
            this->tickets[i]->printTicket();
            return;
        }
    }
    cout << "Ticket ID is invalid!" << endl;
}

void TicketManager::listAudience() const
/* Menampilkan daftar semua pemegang tiket.
    * Output:
    * - Jika belum ada yang membeli tiket, cetak "No audience yet!".
    * - Jika ada, cetak dalam format:
    *   "<nomor>. <printTicket()>"
    *
    * - Nomor urut dalam output harus dimulai dari 1.
    */
{
    if (this->ticketCount == 0) {
        cout << "No audience yet!" << endl;
    } else {
        for (int i = 0; i < this->ticketCount; i++) {
            cout << i+1 << ". ";
            this->tickets[i]->printTicket();
        }
    }
}

int TicketManager::calculateRevenue() const
/* Menghitung total pendapatan dari tiket yang terjual.
    * - Tiket VIP seharga 500.
    * - Tiket Regular seharga 275.
    * 
    * Output: Total pendapatan dalam bentuk integer.
    */
{
    return (500 * this->currentVIPTickets) + (275 * this->currentRegularTickets);
}
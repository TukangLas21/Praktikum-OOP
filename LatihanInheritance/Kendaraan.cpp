#include "Kendaraan.hpp"

using namespace std;

Kendaraan::Kendaraan() : transportID(0) {}
Kendaraan::Kendaraan(int transportID) : transportID(transportID) {}
Kendaraan::Kendaraan(const Kendaraan &transport) : transportID(transport.transportID) {}
Kendaraan& Kendaraan::operator= (const Kendaraan &transport)
{
    transportID = transport.transportID;
    return *this;
}
Kendaraan::~Kendaraan() {}

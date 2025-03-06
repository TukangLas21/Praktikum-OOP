#include "SpacingGuildShip.hpp"

using namespace std;

float SpacingGuildShip::totalGuildTravel = 0;
int SpacingGuildShip::producedShips = 0;

SpacingGuildShip::SpacingGuildShip() : serialNum(producedShips+1), maxPassengerCap(50), guildNavigatorCount(3) {
    this->passengerCount = 0;
    this->operatingGuildNavigator = guildNavigatorCount;
    this->spiceStock = 50;
    producedShips += 1;
}

SpacingGuildShip::SpacingGuildShip(int maxPassengerCap, int guildNavigatorCount, int spiceStock) : serialNum(producedShips+1), maxPassengerCap(maxPassengerCap), guildNavigatorCount(guildNavigatorCount) {
    this->passengerCount = 0;
    this->operatingGuildNavigator = guildNavigatorCount;
    this->spiceStock = spiceStock;
    producedShips += 1;
}

SpacingGuildShip::SpacingGuildShip(const SpacingGuildShip &ship) : serialNum(producedShips+1), maxPassengerCap(ship.maxPassengerCap), guildNavigatorCount(ship.guildNavigatorCount) {
    this->passengerCount = ship.passengerCount;
    this->operatingGuildNavigator = ship.guildNavigatorCount;
    this->spiceStock = ship.spiceStock;
    producedShips += 1;
}

SpacingGuildShip::~SpacingGuildShip() {
}

int SpacingGuildShip::getShipSerialNum() const {
    return this->serialNum;
}

int SpacingGuildShip::getPassengerCount() const {
    return this->passengerCount;
}

void SpacingGuildShip::travel(float distance) {
    if (this->operatingGuildNavigator >= 1) {
        totalGuildTravel += distance / (E*E*this->operatingGuildNavigator);
        this->operatingGuildNavigator -= 1;
    }
}

void SpacingGuildShip::boarding(int addedPassengers) {
    this->passengerCount += addedPassengers;
    if (this->passengerCount > this->maxPassengerCap) {
        this->passengerCount = this->maxPassengerCap;
    }
}

void SpacingGuildShip::dropOff(int droppedPassengers) {
    if (droppedPassengers <= this->passengerCount) {
        this->passengerCount -= droppedPassengers;
    } else {
        this->passengerCount = 0;
    }
}

void SpacingGuildShip::refreshNavigator(int n) {
    while (this->operatingGuildNavigator < this->guildNavigatorCount && this->spiceStock >= GUILD_NAVIGATOR_SPICE_DOSE) {
        this->spiceStock -= GUILD_NAVIGATOR_SPICE_DOSE;
        this->operatingGuildNavigator += 1;
    }
}

void SpacingGuildShip::transitToArrakis(int addedSpice) {
    this->spiceStock += addedSpice;
}
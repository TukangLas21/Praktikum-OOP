#include "Item.hpp"
#include <iostream>

using namespace std;

int Item::totalItems = 0;
int Item::totalRevenue = 0;

Item::Item() : serialNum(totalItems+1) {
    this->stock = 0;
    this->price = 0;
    this->sold = 0;

    totalItems += 1;
}

Item::Item(int stock, int price) : serialNum(totalItems+1) {
    this->stock = stock;
    this->price = price;
    this->sold = 0;

    totalItems += 1;
}

Item::Item(const Item &item) : serialNum(totalItems+1) {
    this->stock = item.stock;
    this->price = item.price;
    this->sold = item.sold;

    totalItems += 1;
}

Item::~Item() {
}

int Item::getSerialNum() const {
    return this->serialNum;
}

int Item::getSold() const {
    return this->sold;
}

int Item::getPrice() const {
    return this->price;
}

void Item::addStock(int addedStock) {
    this->stock += addedStock;
}

void Item::sell(int soldStock) {
    if (this->stock >= soldStock) {
        this->stock -= soldStock;
        this->sold += soldStock;
        totalRevenue += soldStock * this->price;
    } else {
        totalRevenue += this->price * this->stock;
        this->sold += this->stock;
        this->stock = 0;
    }
}

void Item::setPrice(int newPrice) {
    this->price = newPrice;
}
#include "dryFruit.hpp"
#include <iostream>

DryFruit::DryFruit(const std::string& name, size_t amount, size_t basePrice, size_t expirationDate)
    : Fruit(name, amount, basePrice, expirationDate) {};

Fruit& DryFruit::operator--() {
    if (counter_ >= 10) {
        --purchaseDate_;
        counter_ = 0;
    }
     counter_++;
    return *this;
}
Fruit DryFruit::operator--(int) {
    if (counter_ >= 10) {
        --purchaseDate_;
        counter_ = 0;
    }
     counter_++;
    return *this;
}
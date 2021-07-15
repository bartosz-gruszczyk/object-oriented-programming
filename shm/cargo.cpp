#include "cargo.hpp"

Cargo::Cargo(std::string name, size_t amount, size_t basePrice)
    : name_(name)
    , amount_(amount)
    , basePrice_(basePrice)
    {}

Cargo& Cargo::operator+=(size_t amount) {
    amount_ += amount;
    return *this;
}

Cargo& Cargo::operator-=(size_t amount) {
    amount_ -= amount;
    return *this;
}

bool Cargo::operator== (const Cargo& cargo) const {
    return cargo.getName() == name_;
} 

const std::string& Cargo::getName() const {
    return name_;
}
size_t Cargo::getAmount() const {
    return amount_;
}
size_t Cargo::getBasePrice() const {
    return basePrice_;
}
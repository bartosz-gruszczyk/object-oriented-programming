#pragma once 

#include "fruit.hpp"

#include <iostream>

class DryFruit : public Fruit
{
public:
    DryFruit(const std::string& name, size_t amount, size_t basePrice, size_t expirationDate);
    Fruit& operator--() override;
    Fruit operator--(int) override;

    size_t getPrice() const override{ return 3 * basePrice_ * static_cast<float>(purchaseDate_)/ expirationDate_;};
    std::string getName() const override  { return "DryFruit" + name_; };
    size_t getAmount() const override { return amount_; };
    size_t getBasePrice() const  { return basePrice_; };
    size_t getCounter() const {return counter_;};
private:
    size_t counter_{0};
};

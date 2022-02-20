#pragma once
#include "cargo.hpp"

constexpr size_t MaxPercentage { 96 };
// Class responsible for managing Alcohol in the game.
class Alcohol : public Cargo {
public:
    Alcohol(const std::string& name,
        size_t amount,
        size_t basePrice,
        size_t percentage);
    ~Alcohol() override {};

    Cargo& operator+=(size_t amount) override;
    Cargo& operator-=(size_t amount) override;
    bool operator==(const Cargo&) const override;

    size_t getPercentage() const { return percentage_; };
    void setPercentage(size_t percentage) { percentage_ = percentage; };

    // Methods override from Cargo class.
    size_t getPrice() const override;
    std::string getName() const override { return name_; };
    size_t getAmount() const override { return amount_; };
    size_t getBasePrice() const override { return basePrice_; };
    void setAmount(const size_t& amount) override { amount_ = amount; };

private:
    size_t percentage_;
};
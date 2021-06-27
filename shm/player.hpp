#pragma once

#include <memory>

#include "cargo.hpp"
#include "ship.hpp"

class Player {
public:
    Player(Ship&  ship, size_t money, size_t availableSpace) ;
    //~Player();
    // Player() = default;

    //getters
    size_t getMoney() const;
    size_t getAvailableSpace() const;
    std::shared_ptr<Ship> getShip() const;
    size_t getSpeed() const;
    std::shared_ptr<Cargo> getCargo(size_t index) const;
    


private:
    std::shared_ptr<Ship> ship_;
    size_t money_;
    size_t availableSpace_;
    //size_t availableSpace() const;
    

    //methods
   // size_t availableSpace();
};

#include <algorithm>
#include <iostream>
#include <memory>

#include "cargo.hpp"
#include "ship.hpp"

// Class responsible for managing Ships in the game.

Ship& Ship::operator-=(size_t num) {
    if (crew_ - num <= crew_) {
        crew_ -= num;
    } else {
        std::cerr << "You need at least one member of the crew !!!\n";
    }
    return *this;
}

Ship& Ship::operator+=(size_t num) {
    if (crew_ + num <= maxCrew_) {
        crew_ += num;
    } else {
        std::cerr << " The maximum amount of members of the crew is " << maxCrew_ << " !!!! \n";
    }

    return *this;
}

size_t Ship::getCapacity() const {
    return capacity_;
}
size_t Ship::getMaxCrew() const {
    return maxCrew_;
}
size_t Ship::getCrew() const {
    return crew_;
}
size_t Ship::getSpeed() const {
    return speed_;
}
std::string Ship::getName() const {
    return name_;
}
size_t Ship::getId() const {
    return id_;
}
// Function returns specific cargo 
std::shared_ptr<Cargo> Ship::getCargo(size_t index) const {
    if (cargos_.size() <= index) {
        return nullptr;
    }
    return cargos_[index];
}

std::vector<std::shared_ptr<Cargo>> Ship::getCargosVector() const {
    return cargos_;
}

void Ship::setName(const std::string& name) {
    name_ = name;
}

// Function find
std::vector<std::shared_ptr<Cargo>>::iterator Ship::findCargo(const std::shared_ptr<Cargo>& cargo) {
    auto find = std::find_if(cargos_.begin(), cargos_.end(),
                             [cargo](const auto& el) { return cargo->getName() == el->getName() &&
                                                              cargo->getBasePrice() == el->getBasePrice(); });
    return find;
}

void Ship::unload(const std::shared_ptr<Cargo>& cargo) {
    cargos_.erase(findCargo(cargo));
}

void Ship::load(const std::shared_ptr<Cargo>& cargo, size_t amount) {
    auto isNew = findCargo(cargo);

    if (isNew == cargos_.end()) {
        cargos_.push_back(cargo);
        return;
    }
    // To jest wartość która znajduje sie pod iteratorem( *(*isNew));
    **isNew += amount;
}

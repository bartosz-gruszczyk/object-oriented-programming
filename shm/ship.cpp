#include <algorithm>
#include <iomanip>
#include <iostream>
#include <memory>

#include "alcohol.hpp"
#include "cargo.hpp"
#include "fruit.hpp"
#include "item.hpp"
#include "ship.hpp"

Ship::Ship(Time* time)
    : id_(-1)
{
    time->attachObserver(this);
}

Ship::Ship(size_t capacity, size_t maxCrew, size_t crew, size_t speed,
    const std::string& name, size_t id, std::vector<std::shared_ptr<Cargo>> cargos,
    Time* time)
    : capacity_(capacity)
    , maxCrew_(maxCrew)
    , crew_(crew)
    , speed_(speed)
    , name_(name)
    , id_(id)
    , cargos_(cargos)
    , time_(time)
{
    time->attachObserver(this);
}
Ship::Ship(size_t maxCrew, size_t speed, size_t id, Time* time)
    : Ship(0, maxCrew, 0, speed, "", id, {}, time)
{
    time->attachObserver(this);
}

Ship::~Ship() {
    time_->detachObserver(this);
}

Ship& Ship::operator-=(size_t num)
{
    if (crew_ - num <= crew_) {
        crew_ -= num;
    } else {
        crew_ = 0;
        std::cerr << "You need at least one member of the crew !!!\n";
    }
    return *this;
}

Ship& Ship::operator+=(size_t num)
{
    if (crew_ + num <= maxCrew_) {
        crew_ += num;
    } else {
        crew_ = maxCrew_;
        std::cerr << " The maximum amount of members of the crew is " << maxCrew_
                  << " !!!! \n";
    }
    return *this;
}

size_t Ship::getCapacity() const
{
    return capacity_;
}
size_t Ship::getMaxCrew() const
{
    return maxCrew_;
}
size_t Ship::getCrew() const
{
    return crew_;
}
size_t Ship::getSpeed() const
{
    return speed_;
}
std::string Ship::getName() const
{
    return name_;
}
size_t Ship::getId() const
{
    return id_;
}
// Function returns specific cargo
std::shared_ptr<Cargo> Ship::getCargo(size_t index) const
{
    if (cargos_.size() <= index) {
        return nullptr;
    }
    return cargos_[index];
}

std::vector<std::shared_ptr<Cargo>> Ship::getCargosVector() const
{
    return cargos_;
}

void Ship::setName(const std::string& name)
{
    name_ = name;
}

std::vector<std::shared_ptr<Cargo>>::iterator Ship::findMatchCargo(
    std::shared_ptr<Cargo> cargo)
{
    return std::find_if(cargos_.begin(), cargos_.end(),
        [&cargo](const auto& searchCargo) {
            return searchCargo->getName() == cargo->getName();
        });
}

void Ship::unload(std::shared_ptr<Cargo>& cargo, size_t amount)
{
    auto findCargo = findMatchCargo(cargo);
    if (findCargo == cargos_.end()) {
        return;
    }
    std::cout << "Jestem w unload\n";

    if (findCargo != cargos_.end()) {
        findCargo->get()->setAmount(findCargo->get()->getAmount() - amount);
        std::cout << "Jestem w po odjeciu towaru ze statku\n";
    }
}

void Ship::load(std::shared_ptr<Cargo>& cargo, size_t amount)
{
    auto findCargo = findMatchCargo(cargo);

    if (findCargo != cargos_.end()) {
        std::cout << "Dlaczego w to wchodze\n";
        if (capacity_ > cargo->getAmount()) {
            /// I just want to know, is the line below  corrected wrote? OR should I
            /// write it, in another way?
            findCargo->get()->setAmount(findCargo->get()->getAmount() + amount);

        } else {
            std::cerr << "Not enuogh space on ship!!!!\n";
        }
    }
    if (findCargo == cargos_.end()) {
        // cargos_.push_back(cargo);

        addCargo(cargo, amount);

        std::cout << "Gdzie jestem2\n";
    }

    std::cout << "wychodze z funkcji Ship::load\n";
}

void Ship::addCargo(std::shared_ptr<Cargo>& cargo, size_t amount)
{
    if (Alcohol* alcohol = dynamic_cast<Alcohol*>(cargo.get())) {
        cargos_.push_back(std::make_shared<Alcohol>(alcohol->getName(), amount,
            alcohol->getBasePrice(),
            alcohol->getPercentage()));
    } else if (Fruit* fruit = dynamic_cast<Fruit*>(cargo.get())) {
        cargos_.push_back(std::make_shared<Fruit>(fruit->getName(), amount,
            fruit->getBasePrice(),
            fruit->getExpirationDate()));
    } else if (Item* item = dynamic_cast<Item*>(cargo.get())) {
        cargos_.push_back(std::make_shared<Item>(
            item->getName(), amount, item->getPrice(), item->getRarity()));
    }
}
void Ship::setOwner(Player* newOwner)
{
    owner_ = newOwner;
}

void Ship::nextDay()
{
    owner_->setMoney(owner_->getMoney() - ((*owner_->getShip()).getCrew()));
}

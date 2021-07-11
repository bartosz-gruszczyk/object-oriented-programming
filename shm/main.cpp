#include <iostream>
#include <memory>

#include "cargo.hpp"
#include "fruit.hpp"
#include "item.hpp"
#include "alcohol.hpp"
#include "ship.hpp"

void print(const Ship& s) {
    for(const auto& el : s.getCargosVector()) {
        std::cout << "nazwa: " << el->getName() << "\t| amount: " << el->getAmount() << "\t| price: " << el->getPrice() << '\n';
    }
}

int main() {
    Fruit f1("Fasola", 10, 50, 5);
    Item i1("Kosc", 10, 20, Rarity::legendary);
    Alcohol a1("Burbon", 10, 20, 50);

    auto c1 = std::make_shared<Fruit>(f1);
    auto c2 = std::make_shared<Item>(i1);
    auto c3= std::make_shared<Alcohol>(a1);

    auto c4 = std::make_shared<Fruit>("apple", 40, 20, 20);
    auto c5 = std::make_shared<Fruit>("banan", 10, 20, 5);

    std::vector<std::shared_ptr<Cargo>> dupa{c1, c2, c3};

    Ship sh1(500, 20, 5, 3, "Bambo", 1, dupa);

    print(sh1);
    sh1.unload(c2);
    std::cout << "Po usunięciem\n";
    print(sh1);

    sh1.load(c3 , 40);
    std::cout << "Po dodaniu!\n";
     print(sh1);


    sh1.load(c4 , 80);
    sh1.load(c4 , 80);
    std::cout << "Po dodaniu!\n";
    print(sh1);


    return 0;
}
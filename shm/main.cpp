#include <iomanip>
#include <iostream>
#include <memory>

#include "alcohol.hpp"
#include "cargo.hpp"
#include "fruit.hpp"
#include "island.hpp"
#include "item.hpp"
#include "map.hpp"
#include "player.hpp"
#include "ship.hpp"
#include "store.hpp"

int main()
{
    auto cargo1 = std::make_shared<Fruit>("cebula", 40, 2, 20);
    auto cargo2 = std::make_shared<Item>("drewno", 10, 20, Rarity::epic);
    auto cargo3 = std::make_shared<Alcohol>("wino", 10, 100, 15);
    // auto cargo4 = std::make_shared<Cargo>("miedz", 10, 1);
    // auto cargo5 = std::make_shared<Cargo>("rubin", 10, 2);
    // auto cargo6 = std::make_shared<Cargo>("cebula", 3, 10);
    // auto cargo7 = std::make_shared<Cargo>("Woda", 200, 500);

    std::vector<std::shared_ptr<Cargo>> LOAD { cargo1, cargo2, cargo3 };
    Time t;
    auto s1 = std::make_shared<Ship>(500, 20, 14, 5, "Black Widow", 1, LOAD, &t );
    Player pla1(s1, 5000, 0);
    std::cout << '\n';


    Store s;

    auto car1 = s.getCargoOfStore()[1];

  
    std::cout << car1->getName() << " " << car1->getAmount() << " : "
              << car1->getBasePrice() << '\n';
    std::cout << '\n';
    std::cout << '\n';
    std::cout << s;

 

    return 0;
}

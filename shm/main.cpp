#include <iostream>
#include <memory>

#include "alcohol.hpp"
#include "cargo.hpp"
#include "dryFruit.hpp"
#include "fruit.hpp"
#include "item.hpp"
#include "ship.hpp"

void print(const Ship& s) {
    for (const auto& el : s.getCargosVector()) {
        std::cout << "nazwa: " << el->getName() << "\t| amount: " << el->getAmount() << "\t| price: " << el->getPrice() << '\n';
    }
}

int main() {
    DryFruit df1("suszona Śliwa", 50, 20, 20);
    std::cout << '\n';
    std::cout << " Przed obcięciem ceny \n";
    std::cout << "Counter " << df1.getCounter() << '\n';
    std::cout << "Data warznosci: " << df1.getPurchaseData() << '\n';
    std::cout << "Cena : " << df1.getPrice() << '\n';
    std::cout << '\n';

    df1--;
    std::cout << "po pierwszym odjęciu!" << '\n';
    std::cout << "Counter " << df1.getCounter() << '\n';
    std::cout << "Data warznosci: " << df1.getPurchaseData() << '\n';
    std::cout << "Cena : " << df1.getPrice() << '\n';

    df1--;
    std::cout << "po  odjęciu!" << '\n';
    std::cout << "Counter  " << df1.getCounter() << '\n';
    std::cout << "Data warznosci: " << df1.getPurchaseData() << '\n';
    std::cout << "Cena : " << df1.getPrice() << '\n';

    --df1;
    std::cout << "po  odjęciu!" << '\n';
    std::cout << "Counter " << df1.getCounter() << '\n';
    std::cout << "Data warznosci: " << df1.getPurchaseData() << '\n';
    std::cout << "Cena : " << df1.getPrice() << '\n';

        --df1;
        --df1;
        --df1;
        --df1;
        --df1;
        --df1;
        --df1;
        --df1;
        --df1;
        --df1;
    std::cout << "po  odjęciu!" << '\n';
    std::cout << "Counter " << df1.getCounter() << '\n';
    std::cout << "Data warznosci: " << df1.getPurchaseData() << '\n';
    std::cout << "Cena : " << df1.getPrice() << '\n';

    Fruit f1("Ananas", 20, 20, 10);
    

    return 0;
}
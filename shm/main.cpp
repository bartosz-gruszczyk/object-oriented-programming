#include <iostream>
#include <memory>

#include "cargo.hpp"
#include "player.hpp"
#include "ship.hpp"
#include "fruit.hpp"
#include "alcohol.hpp"
#include "item.hpp"

void print(const Fruit& sth) {
    std::cout << "nazwa: " << sth.getName() << ", amount: " << sth.getAmount() << ", base price: " << sth.getBasePrice() << ", dacayDays: " << sth.getExpirationDate() 
              << " cena: " << sth.getPrice() << ", dni od kupienia: "<< sth.getPurchaseData() << '\n';
}

int main() {
    
    Fruit apple("pomarancza", 50, 30, 14);
    print(apple);
    apple += 10;
    print(apple);

    Fruit sth("pomarancza", 30, 10, 2);

    if(apple == sth) {
        apple +=sth.getAmount();
    }

    --apple;
    apple--;

    print(apple);

    // Alcohol a1("kola", 2, 2, 2);
    Fruit f2("jabłko", 10, 20, 10);

    Item i1("osc", 2, 2, Rarity::common);
    Item i2("osc", 2, 3, Rarity::legendary);

    std::cout << "Ilość osci: " << i1.getAmount() << '\n';
    i1+= 20;
    std::cout << "Ilość osci: " << i1.getAmount() << '\n';
    f2+= 10;
    i1 -= 10;
    std::cout << "Ilość osci: " << i1.getAmount() << '\n';
    if(i1 == i2) {
        i1 += i2.getAmount();
    }
    std::cout << "Ilość osci: " << i1.getAmount() << '\n';
    std::cout << "cena osci 1: " << i1.getPrice() << '\n';
    std::cout << "cena osci 2: " << i2.getPrice() << '\n';

    Alcohol a1("whisky", 10, 10 ,50);
    a1 += 20;

    std::cout << "Whisky ile go mam:  " << a1.getAmount()<< '\n';

    std::cout << "Cena aktualna: " << a1.getPrice() << '\n';

    print(apple);

    return 0;

}
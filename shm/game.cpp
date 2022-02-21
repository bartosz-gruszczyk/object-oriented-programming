#include "game.hpp"
#include "map.hpp"
#include <iomanip>

Game::Game(size_t money, size_t days, size_t goal)
    : money_(money)
    , gameDayes_(days)
    , finalGoal_(goal)
{
    time_ = std::make_shared<Time>(gameDayes_);
    map_ = std::make_shared<Map>(time_);
    ship_ = std::make_shared<Ship>(1000, 40, 10, 20, "Santa Blanca", 1, 40);
    player_ = std::make_shared<Player>(ship_, money);
}

//   ship_(std::make_shared<Ship>(1000, 40, 15, 10, "Babilon", 2, {}, 10))

Game::~Game() {};

void Game::startGame()
{
    printHeader();
    // printMenu();

    // size_t option;

    // std::cin >> option;

    while (true) {
        if (checkWinCondition()) {
            printWinScreen();
            exit();
        } else if (checkLoseCondition()) {
            break;
        }
        printMenu();
        std::cout << "Write your choice: ";
        size_t choice;

        std::cin.clear();
        std::cin >> choice;

        chooseOption(static_cast<MenuOption>(choice));
    }
    // printLoseScreen();
    // exit();
}

void Game::printMenu()
{
    std::cout << "/" << std::setfill('-') << std::setw(100) << "/\n";
    std::cout << "*" << std::setfill(' ') << std::setw(58)
              << " CHOOSE ACTION: " << std::setw(42) << "/\n";
    std::cout << "/" << std::setfill('-') << std::setw(100) << "/\n";
    std::cout << "/" << std::setfill(' ') << std::setw(100) << "/\n";
    std::cout << "/" << std::setfill(' ') << std::setw(55)
              << " 1. TRAVEL: " << std::setw(45) << "/\n";
    std::cout << "/" << std::setfill(' ') << std::setw(60)
              << " 2. PRINT CARGO: " << std::setw(40) << "/\n";
    std::cout << "/" << std::setfill(' ') << std::setw(52)
              << " 3. BUY: " << std::setw(48) << "/\n";
    std::cout << "/" << std::setfill(' ') << std::setw(53)
              << " 4. SELL: " << std::setw(47) << "/\n";
    std::cout << "/" << std::setfill(' ') << std::setw(53)
              << " 5. EXIT: " << std::setw(47) << "/\n";
    std::cout << "/" << std::setfill('-') << std::setw(100) << "/\n";
}

void Game::printHeader()
{
    std::cout << "/" << std::setfill('-') << std::setw(100) << "/\n";
    std::cout << "/" << std::setfill(' ') << std::setw(100) << "/\n";
    std::cout << "/" << std::setfill(' ') << std::setw(62)
              << "Welcom to the game SHM" << std::setw(38) << "/\n";
    std::cout << "/" << std::setfill(' ') << std::setw(100) << "/\n";
    std::cout << "/" << std::setfill(' ') << std::setw(55)
              << "YOUR MONEY: " << std::setw(4) << money_ << std::setw(41)
              << "/\n";
    std::cout << "/" << std::setfill(' ') << std::setw(54)
              << "YOUR GOAL: " << std::setw(5) << finalGoal_ << std::setw(41)
              << "/\n";
    std::cout << "/" << std::setfill(' ') << std::setw(54)
              << "TIME LEFT: " << std::setw(5) << gameDayes_ << std::setw(41)
              << "/\n";
    std::cout << "/" << std::setfill(' ') << std::setw(100) << "/\n";
    std::cout << "/" << std::setfill('-') << std::setw(100) << "/\n";
}

void Game::printWinScreen()
{
    std::cout << "/" << std::setfill('-') << std::setw(100) << "/\n";
    std::cout << "/" << std::setfill(' ') << std::setw(100) << "/\n";
    std::cout << "/" << std::setfill(' ') << std::setw(60) << "CONGRATULATION!!!!"
              << std::setw(40) << "/\n";
    std::cout << "/" << std::setfill(' ') << std::setw(100) << "/\n";
    std::cout << "/" << std::setfill(' ') << std::setw(55) << "YOU WIN!!"
              << std::setw(45) << "/\n";
    std::cout << "/" << std::setfill(' ') << std::setw(100) << "/\n";
    std::cout << "/" << std::setfill('-') << std::setw(100) << "/\n";
}

void Game::printLoseScreen()
{
    std::cout << "/" << std::setfill('-') << std::setw(100) << "/\n";
    std::cout << "/" << std::setfill(' ') << std::setw(100) << "/\n";
    std::cout << "/" << std::setfill(' ') << std::setw(60) << "YOU HAVE LOST!!!!"
              << std::setw(40) << "/\n";
    std::cout << "/" << std::setfill(' ') << std::setw(100) << "/\n";
    std::cout << "/" << std::setfill(' ') << std::setw(55) << "SORRY!!!"
              << std::setw(45) << "/\n";
    std::cout << "/" << std::setfill(' ') << std::setw(100) << "/\n";
    std::cout << "/" << std::setfill('-') << std::setw(100) << "/\n";
}

bool Game::checkWinCondition()
{
    // if (player_->getMoney() >= finalGoal_) {
    //     return true;
    // }
    return false;
}

bool Game::checkLoseCondition()
{
    return money_ = 0 || (gameDayes_ >= 0 && money_ < finalGoal_);
}

void Game::chooseOption(MenuOption option)
{
    switch (option) {
    case MenuOption::Travel:
        travel();
        break;
    case MenuOption::PrintCargo:
        printCargo();
        break;
    case MenuOption::Buy:
        buy();
        break;
    case MenuOption::Sell:
        sell();
        break;
    case MenuOption::Exit:
        exit();
        break;
    default:
        std::cout << "Try again\n";
        break;
    }
}

void Game::exit()
{
    std::exit(0);
}

void Game::sell()
{
    // Space for a code
}

void Game::printMap(std::shared_ptr<Map> map)
{
    // Space for a code.
}

void Game::travel()
{
    // std::cout << "Travel\n";
    // map_->printCurrentPosition();
    // std::cout << "Choose island [x, y]: ";
    // size_t x, y;
    // std::cin >> x >> y;
    // while (std::cin.fail()) {
    //     std::cin.clear();
    //     std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    //     std::cout << "Wrong data type. Enter two digits: ";
    //     std::cin >> x >> y;
    // }

    // // auto coordinates = Coordinates(x, y);

    // // std::cout << coordinates.getPositionX() << '\n';
    // // std::cout << coordinates.getPositionY() << '\n';
    // // auto destination = map_->getIsland(coordinates);

    // // std::cout << "What the fuck is destination coordinates: " <<
    // destination.get()->getPosition().getPositionX();

    // // if (destination != nullptr) {
    // //     for (auto i = map_->getDistanceToIsland(destination); i > 0; i--) {
    // //         (*time_)++;
    // //         // if (time_->getTimeElapsed() == 0) {
    // //         //     break;
    // //         // }
    // //     }
    // //     // map_->travel(destination);
    // // } else {
    // //     std::cout << "Wrong coordinates!" << '\n';
    // }
}

void Game::buy()
{
    std::cout << "Buy\n";

    // Spcae for  a code.
    // auto actualIslandStore = map_->getIsland(1);
    // std::cout << &actualIslandStore << '\n';
    // size_t cargoNr, amountNr;
    // std::cout << "Write cargo number: ";
    // std::cin >> cargoNr;
    // std::cout << "Write amount: ";
    // std::cin >> amountNr;

    // while(std::cin.fail() || cargoNr < 0 || cargoNr >> 5 /* wielkość wektora
    // ilosći zakupów w Store*/) {
    //     std::cin.clear();
    //     std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    //     std::cout << " Wrong data. First digit from 0 to " <<  12/* wektor
    //     size*/ << ": "; std::cin >> cargoNr;
    // }
    // cargoNr--;

    // Response
}

void Game::printCargo()
{
    std::cout << "Chuj, dupa i kamienia kupa\n";
    player_->printCargo();
}

void Game::setPlayer()
{
    std::cout << "Set ship name!";
    std::string shipName;
    std::cin >> shipName;
    ship_->setName(shipName);
}
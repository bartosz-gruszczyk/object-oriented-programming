#include <random>
#include "map.hpp"
#include "island.hpp"

Map::Map() {
    // std::random_device rd;
    // std::mt19937 gen(rd());
    // std::uniform_int_distribution<> widthDistribution(0, maxWidth_);
    // std::uniform_int_distribution<> heightDistribution(0, maxHeight_);

    randomGenerator_(randomDevice_());
    islands_.reserve(10);
    for (int i = 0; i < islandsQuantity_; ++i) {
        Island tempIsland(widthDistribution_(randomGenerator_), heightDistribution(gen));
        islands_.push_back(tempIsland);
    }
}

Island* const Map::getPosition() {
   return currentPostion_;
}

Island* Map::getIsland(const Island::Coordinates& coordinate) {
    return std::find(islands_.begin(), islands_.end(), coordinate);
}
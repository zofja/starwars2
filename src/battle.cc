#include <algorithm>
#include <array>
#include <iostream>
#include "battle.h"


SpaceBattle::Builder::Builder() = default;

SpaceBattle::Builder &SpaceBattle::Builder::ship(Ship *s) {

    auto *imperial = dynamic_cast<ImperialStarship *>(s);
    if (imperial) {
        imperials.emplace_back(imperial);
    } else {
        auto *rebel = dynamic_cast<RebelStarship *>(s);
        if (rebel) {
            rebels.emplace_back(rebel);
        }
    }
    return *this;
}

SpaceBattle::Builder &SpaceBattle::Builder::ship(Squadron *s) {
    imperials.insert(imperials.end(), s->getShips().begin(), s->getShips().end());
    return *this;
}

SpaceBattle::Builder &SpaceBattle::Builder::startTime(Time t) {
    t0 = t;
    return *this;
}

SpaceBattle::Builder &SpaceBattle::Builder::maxTime(Time t) {
    t1 = t;
    for (int i = 0; i <= t1; i++) {
        if (i % 5 != 0 and (i % 2 == 0 or i % 3 == 0)) {
            intergalacticTime.emplace_back(i);
        }
    }
    return *this;
}

SpaceBattle SpaceBattle::Builder::build() {
    return SpaceBattle(imperials, rebels, t0, t1, intergalacticTime);
}


SpaceBattle::SpaceBattle(std::vector<ImperialStarship *> imperials, std::vector<RebelStarship *> rebels, Time t0,
                         Time t1, std::vector<Time> igTime) : imperials(std::move(imperials)),
                                                              rebels(std::move(rebels)), time(t0), t1(t1),
                                                              intergalacticTime(std::move(igTime)) {
    this->imperialFleet = this->imperials.size();
    this->rebelFleet = this->rebels.size();
}

size_t SpaceBattle::countImperialFleet() {
    return imperialFleet;
}

size_t SpaceBattle::countRebelFleet() {
    return rebelFleet;
}

void SpaceBattle::tick(Time timeStep) {

    if (countImperialFleet() == 0 && countRebelFleet() == 0) {
        std::cout << "DRAW\n";
    } else if (countRebelFleet() == 0) {
        std::cout << "IMPERIUM WON\n";
    } else if (countImperialFleet() == 0) {
        std::cout << "REBELLION WON\n";
    } else {
        if (std::binary_search(intergalacticTime.begin(), intergalacticTime.end(), time)) {
            imperialAttack();
        }
    }

    time = (time + timeStep) % (t1 + 1);

}

void SpaceBattle::imperialAttack() {
    for (auto &imperial : imperials) {
        for (auto &rebel : rebels) {
            if (!imperial->isDestroyed() && !rebel->isDestroyed()) {
                imperial->attackRebelShip(rebel);
                if (imperial->isDestroyed()) imperialFleet--;
                if (rebel->isDestroyed()) rebelFleet--;
            }
        }
    }
}
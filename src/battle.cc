#include <utility>
#include <algorithm>
#include <array>
#include <iostream>
#include "battle.h"

SpaceBattle::Builder::Builder() = default;

SpaceBattle::Builder &SpaceBattle::Builder::ship(const std::shared_ptr<ImperialUnit> &imperial) {
    imperials.emplace_back(imperial);
    return *this;
}

SpaceBattle::Builder &SpaceBattle::Builder::ship(const std::shared_ptr<RebelStarship> &rebel) {
    rebels.emplace_back(rebel);
    return *this;
}

SpaceBattle::Builder &SpaceBattle::Builder::startTime(Time t) {
    t0 = t;
    return *this;
}

SpaceBattle::Builder &SpaceBattle::Builder::maxTime(Time t) {
    t1 = t;
    return *this;
}

SpaceBattle::SpaceBattle(std::vector<std::shared_ptr<ImperialUnit>> imperials,
                         std::vector<std::shared_ptr<RebelStarship>> rebels, Time t0, Time t1) : imperials(std::move(imperials)),
                                                                                                 rebels(std::move(rebels)),
                                                                                                 timeStrategy(std::make_shared<OurTimeStrategy>(t0, t1)),
                                                                                                 attackStrategy(std::make_shared<OurAttackStrategy>()) {}

SpaceBattle SpaceBattle::Builder::build() {
    return SpaceBattle(imperials, rebels, t0, t1);
}

size_t SpaceBattle::countImperialFleet() {
    size_t size = 0;
    for (auto &ship : imperials) {
        size += ship->getAliveCount();
    }
    return size;
}

size_t SpaceBattle::countRebelFleet() {
    size_t size= 0;
    for (auto &ship : rebels) {
        size += ship->getAliveCount();
    }
    return size;
}

void SpaceBattle::tick(Time timeStep) {

    if (countImperialFleet() == 0 && countRebelFleet() == 0) {
        std::cout << "DRAW\n";
    } else if (countRebelFleet() == 0) {
        std::cout << "IMPERIUM WON\n";
    } else if (countImperialFleet() == 0) {
        std::cout << "REBELLION WON\n";
    } else {
        if (timeStrategy->moveTime(timeStep)) {
            attackStrategy->imperialAttack(this->imperials, this->rebels);
        }
    }
}

void attack(std::shared_ptr<ImperialUnit> &imperial, std::shared_ptr<RebelStarship> &rebel) {

    rebel->takeDamage(imperial->getAttackPower());
    rebel->causeDamage(imperial);
}

OurTimeStrategy::OurTimeStrategy(Time startTime, Time maxTime) : time(startTime), maxTime(maxTime) {}

bool OurTimeStrategy::moveTime(Time timeStep) {

    bool isTimeToAttack = (this->time % 2 == 0 || this->time % 3 == 0) && this->time % 5 != 0;
    time = (time + timeStep) % (maxTime + 1);
    return isTimeToAttack;
}

void OurAttackStrategy::imperialAttack(std::vector<std::shared_ptr<ImperialUnit>> &imperials,
                                       std::vector<std::shared_ptr<RebelStarship>> &rebels) {

    for (auto &imperial : imperials) {
        for (auto &rebel : rebels) {
            if (!imperial->isDestroyed() && !rebel->isDestroyed()) {
                attack(imperial, rebel);
            }
        }
    }
}

OurAttackStrategy::OurAttackStrategy() = default;

#include <utility>

#include <utility>

#include <algorithm>
#include <array>
#include <iostream>
#include "battle.h"

SpaceBattle::Builder::Builder() = default;

SpaceBattle::Builder &SpaceBattle::Builder::ship(std::shared_ptr<ImperialUnit> imperial) {
    imperials.emplace_back(imperial);
    return *this;
}

SpaceBattle::Builder &SpaceBattle::Builder::ship(std::shared_ptr<RebelStarship> rebel) {
    rebels.emplace_back(rebel);
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

SpaceBattle::SpaceBattle(std::vector<std::shared_ptr<ImperialUnit>> imperials,
                         std::vector<std::shared_ptr<RebelStarship>> rebels, Time t0, Time t1,
                         std::vector<Time> igTime) : imperials(std::move(imperials)),
                                                     rebels(std::move(rebels)),
                                                     time(t0),
                                                     t1(t1),
                                                     intergalacticTime(std::move(igTime)) {

    std::cout << "intergalactic time: ";
    for (auto i : this->intergalacticTime) {
        std::cout << i << " ";
    }
    std::cout << "\n";


    std::cout << "imperials to battle\n";
    for (auto &imperial : this->imperials) {
        std::cout << imperial->getAliveCount() << "\n";
        this->imperialFleet += imperial->getAliveCount();
    }
    this->rebelFleet = this->rebels.size();
    std::cout << "\n";
    std::cout << this->imperialFleet << " " << this->rebelFleet << "\n";

}

SpaceBattle SpaceBattle::Builder::build() {
    return SpaceBattle(imperials, rebels, t0, t1, intergalacticTime);
}


size_t SpaceBattle::countImperialFleet() {
    return imperialFleet;
}

size_t SpaceBattle::countRebelFleet() {
    return rebelFleet;
}

void SpaceBattle::tick(Time timeStep) {

    std::cout << "tick\n";
    std::cout << countImperialFleet() << " " << countRebelFleet() << "\n";
    if (countImperialFleet() == 0 && countRebelFleet() == 0) {
        std::cout << "DRAW\n";
    } else if (countRebelFleet() == 0) {
        std::cout << "IMPERIUM WON\n";
    } else if (countImperialFleet() == 0) {
        std::cout << "REBELLION WON\n";
    } else {
        if (std::binary_search(intergalacticTime.begin(), intergalacticTime.end(), time)) {
            std::cout << "imperial attack\n";
            imperialAttack();
        }
    }

    time = (time + timeStep) % (t1 + 1);

}

void SpaceBattle::imperialAttack() {

    for (auto &imperial : imperials) {
        for (auto &rebel : rebels) {
            if (!imperial->isDestroyed() && !rebel->isDestroyed()) {
                auto aliveImperials = imperial->getAliveCount();
                std::cout << "alive imperials before attack\n" << aliveImperials << " " << imperial->getShield() << "\n";
                attack(imperial, rebel);
                imperialFleet -= (aliveImperials - imperial->getAliveCount());
                std::cout << "alive after\n" << imperialFleet << " " << imperial->getShield() << "\n";
                if (rebel->isDestroyed()) rebelFleet--;
            }
        }
    }
}

void attack(std::shared_ptr<ImperialUnit> imperial, std::shared_ptr<RebelStarship> rebel) {

    std::cout << "attack\n";
    rebel->takeDamage(imperial.get()->getAttackPower());
    std::cout << imperial->getShield() << "\n";
    rebel.get()->causeDamage(imperial);
    std::cout << imperial->getShield() << "\n";
    std::cout << "after attack\n";
}

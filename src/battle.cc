#include <utility>

#include <utility>

#include <algorithm>
#include <array>
#include <iostream>
#include "battle.h"

void attack(const std::shared_ptr<Ship> &imperial, const std::shared_ptr<Ship> &rebel) {
    std::cout << "attack\n";
    rebel->takeDamage(dynamic_cast<ImperialUnit*>(imperial.get())->getAttackPower());
    dynamic_cast<RebelStarship*>(rebel.get())->causeDamage(imperial);
}

SpaceBattle::Builder::Builder() = default;

SpaceBattle::Builder &SpaceBattle::Builder::ship(std::shared_ptr<Ship> s) {

    ships.emplace_back(s);
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
    return SpaceBattle(ships, t0, t1, intergalacticTime);
}


SpaceBattle::SpaceBattle(std::vector<std::shared_ptr<Ship>> ships, Time t0,
                         Time t1, std::vector<Time> igTime) : ships(std::move(ships)),
                                                              time(t0), t1(t1),
                                                              intergalacticTime(std::move(igTime)) {

    std::cout << "intergalactic time: ";
    for (auto i : this->intergalacticTime) {
        std::cout << i << " ";
    }
    std::cout << "\n";
    std::cout << "space battle ctor\n";
    for (auto &s : this->ships) {
        std::cout << s->getShield() << "\n";
        if (s->isImperial()) {
            this->imperialFleet++;
        } else {
            this->rebelFleet++;
        }
    }
    std::cout << this->imperialFleet << " " << this->rebelFleet << "\n";
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

    for (auto &imperial : ships) {
        if (imperial->isImperial()) {
            for (auto &rebel : ships) {
                if (!rebel->isImperial()) {
                    if (!imperial->isDestroyed() && !rebel->isDestroyed()) {
                        attack(imperial, rebel);
                        if (imperial->isDestroyed()) imperialFleet--;
                        if (rebel->isDestroyed()) rebelFleet--;
                    }
                }
            }
        }
    }
}

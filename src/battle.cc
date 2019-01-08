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
                         std::vector<std::shared_ptr<RebelStarship>> rebels, Time t0, Time t1) : imperials(std::move(imperials)),
                                                     rebels(std::move(rebels)),
                                                     timeStrategy(std::make_shared<OurTimeStrategy>(t0, t1)),
                                                     attackStrategy(std::make_shared<OurAttackStrategy>()){

//    std::cout << "intergalactic time: ";
//    for (auto i : this->intergalacticTime) {
//        std::cout << i << " ";
//    }
//    std::cout << "\n";


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
    return SpaceBattle(imperials, rebels, t0, t1);
}


size_t SpaceBattle::countImperialFleet() {
    return imperialFleet;
}

size_t SpaceBattle::countRebelFleet() {
    return rebelFleet;
}

void SpaceBattle::tick(Time timeStep) {

    std::cout << "moveTime\n";
    std::cout << countImperialFleet() << " " << countRebelFleet() << "\n";
    if (countImperialFleet() == 0 && countRebelFleet() == 0) {
        std::cout << "DRAW\n";
    } else if (countRebelFleet() == 0) {
        std::cout << "IMPERIUM WON\n";
    } else if (countImperialFleet() == 0) {
        std::cout << "REBELLION WON\n";
    } else {
        if (timeStrategy.get()->moveTime(timeStep)) {
            std::cout << "imperial attack\n";
            std::pair<int, int> destroyed = attackStrategy.get()->imperialAttack(this->imperials, this->rebels);
            this->imperialFleet -= destroyed.first;
            this->rebelFleet -= destroyed.second;
        }
    }

}

//void SpaceBattle::imperialAttack() {
//
//    for (auto &imperial : imperials) {
//        for (auto &rebel : rebels) {
//            if (!imperial->isDestroyed() && !rebel->isDestroyed()) {
//                auto aliveImperials = imperial->getAliveCount();
//                std::cout << "alive imperials before attack\n" << aliveImperials << " " << imperial->getShield() << "\n";
//                attack(imperial, rebel);
//                imperialFleet -= (aliveImperials - imperial->getAliveCount());
//                std::cout << "alive after\n" << imperialFleet << " " << imperial->getShield() << "\n";
//                if (rebel->isDestroyed()) rebelFleet--;
//            }
//        }
//    }
//}

void attack(std::shared_ptr<ImperialUnit> imperial, std::shared_ptr<RebelStarship> rebel) {

    std::cout << "attack\n";
    rebel->takeDamage(imperial.get()->getAttackPower());
    std::cout << imperial->getShield() << "\n";
    rebel.get()->causeDamage(imperial);
    std::cout << imperial->getShield() << "\n";
    std::cout << "after attack\n";
}

OurTimeStrategy::OurTimeStrategy(Time startTime, Time maxTime) : time(startTime), maxTime(maxTime) {}

bool OurTimeStrategy::moveTime(Time timeStep) {

    bool isTimeToAttack = (this->time % 2 == 0 || this->time % 3 == 0) && this->time % 5 != 0;
    time = (time + timeStep) % (maxTime + 1);
    return isTimeToAttack;
}

std::pair<int, int> OurAttackStrategy::imperialAttack(std::vector<std::shared_ptr<ImperialUnit>> imperials, std::vector<std::shared_ptr<RebelStarship>> rebels) {

    int imperialsDestroyed = 0;
    int rebelsDestroyed = 0;

    for (auto &imperial : imperials) {
        for (auto &rebel : rebels) {
            if (!imperial->isDestroyed() && !rebel->isDestroyed()) {
                auto aliveImperials = imperial->getAliveCount();
                attack(imperial, rebel);
                imperialsDestroyed += (aliveImperials - imperial->getAliveCount());
                if (rebel->isDestroyed()) rebelsDestroyed++;
            }
        }
    }

    return std::make_pair(imperialsDestroyed, rebelsDestroyed);
}

OurAttackStrategy::OurAttackStrategy() = default;

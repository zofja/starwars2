#include <utility>


#include <algorithm>
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
    return *this;
}

SpaceBattle SpaceBattle::Builder::build() {
    return SpaceBattle(imperials, rebels, t0, t1);
}

SpaceBattle::SpaceBattle(std::vector<ImperialStarship *> imperials, std::vector<RebelStarship *> rebels, Time t0,
                         Time t1) : imperials(std::move(imperials)), rebels(std::move(rebels)), t0(t0), t1(t1) {}

size_t SpaceBattle::countImperialFleet() {

    return imperials.size();
}

size_t SpaceBattle::countRebelFleet() {
    return rebels.size();
}

void SpaceBattle::tick(Time timeStep) {

}

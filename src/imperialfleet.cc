#include <algorithm>
#include <numeric>
#include "imperialfleet.h"

void ImperialStarship::attackRebelShip(RebelStarship *attackedShip) {

    auto armedThis = dynamic_cast<ArmedShip *>(this);
    attackedShip->takeDamage(armedThis->getAttackPower());

    if (attackedShip->isArmed()) {
        armedThis->takeDamage(dynamic_cast<ArmedRebelStarship *>(attackedShip)->getAttackPower());
    }
}

ImperialStarship::ImperialStarship(ShieldPoints shield, AttackPower attack) : BasicShip(shield),
                                                                              ArmedShip(shield, attack),
                                                                              ImperialUnit(shield, attack) {}

bool ImperialStarship::isDestroyed() {
    // TODO
    return dynamic_cast<BasicShip*>(this)->getShield() == 0;
}

DeathStar::DeathStar(ShieldPoints shield, AttackPower attack) : ImperialStarship(shield, attack) {}

ImperialDestroyer::ImperialDestroyer(ShieldPoints shield, AttackPower attack) : ImperialStarship(shield, attack) {}

TIEFighter::TIEFighter(ShieldPoints shield, AttackPower attack) : ImperialStarship(shield, attack) {}

// TODO
DeathStar *createDeathStar(ShieldPoints shield, AttackPower attack) {
    return new DeathStar(shield, attack);
}

ImperialDestroyer *createImperialDestroyer(ShieldPoints shield, AttackPower attack) {
    return new ImperialDestroyer(shield, attack);
}

TIEFighter *createTIEFighter(ShieldPoints shield, AttackPower attack) {
    return new TIEFighter(shield, attack);
}

Squadron *createSquadron(std::initializer_list<ImperialUnit *> ships) {
    return new Squadron(ships);
}

// TODO jak wywołać konstruktor ImperialUnit ???
Squadron::Squadron(std::initializer_list<ImperialUnit *> ships) : ships(ships) {}

Squadron::Squadron(std::vector<ImperialUnit *> ships) {}

ShieldPoints Squadron::getShield() {
    return std::accumulate(ships.begin(), ships.end(), 0, [](ShieldPoints sum, ImperialUnit *s) {
        return sum += !s->isDestroyed() ? s->getShield() : 0;
    });
}

AttackPower Squadron::getAttackPower() {
    return std::accumulate(ships.begin(), ships.end(), 0, [](AttackPower sum, ImperialUnit *s) {
        return sum += !s->isDestroyed() ? s->getAttackPower() : 0;
    });
}

std::vector<ImperialUnit *> &Squadron::getShips() {
    return this->ships;
}

void Squadron::takeDamage(AttackPower damage) {
    for (auto s : ships) {
        s->takeDamage(damage);
    }
}

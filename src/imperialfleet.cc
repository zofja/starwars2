#include <algorithm>
#include <numeric>
#include "imperialfleet.h"

AttackPower ImperialStarship::getAttackPower() {
    return this->attack;
}

bool ImperialStarship::isImperial() {
    return true;
}

void ImperialStarship::attackRebelShip(RebelStarship *attackedShip) {

    attackedShip->takeDamage(this->getAttackPower());

    if (attackedShip->isArmed())
        this->takeDamage(dynamic_cast<ArmedRebelStarship*>(attackedShip)->getAttackPower());
}

ImperialStarship::ImperialStarship(ShieldPoints shield, AttackPower attack) : Ship(shield), attack(attack) {}

DeathStar::DeathStar(ShieldPoints shield, AttackPower attack) : ImperialStarship(shield, attack) {}

ImperialDestroyer::ImperialDestroyer(ShieldPoints shield, AttackPower attack) : ImperialStarship(shield, attack) {}

TIEFighter::TIEFighter(ShieldPoints shield, AttackPower attack) : ImperialStarship(shield, attack) {}

DeathStar *createDeathStar(ShieldPoints shield, AttackPower attack) {
    return new DeathStar(shield, attack);
}

ImperialDestroyer *createImperialDestroyer(ShieldPoints shield, AttackPower attack) {
    return new ImperialDestroyer(shield, attack);
}

TIEFighter *createTIEFighter(ShieldPoints shield, AttackPower attack) {
    return new TIEFighter(shield, attack);
}

Squadron *createSquadron(std::initializer_list<ImperialStarship*> ships) {
    return new Squadron(ships);
}

Squadron::Squadron(std::initializer_list<ImperialStarship*> ships) : ships(ships) {}

ShieldPoints Squadron::getShield() {
    return std::accumulate(ships.begin(), ships.end(), 0, [](ShieldPoints sum, ImperialStarship *s) {
        return sum += !s->isDestroyed() ? s->getShield() : 0;
    });
}

AttackPower Squadron::getAttackPower() {
    return std::accumulate(ships.begin(), ships.end(), 0, [](AttackPower sum, ImperialStarship *s) {
        return sum += !s->isDestroyed() ? s->getAttackPower() : 0;
    });
}

std::vector<ImperialStarship*> &Squadron::getShips() {
    return this->ships;
}

void Squadron::takeDamage(AttackPower damage) {
    for (auto s : ships) {
        s->takeDamage(damage);
    }
}
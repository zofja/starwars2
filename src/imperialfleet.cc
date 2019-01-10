#include <algorithm>
#include <numeric>
#include "imperialfleet.h"

ImperialStarship::ImperialStarship(ShieldPoints shield, AttackPower attack) : Ship(shield),
                                                                              ArmedShipUnit(shield, attack),
                                                                              BasicShip(shield),
                                                                              ArmedShip(shield, attack),
                                                                              ImperialUnit(shield, attack) {}

DeathStar::DeathStar(ShieldPoints shield, AttackPower attack) : Ship(shield),
                                                                ArmedShipUnit(shield, attack),
                                                                ImperialStarship(shield, attack) {}

ImperialDestroyer::ImperialDestroyer(ShieldPoints shield, AttackPower attack) : Ship(shield),
                                                                                ArmedShipUnit(shield, attack),
                                                                                ImperialStarship(shield, attack) {}

TIEFighter::TIEFighter(ShieldPoints shield, AttackPower attack) : Ship(shield),
                                                                  ArmedShipUnit(shield, attack),
                                                                  ImperialStarship(shield, attack) {}


Squadron::Squadron(std::initializer_list<std::shared_ptr<ImperialUnit>> ships) : Squadron(
        std::vector<std::shared_ptr<ImperialUnit>>(ships.begin(), ships.end())) {}

Squadron::Squadron(std::vector<std::shared_ptr<ImperialUnit>> ships) : Ship(0),
                                                                       ArmedShipUnit(0, 0),
                                                                       ImperialUnit(0, 0),
                                                                       ships(std::move(ships)) {
    ShieldPoints shieldSum = 0;
    AttackPower attackPowerSum = 0;
    for (auto &ship : this->ships) {
        shieldSum += ship->getShield();
        attackPowerSum += ship->getAttackPower();
    }
    this->shield = shieldSum;
    this->attack = attackPowerSum;
    this->aliveCount = this->ships.size();


}

ShieldPoints Squadron::getShield() {
    return this->shield;
}

AttackPower Squadron::getAttackPower() {
    return attack;
}

void Squadron::takeDamage(AttackPower damage) {
    for (auto &s : ships) {

        if (!s->isDestroyed()) {
            auto shield = s->getShield();
            auto attack = s->getAttackPower();
            auto aliveCount = s->getAliveCount();

            s->takeDamage(damage);

            this->shield -= (shield - s->getShield());
            this->aliveCount -= (aliveCount - s->getAliveCount());
            this->attack -= (attack - s->getAttackPower());
        }
    }
}

std::shared_ptr<ImperialUnit> createDeathStar(ShieldPoints shield, AttackPower attack) {
    return std::make_shared<DeathStar>(shield, attack);
}

std::shared_ptr<ImperialUnit> createImperialDestroyer(ShieldPoints shield, AttackPower attack) {
    return std::make_shared<ImperialDestroyer>(shield, attack);
}

std::shared_ptr<ImperialUnit> createTIEFighter(ShieldPoints shield, AttackPower attack) {
    return std::make_shared<TIEFighter>(shield, attack);
}

std::shared_ptr<Squadron> createSquadron(std::initializer_list<std::shared_ptr<ImperialUnit>> ships) {
    return std::make_shared<Squadron>(ships);
}

std::shared_ptr<Squadron> createSquadron(std::vector<std::shared_ptr<ImperialUnit>> ships) {
    return std::make_shared<Squadron>(ships);
}
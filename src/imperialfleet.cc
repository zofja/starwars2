#include <algorithm>
#include <numeric>
#include "imperialfleet.h"

ImperialStarship::ImperialStarship(ShieldPoints shield, AttackPower attack) : Ship(shield),
                                                                              ArmedShipUnit(shield, attack),
                                                                              BasicShip(shield),
                                                                              ArmedShip(shield, attack),
                                                                              ImperialUnit(shield, attack) {}

bool ImperialStarship::isDestroyed() {
    return dynamic_cast<BasicShip *>(this)->getShield() == 0;
}

DeathStar::DeathStar(ShieldPoints shield, AttackPower attack) : Ship(shield), ArmedShipUnit(shield, attack),
                                                                ImperialStarship(shield, attack) {}

ImperialDestroyer::ImperialDestroyer(ShieldPoints shield, AttackPower attack) : Ship(shield),
                                                                                ArmedShipUnit(shield, attack),
                                                                                ImperialStarship(shield, attack) {}

TIEFighter::TIEFighter(ShieldPoints shield, AttackPower attack) : Ship(shield), ArmedShipUnit(shield, attack),
                                                                  ImperialStarship(shield, attack) {}

/*
Squadron::Squadron(std::initializer_list<ImperialUnit> ships) : ImperialUnit(), ships(ships) {}

Squadron::Squadron(std::vector<ImperialUnit> ships) {}

ShieldPoints Squadron::getShield() {
    return std::accumulate(ships.begin(), ships.end(), 0, [](ShieldPoints sum, ImperialUnit &s) {
        return sum += !s.isDestroyed() ? s.getShield() : 0;
    });
}

AttackPower Squadron::getAttackPower() {
    return std::accumulate(ships.begin(), ships.end(), 0, [](AttackPower sum, ImperialUnit &s) {
        return sum += !s.isDestroyed() ? s.getAttackPower() : 0;
    });
}

std::vector<ImperialUnit> &Squadron::getShips() {
    return this->ships;
}

void Squadron::takeDamage(AttackPower damage) {
    for (auto &s : ships) {
        s.takeDamage(damage);
    }
}
 */

std::shared_ptr<DeathStar> createDeathStar(ShieldPoints shield, AttackPower attack) {
    return std::make_shared<DeathStar>(shield, attack);
}

std::shared_ptr<ImperialDestroyer> createImperialDestroyer(ShieldPoints shield, AttackPower attack) {
    return std::make_shared<ImperialDestroyer>(shield, attack);
}

std::shared_ptr<TIEFighter> createTIEFighter(ShieldPoints shield, AttackPower attack) {
    return std::make_shared<TIEFighter>(shield, attack);
}

/*
std::shared_ptr<Squadron> createSquadron(std::initializer_list<ImperialUnit> ships) {
    return std::make_shared<Squadron>(ships);
}

std::shared_ptr<Squadron> createSquadron(std::vector<ImperialUnit> ships) {
    return std::make_shared<Squadron>(ships);
}
*/

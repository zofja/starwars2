#include <cassert>

#include "rebelfleet.h"


Speed RebelStarship::getSpeed() {
    return this->speed;
}

RebelStarship::RebelStarship(ShieldPoints shield, Speed speed) : BasicShip(shield), speed(speed) {}

// TODO no głupie to przyznaję
void RebelStarship::causeDamage(const std::shared_ptr<Ship> &imperial) {
    imperial->takeDamage(0);
}

ArmedRebelStarship::ArmedRebelStarship(ShieldPoints shield, Speed speed, AttackPower attack) : Ship(shield),
                                                                                               ArmedShipUnit(shield, attack),
                                                                                               RebelStarship(shield, speed),
                                                                                               ArmedShip(shield, attack) {}

bool ArmedRebelStarship::isArmed() {
    return true;
}

void ArmedRebelStarship::causeDamage(const std::shared_ptr<Ship> &imperial) {
    imperial->takeDamage(this->getAttackPower());
}

Explorer::Explorer(ShieldPoints shield, Speed speed) : Ship(shield), RebelStarship(shield, speed) {
    assert(299796 <= speed && speed <= 2997960);
}

bool Explorer::isArmed() {
    return false;
}

StarCruiser::StarCruiser(ShieldPoints shield, Speed speed, AttackPower attack) : Ship(shield),
                                                                                 ArmedShipUnit(shield, attack),
                                                                                 ArmedRebelStarship(shield, speed, attack) {
    assert(99999 <= speed && speed <= 299795);
}

XWing::XWing(ShieldPoints shield, Speed speed, AttackPower attack) : Ship(shield),
                                                                     ArmedShipUnit(shield, attack),
                                                                     ArmedRebelStarship(shield, speed, attack) {
    assert(299796 <= speed && speed <= 2997960);
}

std::shared_ptr<RebelStarship> createExplorer(ShieldPoints shield, Speed speed) {
    return std::make_shared<Explorer>(shield, speed);
}

std::shared_ptr<RebelStarship> createStarCruiser(ShieldPoints shield, Speed speed, AttackPower attack) {
    return std::make_shared<StarCruiser>(shield, speed, attack);
}

std::shared_ptr<RebelStarship> createXWing(ShieldPoints shield, Speed speed, AttackPower attack) {
    return std::make_shared<XWing>(shield, speed, attack);
}

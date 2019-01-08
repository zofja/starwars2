#include "helper.h"

Ship::Ship(ShieldPoints shield) : shield(shield) {}


void BasicShip::takeDamage(AttackPower damage) {
    this->shield = damage > this->shield ? 0 : this->shield - damage;
    this->aliveCount = (this->shield == 0) ? 0 : 1;
}

ShieldPoints BasicShip::getShield() {
    return this->shield;
}

BasicShip::BasicShip(ShieldPoints shield) : Ship(shield) {}

//bool BasicShip::isDestroyed() {
//    return this->getShield() == 0;
//}

AttackPower ArmedShip::getAttackPower() {
    return (this->isDestroyed()) ? 0 : this->attack;
}

ArmedShipUnit::ArmedShipUnit(ShieldPoints shield, AttackPower attack) : Ship(shield), attack(attack) {}

ArmedShip::ArmedShip(ShieldPoints shield, AttackPower attack) : ArmedShipUnit(shield, attack) {}

ImperialUnit::ImperialUnit(ShieldPoints shield, AttackPower attack) : ArmedShipUnit(shield, attack) {}

bool ImperialUnit::isImperial() {
    return true;
}

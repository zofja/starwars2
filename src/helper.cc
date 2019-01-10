#include "helper.h"

Ship::Ship(ShieldPoints shield) : shield(shield) {}

bool Ship::isDestroyed() {
    return this->shield == 0;
}

size_t Ship::getAliveCount() {
    return this->aliveCount;
}

void BasicShip::takeDamage(AttackPower damage) {
    this->shield = damage > this->shield ? 0 : this->shield - damage;
    this->aliveCount = (this->shield == 0) ? 0 : 1;
}

ShieldPoints BasicShip::getShield() {
    return this->shield;
}

BasicShip::BasicShip(ShieldPoints shield) : Ship(shield) {}

AttackPower ArmedShip::getAttackPower() {
    return (this->isDestroyed()) ? 0 : this->attack;
}

ArmedShipUnit::ArmedShipUnit(ShieldPoints shield, AttackPower attack) : Ship(shield), attack(attack) {}

ArmedShip::ArmedShip(ShieldPoints shield, AttackPower attack) : ArmedShipUnit(shield, attack) {}

ImperialUnit::ImperialUnit(ShieldPoints shield, AttackPower attack) : ArmedShipUnit(shield, attack) {}

#include "helper.h"

void BasicShip::takeDamage(AttackPower damage) {
    this->shield = damage > this->shield ? 0 : this->shield - damage;
}

ShieldPoints BasicShip::getShield() {
    return this->shield;
}

size_t BasicShip::getAliveCount() {
    return this->shield == 0 ? 0 : 1;
}

BasicShip::BasicShip(ShieldPoints shield) : shield(shield) {}

AttackPower ArmedShip::getAttackPower() {
    return (this->getAliveCount() == 0) ? 0 : this->attack;
}

ArmedShip::ArmedShip(AttackPower attack) : attack(attack) {}
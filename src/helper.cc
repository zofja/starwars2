#include "helper.h"

BasicShip::BasicShip(ShieldPoints shield) : shield(shield) {}

ShieldPoints BasicShip::getShield() {
    return this->shield;
}

void BasicShip::takeDamage(AttackPower damage) {
    this->shield = damage > this->shield ? 0 : this->shield - damage;
}

size_t BasicShip::getAliveCount() {
    return this->shield == 0 ? 0 : 1;
}

ArmedShip::ArmedShip(AttackPower attack) : attack(attack) {}

AttackPower ArmedShip::getAttackPower() {
    return this->attack;
}
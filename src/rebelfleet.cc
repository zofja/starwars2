#include <cassert>

#include "rebelfleet.h"

ShieldPoints Ship::getShield() {
    return this->shield;
}

void Ship::takeDamage(AttackPower damage) {
    this->shield = damage > this->shield ? 0 : this->shield - damage;
}

bool Ship::isDestroyed() {
    return this->shield == 0;
}

Ship::Ship(ShieldPoints shield) : shield(shield) {}

Speed RebelStarship::getSpeed() {
    return this->speed;
}

bool RebelStarship::isImperial() {
    return false;
}

RebelStarship::RebelStarship(ShieldPoints shield, Speed speed) : Ship(shield), speed(speed) {}

bool BasicRebelStarship::isArmed() {
    return false;
}

BasicRebelStarship::BasicRebelStarship(ShieldPoints shield, Speed speed) : RebelStarship(shield, speed) {}

AttackPower ArmedRebelStarship::getAttackPower() {
    return this->attack;
}

bool ArmedRebelStarship::isArmed() {
    return true;
}

ArmedRebelStarship::ArmedRebelStarship(ShieldPoints shield, Speed speed, AttackPower attack) : RebelStarship(shield, speed), attack(attack) {}

Explorer::Explorer(ShieldPoints shield, Speed speed) : BasicRebelStarship(shield, speed) {
    assert(299796 <= speed && speed <= 2997960);
}

StarCruiser::StarCruiser(ShieldPoints shield, Speed speed, AttackPower attack) : ArmedRebelStarship(shield, speed, attack) {
    assert(99999 <= speed && speed <= 299795);
}

XWing::XWing(ShieldPoints shield, Speed speed, AttackPower attack) : ArmedRebelStarship(shield, speed, attack) {
    assert(299796 <= speed && speed <= 2997960);
}

Explorer createExplorer(ShieldPoints shield, Speed speed) {
    return Explorer(shield, speed);
}

StarCruiser createStarCruiser(ShieldPoints shield, Speed speed, AttackPower attack) {
    return StarCruiser(shield, speed, attack);
}

XWing createXWing(ShieldPoints shield, Speed speed, AttackPower attack) {
    return XWing(shield, speed, attack);
}
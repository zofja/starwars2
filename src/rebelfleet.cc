#include <cassert>

#include "rebelfleet.h"


Speed RebelStarship::getSpeed() {
    return this->speed;
}

RebelStarship::RebelStarship(ShieldPoints shield, Speed speed) : BasicShip(shield), speed(speed) {}

bool RebelStarship::isImperial() {
    return false;
}

ArmedRebelStarship::ArmedRebelStarship(ShieldPoints shield, Speed speed, AttackPower attack)
        : RebelStarship(shield, speed), ArmedShip(shield, attack) {}

bool ArmedRebelStarship::isArmed() {
    return true;
}

Explorer::Explorer(ShieldPoints shield, Speed speed) : RebelStarship(shield, speed) {
    assert(299796 <= speed && speed <= 2997960);
}

bool Explorer::isArmed() {
    return false;
}

StarCruiser::StarCruiser(ShieldPoints shield, Speed speed, AttackPower attack)
        : ArmedRebelStarship(shield, speed, attack) {
    assert(99999 <= speed && speed <= 299795);
}


XWing::XWing(ShieldPoints shield, Speed speed, AttackPower attack) : ArmedRebelStarship(shield, speed, attack) {
    assert(299796 <= speed && speed <= 2997960);
}

Explorer *createExplorer(ShieldPoints shield, Speed speed) {
    return new Explorer(shield, speed);
}

// TODO
StarCruiser *createStarCruiser(ShieldPoints shield, Speed speed, AttackPower attack) {
    return new StarCruiser(shield, speed, attack);
}

// TODO
XWing *createXWing(ShieldPoints shield, Speed speed, AttackPower attack) {
    return new XWing(shield, speed, attack);
}
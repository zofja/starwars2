#include "imperialfleet.h"
#include "rebelfleet.h"

AttackPower ImperialStarship::getAttackPower() {
    return this->attack;
}

bool ImperialStarship::isImperial() {
    return true;
}

void ImperialStarship::attackRebelShip(RebelStarship &attackedShip) {

    attackedShip.takeDamage(this->getAttackPower());

    if (attackedShip.isArmed())
        this->takeDamage(dynamic_cast<ArmedRebelStarship&>(attackedShip).getAttackPower());
}

ImperialStarship::ImperialStarship(ShieldPoints shield, AttackPower attack) : Ship(shield), attack(attack) {}

DeathStar::DeathStar(ShieldPoints shield, AttackPower attack) : ImperialStarship(shield, attack) {}

ImperialDestroyer::ImperialDestroyer(ShieldPoints shield, AttackPower attack) : ImperialStarship(shield, attack) {}

TIEFighter::TIEFighter(ShieldPoints shield, AttackPower attack) : ImperialStarship(shield, attack) {}

DeathStar createDeathStar(ShieldPoints shield, AttackPower attack) {
    return DeathStar(shield, attack);
}

ImperialDestroyer createImperialDestroyer(ShieldPoints shield, AttackPower attack) {
    return ImperialDestroyer(shield, attack);
}

TIEFighter createTIEFighter(ShieldPoints shield, AttackPower attack) {
    return TIEFighter(shield, attack);
}
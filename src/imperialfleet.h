#ifndef STARWARS2_IMPERIALFLEET_H
#define STARWARS2_IMPERIALFLEET_H

#include "rebelfleet.h"

class ImperialStarship : public Ship {

protected:
    AttackPower attack;

public:
    AttackPower getAttackPower();
    bool isImperial();
    void attackRebelShip(RebelStarship &attackedShip);

protected:
    ImperialStarship(ShieldPoints shield, AttackPower attack);
};

class DeathStar : public ImperialStarship {

public:
    DeathStar(ShieldPoints shield, AttackPower attack);
};

class ImperialDestroyer : public ImperialStarship {

public:
    ImperialDestroyer(ShieldPoints shield, AttackPower attack);
};

class TIEFighter : public ImperialStarship {

public:
    TIEFighter(ShieldPoints shield, AttackPower attack);
};

DeathStar createDeathStar(ShieldPoints shield, AttackPower attack);

ImperialDestroyer createImperialDestroyer(ShieldPoints shield, AttackPower attack);

TIEFighter createTIEFighter(ShieldPoints shield, AttackPower attack);

#endif //STARWARS2_IMPERIALFLEET_H

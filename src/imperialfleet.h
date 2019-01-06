#ifndef STARWARS2_IMPERIALFLEET_H
#define STARWARS2_IMPERIALFLEET_H

#include <initializer_list>
#include <vector>
#include "rebelfleet.h"

class ImperialStarship : public Ship {

protected:
    AttackPower attack;

public:
    AttackPower getAttackPower();

    bool isImperial() override;

    void attackRebelShip(RebelStarship *attackedShip);

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

class Squadron {

public:

    Squadron(std::initializer_list<ImperialStarship*> ships);

    ShieldPoints getShield();

    AttackPower getAttackPower();

    void takeDamage(AttackPower damage);

    std::vector<ImperialStarship*> &getShips();


private:

    std::vector<ImperialStarship*> ships;

};

DeathStar *createDeathStar(ShieldPoints shield, AttackPower attack);

ImperialDestroyer *createImperialDestroyer(ShieldPoints shield, AttackPower attack);

TIEFighter *createTIEFighter(ShieldPoints shield, AttackPower attack);

Squadron *createSquadron(std::initializer_list<ImperialStarship*> ships);

#endif //STARWARS2_IMPERIALFLEET_H

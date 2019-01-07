#ifndef STARWARS2_IMPERIALFLEET_H
#define STARWARS2_IMPERIALFLEET_H

#include <initializer_list>
#include <vector>
#include "helper.h"
#include "rebelfleet.h"

class ImperialStarship : public BasicShip, public ArmedShip, public ImperialUnit {

public:

    bool isDestroyed() override;

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


class Squadron : public ImperialUnit {

public:

    // TODO czy ma przyjmować ImperialUnity?
    Squadron(std::initializer_list<ImperialUnit*> ships);

    Squadron(std::vector<ImperialUnit *> ships);

    ShieldPoints getShield() override;

    AttackPower getAttackPower() override;

    void takeDamage(AttackPower damage) override;

    std::vector<ImperialUnit *> &getShips();

private:

    std::vector<ImperialUnit *> ships;

};

// funkcje fabrykujące
DeathStar *createDeathStar(ShieldPoints shield, AttackPower attack);

ImperialDestroyer *createImperialDestroyer(ShieldPoints shield, AttackPower attack);

TIEFighter *createTIEFighter(ShieldPoints shield, AttackPower attack);

Squadron *createSquadron(std::initializer_list<ImperialStarship *> ships);

#endif //STARWARS2_IMPERIALFLEET_H

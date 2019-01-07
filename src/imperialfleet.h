#ifndef STARWARS2_IMPERIALFLEET_H
#define STARWARS2_IMPERIALFLEET_H

#include <initializer_list>
#include <memory>
#include <vector>
#include "helper.h"
#include "rebelfleet.h"

class ImperialStarship : public BasicShip, public ArmedShip, public ImperialUnit {

public:

    bool isDestroyed() override;

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

/*
class Squadron : public ImperialUnit {

public:

    Squadron(std::initializer_list<ImperialUnit> ships);

    explicit Squadron(std::vector<ImperialUnit> ships);

    ShieldPoints getShield() override;

    AttackPower getAttackPower() override;

    void takeDamage(AttackPower damage) override;

    std::vector<ImperialUnit> &getShips();

private:

    std::vector<ImperialUnit> ships;

};
 */

// funkcje fabrykujące
std::shared_ptr<DeathStar> createDeathStar(ShieldPoints shield, AttackPower attack);

std::shared_ptr<ImperialDestroyer> createImperialDestroyer(ShieldPoints shield, AttackPower attack);

std::shared_ptr<TIEFighter> createTIEFighter(ShieldPoints shield, AttackPower attack);

/*
std::shared_ptr<Squadron> createSquadron(std::initializer_list<ImperialUnit> ships);

std::shared_ptr<Squadron> createSquadron(std::vector<ImperialUnit> ships);
*/

#endif //STARWARS2_IMPERIALFLEET_H

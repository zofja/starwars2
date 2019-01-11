#ifndef STARWARS2_REBELFLEET_H
#define STARWARS2_REBELFLEET_H

#include <memory>
#include "helper.h"

class RebelStarship : public BasicShip {

protected:

    Speed speed;

public:

    Speed getSpeed();

    virtual void causeDamage(const std::shared_ptr<Ship> &imperial) = 0;

protected:

    RebelStarship(ShieldPoints shield, Speed speed);
};

class ArmedRebelStarship : public RebelStarship, public ArmedShip {

public:

    void causeDamage(const std::shared_ptr<Ship> &imperial) override;

protected:

    ArmedRebelStarship(ShieldPoints shield, Speed speed, AttackPower attack);
};


class Explorer : public RebelStarship {

public:

    void causeDamage(const std::shared_ptr<Ship> &imperial) override;

    Explorer(ShieldPoints shield, Speed speed);
};

class StarCruiser : public ArmedRebelStarship {

public:

    StarCruiser(ShieldPoints shield, Speed speed, AttackPower attack);

};

class XWing : public ArmedRebelStarship {

public:

    XWing(ShieldPoints shield, Speed speed, AttackPower attack);
};

std::shared_ptr<RebelStarship> createExplorer(ShieldPoints shield, Speed speed);

std::shared_ptr<RebelStarship> createStarCruiser(ShieldPoints shield, Speed speed, AttackPower attack);

std::shared_ptr<RebelStarship> createXWing(ShieldPoints shield, Speed speed, AttackPower attack);

#endif //STARWARS2_REBELFLEET_H

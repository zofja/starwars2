#ifndef STARWARS2_REBELFLEET_H
#define STARWARS2_REBELFLEET_H

#include <memory>
#include "helper.h"

class RebelStarship : public BasicShip {

protected:
    Speed speed;

public:

    virtual void causeDamage(const std::shared_ptr<Ship> &imperial);

    Speed getSpeed();

    virtual bool isArmed() = 0;

protected:
    RebelStarship(ShieldPoints shield, Speed speed);
};

class ArmedRebelStarship : public RebelStarship, public ArmedShip {

public:

    bool isArmed() override;

    void causeDamage(const std::shared_ptr<Ship> &imperial) override;

protected:

    ArmedRebelStarship(ShieldPoints shield, Speed speed, AttackPower attack);
};


class Explorer : public RebelStarship {

public:
    Explorer(ShieldPoints shield, Speed speed);

    bool isArmed() override;
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

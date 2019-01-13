#ifndef REBELFLEET_H
#define REBELFLEET_H

#include <memory>
#include "helper.h"

class RebelStarship : public BasicShip {

protected:

    Speed speed; //represents value of ship's speed

public:

    Speed getSpeed();

    /*
     * If the ship is armed function inflicts damage(equal to the attack power of the ship) on the imperial ship.
     */
    virtual void causeDamage(const std::shared_ptr<ShipUnit> &imperial) = 0;

protected:

    RebelStarship(ShieldPoints shield, Speed speed);

    virtual ~RebelStarship() = default;
};

class ArmedRebelStarship : public RebelStarship, public ArmedShip {

public:

    void causeDamage(const std::shared_ptr<ShipUnit> &imperial) override;

protected:

    ArmedRebelStarship(ShieldPoints shield, Speed speed, AttackPower attack);

    virtual ~ArmedRebelStarship() = default;
};


class Explorer : public RebelStarship {

public:

    void causeDamage(const std::shared_ptr<ShipUnit> &imperial) override;

    Explorer(ShieldPoints shield, Speed speed);

    ~Explorer() = default;
};

class StarCruiser : public ArmedRebelStarship {

public:

    StarCruiser(ShieldPoints shield, Speed speed, AttackPower attack);

    ~StarCruiser() = default;
};

class XWing : public ArmedRebelStarship {

public:

    XWing(ShieldPoints shield, Speed speed, AttackPower attack);

    ~XWing() = default;
};

std::shared_ptr<RebelStarship> createExplorer(ShieldPoints shield, Speed speed);

std::shared_ptr<RebelStarship> createStarCruiser(ShieldPoints shield, Speed speed, AttackPower attack);

std::shared_ptr<RebelStarship> createXWing(ShieldPoints shield, Speed speed, AttackPower attack);

#endif

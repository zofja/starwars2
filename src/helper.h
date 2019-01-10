#ifndef STARWARS2_HELPER_H
#define STARWARS2_HELPER_H

#include <memory>

typedef int ShieldPoints;
typedef int Speed;
typedef int AttackPower;

// TODO pure virtual abstract classes
class Ship {

protected:

    ShieldPoints shield;

    size_t aliveCount = 1;


public:

    virtual ShieldPoints getShield() = 0;

    virtual void takeDamage(AttackPower damage) = 0;

    virtual bool isDestroyed();

    virtual size_t getAliveCount();

protected:


    explicit Ship(ShieldPoints shield);

    virtual ~Ship() = default;

};

class BasicShip : public virtual Ship {

public:

    ShieldPoints getShield() override;

    void takeDamage(AttackPower damage) override;

public:

    explicit BasicShip(ShieldPoints shield);

    ~BasicShip() override = default;

};


class ArmedShipUnit : public virtual Ship {

public:

    virtual AttackPower getAttackPower() = 0;

protected:

    ArmedShipUnit(ShieldPoints shield, AttackPower attack);

    ~ArmedShipUnit() override = default;

    AttackPower attack;

};

class ArmedShip : public virtual ArmedShipUnit {

public:

    AttackPower getAttackPower() override;

protected:

    explicit ArmedShip(ShieldPoints shield, AttackPower attack);

    ~ArmedShip() override = default;

};

class ImperialUnit : public virtual ArmedShipUnit {

protected:

    explicit ImperialUnit(ShieldPoints shield, AttackPower attack);

    ~ImperialUnit() override = default;

};

#endif //STARWARS2_HELPER_H

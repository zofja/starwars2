#ifndef STARWARS2_HELPER_H
#define STARWARS2_HELPER_H

#include <memory>

typedef int ShieldPoints;
typedef int Speed;
typedef int AttackPower;

class Ship {

public:

    virtual ShieldPoints getShield() = 0;

    virtual void takeDamage(AttackPower damage) = 0;

    virtual size_t getAliveCount() = 0;

protected:

    Ship() = default;
    virtual ~Ship() = default;
};

class BasicShip : public virtual Ship {

protected:

    ShieldPoints shield;

public:

    ShieldPoints getShield() override;

    void takeDamage(AttackPower damage) override;

    size_t getAliveCount() override;

protected:

    explicit BasicShip(ShieldPoints shield);
    ~BasicShip() override = default;
};


class ArmedShipUnit : public virtual Ship {

public:

    virtual AttackPower getAttackPower() = 0;

protected:

    ArmedShipUnit() = default;
    ~ArmedShipUnit() override = default;
};

class ArmedShip : public virtual ArmedShipUnit {

protected:

    AttackPower attack;

public:

    AttackPower getAttackPower() override;

protected:

    explicit ArmedShip(AttackPower attack);
    ~ArmedShip() override = default;

};

class ImperialUnit : public virtual ArmedShipUnit {

protected:

    ImperialUnit() = default;
    ~ImperialUnit() override = default;
};

#endif //STARWARS2_HELPER_H

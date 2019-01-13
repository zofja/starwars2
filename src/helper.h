#ifndef HELPER_H
#define HELPER_H

#include <memory>

typedef int ShieldPoints;
typedef int Speed;
typedef int AttackPower;

class ShipUnit {

public:

    /*
     * Returns the current value of ship's shield.
     */
    virtual ShieldPoints getShield() = 0;

    /*
     * Lowers ship's shield by the damage received or sets it to 0 if damage is greater that shield.
     */
    virtual void takeDamage(AttackPower damage) = 0;

    /*
     * Returns number of ships alive in this unit.
     */
    virtual size_t getAliveCount() = 0;

protected:

    ShipUnit() = default;

    virtual ~ShipUnit() = default;
};

class BasicShip : public virtual ShipUnit {

protected:

    ShieldPoints shield; //represents value of ship's shield

public:

    ShieldPoints getShield() override;

    void takeDamage(AttackPower damage) override;

    size_t getAliveCount() override;

protected:

    explicit BasicShip(ShieldPoints shield);

    virtual ~BasicShip() = default;
};


class ArmedShipUnit : public virtual ShipUnit {

public:

    /*
     * Returns the values of ship's attack power.
     */
    virtual AttackPower getAttackPower() = 0;

protected:

    ArmedShipUnit() = default;

    virtual ~ArmedShipUnit() = default;
};

class ArmedShip : public virtual ArmedShipUnit {

protected:

    AttackPower attack; //represents value of ship's attack power

public:

    AttackPower getAttackPower() override;

protected:

    explicit ArmedShip(AttackPower attack);

    virtual ~ArmedShip() = default;

};

class ImperialUnit : public virtual ArmedShipUnit {

protected:

    ImperialUnit() = default;

    virtual ~ImperialUnit() = default;
};

#endif

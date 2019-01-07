#ifndef STARWARS2_HELPER_H
#define STARWARS2_HELPER_H

typedef int ShieldPoints;
typedef int Speed;
typedef int AttackPower;

// Pure virtual base class
class Ship {

protected:

    ShieldPoints shield;

public:

    virtual ShieldPoints getShield() = 0;

    virtual void takeDamage(AttackPower damage) = 0;

    virtual bool isImperial() = 0;

    virtual bool isDestroyed() = 0;

protected:

    explicit Ship(ShieldPoints shield);

};

// Abstract virtual class
class BasicShip : public Ship {

public:

    // override bo może
    ShieldPoints getShield() override;

    void takeDamage(AttackPower damage) override;

    bool isDestroyed() override;

public:

    explicit BasicShip(ShieldPoints shield);

};


// Abstract virtual class
class ArmedShipUnit : public Ship {

public:

    virtual AttackPower getAttackPower();

protected:

    ArmedShipUnit(ShieldPoints shield, AttackPower attack);

    AttackPower attack;

};

// Abstract virtual class
class ArmedShip : public virtual ArmedShipUnit {

public:

    AttackPower getAttackPower() override;

protected:

    explicit ArmedShip(ShieldPoints shield, AttackPower attack);

};

class ImperialUnit : public virtual ArmedShipUnit {

public:

    bool isImperial() override;

protected:

    explicit ImperialUnit(ShieldPoints shield, AttackPower attack);

};

#endif //STARWARS2_HELPER_H

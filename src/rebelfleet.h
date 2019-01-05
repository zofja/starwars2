#ifndef STARWARS2_REBELFLEET_H
#define STARWARS2_REBELFLEET_H

typedef int ShieldPoints;
typedef int Speed;
typedef int AttackPower;

class Ship {

protected:
    ShieldPoints shield;
    Speed speed;

public:
    ShieldPoints getShield();
    Speed getSpeed();
    void takeDamage(AttackPower damage);

    virtual bool isArmed() = 0;
    virtual bool isImperial() = 0;

protected:
    Ship(ShieldPoints shield, Speed speed);
};

class RebelStarship : public Ship {

public:
    bool isImperial() override;

protected:
    RebelStarship(ShieldPoints shield, Speed speed);
};

class ArmedRebelStarship : public RebelStarship {

protected:
    AttackPower attack;

public:
    AttackPower getAttackPower();
    bool isArmed() override;

protected:
    ArmedRebelStarship(ShieldPoints shield, Speed speed, AttackPower attack);
};

class BasicRebelStarship : public RebelStarship {

public:
    bool isArmed() override;

protected:
    BasicRebelStarship(ShieldPoints shield, Speed speed);
};

class Explorer : public BasicRebelStarship {

public:
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

Explorer createExplorer(ShieldPoints shield, Speed speed);

StarCruiser createStarCruiser(ShieldPoints shield, Speed speed, AttackPower attack);

XWing createXWing(ShieldPoints shield, Speed speed, AttackPower attack);

#endif //STARWARS2_REBELFLEET_H

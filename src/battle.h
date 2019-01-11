#ifndef STARWARS2_BATTLE_H
#define STARWARS2_BATTLE_H

#include <vector>
#include "rebelfleet.h"
#include "imperialfleet.h"

typedef int Time;

class TimeStrategy {

public:

    virtual bool moveTime(Time timeStep) = 0;

    virtual ~TimeStrategy() = default;
};

class OurTimeStrategy : public virtual TimeStrategy {

public:

    OurTimeStrategy(Time startTime, Time maxTime);

    bool moveTime(Time timeStep) override;

private:

    Time time;
    Time maxTime;

};

class AttackStrategy {

public:

    virtual ~AttackStrategy() = default;

    virtual void imperialAttack(std::vector<std::shared_ptr<ImperialUnit>> &imperials,
                                std::vector<std::shared_ptr<RebelStarship>> &rebels) = 0;

};

class OurAttackStrategy : public virtual AttackStrategy {

public:
    OurAttackStrategy();

    void imperialAttack(std::vector<std::shared_ptr<ImperialUnit>> &imperials,
                        std::vector<std::shared_ptr<RebelStarship>> &rebels) override;
};

class SpaceBattle {

public:

    SpaceBattle(std::vector<std::shared_ptr<ImperialUnit>> imperials,
                std::vector<std::shared_ptr<RebelStarship>> rebels,
                Time t0, Time t1);

    size_t countImperialFleet();

    size_t countRebelFleet();

    void tick(Time timeStep);

    class Builder {

    public:

        Builder();

        Builder &ship(const std::shared_ptr<ImperialUnit> &imperial);

        Builder &ship(const std::shared_ptr<RebelStarship> &rebel);

        Builder &startTime(Time t);

        Builder &maxTime(Time t);

        SpaceBattle build();


    private:

        std::vector<std::shared_ptr<ImperialUnit>> imperials;
        std::vector<std::shared_ptr<RebelStarship>> rebels;
        Time t0;
        Time t1;

    };

private:

    std::vector<std::shared_ptr<ImperialUnit>> imperials;
    std::vector<std::shared_ptr<RebelStarship>> rebels;
    std::shared_ptr<TimeStrategy> timeStrategy;
    std::shared_ptr<AttackStrategy> attackStrategy;

};

void attack(std::shared_ptr<ImperialUnit> &imperial, std::shared_ptr<RebelStarship> &rebel);

#endif //STARWARS2_BATTLE_H

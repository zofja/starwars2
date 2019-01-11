#ifndef BATTLE_H
#define BATTLE_H

#include <vector>
#include "rebelfleet.h"
#include "imperialfleet.h"

typedef int Time;

class TimeStrategy {

public:

    virtual bool moveTime(Time timeStep) = 0;

protected:

    TimeStrategy() = default;

    virtual ~TimeStrategy() = default;
};

class DefaultTimeStrategy : public virtual TimeStrategy {

public:

    DefaultTimeStrategy(Time startTime, Time maxTime);

    bool moveTime(Time timeStep) override;

private:

    Time time;
    Time maxTime;

};

class AttackStrategy {

public:

    virtual void imperialAttack(std::vector<std::shared_ptr<ImperialUnit>> &imperials,
                                std::vector<std::shared_ptr<RebelStarship>> &rebels) = 0;

protected:

    AttackStrategy() = default;

    virtual ~AttackStrategy() = default;
};

class DefaultAttackStrategy : public virtual AttackStrategy {

public:
    DefaultAttackStrategy();

    void imperialAttack(std::vector<std::shared_ptr<ImperialUnit>> &imperials,
                        std::vector<std::shared_ptr<RebelStarship>> &rebels) override;
};

class SpaceBattle {

public:

    SpaceBattle(const std::vector<std::shared_ptr<ImperialUnit>> &imperials,
                const std::vector<std::shared_ptr<RebelStarship>> &rebels,
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

#endif

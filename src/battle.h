#ifndef STARWARS2_BATTLE_H
#define STARWARS2_BATTLE_H

#include <vector>
#include "rebelfleet.h"
#include "imperialfleet.h"

typedef int Time;

class TimeStrategy {

public:
    virtual bool moveTime(Time timeStep) = 0;

};

class OurTimeStrategy : public TimeStrategy {

private:
    Time time;
    Time maxTime;

public:
    OurTimeStrategy(Time startTime, Time maxTime);
    bool moveTime(Time timeStep) override;

};

class AttackStrategy {

public:
    virtual std::pair<int, int> imperialAttack(std::vector<std::shared_ptr<ImperialUnit>> imperials, std::vector<std::shared_ptr<RebelStarship>> rebels) = 0;

};

class OurAttackStrategy : public AttackStrategy {

public:
    std::pair<int, int> imperialAttack(std::vector<std::shared_ptr<ImperialUnit>> imperials, std::vector<std::shared_ptr<RebelStarship>> rebels) override;
    OurAttackStrategy();
};


class SpaceBattle {

public:

    SpaceBattle(std::vector<std::shared_ptr<ImperialUnit>> imperials, std::vector<std::shared_ptr<RebelStarship>> rebels,
                Time t0, Time t1);

    size_t countImperialFleet();

    size_t countRebelFleet();

    void tick(Time timeStep);

    // TODO debug - usunąć potem
    void printShips() {
        for (auto &ship : rebels) {
            std::cout << ship->getShield() << "\n";
        }
        for (auto &ship : imperials) {
            std::cout << ship->getShield() << "\n";
        }
    };

    class Builder {

    public:

        Builder();

        Builder &ship(std::shared_ptr<ImperialUnit> imperial);

        Builder &ship(std::shared_ptr<RebelStarship> rebel);

        Builder &startTime(Time t);

        Builder &maxTime(Time t);

        SpaceBattle build();


    private:

        std::vector<std::shared_ptr<ImperialUnit>> imperials;
        std::vector<std::shared_ptr<RebelStarship>> rebels;
        std::vector<Time> intergalacticTime;
        Time t0;
        Time t1;

    };

private:

    std::vector<std::shared_ptr<ImperialUnit>> imperials;
    std::vector<std::shared_ptr<RebelStarship>> rebels;
    size_t imperialFleet = 0;
    size_t rebelFleet = 0;
    std::shared_ptr<TimeStrategy> timeStrategy;
    std::shared_ptr<AttackStrategy> attackStrategy;

    void imperialAttack();
};

void attack(std::shared_ptr<ImperialUnit> imperial, std::shared_ptr<RebelStarship> rebel);

#endif //STARWARS2_BATTLE_H

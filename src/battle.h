#ifndef STARWARS2_BATTLE_H
#define STARWARS2_BATTLE_H

#include <vector>
#include "rebelfleet.h"
#include "imperialfleet.h"

typedef int Time;

class SpaceBattle {

public:

    SpaceBattle(std::vector<ImperialStarship *> imperials, std::vector<RebelStarship *> rebels, Time t0, Time t1,
                std::vector<Time> igTime);

    size_t countImperialFleet();

    size_t countRebelFleet();

    void tick(Time timeStep);

    class Builder {

    public:

        Builder();

        Builder &ship(Ship *s);

        Builder &ship(Squadron *s);

        Builder &startTime(Time t);

        Builder &maxTime(Time t);

        SpaceBattle build();


    private:

        std::vector<ImperialStarship *> imperials;
        std::vector<RebelStarship *> rebels;
        std::vector<Time> intergalacticTime;
        Time t0;
        Time t1;

    };

private:

    std::vector<ImperialStarship *> imperials;
    std::vector<RebelStarship *> rebels;
    Time time;
    Time t1;
    std::vector<Time> intergalacticTime;
    size_t imperialFleet;
    size_t rebelFleet;

    void imperialAttack();
};

#endif //STARWARS2_BATTLE_H

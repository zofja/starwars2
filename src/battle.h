#ifndef STARWARS2_BATTLE_H
#define STARWARS2_BATTLE_H

#include <vector>
#include "rebelfleet.h"
#include "imperialfleet.h"

/*
 *     auto battle = SpaceBattle::Builder()
        .ship(squadron)
        .startTime(2)
        .maxTime(23)
        .ship(xwing)
        .ship(explorer)
        .build();
 */
typedef int Time;

class SpaceBattle {

public:

    SpaceBattle(std::vector<ImperialStarship *> imperials, std::vector<RebelStarship *> rebels, Time t0, Time t1);

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

        std::vector<RebelStarship *> rebels;
        std::vector<ImperialStarship *> imperials;
        Time t0;
        Time t1;

    };

private:

    std::vector<RebelStarship *> rebels;
    std::vector<ImperialStarship *> imperials;
    Time t0;
    Time t1;
};

#endif //STARWARS2_BATTLE_H

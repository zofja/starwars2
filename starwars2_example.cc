#include <cassert>
#include <iostream>
#include "src/imperialfleet.h"
#include "src/rebelfleet.h"
#include "src/battle.h"

int main() {
    auto xwing = createXWing(100, 300000, 50);
    auto explorer = createExplorer(150, 400000);
    auto cruiser = createStarCruiser(1234, 100000, 11);
    auto deathStar = createDeathStar(10000, 75);
    auto fighter = createTIEFighter(50, 9);
    auto destroyer = createImperialDestroyer(150, 20);
    // TODO co w końcu z tym konstruktorem
    std::initializer_list<std::shared_ptr<ImperialUnit>> list = {deathStar, fighter};
    auto squadron = createSquadron(list);

    auto battle = SpaceBattle::Builder()
        .ship(squadron)
        .startTime(2)
        .maxTime(23)
        .ship(xwing)
        .ship(explorer)
        .build();

    assert(battle.countRebelFleet() == 2);
    assert(battle.countImperialFleet() == 2);

    battle.tick(3);
    assert(battle.countRebelFleet() == 2);
    assert(battle.countImperialFleet() == 1);

    battle.tick(1);
    assert(battle.countRebelFleet() == 2);
    assert(battle.countImperialFleet() == 1);

    battle.tick(4);
    assert(battle.countRebelFleet() == 0);
    assert(battle.countImperialFleet() == 1);

    battle.tick(1); // Wypisuje "IMPERIUM WON\n".
}


//#include <cassert>
//#include "src/imperialfleet.h"
//#include "src/rebelfleet.h"
//#include "src/battle.h"
//
//int main() {
//    auto deathStar = createDeathStar(10000, 75);
//    auto fighter = createTIEFighter(50, 9);
//    auto squadron = createSquadron(std::vector{deathStar, fighter});
//}
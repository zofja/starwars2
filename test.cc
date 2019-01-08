#include <iostream>
#include <bits/stdc++.h>
#include "src/helper.h"
#include "src/rebelfleet.h"
#include "src/imperialfleet.h"
#include "src/battle.h"

using namespace std;

int main() {

    auto xwing = createXWing(100, 300000, 50);
    auto explorer = createExplorer(150, 400000);
    auto cruiser = createStarCruiser(1234, 100000, 11);
    auto deathStar = createDeathStar(10000, 75);
    auto fighter = createTIEFighter(50, 9);
    auto destroyer = createImperialDestroyer(150, 20);


//    /*
    cout << "XWing: " << endl;
    cout << ">shield: " << xwing->getShield() << endl;
    cout << ">speed: " << xwing->getSpeed() << endl;
//    cout << ">attack: " << xwing->getAttackPower() << endl;
    cout << ">isImperial: " << xwing->isImperial() << endl;
    cout << ">isArmed: " << xwing->isArmed() << endl;
    cout << endl;

    cout << "Explorer: " << endl;
    cout << ">shield: " << explorer->getShield() << endl;
    cout << ">speed: " << explorer->getSpeed() << endl;
    cout << ">isImperial: " << explorer->isImperial() << endl;
    cout << ">isArmed: " << explorer->isArmed() << endl;
    cout << endl;

    cout << "StarCruiser: " << endl;
    cout << ">shield: " << cruiser->getShield() << endl;
    cout << ">speed: " << cruiser->getSpeed() << endl;
//    cout << ">attack: " << cruiser->getAttackPower() << endl;
    cout << ">isImperial: " << cruiser->isImperial() << endl;
    cout << ">isArmed: " << cruiser->isArmed() << endl;
    cout << endl;

    cout << "DeathStar: " << endl;
    cout << ">shield: " << deathStar->getShield() << endl;
    cout << ">attack: " << deathStar->getAttackPower() << endl;
    cout << ">isImperial: " << deathStar->isImperial() << endl;
    cout << endl;

    cout << "TIEFighter: " << endl;
    cout << ">shield: " << fighter->getShield() << endl;
    cout << ">attack: " << fighter->getAttackPower() << endl;
    cout << ">isImperial: " << fighter->isImperial() << endl;
    cout << endl;

    cout << "ImperialDestroyer: " << endl;
    cout << ">shield: " << destroyer->getShield() << endl;
    cout << ">attack: " << destroyer->getAttackPower() << endl;
    cout << ">isImperial: " << destroyer->isImperial() << endl;
    cout << endl;

    xwing->takeDamage(10);
    explorer->takeDamage(20);
    cruiser->takeDamage(1000);
    deathStar->takeDamage(999);
    fighter->takeDamage(20);
    destroyer->takeDamage(10);

    cout << "XWing shield: " << xwing->getShield() << endl;
    cout << "Explorer shield: " << explorer->getShield() << endl;
    cout << "StarCruiser shield: " << cruiser->getShield() << endl;
    cout << "DeathStar shield: " << deathStar->getShield() << endl;
    cout << "TIEFighter shield: " << fighter->getShield() << endl;
    cout << "ImperialDestroyer shield: " << destroyer->getShield() << endl;
    cout << endl;

    /*
    deathStar->attackRebelShip(xwing);
    fighter->attackRebelShip(cruiser);
    destroyer->attackRebelShip(explorer);

    cout << "XWing shield: " << xwing->getShield() << endl;
    cout << "Explorer shield: " << explorer->getShield() << endl;
    cout << "StarCruiser shield: " << cruiser->getShield() << endl;
    cout << "DeathStar shield: " << deathStar->getShield() << endl;
    cout << "TIEFighter shield: " << fighter->getShield() << endl;
    cout << "ImperialDestroyer shield: " << destroyer->getShield() << endl;
    cout << endl;

    fighter->attackRebelShip(xwing);
    deathStar->attackRebelShip(explorer);
    destroyer->attackRebelShip(cruiser);

    cout << "XWing shield: " << xwing->getShield() << endl;
    cout << "Explorer shield: " << explorer->getShield() << endl;
    cout << "StarCruiser shield: " << cruiser->getShield() << endl;
    cout << "DeathStar shield: " << deathStar->getShield() << endl;
    cout << "TIEFighter shield: " << fighter->getShield() << endl;
    cout << "ImperialDestroyer shield: " << destroyer->getShield() << endl;
    cout << endl;

    cout << "XWing isDestroyed: " << xwing->isDestroyed() << endl;
    cout << "Explorer isDestroyed: " << explorer->isDestroyed() << endl;
    cout << "StarCruiser isDestroyed: " << cruiser->isDestroyed() << endl;
    cout << "DeathStar isDestroyed: " << deathStar->isDestroyed() << endl;
    cout << "TIEFighter isDestroyed: " << fighter->isDestroyed() << endl;
    cout << "ImperialDestroyer isDestroyed: " << destroyer->isDestroyed() << endl;
    cout << endl;
    */

    auto battle = SpaceBattle::Builder().ship(deathStar).ship(xwing).startTime(0).maxTime(3).build();

    battle.printShips();
    battle.tick(2);
    battle.printShips();
    battle.tick(1);
    battle.printShips();
    battle.tick(1);
    battle.printShips();
    battle.tick(1);

}


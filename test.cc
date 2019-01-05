#include <iostream>

#include "src/rebelfleet.h"

using namespace std;

int main() {

    auto xwing = createXWing(100, 300000, 50);
    auto explorer = createExplorer(150, 400000);
    auto cruiser = createStarCruiser(1234, 100000, 11);

    cout << "XWing: " << endl;
    cout << ">shield: " << xwing.getShield() << endl;
    cout << ">speed: " << xwing.getSpeed() << endl;
    cout << ">attack: " << xwing.getAttackPower() << endl;
    cout << ">isImperial: " << xwing.isImperial() << endl;
    cout << ">isArmed: " << xwing.isArmed() << endl;
    cout << endl;

    cout << "Explorer: " << endl;
    cout << ">shield: " << explorer.getShield() << endl;
    cout << ">speed: " << explorer.getSpeed() << endl;
    cout << ">isImperial: " << explorer.isImperial() << endl;
    cout << ">isArmed: " << explorer.isArmed() << endl;
    cout << endl;

    cout << "StarCruiser: " << endl;
    cout << ">shield: " << cruiser.getShield() << endl;
    cout << ">speed: " << cruiser.getSpeed() << endl;
    cout << ">attack: " << cruiser.getAttackPower() << endl;
    cout << ">isImperial: " << cruiser.isImperial() << endl;
    cout << ">isArmed: " << cruiser.isArmed() << endl;
    cout << endl;

    xwing.takeDamage(50);
    explorer.takeDamage(300);
    cruiser.takeDamage(1000);

    cout << "XWing shield: " << xwing.getShield() << endl;
    cout << "Explorer shield: " << explorer.getShield() << endl;
    cout << "StarCruiser shield: " << cruiser.getShield() << endl;
}


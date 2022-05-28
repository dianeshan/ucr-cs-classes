#include <string>
#include <iostream>

using namespace std;

#include "Warrior.h"

Warrior::Warrior(const string &name, double health, double attackStrength, const string &allegiance)
: Character(WARRIOR, name, health, attackStrength) {
    this->allegiance = allegiance;
}

void Warrior::attack(Character &baddie) {
    if (baddie.getType() == WARRIOR) {
        Warrior &opp = dynamic_cast<Warrior &>(baddie);
        if (opp.allegiance == allegiance) {
            cout << "Warrior " << name << " does not attack Warrior " << opp.name << "." << endl;
            cout << "They share an allegiance with " << allegiance << "." << endl;
        }
        else {
            double d;
            d = (health / MAX_HEALTH) * attackStrength;
            opp.damage(d);
            cout << "Warrior " << name << " attacks " << opp.name << " --- SLASH!!" << endl;
            cout << opp.name << " takes " << d << " damage." << endl;
        }
    }
    else {
        double d;
        d = (health / MAX_HEALTH) * attackStrength;
        baddie.damage(d);
        cout << "Warrior " << name << " attacks " << baddie.getName() << " --- SLASH!!" << endl;
        cout <<  baddie.getName() << " takes " << d << " damage." << endl;
    }
}
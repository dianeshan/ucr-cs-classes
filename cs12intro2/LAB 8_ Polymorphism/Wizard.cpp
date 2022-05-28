#include <string>
#include <iostream>

using namespace std;

#include "Wizard.h"

Wizard::Wizard(const string &name, double health, double attackStrength, int rank) 
: Character(WIZARD, name, health, attackStrength), rank(rank) { }

void Wizard::attack(Character &baddie) {
    if (baddie.getType() == WIZARD) {
        Wizard &opp = dynamic_cast<Wizard &>(baddie);
        double d;
        d = attackStrength * (rank/static_cast<double>(opp.rank));
        opp.damage(d);
        cout << "Wizard " << name << " attacks " << opp.name << " --- POOF!!" << endl;
        cout << opp.name << " takes " << d << " damage." << endl;
    }
    else {
        double d = attackStrength;
        baddie.damage(d);
        cout << "Wizard " << name << " attacks " << baddie.getName() << " --- POOF!!" << endl;
        cout << baddie.getName() << " takes " << d << " damage." << endl;
    } 
}
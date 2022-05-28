#include <string>
#include <iostream>

using namespace std;

#include "Elf.h"

Elf::Elf(const string &name, double health, double attackStrength, const string &fam)
: Character(ELF, name, health, attackStrength) {
    this->fam = fam;
}

void Elf::attack(Character &baddie) {
    if (baddie.getType() == ELF) {
        Elf &opp = dynamic_cast<Elf &>(baddie);
        if (opp.fam == fam) {
            cout << "Elf " << name << " does not attack Elf " << opp.name << "." << endl;
            cout << "They are both members of the " << fam << " family." << endl;
        }
        else {
            double d;
            d = (health / MAX_HEALTH) * attackStrength;
            opp.damage(d);
            cout << "Elf " << name << " shoots an arrow at " << opp.name << " --- TWANG!!" << endl;
            cout << opp.name << " takes " << d << " damage." << endl;
        }
    }
    else {
        double d;
        d = (health / MAX_HEALTH) * attackStrength;
        baddie.damage(d);
        cout << "Elf " << name << " shoots an arrow at " << baddie.getName() << " --- TWANG!!" << endl;
        cout << baddie.getName() << " takes " << d << " damage." << endl;
    }
}
#include <string>
#include <iostream>

using namespace std;

#ifndef __WARRIOR_H__
#define __WARRIOR_H__

#include "Character.h"

class Warrior : public Character {
    private:
        string allegiance;
    public:
        Warrior(const string &, double, double, const string &);
        void attack(Character &);
};

#endif
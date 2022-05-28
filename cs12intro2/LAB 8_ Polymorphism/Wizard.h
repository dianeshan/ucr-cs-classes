#include <string>
#include <iostream>

using namespace std;

#ifndef __WIZARD_H__
#define __WIZARD_H__

#include "Character.h"

class Wizard : public Character {
    private:
        int rank;
    public:
        Wizard(const string &, double, double, int);
        void attack(Character &);
};

#endif
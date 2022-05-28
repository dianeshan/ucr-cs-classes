#include <string>
#include <iostream>

using namespace std;

#ifndef __ELF_H__
#define __ELF_H__

#include "Character.h"

class Elf : public Character {
    private:
        string fam;
    public:
        Elf(const string &, double, double, const string &);
        void attack(Character &);
};

#endif
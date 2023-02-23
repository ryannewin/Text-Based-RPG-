#include <iostream>
#include <vector>
#include <cstdlib>
#include<string>

#ifndef __WIZARD_H__
#define __WIZARD_H__
#include "Character.h"

struct Wand  {
    int magicFuel;
    Wand(int fuel) : magicFuel(fuel) {};
};

class Wizard:public Character {
    public:
        Wizard(const string &n, int hp, int attStength, int attSpeed, int g, int lvl, int exp, int fuel, bool wood, bool gold, bool diamond)
            : Character (WIZARD, n, hp, attStength, attSpeed, g, lvl, exp, wood, gold, diamond), wand(fuel) {};
    Wand wand;
    virtual void attack(Character &) override;
    virtual void enemyAttack(Character &) override;
};
#endif
#include <iostream>
#include <vector>
#include <cstdlib>
#include<string>

#ifndef __BEAST_H__
#define __BEAST_H__

#include "Character.h"

class Beast:public Character {
    public:
        Beast(const string &n, int hp, int attStength, int attSpeed, int g, int lvl, int exp, bool wood, bool gold, bool diamond)
            : Character (BEAST, n, hp, attStength, attSpeed, g, lvl, exp, wood, gold, diamond) {};
    virtual void attack(Character &) override;
    virtual void enemyAttack(Character &) override;
    //virtual ~Beast() {}
};
#endif
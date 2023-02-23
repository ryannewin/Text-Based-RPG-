#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>

#ifndef __ELF_H__
#define __ELF_H__

#include "Character.h"

struct Bow  {
    int fireArrow; // 1.5x damage to enemy
    Bow(int fire) : fireArrow(fire) {}; //this->fireArrow = fire;
    // Bow (bool fire){
    //     this->fireArrow = fire;
    // }
};

class Elf:public Character {
    public:
        Elf(const string &n, int hp, int attStength, int attSpeed, int g, int lvl, int exp, int fire, bool wood, bool gold, bool diamond)
            : Character (ELF, n, hp, attStength, attSpeed, g, lvl, exp, wood, gold, diamond), bow(fire) {};
    Bow bow;
    virtual void attack(Character &) override;
    virtual void enemyAttack(Character &) override;
    void useFireArrow(Character &);
};
#endif
#include <iostream>
#include <vector>
#include <cstdlib>
#include<string>

#ifndef __KNIGHT_H__
#define __KNIGHT_H__

#include "Character.h"

// struct Sword  {
//     bool fireArrow; // 1.5x damage to enemy
//     Sword(bool fire) : fireArrow(fire) {}; //this->fireArrow = fire;
//     // Bow (bool fire){
//     //     this->fireArrow = fire;
//     // }
// };

class Knight:public Character {
    public:
        Knight(const string &n, int hp, int attStength, int attSpeed, int g, int lvl, int exp, bool wood, bool gold, bool diamond)
            : Character (KNIGHT, n, hp, attStength, attSpeed, g, lvl, exp, wood, gold, diamond) {};
    // Sword sword;
    virtual void attack(Character &) override;
    virtual void enemyAttack(Character &) override;
};
#endif
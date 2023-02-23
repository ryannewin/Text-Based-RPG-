#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>

#include "Character.h"
// struct Armor{
//     bool wood; 
//     bool gold;
//     bool diamond;
// };
Character::Character(HeroType ht, const string &n, int hp, int attStength, int attSpeed, int g, int lvl, int xp, bool woodArmor, bool goldArmor, bool diamondArmor){
    Type = ht;
    name = n;
    health = hp;
    attackStrength = attStength;
    attackSpeed = attSpeed;
    gold = g;
    level = lvl;
    exp = xp;
    Armor armor;
    armor.wood = woodArmor;
    armor.gold = goldArmor;
    armor.diamond = diamondArmor;
}
const string & Character::getName() const {
    return name;
}
int Character::getHealth() const {
    return health;
}
HeroType Character::getType() const {
    return Type;
}
void Character::damage(int d) {
    health -= d;
    cout << this->getName() << " takes " << d << " damage." << endl;
}
bool Character::isAlive() const {
    return getHealth() > 0;
}
int Character::getAttackStrength() const {
    return attackStrength;
}
int Character::getAttackSpeed() const {
    return attackSpeed;
}
int Character::getGold() const {
    return gold;
}
int Character::getLevel() const {
    return level;
}
int Character::getXP() const {
    return exp;
}
void Character::playerInfo(Character & h) const {
    cout << "Statistics for " << h.name << ":" << endl;
    cout << "Health: " << h.health << "/ 100" << endl;
    cout << "Damage: " << h.attackStrength << endl;
    cout << "Current Gold: " << h.gold << endl;
    //cout << "Current level: " << h.level << endl;
    //cout << "Current XP " << h.exp << endl;
}
// void Character::quickInfo() const {
//     cout << "Statistics for " << name << " the " << Type << ":" << endl;
//     cout << "Health: " << health << "/ 1000" << endl;
//     cout << "Damage: " << attackStrength;
// }
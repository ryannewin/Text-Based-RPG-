#include <string>

using namespace std;


#ifndef __CHARACTER_H__
#define __CHARACTER_H__

enum HeroType {KNIGHT, ELF, WIZARD, BEAST};

struct Armor{
    bool wood; 
    bool gold;
    bool diamond;
};

class Character {
    public:
        Armor armor;
        HeroType Type;
        string name;
        int health;
        int attackStrength;
        int attackSpeed;
        int gold;
        int level;
        int exp;
        Character(HeroType, const string &, int, int, int, int, int, int, bool, bool, bool);
        const string & getName() const;
        int getHealth() const;
        virtual void attack(Character &) = 0;
        virtual void enemyAttack(Character &) = 0;
        HeroType getType() const;
        void damage(int d);
        bool isAlive() const;
        int getAttackStrength() const;
        int getAttackSpeed() const;
        int getGold() const;
        int getLevel() const;
        int getXP() const;
        void playerInfo(Character&) const;
        //void quickInfo()  const;
};

#endif

// /* Main menu screen:
//     Press to enter a game;
//     Craft your character; hero type, and name

//     ...crafting character 
//     "Your character type and name starts out with clothes as armor

//     "You have been chosen by the (hero type) king to be set on a quest to find (type) princess who has been taken 
//     by the beast kingdom. The queen has given you a (weapon) and a set of clothes, and 1 small potion.

//     "You are currently in the (type) Kingdom: Would you like to go back the (type) Palace or head forward to the first town?"
//     Player chooses back: "Kind and queen are busy right now"
//     Forward: "You have entered town 1"
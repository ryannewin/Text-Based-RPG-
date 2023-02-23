#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <string>

#include "Knight.h"

void Knight::attack(Character &opponent){
    srand(time(0));
    int block = rand()%5; //20% of blocking
    int block1 = rand()%5;
    if (block == block1){
            cout << "The opponent blocked " << this->getName() << "'s attack!" << endl;
            return;
        }
    cout << this->getName() << " swings their sword at " << opponent.getType() << endl;
    opponent.health -= this->attackStrength;
}
void Knight::enemyAttack(Character &player){
    srand(time(0));
    int block = rand()%5; //20% of blocking
    int block1 = rand()%5;
    if (block == block1){
            cout << player.getName() << " blocked the " << this->getName() << "'s attack!" << endl;
            return;
    }
    int armorBuffer = 1;
    if (player.armor.wood == true){
        armorBuffer = .9;
        cout << "You are wearing wood armor! 10% block!" << endl;
    }
    else if (player.armor.gold == true){
        armorBuffer = .8;
        cout << "You are wearing gold armor! 20% block!" << endl;
    }
    else if (player.armor.diamond == true){
        armorBuffer = .7;
        cout << "You are wearing diamond armor! 30% block!" << endl;
    }
    else{
        cout << "Your character isn't wearing any armor!" << endl;
    }
    cout << "The " << this->getName() << " uses their sword and hits " << player.getName() << " with a powerful swing!" << endl;
    player.health -= armorBuffer*(this->attackStrength);
}
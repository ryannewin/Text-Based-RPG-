#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>

#include "Elf.h"

void Elf::attack(Character &opponent){
    cout << this->getName() << " shoots an arrow at " << opponent.getName() << endl;
    opponent.health -= this->attackStrength;
}
void Elf::enemyAttack(Character &player){
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

    cout << "The " << this->getName() << " uses their bow and hits " << player.getName() << " with an arrow!" << endl;
    player.health -= this->attackStrength;
}

//implement function for fire arrows: 1.5x damage, -1 firearrows
void Elf::useFireArrow(Character &opponent){ //enemies can't use fireArrows
    if (this->bow.fireArrow <= 0){
        cout << "You are out of fire arrows!" << endl;
        return;
    }
    cout << this->getName() << " shoots an arrow at " << opponent.getName() << endl;
    opponent.health -= 1.5*(this->attackStrength);
    this->bow.fireArrow--;
}
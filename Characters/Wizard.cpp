#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>

#include "Wizard.h"

void Wizard::attack(Character &opponent){
    if (this->wand.magicFuel <= 0){
        cout << "Out of magic fuel...can't attack" << endl;
        return;
    }
    cout << this->getName() << " aims their wand and blasts " << opponent.getName() << endl;
    opponent.health -= this->attackStrength;
    this->wand.magicFuel = this->wand.magicFuel - 5;
    cout << this->getName() << " used 5 magic fuel!" << endl;
}
void Wizard::enemyAttack(Character &player){
    if (this->wand.magicFuel <= 0){
        cout << "The enemy Wizard is out of magic fuel!" << endl;
        return;
    }
    cout << "The " << this->getName() << " uses their wand and casts a damage spell on " << player.getName() << endl;
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
    player.health -= armorBuffer*(this->attackStrength);
    this->wand.magicFuel = this->wand.magicFuel - 5;
    cout << "Enemy wizard used 5 magic fuel!" << endl;
}
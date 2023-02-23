#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <string>

#include "Beast.h"

void Beast::attack(Character & opponent){
    cout << "ERROR: Player can't choose Beast to play as." << endl;
}

void Beast::enemyAttack(Character &player){
    srand(time(0));
    int criticalHit = rand()%5; //20% critial hit x2 damage
    int criticalHit1 = rand()%5;
    if (criticalHit == criticalHit1){
            cout << "The beast got a critial hit on " << player.getName()<<  "!" << endl;
            player.health -= 2*(this->attackStrength);
    }
    else{

        cout << "The " << this->getName() << " growls and hits " << player.getName() << " with mighty force!" << endl;
        player.health -= this->attackStrength;
    }
}

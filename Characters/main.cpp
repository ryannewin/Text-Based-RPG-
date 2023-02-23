#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>

#include "Character.h"
#include "Knight.h"
#include "Wizard.h"
#include "Beast.h"
#include "Elf.h"
#include "Hospital.h"
#include "Armory.h"

using namespace std;

int main () {
    vector <Character*> player;

    cout << endl;
    cout << "------------------------ Welcome to Don't Slip: Save the Princess - Text Based RPG Game ------------------------" << endl;
    cout << "   Travel the journey as a hero of your choice and defeat the monsters that riddle the path that is to come!!" << endl; 
    cout << "                           Beware of the bananas on your quest to save the princess!" << endl;
    cout << endl;

    cout << "       --------------------------------------------------------------------------------------------------" << endl;
    cout << "       |                                           RULES:                                               |" << endl;
    cout << "       |                                                                                                |" << endl;
    cout << "       |   - If you die, your adventure comes to an end. You must start over!                           |" << endl;
    cout << "       |   - You can heal your character by going to the Hospital. It'll cost you some of your gold!    |" << endl;
    cout << "       |   - You will be given choices on how you want to explore the world!                            |" << endl;
    cout << "       --------------------------------------------------------------------------------------------------" << endl;
    
    string play;
    cout << endl << "Please type 'Play' to start the game" << endl;
    cin >> play;

    string characterType;
    string name;
    if (play == "Play" || "play") {
        cout << endl << "== Craft your character! ==" << endl; 

        cout << "Would you like to be a Wizard, Elf, or Knight? Please type your choice => ";
        cin >> characterType;
        cout << "Please enter your character's name: ";
        cin >> name;

        cout << endl << "== Hello " << name << " the " << characterType << "! == " << endl;
        cout << "   Your character starts out with clothes as armor, 0 gold, and a ";
    
        if (characterType == "Wizard") {
            player.push_back(new Wizard(name, 100, 25, 25, 0, 1, 0, 100, false, false, false));
            cout << "wand! You have 25 attack strength and 25 speed!" << endl;
        }
        else if (characterType == "Elf") {
            player.push_back(new Elf(name, 100, 15, 30, 0, 1, 0, 100, false, false, false));
            cout << "bow! You have 15 attack strength and 35 speed!" << endl;
        }
        else if (characterType == "Knight") {
            player.push_back(new Knight(name, 100, 20, 20, 0, 1, 0, false, false, false));
            cout << "sword! You have 20 attack strength and 20 speed!" << endl;
        }
    }
    

    cout << endl << "       You have been chosen by the " << characterType << " king to find the " << characterType << " princess taken by the Banana kingdom!" << endl;
    cout << "           Your journey into the world now begins! Don't Slip " << name <<  " the " << characterType << ", Save the Princess! "<< endl;

    cout << endl << "                  ~~~~~~~~~~~~~~~~~~~~ You have now entered Town of Bananas! ~~~~~~~~~~~~~~~~~~~~" << endl << endl;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cout << "Please type where you want to go below!" << endl;
    cout << "Left? Right? Hospital? Armory?" << endl;

    string choice1;
    cin >> choice1;

    cout << endl << "You have selected " << choice1 << "!" << endl << endl;

    if (choice1 == "Left") {
        cout << "   Oops! You slipped on a banana!! You lost 5 HP!" << endl;
        player.at(0)->health -= 5;
        if (player.at(0)->health <= 0) {
            cout << "   You have died! Beware of the bananas! Please play again!" << endl;
            for (int i = 0; i < player.size(); ++i) {
                delete player.at(i);
            }
            exit(1);
        }
        else {
            cout << "   You now have " << player.at(0)->health << " health! Beware of the bananas!" << endl;
        }
    }

    else if (choice1 == "Right") {
        cout << "   Oh no! A Fat Banana the Beast is blocking the way! Defeat the beast to continue!!" << endl;
        Beast b = Beast("Fat Banana", 120, 15, 10, 0, 1, 0, false, false, false);

        while (int x = 1) {
            player.at(0)->attack(b);
            player.at(0)->attack(b);
            b.enemyAttack(*player.at(0));
            if (!b.isAlive() || !player.at(0) -> isAlive()) {
                break;
            }
        }
        if (player.at(0) -> isAlive()) {
            cout << endl << "   You defeated the " << b.getName() << "! You earned 100 gold!" << endl;
            player.at(0)->gold += 100;
            player.at(0) -> playerInfo(*player.at(0));
            //add stats
        }
        else {
            cout << endl << "   You died! Please play again!" << endl;
            for (int i = 0; i < player.size(); ++i) {
                delete player.at(i);
            }
            exit(1);
        }
    }
    else if (choice1 == "Hospital") {
        Hospital Hospital;
        Hospital.HealPlayer(*player.at(0));
    }
    else if (choice1 == "Armory") {
        Armory Armory;
        Armory.listOPS(*player.at(0));

    }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cout << endl << "Please type where you want to go below!" << endl;
    cout << "Left? Right? Hospital? Armory?" << endl;

    string choice2;
    cin >> choice2;

    cout << endl << "You have selected " << choice2 << "!" << endl << endl;

    if (choice2 == "Left") {
        cout << "   Along your journey.. you helped a man with some food and you received 20 gold!!" << endl;
        player.at(0)->gold += 20;
        cout << "   You now have " << player.at(0)->gold << " gold!" << endl;
    }

    else if (choice2 == "Right") {
        cout << "   Oops! You slipped on a pile of bananas!! You lost 10 HP!" << endl;
        player.at(0)->health -= 10;
        if (player.at(0)->health <= 0) {
            cout << "   You have died! Beware of the bananas! Please play again!" << endl;
            for (int i = 0; i < player.size(); ++i) {
                delete player.at(i);
            }
            exit(1);
        }
        else {
        cout << "   You now have " << player.at(0)->health << " health! Beware of the bananas!" << endl;
        }
    }
    else if (choice2 == "Hospital") {
        Hospital Hospital;
        Hospital.HealPlayer(*player.at(0));
    }
    else if (choice2 == "Armory") {
        Armory Armory;
        Armory.listOPS(*player.at(0));

    }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cout << endl << "Please type where you want to go below!" << endl;
    cout << "Left? Right? Hospital? Armory?" << endl;

    string choice3;
    cin >> choice3;

    cout << endl << "You have selected " << choice3 << "!" << endl << endl;

    if (choice3 == "Left") {
        cout << "   Oh no! An evil Wizard controlled by the Banana Kingdom is blocking the path! Defeat the evil!! " << endl;
        Wizard enemy = Wizard("Evil Wizard", 120, 30, 10, 0, 1, 1, 100, false, false, false);
        while (int x = 1) {
            player.at(0)->attack(enemy);
            player.at(0)->attack(enemy);
            enemy.enemyAttack(*player.at(0));
            if (!enemy.isAlive() || !player.at(0) -> isAlive()) {
                break;
            }
        }
        if (player.at(0) -> isAlive()) {
            cout << endl << "   You defeated the " << enemy.getName() << "! You earned 100 gold!" << endl;
            player.at(0)->gold += 100;
            player.at(0) -> playerInfo(*player.at(0));
        }
        else {
            cout << endl << "   You died! Please play again!" << endl;
            for (int i = 0; i < player.size(); ++i) {
                delete player.at(i);
            }
            exit(1);
        }
    }

    else if (choice3 == "Right") {
        cout << "   Oh no! An evil Elf controlled by the Banana Kingdom is blocking the path! Defeat the evil!! " << endl;
        Elf enemy = Elf("Evil Elf", 120, 30, 10, 0, 1, 1, 100, false, false, false);
        while (int x = 1) {
            player.at(0)->attack(enemy);
            player.at(0)->attack(enemy);
            enemy.enemyAttack(*player.at(0));
            if (!enemy.isAlive() || !player.at(0) -> isAlive()) {
                break;
            }
        }
        if (player.at(0) -> isAlive()) {
            cout << endl << "   You defeated the " << enemy.getName() << "! You earned 100 gold!" << endl;
            player.at(0)->gold += 100;
        }
        else {
            cout << endl << "   You died! Please play again!" << endl;
            for (int i = 0; i < player.size(); ++i) {
                delete player.at(i);
            }
            exit(1);
        }
    }
    else if (choice3 == "Hospital") {
        Hospital Hospital;
        Hospital.HealPlayer(*player.at(0));
    }
    else if (choice3 == "Armory") {
        Armory Armory;
        Armory.listOPS(*player.at(0));

    }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  
    cout << endl << "                  ~~~~~~~~~~~~~~~~~~~~ You have now entered Town of Peels! ~~~~~~~~~~~~~~~~~~~~" << endl << endl;

    cout << "Please type where you want to go below!" << endl;
    cout << "Left? Right? Hospital? Armory?" << endl;

    string choice4;
    cin >> choice4;

    cout << endl << "You have selected " << choice4 << "!" << endl << endl;

    if (choice4 == "Left") {
                cout << "   Oh no! An evil Knight controlled by the Banana Kingdom is blocking the path! Defeat the evil!! " << endl;
        Knight enemy = Knight("Evil Knight", 120, 30, 10, 0, 1, 1, false, false, false);
        while (int x = 1) {
            player.at(0)->attack(enemy);
            player.at(0)->attack(enemy);
            enemy.enemyAttack(*player.at(0));
            if (!enemy.isAlive() || !player.at(0) -> isAlive()) {
                break;
            }
        }
        if (player.at(0) -> isAlive()) {
            cout << endl << "   You defeated the " << enemy.getName() << "! You earned 100 gold!" << endl;
            player.at(0)->gold += 100;
            player.at(0) -> playerInfo(*player.at(0));
        }
        else {
            cout << endl << "   You died! Please play again!" << endl;
            for (int i = 0; i < player.size(); ++i) {
                delete player.at(i);
            }
            exit(1);
        }
    }

    else if (choice4 == "Right") {
        cout << "   Oh no! A Fat Banana the Beast is blocking the way! Defeat the beast to continue!!" << endl;
        Beast b = Beast("Fat Banana", 120, 15, 10, 0, 1, 0, false, false, false);

        while (int x = 1) {
            player.at(0)->attack(b);
            player.at(0)->attack(b);
            b.enemyAttack(*player.at(0));
            if (!b.isAlive() || !player.at(0) -> isAlive()) {
                break;
            }
        }
        if (player.at(0) -> isAlive()) {
            cout << endl << "   You defeated the " << b.getName() << "! You earned 100 gold!" << endl;
            player.at(0)->gold += 100;
            player.at(0) -> playerInfo(*player.at(0));
        }
        else {
            cout << endl << "   You died! Please play again!" << endl;
            for (int i = 0; i < player.size(); ++i) {
                delete player.at(i);
            }
            exit(1);
        }
    }
    else if (choice4 == "Hospital") {
        Hospital Hospital;
        Hospital.HealPlayer(*player.at(0));
    }
    else if (choice4 == "Armory") {
        Armory Armory;
        Armory.listOPS(*player.at(0));

    }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cout << endl << "Please type where you want to go below!" << endl;
    cout << "Left? Right? Hospital? Armory?" << endl;

    string choice5;
    cin >> choice5;

    cout << endl << "You have selected " << choice5 << "!" << endl << endl;

    if (choice5 == "Left") {
        cout << "   Oh no! A Fat Banana the Beast is blocking the way! Defeat the beast to continue!!" << endl;
        Beast b = Beast("Fat Banana", 120, 15, 10, 0, 1, 0, false, false, false);

        while (int x = 1) {
            player.at(0)->attack(b);
            player.at(0)->attack(b);
            b.enemyAttack(*player.at(0));
            if (!b.isAlive() || !player.at(0) -> isAlive()) {
                break;
            }
        }
        if (player.at(0) -> isAlive()) {
            cout << endl << "   You defeated the " << b.getName() << "! You earned 100 gold!" << endl;
            player.at(0)->gold += 100;
            player.at(0) -> playerInfo(*player.at(0));
        }
        else {
            cout << endl << "   You died! Please play again!" << endl;
            for (int i = 0; i < player.size(); ++i) {
                delete player.at(i);
            }
            exit(1);
        }
    }

    else if (choice5 == "Right") {
        cout << "   Oops! You slipped on a pile of bananas!! You lost 10 HP!" << endl;
        player.at(0)->health -= 10;
        if (player.at(0)->health <= 0) {
            cout << "   You have died! Beware of the bananas! Please play again!" << endl;
            for (int i = 0; i < player.size(); ++i) {
                delete player.at(i);
            }
            exit(1);
        }
        else {
            cout << "   You now have " << player.at(0)->health << " health! Beware of the bananas!" << endl;
        }
    }
    else if (choice5 == "Hospital") {
        Hospital Hospital;
        Hospital.HealPlayer(*player.at(0));
    }
    else if (choice5 == "Armory") {
        Armory Armory;
        Armory.listOPS(*player.at(0));

    }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cout << endl << "Please type where you want to go below!" << endl;
    cout << "Left? Right? Hospital? Armory?" << endl;

    string choice6;
    cin >> choice6;

    cout << endl << "You have selected " << choice6 << "!" << endl << endl;

    if (choice6 == "Left") {
        cout << "   Oh no! An evil Wizard controlled by the Banana Kingdom is blocking the path! Defeat the evil!! " << endl;
        Wizard enemy = Wizard("Evil Wizard", 120, 30, 10, 0, 1, 1, 100, false, false, false);
        while (int x = 1) {
            player.at(0)->attack(enemy);
            player.at(0)->attack(enemy);
            enemy.enemyAttack(*player.at(0));
            if (!enemy.isAlive() || !player.at(0) -> isAlive()) {
                break;
            }
        }
        if (player.at(0) -> isAlive()) {
            cout << endl << "   You defeated the " << enemy.getName() << "! You earned 100 gold!" << endl;
            player.at(0)->gold += 100;
            player.at(0) -> playerInfo(*player.at(0));
        }
        else {
            cout << endl << "   You died! Please play again!" << endl;
            for (int i = 0; i < player.size(); ++i) {
                delete player.at(i);
            }
            exit(1);
        }
    }
    else if (choice6 == "Right") {
        cout << "   Oops! You slipped on a banana!! You lost 5 HP!" << endl;
        player.at(0)->health -= 5;
        if (player.at(0)->health <= 0) {
            cout << "   You have died! Beware of the bananas! Please play again!" << endl;
            for (int i = 0; i < player.size(); ++i) {
                delete player.at(i);
            }
            exit(1);
        }
        else {
            cout << "   You now have " << player.at(0)->health << " health! Beware of the bananas!" << endl;
        }
    }
    else if (choice6 == "Hospital") {
        Hospital Hospital;
        Hospital.HealPlayer(*player.at(0));
    }
    else if (choice6 == "Armory") {
        Armory Armory;
        Armory.listOPS(*player.at(0));

    }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  
    cout << endl << "              ~~~~~~~~~~~~~~~~~~~~ You have now found the Banana Beast Kingdom! ~~~~~~~~~~~~~~~~~~~~" << endl << endl;
            cout << "                                           You saved the Princess!!! " << endl;

for (int i = 0; i < player.size(); ++i) {
    delete player.at(i);
}

 return 0;
}



#include <iostream>

#include "Armory.h"
#include "Character.h"
//#include "Knight.h"

void Armory :: listOPS (Character& h) {
    int userChoice = 0;

    cout << "--------------- Hello! Welcome to the Armory! ---------------" << endl; 
    cout << "              What would you like to purchase?" << endl;

    while (userChoice == 0) {
        cout << endl;
        cout << "Please press 1 to buy wooden armor for 10 gold.." << endl;
        cout << "Please press 2 to buy golden armor for 25 gold.." << endl;
        cout << "Please press 3 to buy diamond armor for 50 gold.." << endl;
        cout << "Please press 4 to buy attack potion for 60 gold.." << endl;
        cout << "Please press 5 to buy attack speed potion for 60 gold.." << endl;
        cout << "Please press 6 to exit armory" << endl;
        
        cin >> userChoice;

        if (userChoice == 1) {
            if (h.gold < 10) {
                cout << endl << "   You do not have enough funds, please start over." << endl;
                userChoice = 0;
                continue; 
            }
            cout << "   You have selected wooden armor. This will cost 10 gold." << endl;
            h.gold -= 10;
            h.armor.wood = true;
            h.armor.gold = false;
            h.armor.diamond = false;
        } 

        if (userChoice == 2) {
            if (h.gold < 50) {
                cout << endl << "   You do not have enough funds, please start over." << endl;
                userChoice = 0;
                continue; 
            }
            cout << endl << "   You have selected gold armor. This will cost 25 gold." << endl;
            h.gold -= 25;
            h.armor.wood = false;
            h.armor.gold = true;
            h.armor.diamond = false;
        } 


        if (userChoice == 3) {
            if (h.gold < 50) {
                cout << endl << "   You do not have enough funds, please start over." << endl;
                userChoice = 0;
                continue; 
            }
            cout << endl << "   You have selected diamond armor. This will cost 50 gold." << endl;
            h.gold -= 50;
            h.armor.wood = false;
            h.armor.gold = false;
            h.armor.diamond = true;
        } 

        if (userChoice == 4) {
            if (h.gold < 60) {
                cout << endl << "   You do not have enough funds, please start over." << endl;
                userChoice = 0;
                continue;
            }
            cout << endl << "   You have selected attack potion. This will cost 60 gold." << endl;
            h.attackStrength += 10;
        } 

        if (userChoice == 5) {
            if (h.gold < 60) {
                cout << endl << "   You do not have enough funds, please start over." << endl;
                userChoice = 0;
                continue;
            }
            cout << endl << "   You have selected attack speed potion. This will cost 60 gold." << endl;
            h.attackSpeed += 10;
        } 
        if (userChoice == 6) {
            cout << endl << "   Come again soon!" << endl;
            return;
        }
        
    }
}

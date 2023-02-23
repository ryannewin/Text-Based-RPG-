#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>

#include "Hospital.h"

void Hospital :: HealPlayer(Character& player) {
    
    cout << "--------------- Hello! Welcome to the Hospital! ---------------" << endl; 
    cout << "   It costs 25 gold to heal your character to full health." << endl;
    cout << "       Would you like to spend your gold? 'Yes' or 'No' " << endl;
    string answer;
    cin >> answer;

    if (player.health != 100) {
        if (player.gold >= 25) {
            if (answer == "Yes") {
                player.gold -= 25;
                player.health = 100;

                cout << "Your health is now 100 and you have " << player.gold << " remaining. Thank you! Come again!" << endl; 
                }
            else {
                cout << "You picked not to spend your gold. Your health is " << player.health << ". You have " << player.gold << " gold. Come again!" << endl; 
            }
        }
        else {
            if (answer == "Yes") { 
                cout << "I'm sorry you do not have enough gold. Your health is " << player.health << ". You have " << player.gold << " gold. Continue fighting to get more gold and come again!" << endl;
            }
            else { 
                cout << "You picked not to spend your gold. Your health is " << player.health << ". You have " << player.gold << " gold. Come again!" << endl; 
            }
        }  

    }
    else {
        cout << "   Your health is already 100. Come again!" << endl;
    }
}
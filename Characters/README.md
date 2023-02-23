[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-c66648af7eb3fe8bc4f294546bfd86ef473780cde1dea487d3c4ff354943c9ae.svg)](https://classroom.github.com/online_ide?assignment_repo_id=8941489&assignment_repo_type=AssignmentRepo)
# Don't Slip, Save the Princess - Text Based RPG Game
 > Authors:
 > Ryan Nguyen, Charlize Esparza, Sachin Chopra, Byron Bhuiyan

## Project Description

 Project Name: Don't Slip, Save the Princess - Text Based RPG Game

 #### Group Members: 
 
 > * Ryan Nguyen (rnguy135): https://github.com/ryannewin 
 > * Charlize Esparza (cespa014): https://github.com/charlize23 
 > * Sachin Chopra (schop021): https://github.com/SafeDuck 
 > * Byron Bhuiyan (rbhui003): https://github.com/AgentEinstein

 #### Project:
 
 > * We all enjoy playing games and a couple of years ago, one of our members found this Discord bot that adds a text based RPG game into the server and they thought it would be interesting to make our own version of the game in the terminal with our own unique spin. 
 > * Our game has a banana themed aspect and your goal is to survive, upgrade, and heal in order to save the Princess from the evil kingdom.
 > * We would input different types of commands like “attack” and in return it would output the amount of damage dealt and the health remaining of the creature being attacked, along with a message describing the attack between the two characters.
 > * The user can fight both beasts and other Evil Wizards, Elves, and Knights that became controlled by the Banana Kingdom holding the Princess. 
 > * Along with many functions and paths that allow the user to have more creative control and choose where they want to go. 
 > * The project provides users with an entertaining text based game that tracks and explores the journey of a character of your choosing. 
 
 #### Languages/Tools/Techniques:
 
 > * C++
 > * Visual Studio Code
 > * Git
 > * Valgrind 
 > * Github
 > * Diagrams.net - To create UML Diagram
 > * Cmake
 > * Google Test Framework 
 
 #### Program inputs/outputs:
 
 > Inputs - After running the program, the user will be prompted with options that allow them to start playing the game, choose the class of character they would like to play as, and pick the name for their character. Finally to play the game, our game will take in user input that allows them to either turn left, right, go to the hospital, or go to the armory throughout the story. 

 > Outputs - The program starts by prompting the user with an “introduction” screen that shows all the rules and the storyline of the game. After it takes in the initial user inputs, it will provide a story line of what happens after a user chooses to go to a certain location such as the enemies they face or the attack sequence between the user’s character and any enemies. Finally, it will print a specific statement of when the user dies or if they do not die and successfully finish the game and rescue the princess. 
 
## Class Diagram 
 [![Screen-Shot-2022-11-28-at-11-46-15-PM.png](https://i.postimg.cc/J40F2cjT/Screen-Shot-2022-11-28-at-11-46-15-PM.png)](https://postimg.cc/SJ0VX9T8)
 
 > The UML diagram depicts a character class that acts as the “parent” class from which all other character-type classes (“child classes”) inherit from. This character class includes variables such as health, gold, xp, etc. which are traits of the classes that inherit from it including Wizard, Elf, Knight, and Beast (Note: The beast is not a playable character, it is only an opponent). When a Character is constructed, an armor set is automatically constructed too using an armor struct. Each type of character has a unique feature; For the beast and knight class they have a 20% chance of landing a critical hit and blocking respectively. However, for elf and wizard, their special features are unique to their weapons - bow and wand. The bow has fire arrows and the wand has magic fuel. These characters also have their own virtual function that allows them to attack opponents and for the opponents to attack the player. The Armory and Hospital class modify character data, so they have a direct association with the Character class. The armory is a shop for the character to purchase armor upgrades and potions with their gold that they earn from fighting opponents. Finally, the hospital class allows for the character to replenish their health for gold.
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 
 > * Running cmake . and make
 [![demo1.png](https://i.postimg.cc/fRtZdp7d/demo1.png)](https://postimg.cc/75kp8BWP)
 > * Running ./gamex and intro screen to create character
 [![demo2.png](https://i.postimg.cc/cHZNVJp7/demo2.png)](https://postimg.cc/Lqy7Pm6h)
 > * Entering first town, going right, defeating beast, and displaying player stats after beating enemy
 [![demo3.png](https://i.postimg.cc/VNX8GtVL/demo3.png)](https://postimg.cc/gwcQrxpf)
 > * Visiting the armory and buying armor
 [![demo4.png](https://i.postimg.cc/2SsY7GTK/demo4.png)](https://postimg.cc/jD4BszpH)
 > * Visiting the hospital and healing your character
 [![demo5.png](https://i.postimg.cc/qMWSPRnt/demo5.png)](https://postimg.cc/BXcmDJms)
 > * Going right and slipping on banana, then going left and defeating an Evil Wizard along with showing player stats, and end game screen
 [![demo6.png](https://i.postimg.cc/hvfZwWtb/demo6.png)](https://postimg.cc/FkXxd6c7)
 
 ## Installation/Usage
 > Instructions on installing and running your application
 
Using git, clone the repository below, and `cd` into it to gain access to the our game>

```
git clone https://github.com/cs100/final-project-cespa014-rnguy135-schop021-rbhui003.git
```
This project uses 'cmake' and 'make'. Install these tools then run the following commands to ceate the executables.

```
cmake .
make
```

Executables created:

```
test
gamex
```

Then run the executable to start the game:

```
./gamex
```

 ## Testing
 > After following the instructions in the **Installation/Usage** section to generate the executables, running `./test` will run the unit tests for this program. We have a total of 28 unit tests across 6 test suites. The first two unit tests test whether the player says "Yes" or "No" for the hospital. For the unit tests to pass, intially type "Yes" when asked if you want to spend your gold, then type "No". The rest of the unit tests should execute with valgrind. 
 
 > We also used Valgrind to make sure that there were no memory leaks in the program. You can still run valgrind with `cmake .` and `make`, then run `$ valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./test` to check valgrind and unit tests at the same time. 
 
  <details><summary>Example of the valgrind results and googleTests</summary>
<p>

```$ valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./test
==395868== Memcheck, a memory error detector
==395868== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==395868== Using Valgrind-3.19.0 and LibVEX; rerun with -h for copyright info
==395868== Command: ./test
==395868== 
[==========] Running 28 tests from 6 test suites.
[----------] Global test environment set-up.
[----------] 2 tests from HospitalTests
[ RUN      ] HospitalTests.Htest1
--------------- Hello! Welcome to the Hospital! ---------------
   It costs 25 gold to heal your character to full health.
       Would you like to spend your gold? 'Yes' or 'No' 
Yes
Your health is now 100 and you have 0 remaining. Thank you! Come again!
[       OK ] HospitalTests.Htest1 (8563 ms)
[ RUN      ] HospitalTests.Htest2
--------------- Hello! Welcome to the Hospital! ---------------
   It costs 25 gold to heal your character to full health.
       Would you like to spend your gold? 'Yes' or 'No' 
No
You picked not to spend your gold. Your health is 80. You have 20 gold. Come again!
[       OK ] HospitalTests.Htest2 (2326 ms)
[----------] 2 tests from HospitalTests (10900 ms total)

[----------] 4 tests from WizardTests
[ RUN      ] WizardTests.WtestConstructor1
[       OK ] WizardTests.WtestConstructor1 (3 ms)
[ RUN      ] WizardTests.WtestConstructor2
[       OK ] WizardTests.WtestConstructor2 (2 ms)
[ RUN      ] WizardTests.WizardAttack
Rakesh aims their wand and blasts Patel
Rakesh used 5 magic fuel!
[       OK ] WizardTests.WizardAttack (5 ms)
[ RUN      ] WizardTests.EnemyAttacksWizard
The Patel uses their wand and casts a damage spell on Rakesh
You are wearing wood armor! 10% block!
Enemy wizard used 5 magic fuel!
[       OK ] WizardTests.EnemyAttacksWizard (5 ms)
[----------] 4 tests from WizardTests (18 ms total)

[----------] 5 tests from ElfTests
[ RUN      ] ElfTests.EtestConstructor1
[       OK ] ElfTests.EtestConstructor1 (3 ms)
[ RUN      ] ElfTests.EtestConstructor2
[       OK ] ElfTests.EtestConstructor2 (2 ms)
[ RUN      ] ElfTests.ElfAttack
Rakesh shoots an arrow at Patel
[       OK ] ElfTests.ElfAttack (4 ms)
[ RUN      ] ElfTests.EnemyAttacksElf

You are wearing wood armor! 10% block!
The Patel uses their bow and hits Rakesh with an arrow!
[       OK ] ElfTests.EnemyAttacksElf (5 ms)
[ RUN      ] ElfTests.UseFlamingArrowButYouHaveNone
[       OK ] ElfTests.UseFlamingArrowButYouHaveNone (3 ms)
[----------] 5 tests from ElfTests (20 ms total)

[----------] 2 tests from KnightTests
[ RUN      ] KnightTests.KTestConstructor1
[       OK ] KnightTests.KTestConstructor1 (2 ms)
[ RUN      ] KnightTests.KTestConstructor2
[       OK ] KnightTests.KTestConstructor2 (2 ms)
[----------] 2 tests from KnightTests (6 ms total)

[----------] 2 tests from BeastTests
[ RUN      ] BeastTests.testConstructor
[       OK ] BeastTests.testConstructor (3 ms)
[ RUN      ] BeastTests.testConstructor2
[       OK ] BeastTests.testConstructor2 (2 ms)
[----------] 2 tests from BeastTests (6 ms total)

[----------] 13 tests from CharacterTests
[ RUN      ] CharacterTests.testconstructor
[       OK ] CharacterTests.testconstructor (2 ms)
[ RUN      ] CharacterTests.testgetName
[       OK ] CharacterTests.testgetName (2 ms)
[ RUN      ] CharacterTests.testgetHealth
[       OK ] CharacterTests.testgetHealth (2 ms)
[ RUN      ] CharacterTests.testattack
NAME aims their wand and blasts EMAN
NAME used 5 magic fuel!
[       OK ] CharacterTests.testattack (3 ms)
[ RUN      ] CharacterTests.testenemyattack
The EMAN uses their wand and casts a damage spell on NAME
You are wearing wood armor! 10% block!
Enemy wizard used 5 magic fuel!
[       OK ] CharacterTests.testenemyattack (4 ms)
[ RUN      ] CharacterTests.testgetType
[       OK ] CharacterTests.testgetType (3 ms)
[ RUN      ] CharacterTests.testdamage
NAME takes 10 damage.
[       OK ] CharacterTests.testdamage (3 ms)
[ RUN      ] CharacterTests.testisAlive
[       OK ] CharacterTests.testisAlive (3 ms)
[ RUN      ] CharacterTests.testgetAttackStrength
[       OK ] CharacterTests.testgetAttackStrength (2 ms)
[ RUN      ] CharacterTests.testgetAttackSpeed
[       OK ] CharacterTests.testgetAttackSpeed (2 ms)
[ RUN      ] CharacterTests.testgetGold
[       OK ] CharacterTests.testgetGold (2 ms)
[ RUN      ] CharacterTests.testgetLevel
[       OK ] CharacterTests.testgetLevel (2 ms)
[ RUN      ] CharacterTests.testgetXP
[       OK ] CharacterTests.testgetXP (2 ms)
[----------] 13 tests from CharacterTests (42 ms total)

[----------] Global test environment tear-down
[==========] 28 tests from 6 test suites ran. (11068 ms total)
[  PASSED  ] 28 tests.
==395868== 
==395868== HEAP SUMMARY:
==395868==     in use at exit: 0 bytes in 0 blocks
==395868==   total heap usage: 575 allocs, 575 frees, 160,005 bytes allocated
==395868== 
==395868== All heap blocks were freed -- no leaks are possible
==395868== 
==395868== For lists of detected and suppressed errors, rerun with: -s
==395868== ERROR SUMMARY: 3 errors from 3 contexts (suppressed: 0 from 0)
```

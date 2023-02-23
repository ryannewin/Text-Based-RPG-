#include <gtest/gtest.h>
#include "Character.h"
#include "Hospital.h"
#include "Armory.h"
#include "Wizard.h"
#include "Elf.h"
#include "Knight.h"
#include "Beast.h"
TEST(HospitalTests, Htest1){
    Knight chad = Knight("Chad", 80, 15, 10, 25, 1, 0, false, false, false);
    Hospital bottomFeeder;
    bottomFeeder.HealPlayer(chad);
    EXPECT_EQ(chad.getGold(), 0);
    EXPECT_EQ(chad.getHealth(), 100); // test with yes
}
TEST(HospitalTests, Htest2){
    Knight tim = Knight("Tim", 80, 15, 10, 20, 1, 0, false, false, false);
    Hospital bottomFeeder;
    bottomFeeder.HealPlayer(tim);
    EXPECT_EQ(tim.getGold(), 20);
    EXPECT_EQ(tim.getHealth(), 80); // test with no
}

TEST(WizardTests, WtestConstructor1){
    Wizard punjeet = Wizard("Punjeet", 80, 15, 10, 0, 1, 5, 6, false, false, false);
    EXPECT_EQ(punjeet.getName(), "Punjeet");
}
TEST(WizardTests, WtestConstructor2){
    Wizard punjeet = Wizard("The other Punjeet", 80, 15, 10, 0, 1, 5, 6, false, false, false);
    EXPECT_EQ(punjeet.getGold(), 0);
}
TEST(WizardTests, WizardAttack){
    Wizard rakesh = Wizard("Rakesh", 80, 15, 10, 0, 1, 5, 6, false, false, false);
    Beast patel = Beast("Patel", 80, 15, 10, 0, 1, 0, false, false, false);
    rakesh.attack(patel);
    //EXPECT_EQ(rakesh.fuel, 1);
    EXPECT_EQ(patel.getHealth(), 65);
}
TEST(WizardTests, EnemyAttacksWizard){
    Wizard rakesh = Wizard("Rakesh", 80, 15, 10, 0, 1, 5, 6, true, false, false);
    Wizard patel = Wizard("Patel", 80, 15, 10, 0, 1, 5, 6, false, false, false);
    patel.enemyAttack(rakesh);
    //EXPECT_EQ(patel.fuel, 1);
    EXPECT_EQ(rakesh.getHealth(), 80);
}
TEST(ElfTests, EtestConstructor1){
    Elf punjeet = Elf("Punjeet", 80, 15, 10, 0, 1, 5, 6, false, false, false);
    EXPECT_EQ(punjeet.getHealth(), 80);
}
TEST(ElfTests, EtestConstructor2){
    Elf punjeet = Elf("The other Punjeet", 80, 15, 10, 0, 1, 5, 6, false, false, false);
    EXPECT_EQ(punjeet.getGold(), 0);
}
TEST(ElfTests, ElfAttack){
    Elf rakesh = Elf("Rakesh", 80, 15, 10, 0, 1, 5, 6, false, false, false);
    Beast patel = Beast("Patel", 80, 15, 10, 0, 1, 0, false, false, false);
    rakesh.attack(patel);
    EXPECT_EQ(patel.getHealth(), 65);
}
TEST(ElfTests, EnemyAttacksElf){
    Elf rakesh = Elf("Rakesh", 80, 15, 10, 0, 1, 5, 6, false, false, false);
    Elf patel = Elf("Patel", 80, 15, 10, 0, 1, 5, 6, false, false, false);
    patel.enemyAttack(rakesh);
    EXPECT_EQ(rakesh.getHealth(), 65);
}
TEST(ElfTests, UseFlamingArrowButYouHaveNone){
    Elf rakesh = Elf("Rakesh", 80, 15, 10, 0, 1, 5, 0, false, false, false);
    Elf patel = Elf("Patel", 80, 15, 10, 0, 1, 5, 6, false, false, false);
    EXPECT_EQ(patel.getHealth(), 80);
}
TEST(KnightTests, KTestConstructor1){
    Knight punjeet = Knight("Punjeet", 80, 15, 10, 20, 1, 0, false, false, false);
    EXPECT_EQ(punjeet.getHealth(), 80);
}
TEST(KnightTests, KTestConstructor2){
    Knight punjeet = Knight("Punjeet", 80, 15, 10, 20, 1, 0, false, false, false);
    EXPECT_EQ(punjeet.getGold(), 20);
}

TEST (BeastTests, testConstructor) {
    Beast hero = Beast("NAME", 120, 15, 10, 0, 1, 0, false, false, false);
    EXPECT_EQ (hero.name, "NAME");
}

TEST (BeastTests, testConstructor2) {
    Beast hero = Beast("EMAN", 120, 15, 10, 0, 1, 0, false, false, false);
    EXPECT_EQ (hero.name, "EMAN");
}


TEST (CharacterTests, testconstructor) {
    Knight k = Knight("NAME", 120, 15, 10, 0, 1, 0, false, false, false);
    EXPECT_EQ (k.name,"NAME");
}

TEST (CharacterTests, testgetName) {
    Knight k = Knight("NAME", 120, 15, 10, 0, 1, 0, false, false, false);
    EXPECT_EQ (k.getName(),"NAME");
}
TEST (CharacterTests, testgetHealth) {
    Knight k = Knight("NAME", 120, 15, 10, 0, 1, 0, false, false, false);
    EXPECT_EQ (k.getHealth(), 120);
}
TEST (CharacterTests, testattack) {
    Wizard k = Wizard("NAME", 120, 15, 10, 0, 1, 0, 1, false, false, false);
    Wizard l = Wizard("EMAN", 120, 15, 10, 0, 1, 0, 1, false, false, false);
    k.attack(l);
    EXPECT_EQ(l.health, 105);
}
TEST (CharacterTests, testenemyattack) {
    Wizard k = Wizard("NAME", 120, 15, 10, 0, 1, 0, 1, true, false, false);
    Wizard l = Wizard("EMAN", 120, 15, 10, 0, 1, 0, 1,false, false, false);
    l.enemyAttack(k);
    EXPECT_EQ(k.health, 120);
}
TEST (CharacterTests, testgetType) {
    Knight k = Knight("NAME", 120, 15, 10, 0, 1, 0, false, false, false);
    EXPECT_EQ(k.getType(), 0);
}
TEST (CharacterTests, testdamage) {
    Knight k = Knight("NAME", 120, 15, 10, 0, 1, 0, false, false, false);
    k.damage(10);
    EXPECT_EQ(k.health, 110);
}
TEST (CharacterTests, testisAlive) {
    Knight k = Knight("NAME", 120, 15, 10, 0, 1, 0, false, false, false);
    EXPECT_EQ(k.isAlive(), true);
}
TEST (CharacterTests, testgetAttackStrength) {
    Knight k = Knight("NAME", 120, 15, 10, 0, 1, 0, false, false, false);
    EXPECT_EQ(k.getAttackStrength(), 15);
}
TEST (CharacterTests, testgetAttackSpeed) {
    Knight k = Knight("NAME", 120, 15, 10, 0, 1, 0, false, false, false);
    EXPECT_EQ(k.getAttackSpeed(), 10);
}
TEST (CharacterTests, testgetGold) {
    Knight k = Knight("NAME", 120, 15, 10, 0, 1, 0, false, false, false);
    EXPECT_EQ(k.getGold(), 0);

}
TEST (CharacterTests, testgetLevel) {
    Knight k = Knight("NAME", 120, 15, 10, 0, 1, 0, false, false, false);
    EXPECT_EQ(k.getLevel(), 1);
}
TEST (CharacterTests, testgetXP) {
    Knight k = Knight("NAME", 120, 15, 10, 0, 1, 0, false, false, false);
    EXPECT_EQ(k.getXP(), 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

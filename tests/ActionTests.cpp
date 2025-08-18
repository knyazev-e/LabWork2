/* Kniazeva Eva Andreevna
st128104@student.spbu.ru
labwork2: rpg game */

#include "../source/Action.h"
#include "../source/Dodge.h"
#include "../source/Distract.h"
#include "../source/Equip.h"
#include "../source/StatModifyingAction.h"
#include "../source/Spell.h"
#include "../source/Character.h"
#include "../source/Battle.h"
#include "../source/Item.h"
#include "gtest/gtest.h"

TEST(ActionTest, InitializationTest) {
    Action a("Test Action", "desc", 5);
    EXPECT_EQ(a.getName(), "Test Action");
    EXPECT_EQ(a.getDesc(), "desc");
    EXPECT_EQ(a.getManaUsage(), 5);
}

TEST(DodgeTest, ManaChangeTest) {
    Character c("Char", 1, 100, 50, 10, 5, 5);
    Dodge dodge("Dodge", "desc", 5);
    int originalMana = c.getMana();
    dodge.attempt(c);
    EXPECT_LT(c.getMana(), originalMana);
}

TEST(DistractTest, TurnBlockTest) {
    Character c("Char", 1, 100, 50, 10, 5, 5);
    Battle battle;
    Distract distract("Distract", "desc", 5);
    distract.execute(c, c, battle, nullptr, c);
    EXPECT_EQ(battle.get_turn_block(), 2);
}

TEST(EquipTest, EquippinTest) {
    Character performer("Performer", 1, 100, 50, 10, 5, 5);
    Character target("Target", 1, 100, 50, 10, 5, 5);
    Battle battle;
    auto armour = std::make_shared<Armour>("Shield", "desc", 10, 2, 3, 5);
    Equip equip("Equip", "desc", 0);
    equip.execute(performer, target, battle, armour, target);
    EXPECT_EQ(target.getArmour()->getName(), "Shield");
}

/* Kniazeva Eva Andreevna
st128104@student.spbu.ru
labwork2: rpg game */

#include "../source/Character.h"
#include "../source/Player.h"
#include "../source/Bard.h"
#include "../source/Druid.h"
#include "../source/Knight.h"
#include "../source/Wizard.h"
#include "gtest/gtest.h"

TEST(CharacterTest, InitializationTest) {
    Character c("Char", 5, 100, 50, 20, 15, 5);
    EXPECT_EQ(c.getName(), "Char");
    EXPECT_EQ(c.getHealth(), 100);
    EXPECT_EQ(c.getMana(), 50);
    EXPECT_EQ(c.getCid(), 5);
}

TEST(PlayerTest, ItemTest) {
    Player player;
    EXPECT_EQ(player.getItem(), nullptr);
    auto item = std::make_shared<Item>("Potion", "desc", -1, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    player.setItem(item);
    EXPECT_NE(player.getItem(), nullptr);
    EXPECT_EQ(player.getItem()->getName(), "Potion");
}

TEST(BardTest, LuckTest) {
    Bard bard;
    bard.setLuck(0.5);
    EXPECT_DOUBLE_EQ(bard.getLuck(), 0.5);
}

TEST(DruidTest, HealingBonusTest) {
    Druid druid;
    druid.setHealingBonus(10);
    EXPECT_EQ(druid.getHealingBonus(), 10);
}

TEST(KnightTest, CritChanceTest) {
    Knight knight;
    knight.setCritChance(0.3);
    EXPECT_DOUBLE_EQ(knight.getCritChance(), 0.3);
}

TEST(WizardTest, IntelligenceTest) {
    Wizard wizard;
    wizard.setIntelligence(12);
    EXPECT_EQ(wizard.getIntelligence(), 12);
}

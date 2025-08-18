/* Kniazeva Eva Andreevna
st128104@student.spbu.ru
labwork2: rpg game */

#include "../source/Item.h"
#include "../source/Armour.h"
#include "../source/Weapon.h"
#include "gtest/gtest.h"

TEST(ItemTest, InitializationTest) {
    Item item("Potion", "desc", 10, 0, 5, 2, 3, 4, 0.1, 1, 0.01, 7);
    EXPECT_EQ(item.getName(), "Potion");
    EXPECT_EQ(item.getDurability(), 10);
    EXPECT_EQ(item.getManaBonus(), 3);
    EXPECT_GT(item.getLuckBonus(), 0);
}

TEST(ArmourTest, WeightTest) {
    Armour armour("Shield", "desc", 20, 5, 1, 10);
    EXPECT_EQ(armour.getWeight(), 10);
    armour.setWeight(15);
    EXPECT_EQ(armour.getWeight(), 15);
}

TEST(WeaponTest, LevelTest) {
    Weapon weapon("Sword", "desc", 30, 3, 7, 0.05, 2);
    EXPECT_EQ(weapon.getLevel(), 2);
    weapon.setLevel(5);
    EXPECT_EQ(weapon.getLevel(), 5);
}

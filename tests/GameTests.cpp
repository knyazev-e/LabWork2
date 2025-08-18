/* Kniazeva Eva Andreevna
st128104@student.spbu.ru
labwork2: rpg game */

#include "../source/Game.h"
#include "../source/Battle.h"
#include "../source/Statistics.h"
#include "../source/EnemyAI.h"
#include "../source/Player.h"
#include "../source/Enemy.h"
#include "gtest/gtest.h"

TEST(GameTest, InitializationTest) {
    Game game;
    EXPECT_FALSE(game.getState());
    game.init_characters();
    auto chars = game.getCharacters();
    EXPECT_EQ(chars.size(), 4);
    EXPECT_EQ(chars[0]->getName(), "Bard");
    EXPECT_EQ(chars[3]->getName(), "Wizard");
}

TEST(BattleTest, InitializationTest) {
    Battle battle;
    EXPECT_TRUE(battle.get_turn());
    battle.set_turn(false);
    EXPECT_FALSE(battle.get_turn());
    EXPECT_EQ(battle.get_turn_block(), 0);
}

TEST(EnemyAITest, ActionChoiceTest) {
    EnemyAI ai;
    Player player("Test", 0, 80, 50, 15, 10, 10, "desc", nullptr);
    Enemy enemy;
    Battle battle;
    int action = ai.chooseAction(player, enemy, battle);
    EXPECT_GE(action, 0);
    EXPECT_LT(action, 6);
}

TEST(StatisticsTest, InitialStats) {
    Statistics stats;
    EXPECT_EQ(stats.get_score(), 0);
    EXPECT_EQ(stats.get_games(), 0);
}


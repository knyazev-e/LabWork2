/* Kniazeva Eva Andreevna
st128104@student.spbu.ru
labwork2: rpg game */

#include "../source/Game.h"
#include "../source/Character.h"
#include "../source/Action.h"
#include "../source/Battle.h"
#include "../source/Item.h"
#include "gtest/gtest.h"

TEST(InteractionTest, ActionUsageTest) {
    Game game;
    game.init_characters();
    game.init_items(game.getCharacters()[0], game.getCharacters()[1], game.getCharacters()[2], game.getCharacters()[3]);
    game.init_actions(game.getCharacters()[0], game.getCharacters()[1], game.getCharacters()[2], game.getCharacters()[3]);

    Character& attacker = *(game.getCharacters()[0]);
    Character& target = *(game.getCharacters()[1]);
    Battle battle;

    auto action = game.getGeneralActions()[1];

    int targetHealthBefore = target.getHealth();
    action->execute(attacker, target, battle, nullptr, target);
    EXPECT_LT(target.getHealth(), targetHealthBefore);
}

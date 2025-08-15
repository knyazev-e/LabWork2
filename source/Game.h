#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <cstdlib>
#include "Battle.h"
#include "Player.h"
#include "Statistics.h"
#include "Enemy.h"
#include "EnemyAI.h"
#include "Action.h"
#include "StatModifyingAction.h"
#include "Dodge.h"
#include "Distract.h"
#include "Equip.h"
#include "Spell.h"
#include "Bard.h"
#include "Druid.h"
#include "Knight.h"
#include "Wizard.h"
#include "ConstVariables.h"


class Game {
public:
    Game();

    void start();
    void quit();
    void start_battle();
    void edit_character();
    void settings();
    void leaderboard();
    void display();
    void init_characters();
    void init_items(std::shared_ptr<Player> bard, std::shared_ptr<Player> druid, std::shared_ptr<Player> knight, std::shared_ptr<Player> wizard);
    void init_actions(std::shared_ptr<Player> bard, std::shared_ptr<Player> druid, std::shared_ptr<Player> knight, std::shared_ptr<Player> wizard);
    bool is_numeric(std::string& input);
    void exit_battle();

protected:
    Battle battle;
    std::shared_ptr<Player> player;
    Enemy enemy;
    Statistics statistics;
    EnemyAI enemy_ai;
    int state;
    int difficulty;
    bool is_running;
    std::vector<std::shared_ptr<Player>> characters;
    std::vector<std::shared_ptr<Item>> general_items;
    std::vector<std::shared_ptr<Item>> enemy_items;
    std::vector<std::shared_ptr<Action>> general_actions;
};

#endif

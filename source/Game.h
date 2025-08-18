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

/**
 * @class Game
 * @brief Main game class controlling state, characters, battles, and user interaction.
 */
class Game {
public:
    /**
     * @brief Default constructor initializes game state.
     */
    Game();

    /**
     * @brief Starts the main game loop.
     */
    void start();

    /**
     * @brief Quits the game and stops the game loop.
     */
    void quit();

    /**
     * @brief Starts a battle session.
     */
    void start_battle();

    /**
     * @brief Puts game into character edit mode.
     */
    void edit_character();

    /**
     * @brief Opens settings menu.
     */
    void settings();

    /**
     * @brief Displays leaderboard or game statistics.
     */
    void leaderboard();

    /**
     * @brief Displays the current screen based on game state.
     */
    void display();

    /**
     * @brief Initializes the available player characters.
     */
    void init_characters();

    /**
     * @brief Initializes items associated with player classes and enemies.
     * @param bard Bard player instance.
     * @param druid Druid player instance.
     * @param knight Knight player instance.
     * @param wizard Wizard player instance.
     */
    void init_items(std::shared_ptr<Player> bard, std::shared_ptr<Player> druid,
                    std::shared_ptr<Player> knight, std::shared_ptr<Player> wizard);

    /**
     * @brief Initializes actions available to player classes and general actions.
     * @param bard Bard player instance.
     * @param druid Druid player instance.
     * @param knight Knight player instance.
     * @param wizard Wizard player instance.
     */
    void init_actions(std::shared_ptr<Player> bard, std::shared_ptr<Player> druid,
                      std::shared_ptr<Player> knight, std::shared_ptr<Player> wizard);

    /**
     * @brief Checks if a string input is numeric.
     * @param input String input.
     * @return True if numeric, false otherwise.
     */
    bool is_numeric(std::string& input);

    /**
     * @brief Exits from battle and resets battle-related state.
     */
    void exit_battle();



    /**
     * @brief Gets the current state indicating if the game is running.
     * @return True if the game is running, false otherwise.
     */
    bool getState() const;

    /**
     * @brief Gets the list of all player characters available in the game.
     * @return Const reference to a vector of shared pointers to Player objects.
     */
    const std::vector<std::shared_ptr<Player>>& getCharacters() const;

    /**
     * @brief Gets the general actions available in the game.
     * @return Const reference to a vector of shared pointers to Action objects.
     */
    const std::vector<std::shared_ptr<Action>>& getGeneralActions() const;


protected:
    Battle battle;                               ///< Battle session instance
    std::shared_ptr<Player> player;              ///< Current player character
    Enemy enemy;                                 ///< Current enemy character
    Statistics statistics;                       ///< Game statistics tracking
    EnemyAI enemy_ai;                            ///< Enemy AI logic handler
    int state;                                  ///< Current game state indicator
    int difficulty;                             ///< Difficulty setting
    bool is_running;                            ///< Flag to keep game loop running
    std::vector<std::shared_ptr<Player>> characters; ///< All player character options
    std::vector<std::shared_ptr<Item>> general_items; ///< Items available generally
    std::vector<std::shared_ptr<Item>> enemy_items; ///< Items available to enemy
    std::vector<std::shared_ptr<Action>> general_actions; ///< General actions available
};

#endif

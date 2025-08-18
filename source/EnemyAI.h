/* Kniazeva Eva Andreevna
st128104@student.spbu.ru
labwork2: rpg game */

#ifndef ENEMYAI_H
#define ENEMYAI_H

#include <memory>
#include "ConstVariables.h"
#include "Player.h"
#include "Enemy.h"
#include "Battle.h"

/**
 * @class EnemyAI
 * @brief Implements logic for enemy action decision-making during battle.
 */
class EnemyAI {
public:
    /**
     * @brief Default constructor.
     */
    EnemyAI();

    /**
     * @brief Chooses the next action for the enemy given player, enemy, and battle state.
     * @param player The player character.
     * @param enemy The enemy character.
     * @param battle Current battle context.
     * @return Index code representing the chosen action.
     */
    int chooseAction(Player& player, Enemy& enemy, Battle& battle);
};

#endif

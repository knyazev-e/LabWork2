/* Kniazeva Eva Andreevna
st128104@student.spbu.ru
labwork2: rpg game */

#ifndef BATTLE_H
#define BATTLE_H

#include <vector>
#include <memory>
#include <random>
#include <string>
#include "Action.h"
#include "Enemy.h"

/**
 * @class Battle
 * @brief Manages battle state, actions, items, and calculates damage in the game.
 */
class Battle {
public:
    /**
     * @brief Constructs a Battle with default settings.
     */
    Battle();

    /**
     * @brief Sets the current turn indicator.
     * @param turn True if it is player's turn, false otherwise.
     */
    void set_turn(bool turn);

    /**
     * @brief Gets the current turn indicator.
     * @return True if player's turn, false otherwise.
     */
    bool get_turn() const;

    /**
     * @brief Sets the count of turn blocks (to skip turns).
     * @param n Number of turn blocks.
     */
    void set_turn_block(int n);

    /**
     * @brief Gets the current number of turn blocks.
     * @return Integer turn block count.
     */
    int get_turn_block();

    /**
     * @brief Sets the report message code.
     * @param m Message code index.
     */
    void setReportMessage(int m);

    /**
     * @brief Gets the current report message code.
     * @return Message code index.
     */
    int getReportMessage();

    /**
     * @brief Calculates damage from performer to target based on stats and items.
     * @param performer Character performing the attack.
     * @param target Character targeted.
     * @return Calculated damage as integer.
     */
    int calculate_damage(Character& performer, Character& target);

    /**
     * @brief Determines whether the attack is critical based on chance.
     * @param performer Character performing the attack.
     * @return True if critical hit, false otherwise.
     */
    bool is_critical(Character& performer);

    /**
     * @brief Checks if performer has enough mana for the given action.
     * @param performer Character performing the action.
     * @param action Action to be performed.
     * @return True if enough mana, false otherwise.
     */
    bool is_enough_mana(Character& performer, Action& action);

    /**
     * @brief Sets the list of available actions in this battle.
     * @param a Vector of shared pointers to actions.
     */
    void setActionsCatalogue(std::vector<std::shared_ptr<Action>> a);

    /**
     * @brief Gets the list of available actions in this battle.
     * @return Const reference to vector of shared pointers to actions.
     */
    const std::vector<std::shared_ptr<Action>>& getActionsCatalogue();

    /**
     * @brief Sets the list of available items in this battle.
     * @param i Vector of shared pointers to items.
     */
    void setItemsCatalogue(std::vector<std::shared_ptr<Item>> i);

    /**
     * @brief Gets the list of available items in this battle.
     * @return Const reference to vector of shared pointers to items.
     */
    const std::vector<std::shared_ptr<Item>>& getItemsCatalogue();

protected:
    bool turn; ///< True if it is the player's turn
    int turn_block; ///< Number of remaining turns blocked
    int report_message; ///< Current report message index
    std::vector<std::shared_ptr<Action>> actions_catalogue; ///< Available actions
    std::vector<std::shared_ptr<Item>> items_catalogue; ///< Available items
};

#endif

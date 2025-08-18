/* Kniazeva Eva Andreevna
st128104@student.spbu.ru
labwork2: rpg game */

#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"
#include "Action.h"
#include "ConstVariables.h"

/**
 * @class Enemy
 * @brief Represents an enemy character in the game with AI-specific attributes.
 *
 * Inherits from Character with additional attributes like critical chance,
 * equipping flags, and next planned action.
 */
class Enemy : public Character {
public:
    /**
     * @brief Default constructor for Enemy with initial standard stats.
     */
    Enemy();

    /**
     * @brief Constructs an Enemy with specific attributes.
     * @param name Name of the enemy.
     * @param health Health points.
     * @param mana Mana points.
     * @param attack_power Attack power.
     * @param defence Defense rating.
     * @param hr Healing rate.
     * @param crit_chance Probability of critical hit.
     * @param equipping_flag Flag indicating item equipping status.
     * @param nxt_act Next planned action for the enemy.
     */
    Enemy(const std::string& name,
          int health,
          int mana,
          int attack_power,
          int defence,
          int hr,
          double crit_chance,
          int equipping_flag,
          std::shared_ptr<Action> nxt_act);

    /**
     * @brief Destructor.
     */
    ~Enemy();

    /**
     * @brief Sets the critical chance for the enemy.
     * @param chance Critical hit probability.
     */
    void setCritChance(double chance);

    /**
     * @brief Gets the critical chance for the enemy.
     * @return Critical hit probability.
     */
    double getCritChance() const;

    /**
     * @brief Sets the equipping flag indicating item equip status.
     * @param f Flag value.
     */
    void setEquippingFlag(int f);

    /**
     * @brief Gets the equipping flag.
     * @return Equipping flag value.
     */
    int getEquippingFlag();

    /**
     * @brief Sets the next planned action for the enemy.
     * @param act Shared pointer to the action.
     */
    void setNextAction(std::shared_ptr<Action> act);

    /**
     * @brief Gets the next planned action.
     * @return Shared pointer to next action.
     */
    std::shared_ptr<Action> getNextAction() const;

protected:
    double crit_chance;                ///< Enemy critical hit chance
    int equipping_flag;                ///< Enemy equip flag
    std::shared_ptr<Action> next_action; ///< Enemy's next planned action
};

#endif

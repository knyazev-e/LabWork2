/* Kniazeva Eva Andreevna
st128104@student.spbu.ru
labwork2: rpg game */

#ifndef DRUID_H
#define DRUID_H

#include "Player.h"

/**
 * @class Druid
 * @brief Player class representing a Druid with healing bonus ability.
 *
 * Inherits from Player and adds healing bonus.
 */
class Druid : public Player {
public:
    /**
     * @brief Constructs a Druid with specified attributes and healing bonus.
     * @param name Character name.
     * @param health Health points.
     * @param mana Mana points.
     * @param attack_power Attack power.
     * @param defence Defense rating.
     * @param hr Healing rate.
     * @param desc Description.
     * @param item Starting item.
     * @param healing_bonus Additional healing bonus.
     */
    Druid(const std::string& name,
          int health,
          int mana,
          int attack_power,
          int defence,
          int hr,
          const std::string& desc,
          std::shared_ptr<Item> item,
          int healing_bonus);

    /**
     * @brief Default constructor initializing standard Druid stats.
     */
    Druid();

    /**
     * @brief Destructor.
     */
    ~Druid();

    /**
     * @brief Sets the healing bonus.
     * @param bonus Healing bonus value.
     */
    void setHealingBonus(int bonus) override;

    /**
     * @brief Gets the healing bonus.
     * @return Healing bonus value.
     */
    int getHealingBonus() const override;

    /**
     * @brief Clones the Druid object polymorphically.
     * @return Shared pointer to copied Druid.
     */
    std::shared_ptr<Player> clone() const override;

protected:
    int healing_bonus; ///< Additional healing bonus of the Druid
};

#endif

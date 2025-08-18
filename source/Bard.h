/* Kniazeva Eva Andreevna
st128104@student.spbu.ru
labwork2: rpg game */

#ifndef BARD_H
#define BARD_H

#include "Player.h"

/**
 * @class Bard
 * @brief Player class representing a Bard character with a luck attribute.
 *
 * Inherits from Player and adds luck functionality.
 */
class Bard : public Player {
public:
    /**
     * @brief Constructs a Bard with specific attributes.
     * @param name Character name.
     * @param health Health points.
     * @param mana Mana points.
     * @param attack_power Attack power.
     * @param defence Defense value.
     * @param hr Healing rate.
     * @param desc Description text.
     * @param item Starting item.
     * @param luck Luck factor affecting probabilities.
     */
    Bard(const std::string& name,
         int health,
         int mana,
         int attack_power,
         int defence,
         int hr,
         const std::string& desc,
         std::shared_ptr<Item> item,
         double luck);

    /**
     * @brief Default constructor for Bard with initial standard stats.
     */
    Bard();

    /**
     * @brief Destructor.
     */
    ~Bard();

    /**
     * @brief Sets luck value.
     * @param luck Luck value to set.
     */
    void setLuck(double luck) override;

    /**
     * @brief Gets the current luck value.
     * @return Luck value.
     */
    double getLuck() const override;

    /**
     * @brief Creates a polymorphic clone of the Bard object.
     * @return Shared pointer to a copy of this Bard.
     */
    std::shared_ptr<Player> clone() const override;

protected:
    double luck; ///< Luck factor affecting character abilities
};

#endif

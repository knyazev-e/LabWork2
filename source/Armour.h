/* Kniazeva Eva Andreevna
st128104@student.spbu.ru
labwork2: rpg game */

#ifndef ARMOUR_H
#define ARMOUR_H

#include "Item.h"

/**
 * @class Armour
 * @brief Represents a piece of armour in the game, providing defense and weight.
 *
 * Inherits from Item and adds a weight attribute.
 */
class Armour : public Item {
public:
    /**
     * @brief Constructs an Armour object.
     * @param name Name of the armour piece.
     * @param desc Description of the armour.
     * @param durability Durability value.
     * @param defence_bonus Defense bonus provided by the armour.
     * @param attack_bonus Attack bonus provided by the armour.
     * @param weight Weight of the armour.
     */
    Armour(const std::string& name,
           const std::string& desc,
           int durability,
           int defence_bonus,
           int attack_bonus,
           int weight);

    /**
     * @brief Sets the weight of the armour.
     * @param weight New weight value.
     */
    void setWeight(int weight);

    /**
     * @brief Gets the weight of the armour.
     * @return Weight value.
     */
    int getWeight() const;

protected:
    int weight; ///< Weight of the armour
};

#endif

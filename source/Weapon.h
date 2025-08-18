/* Kniazeva Eva Andreevna
st128104@student.spbu.ru
labwork2: rpg game */

#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include "Item.h"

/**
 * @class Weapon
 * @brief Represents a weapon item with additional level attribute.
 *
 * Inherits from Item.
 */
class Weapon : public Item {
public:
    /**
     * @brief Constructs a Weapon with specified attributes.
     * @param name Weapon name.
     * @param desc Weapon description.
     * @param durability Durability value.
     * @param defence_bonus Defense bonus.
     * @param attack_bonus Attack bonus.
     * @param crit_chance_bonus Critical chance bonus.
     * @param lvl Weapon level.
     */
    Weapon(const std::string& name,
           const std::string& desc,
           int durability,
           int defence_bonus,
           int attack_bonus,
           double crit_chance_bonus,
           int lvl);

    /**
     * @brief Sets the weapon's level.
     * @param lvl Level to set.
     */
    void setLevel(int lvl);

    /**
     * @brief Gets the weapon's level.
     * @return Weapon level.
     */
    int getLevel() const;

protected:
    int level; ///< Weapon level
};

#endif

/* Kniazeva Eva Andreevna
st128104@student.spbu.ru
labwork2: rpg game */

#ifndef STATMODIFYINGACTION_H
#define STATMODIFYINGACTION_H

#include "Action.h"
#include "Battle.h"

/**
 * @class StatModifyingAction
 * @brief Action that modifies character stats such as health, mana, attack, or defense.
 */
class StatModifyingAction : public Action {
public:
    /**
     * @brief Constructs a StatModifyingAction.
     * @param name Name of the action.
     * @param desc Description of the action.
     * @param mana Mana cost.
     * @param modified_stat Stat identifier to modify.
     * @param quantity Quantity to modify stat by (positive or negative).
     */
    StatModifyingAction(const std::string& name, const std::string& desc, int mana, int modified_stat, int quantity);

    /**
     * @brief Sets the stat to be modified.
     * @param stat Stat ID.
     */
    void setModifiedStat(int stat);

    /**
     * @brief Gets the stat to be modified.
     * @return Stat ID.
     */
    int getModifiedStat() const;

    /**
     * @brief Sets the quantity for stat modification.
     * @param quantity Amount to modify.
     */
    void setQuantity(int quantity);

    /**
     * @brief Gets the quantity of stat modification.
     * @return Amount of modification.
     */
    int getQuantity() const;

    /**
     * @brief Executes the stat modification action on the target character.
     * @param performer Character performing the action.
     * @param target Character targeted.
     * @param battle Current battle context.
     * @param item Optional item used.
     * @param item_target Character affected by item.
     */
    void execute(Character& performer, Character& target, Battle& battle, std::shared_ptr<Item>, Character&) override;

protected:
    int modified_stat; ///< Stat identifier to modify
    int quantity;      ///< Amount to modify the stat
};

#endif

#ifndef EQUIP_H
#define EQUIP_H

#include "Action.h"

/**
 * @class Equip
 * @brief Action to equip an item, weapon, or armour on a character.
 *
 * Derived from Action.
 */
class Equip : public Action {
public:
    /**
     * @brief Constructs an Equip action.
     * @param name Name of the action.
     * @param description Description of the action.
     * @param mana Mana cost (usually 0).
     */
    Equip(const std::string& name, const std::string& description, int mana);

    /**
     * @brief Executes the equip action on the target character.
     * @param performer Character performing equip.
     * @param unused Unused target character (not used).
     * @param battle Current battle context.
     * @param item Item to equip.
     * @param item_target Character receiving the item.
     */
    void execute(Character& performer, Character&, Battle&, std::shared_ptr<Item> item, Character& item_target) override;
};

#endif

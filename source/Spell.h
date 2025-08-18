#ifndef SPELL_H
#define SPELL_H

#include <random>
#include <cmath>
#include "Action.h"

/**
 * @class Spell
 * @brief Represents a spell action with effect based on intelligence and attack power.
 *
 * Derived from Action.
 */
class Spell : public Action {
public:
    /**
     * @brief Constructs a Spell action.
     * @param name Name of the spell.
     * @param desc Description of the spell.
     * @param mana Mana cost for casting.
     */
    Spell(const std::string& name, const std::string& desc, int mana);

    /**
     * @brief Executes the spell's effect targeting a character within a battle.
     * @param performer Character casting the spell.
     * @param target Target character.
     * @param battle Current battle context.
     * @param item Optional item involved in spell effect.
     * @param item_target Character receiving the item effect.
     */
    void exucute(Character& performer, Character& target, Battle& battle, std::shared_ptr<Item> item, Character& item_target);
};

#endif

#ifndef DISTRACT_H
#define DISTRACT_H

#include "Action.h"
#include "Battle.h"

/**
 * @class Distract
 * @brief Action that causes the opponent to skip their next turn.
 *
 * Derived from Action class.
 */
class Distract : public Action {
public:
    /**
     * @brief Constructs a Distract action.
     * @param name Action name.
     * @param desc Action description.
     * @param mana Mana cost.
     */
    Distract(const std::string& name, const std::string& desc, int mana);

    /**
     * @brief Executes the distraction, setting the turn block in the battle.
     * @param performer Character performing the action.
     * @param unused Target character (not used).
     * @param battle Reference to the battle.
     * @param unused Item used (not used).
     * @param unused Character item target (not used).
     */
    void execute(Character& performer, Character&, Battle& battle, std::shared_ptr<Item>, Character&) override;
};

#endif

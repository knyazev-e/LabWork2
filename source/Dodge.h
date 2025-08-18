#ifndef DODGE_H
#define DODGE_H

#include <random>
#include "Action.h"

/**
 * @class Dodge
 * @brief Action that attempts to dodge an opponent’s attack with a probabilistic success.
 */
class Dodge: public Action {
public:
    /**
     * @brief Constructs a Dodge action.
     * @param name Action name.
     * @param desc Description of action.
     * @param mana Mana cost.
     */
    Dodge(const std::string& name, const std::string& desc, int mana);

    /**
     * @brief Attempts to perform the dodge action.
     * @param performer Character attempting the dodge.
     * @return True if dodge is successful, false otherwise.
     */
    bool attempt(Character& performer) override;
};

#endif

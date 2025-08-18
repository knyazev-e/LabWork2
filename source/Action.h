/* Kniazeva Eva Andreevna
st128104@student.spbu.ru
labwork2: rpg game */

#ifndef ACTION_H
#define ACTION_H

#include <string>
#include "Character.h"
#include "Item.h"
class Battle;

/**
 * @class Action
 * @brief Represents a generic action in the game with a name, description, and mana cost.
 *
 * Base class for specific actions that characters can perform during battle.
 */
class Action {
public:
    /**
     * @brief Constructs an Action.
     * @param name Name of the action.
     * @param desc Description of the action.
     * @param mana Mana cost to perform the action.
     */
    Action(const std::string& name, const std::string& desc, int mana);

    /**
     * @brief Destructor.
     */
    virtual ~Action();

    /**
     * @brief Sets the name of the action.
     * @param name New name to set.
     */
    void setName(const std::string& name);

    /**
     * @brief Gets the action name.
     * @return Reference to the action's name.
     */
    const std::string& getName() const;

    /**
     * @brief Sets the description for the action.
     * @param desc New description.
     */
    void setDesc(const std::string& desc);

    /**
     * @brief Gets the action description.
     * @return Reference to the description string.
     */
    const std::string& getDesc();

    /**
     * @brief Sets the mana cost for the action.
     * @param mana Mana usage to set.
     */
    void setManaUsage(int mana);

    /**
     * @brief Gets the mana cost to perform the action.
     * @return Integer mana usage.
     */
    int getManaUsage();

    /**
     * @brief Executes the action.
     * @param performer Character performing the action.
     * @param target Character targeted by the action.
     * @param battle Current battle context.
     * @param item Optional item used during the action.
     * @param item_target Character receiving the item effect.
     */
    virtual void execute(Character&, Character&, Battle&, std::shared_ptr<Item>, Character&);

    /**
     * @brief Attempts to perform the action, may include success probability.
     * @param performer Character attempting the action.
     * @return True on success, false otherwise.
     */
    virtual bool attempt(Character&);

protected:
    std::string name;        ///< Action name
    std::string description; ///< Description of what the action does
    int mana_usage;          ///< Mana points required to perform the action
};

#endif

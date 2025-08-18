#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include "Item.h"
#include "Action.h"
#include "ConstVariables.h"
#include <stdexcept>
#include <vector>
#include <memory>

/**
 * @class Player
 * @brief Represents a player character, inheriting from Character.
 *
 * Contains inventory items and actions specific to player subclasses.
 */
class Player : public Character {
public:
    /**
     * @brief Default constructor.
     */
    Player();

    /**
     * @brief Constructs a player with customized parameters.
     * @param name Character name.
     * @param cid Class ID.
     * @param health Health points.
     * @param mana Mana points.
     * @param attack_power Attack power.
     * @param defence Defense rating.
     * @param hr Healing rate.
     * @param desc Description text.
     * @param item Starting item.
     */
    Player(const std::string& name,
           int cid,
           int health,
           int mana,
           int attack_power,
           int defence,
           int hr,
           const std::string& desc,
           std::shared_ptr<Item> item);

    /**
     * @brief Destructor.
     */
    ~Player();

    /**
     * @brief Sets an equipped item.
     * @param i Item to equip.
     */
    void setItem(std::shared_ptr<Item> i) override;

    /**
     * @brief Gets the equipped item.
     * @return Pointer to equipped item.
     */
    std::shared_ptr<Item> getItem() const override;

    /**
     * @brief Sets the class description.
     * @param desc Description string.
     */
    void setDesc(const std::string& desc);

    /**
     * @brief Returns the class description.
     * @return Description string.
     */
    std::string getDesc();

    /**
     * @brief Sets the class-specific items available.
     * @param v Vector of item pointers.
     */
    void setClassItems(const std::vector<std::shared_ptr<Item>>& v);

    /**
     * @brief Returns class-specific items.
     * @return Vector of item pointers.
     */
    const std::vector<std::shared_ptr<Item>>& getClassItems();

    /**
     * @brief Sets the class-specific actions available.
     * @param v Vector of action pointers.
     */
    void setClassActions(const std::vector<std::shared_ptr<Action>>& v);

    /**
     * @brief Returns class-specific actions.
     * @return Vector of action pointers.
     */
    const std::vector<std::shared_ptr<Action>>& getClassActions();

    /**
     * @brief Clones the player object.
     * @return Shared pointer to a copy of this Player.
     */
    virtual std::shared_ptr<Player> clone() const;

protected:
    std::vector<std::shared_ptr<Item>> class_items;     ///< Items specific to this player class
    std::vector<std::shared_ptr<Action>> class_actions; ///< Actions specific to this player class
    std::shared_ptr<Item> item;                          ///< Currently equipped item
    std::string description;                             ///< Class description
};

#endif

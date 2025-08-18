#ifndef KNIGHT_H
#define KNIGHT_H

#include "Player.h"

/**
 * @class Knight
 * @brief Player class representing a Knight character with critical chance attribute.
 *
 * Inherits from Player and adds critical chance functionality.
 */
class Knight : public Player {
public:
    /**
     * @brief Constructs a Knight with given parameters.
     * @param name Character name.
     * @param health Health points.
     * @param mana Mana points.
     * @param attack_power Attack power.
     * @param defence Defense rating.
     * @param hr Healing rate.
     * @param desc Description.
     * @param item Starting item.
     * @param crit_chance Critical hit chance.
     */
    Knight(const std::string& name,
           int health,
           int mana,
           int attack_power,
           int defence,
           int hr,
           const std::string& desc,
           std::shared_ptr<Item> item,
           double crit_chance);

    /**
     * @brief Default constructor for Knight with initial stats.
     */
    Knight();

    /**
     * @brief Destructor.
     */
    ~Knight();

    /**
     * @brief Sets the critical chance.
     * @param chance Critical hit chance value.
     */
    void setCritChance(double chance) override;

    /**
     * @brief Gets the critical chance.
     * @return Critical hit chance value.
     */
    double getCritChance() const override;

    /**
     * @brief Clones the Knight object.
     * @return Shared pointer to a copy of this Knight.
     */
    std::shared_ptr<Player> clone() const override;

protected:
    double crit_chance; ///< Critical hit chance
};

#endif

/* Kniazeva Eva Andreevna
st128104@student.spbu.ru
labwork2: rpg game */

#ifndef WIZARD_H
#define WIZARD_H

#include "Player.h"

/**
 * @class Wizard
 * @brief Player class representing a Wizard with intelligence attribute.
 *
 * Inherits from Player and adds intelligence functionality.
 */
class Wizard : public Player {
public:
    /**
     * @brief Constructs a Wizard with specific stats.
     * @param name Character name.
     * @param health Health points.
     * @param mana Mana points.
     * @param attack_power Attack value.
     * @param defence Defense value.
     * @param hr Healing rate.
     * @param desc Description string.
     * @param item Starting item.
     * @param intelligence Intelligence stat.
     */
    Wizard(const std::string& name,
           int health,
           int mana,
           int attack_power,
           int defence,
           int hr,
           const std::string& desc,
           std::shared_ptr<Item> item,
           int intelligence);

    /**
     * @brief Default constructor initializing base Wizard stats.
     */
    Wizard();

    /**
     * @brief Destructor.
     */
    ~Wizard();

    /**
     * @brief Sets the intelligence attribute.
     * @param intel New intelligence value.
     */
    void setIntelligence(int intel) override;

    /**
     * @brief Gets the intelligence attribute.
     * @return Intelligence value.
     */
    int getIntelligence() const override;

    /**
     * @brief Clones the Wizard object.
     * @return Shared pointer to a copied Wizard.
     */
    std::shared_ptr<Player> clone() const override;

protected:
    int intelligence; ///< Intelligence stat
};

#endif

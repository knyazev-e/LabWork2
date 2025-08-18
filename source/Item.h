/* Kniazeva Eva Andreevna
st128104@student.spbu.ru
labwork2: rpg game */

#ifndef ITEM_H
#define ITEM_H

#include <string>

/**
 * @class Item
 * @brief Represents an item that characters can equip or use, with various stat bonuses.
 */
class Item {
public:
    /**
     * @brief Constructs an Item with specified attributes.
     * @param name Item name.
     * @param desc Item description.
     * @param durability Durability of the item.
     * @param type Item type code.
     * @param health_bonus Health bonus given by the item.
     * @param defence_bonus Defense bonus.
     * @param mana_bonus Mana bonus.
     * @param attack_bonus Attack bonus.
     * @param luck_bonus Luck bonus.
     * @param hb_bonus Healing bonus.
     * @param crit_chance_bonus Critical chance bonus.
     * @param int_bonus Intelligence bonus.
     */
    Item(const std::string& name,
         const std::string& desc,
         int durability,
         int type,
         int health_bonus,
         int defence_bonus,
         int mana_bonus,
         int attack_bonus,
         double luck_bonus,
         int hb_bonus,
         double crit_chance_bonus,
         int int_bonus);

    /**
     * @brief Destructor.
     */
    virtual ~Item();

    /**
     * @brief Sets the name of the item.
     * @param n New name.
     */
    void setName(const std::string& n);

    /**
     * @brief Gets the name of the item.
     * @return Const reference to name string.
     */
    const std::string& getName() const;

    /**
     * @brief Sets the description of the item.
     * @param desc New description.
     */
    void setDesc(const std::string& desc);

    /**
     * @brief Gets the description of the item.
     * @return Const reference to description string.
     */
    const std::string& getDesc() const;

    /**
     * @brief Sets the durability of the item.
     * @param d Durability value.
     */
    void setDurability(int d);

    /**
     * @brief Gets the durability of the item.
     * @return Durability value.
     */
    int getDurability() const;

    /**
     * @brief Sets health bonus.
     * @param h Health bonus value.
     */
    void setHealthBonus(int h);

    /**
     * @brief Gets health bonus.
     * @return Health bonus value.
     */
    int getHealthBonus() const;

    /**
     * @brief Sets defense bonus.
     * @param d Defense bonus value.
     */
    void setDefenceBonus(int d);

    /**
     * @brief Gets defense bonus.
     * @return Defense bonus value.
     */
    int getDefenceBonus() const;

    /**
     * @brief Sets mana bonus.
     * @param m Mana bonus value.
     */
    void setManaBonus(int m);

    /**
     * @brief Gets mana bonus.
     * @return Mana bonus value.
     */
    int getManaBonus() const;

    /**
     * @brief Sets attack bonus.
     * @param a Attack bonus value.
     */
    void setAttackBonus(int a);

    /**
     * @brief Gets attack bonus.
     * @return Attack bonus value.
     */
    int getAttackBonus() const;

    /**
     * @brief Sets luck bonus.
     * @param l Luck bonus value.
     */
    void setLuckBonus(double l);

    /**
     * @brief Gets luck bonus.
     * @return Luck bonus value.
     */
    double getLuckBonus() const;

    /**
     * @brief Sets healing bonus.
     * @param hbb Healing bonus value.
     */
    void setHBBonus(int hbb);

    /**
     * @brief Gets healing bonus.
     * @return Healing bonus value.
     */
    int getHBBonus() const;

    /**
     * @brief Sets critical chance bonus.
     * @param c Critical chance bonus value.
     */
    void setCritChanceBonus(double c);

    /**
     * @brief Gets critical chance bonus.
     * @return Critical chance bonus value.
     */
    int getCritChanceBonus() const;

    /**
     * @brief Sets intelligence bonus.
     * @param i Intelligence bonus value.
     */
    void setIntBonus(int i);

    /**
     * @brief Gets intelligence bonus.
     * @return Intelligence bonus value.
     */
    int getIntBonus() const;

    /**
     * @brief Gets the item type code.
     * @return Item type integer.
     */
    int getType() const;

protected:
    std::string name;          ///< Item name
    std::string description;   ///< Item description
    int durability;            ///< Remaining durability
    int type;                  ///< Item type code
    int health_bonus;          ///< Bonus to health
    int defence_bonus;         ///< Bonus to defense
    int mana_bonus;            ///< Bonus to mana
    int attack_bonus;          ///< Bonus to attack power
    double luck_bonus;         ///< Bonus to luck
    int hb_bonus;              ///< Healing bonus
    double crit_chance_bonus;  ///< Critical hit chance bonus
    int int_bonus;             ///< Intelligence bonus
};

#endif

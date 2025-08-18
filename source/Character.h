#ifndef CHARACTER_H
#define CHARACTER_H

#include "Weapon.h"
#include "Armour.h"
#include <string>
#include <memory>

/**
 * @class Character
 * @brief Represents a generic character in the game with stats and equipment.
 */
class Character {
public:
    /**
     * @brief Constructs a Character with given attributes.
     * @param name Character's name.
     * @param cid Class ID to identify character class.
     * @param health Health points.
     * @param mana Mana points.
     * @param attack_power Attack power.
     * @param defence Defense rating.
     * @param hr Healing rate.
     */
    Character(const std::string& name,
              int cid,
              int health,
              int mana,
              int attack_power,
              int defence,
              int hr);

    /**
     * @brief Destructor.
     */
    virtual ~Character();

    /**
     * @brief Sets the character's name.
     * @param n New name.
     */
    void setName(const std::string& n);

    /**
     * @brief Gets the character's name.
     * @return Name as string.
     */
    std::string getName() const;

    /**
     * @brief Sets the character's health.
     * @param h Health points.
     */
    void setHealth(int h);

    /**
     * @brief Gets the character's health.
     * @return Current health points.
     */
    int getHealth() const;

    /**
     * @brief Sets the character's mana.
     * @param m Mana points.
     */
    void setMana(int m);

    /**
     * @brief Gets the character's mana.
     * @return Current mana points.
     */
    int getMana() const;

    /**
     * @brief Sets the attack power.
     * @param ap Attack power value.
     */
    void setAttackPower(int ap);

    /**
     * @brief Gets the attack power.
     * @return Attack power value.
     */
    int getAttackPower() const;

    /**
     * @brief Sets the defense rating.
     * @param d Defense value.
     */
    void setDefence(int d);

    /**
     * @brief Gets the defense rating.
     * @return Defense value.
     */
    int getDefence() const;

    /**
     * @brief Sets the healing rate.
     * @param hr Healing rate value.
     */
    void setHealingRate(int hr);

    /**
     * @brief Gets the healing rate.
     * @return Healing rate value.
     */
    int getHealingRate();

    /**
     * @brief Sets the luck stat (default empty in base).
     * @param Not used.
     */
    virtual void setLuck(double);

    /**
     * @brief Gets the luck stat (default zero in base).
     * @return Luck value.
     */
    virtual double getLuck() const;

    /**
     * @brief Sets the healing bonus (default empty).
     * @param Not used.
     */
    virtual void setHealingBonus(int);

    /**
     * @brief Gets the healing bonus (default zero).
     * @return Healing bonus.
     */
    virtual int getHealingBonus() const;

    /**
     * @brief Sets the critical chance (default empty).
     * @param Not used.
     */
    virtual void setCritChance(double);

    /**
     * @brief Gets the critical chance (default zero).
     * @return Critical chance value.
     */
    virtual double getCritChance() const;

    /**
     * @brief Sets the intelligence stat (default empty).
     * @param Not used.
     */
    virtual void setIntelligence(int);

    /**
     * @brief Gets the intelligence stat (default zero).
     * @return Intelligence value.
     */
    virtual int getIntelligence() const;

    /**
     * @brief Sets the armour equipped.
     * @param a Shared pointer to Armour.
     */
    void setArmour(std::shared_ptr<Armour> a);

    /**
     * @brief Gets the currently equipped armour.
     * @return Shared pointer to Armour.
     */
    std::shared_ptr<Armour> getArmour() const;

    /**
     * @brief Sets the weapon equipped.
     * @param w Shared pointer to Weapon.
     */
    void setWeapon(std::shared_ptr<Weapon> w);

    /**
     * @brief Gets the currently equipped weapon.
     * @return Shared pointer to Weapon.
     */
    std::shared_ptr<Weapon> getWeapon() const;

    /**
     * @brief Sets the currently held item (default empty).
     * @param Shared pointer to Item.
     */
    virtual void setItem(std::shared_ptr<Item>);

    /**
     * @brief Gets the currently held item (default nullptr).
     * @return Shared pointer to Item.
     */
    virtual std::shared_ptr<Item> getItem() const;

    /**
     * @brief Gets the class ID.
     * @return Class ID integer.
     */
    int getCid();

protected:
    std::string name;      ///< Character's name
    int class_id;          ///< Class identifier
    int health;            ///< Health points
    int mana;              ///< Mana points
    int attack_power;      ///< Attack power
    int defence;           ///< Defense value
    int healing_rate;      ///< Healing rate
    std::shared_ptr<Weapon> weapon; ///< Equipped weapon
    std::shared_ptr<Armour> armour; ///< Equipped armour
};

#endif

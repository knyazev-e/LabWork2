#ifndef CHARACTER_H
#define CHARACTER_H

#include "Weapon.h"
#include "Armour.h"
#include <string>
#include <memory>


class Character {
public:
    Character(const std::string& name,
              int cid,
              int health,
              int mana,
              int attack_power,
              int defence,
              int hr);

    virtual ~Character();

    void setName(const std::string& name);
    std::string getName() const;

    void setHealth(int health);
    int getHealth() const;

    void setMana(int mana);
    int getMana() const;

    void setAttackPower(int ap);
    int getAttackPower() const;

    void setDefence(int def);
    int getDefence() const;

    void setHealingRate(int hr);
    int getHealingRate();


    virtual void setLuck(double);
    virtual double getLuck() const;

    virtual void setHealingBonus(int);
    virtual int getHealingBonus() const;

    virtual void setCritChance(double);
    virtual double getCritChance() const;

    virtual void setIntelligence(int);
    virtual int getIntelligence() const;


    void setArmour(std::shared_ptr<Armour> a);
    std::shared_ptr<Armour> getArmour() const;

    void setWeapon(std::shared_ptr<Weapon> w);
    std::shared_ptr<Weapon> getWeapon() const;

    virtual void setItem(std::shared_ptr<Item>);
    virtual std::shared_ptr<Item> getItem() const;

    int getCid();

protected:
    std::string name;
    int class_id;
    int health;
    int mana;
    int attack_power;
    int defence;
    int healing_rate;
    std::shared_ptr<Weapon> weapon;
    std::shared_ptr<Armour> armour;
};


#endif

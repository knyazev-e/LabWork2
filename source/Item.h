#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
public:
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

    virtual ~Item();

    void setName(const std::string& n);
    const std::string& getName() const;

    void setDesc(const std::string& desc);
    const std::string& getDesc() const;

    void setDurability(int d);
    int getDurability() const;

    void setHealthBonus(int h);
    int getHealthBonus() const;

    void setDefenceBonus(int d);
    int getDefenceBonus() const;

    void setManaBonus(int m);
    int getManaBonus() const;

    void setAttackBonus(int a);
    int getAttackBonus() const;

    void setLuckBonus(double l);
    double getLuckBonus() const;

    void setHBBonus(int hbb);
    int getHBBonus() const;

    void setCritChanceBonus(double c);
    int getCritChanceBonus() const;

    void setIntBonus(int i);
    int getIntBonus() const;

    int getType() const;

protected:
    std::string name;
    std::string description;
    int durability;
    int type;
    int health_bonus;
    int defence_bonus;
    int mana_bonus;
    int attack_bonus;
    double luck_bonus;
    int hb_bonus;
    double crit_chance_bonus;
    int int_bonus;
};

#endif

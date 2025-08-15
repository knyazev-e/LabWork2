#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include "Item.h"

class Weapon : public Item {
public:
    Weapon(const std::string& name,
           const std::string& desc,
           int durability,
           int defence_bonus,
           int attack_bonus,
           double crit_chance_bonus,
           int lvl);

    void setLevel(int lvl);
    int getLevel() const;

protected:
    int level;
};

#endif

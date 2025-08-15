#ifndef ARMOUR_H
#define ARMOUR_H

#include "Item.h"

class Armour : public Item {
public:
    Armour(const std::string& name,
           const std::string& desc,
           int durability,
           int defence_bonus,
           int attack_bonus,
           int weight);

    void setWeight(int weight);
    int getWeight() const;

protected:
    int weight;
};

#endif

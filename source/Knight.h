#ifndef KNIGHT_H
#define KNIGHT_H

#include "Player.h"

class Knight : public Player {
public:
    Knight(const std::string& name,
           int health,
           int mana,
           int attack_power,
           int defence,
           int hr,
           const std::string& desc,
           std::shared_ptr<Item> item,
           double crit_chance);

    Knight();
    ~Knight();

    void setCritChance(double chance) override;
    double getCritChance() const override;

    std::shared_ptr<Player> clone() const override;

protected:
    double crit_chance;
};


#endif

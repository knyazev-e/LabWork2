#ifndef DRUID_H
#define DRUID_H

#include "Player.h"

class Druid : public Player {
public:
    Druid(const std::string& name,
         int health,
         int mana,
         int attack_power,
         int defence,
         int hr,
         const std::string& desc,
         std::shared_ptr<Item> item,
         int healing_bonus);

    Druid();
    ~Druid();

    void setHealingBonus(int bonus) override;
    int getHealingBonus() const override;

    std::shared_ptr<Player> clone() const override;

protected:
    int healing_bonus;
};

#endif

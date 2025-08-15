#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"
#include "Action.h"
#include "ConstVariables.h"

class Enemy : public Character {
public:
    Enemy();
    Enemy(const std::string& name,
          int health,
          int mana,
          int attack_power,
          int defence,
          int hr,
          double crit_chance,
          int equipping_flag,
          std::shared_ptr<Action> nxt_act);

    ~Enemy();

    void setCritChance(double chance);
    double getCritChance() const;

    void setEquippingFlag(int f);
    int getEquippingFlag();

    void setNextAction(std::shared_ptr<Action> act);
    std::shared_ptr<Action> getNextAction() const;

protected:
    double crit_chance;
    int equipping_flag;
    std::shared_ptr<Action> next_action;
};

#endif

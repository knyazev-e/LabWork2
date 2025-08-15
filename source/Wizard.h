#ifndef WIZARD_H
#define WIZARD_H

#include "Player.h"

class Wizard : public Player {
public:
    Wizard(const std::string& name,
           int health,
           int mana,
           int attack_power,
           int defence,
           int hr,
           const std::string& desc,
           std::shared_ptr<Item> item,
           int intelligence);

    Wizard();
    ~Wizard();

    void setIntelligence(int intelligence) override;
    int getIntelligence() const override;

    std::shared_ptr<Player> clone() const override;

protected:
    int intelligence;
};

#endif

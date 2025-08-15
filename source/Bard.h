#ifndef BARD_H
#define BARD_H

#include "Player.h"

class Bard : public Player {
public:
    Bard(const std::string& name,
         int health,
         int mana,
         int attack_power,
         int defence,
         int hr,
         const std::string& desc,
         std::shared_ptr<Item> item,
         double luck);

    Bard();
    ~Bard();

    void setLuck(double luck) override;
    double getLuck() const override;

    std::shared_ptr<Player> clone() const override;

protected:
    double luck;
};


#endif

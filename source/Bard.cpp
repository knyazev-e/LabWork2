#include "Bard.h"

Bard::Bard(const std::string& name,
           int health,
           int mana,
           int attack_power,
           int defence,
           int hr,
           const std::string& desc,
           std::shared_ptr<Item> item,
           double luck)
    : Player(name, 1, health, mana, attack_power, defence, hr, desc, item),
      luck(luck) {}

Bard::Bard() : Player("Bard", 1, bard_init_hp, bard_init_mana, bard_init_attack, bard_init_defence, bard_healing_rate, bard_desc, nullptr), luck(bard_init_luck) {}

Bard::~Bard() = default;

void Bard::setLuck(double l) { luck = l; }
double Bard::getLuck() const { return luck; }


std::shared_ptr<Player> Bard::clone() const {
    return std::make_shared<Bard>(*this);
}

/* Kniazeva Eva Andreevna
st128104@student.spbu.ru
labwork2: rpg game */

#include "Druid.h"

Druid::Druid(const std::string& name,
             int health,
             int mana,
             int attack_power,
             int defence,
             int hr,
             const std::string& desc,
             std::shared_ptr<Item> item,
             int healing_bonus)
    : Player(name, 2, health, mana, attack_power, defence, hr, desc, item),
      healing_bonus(healing_bonus) {}

Druid::Druid() : Player("Druid", 2, druid_init_hp, druid_init_mana, druid_init_attack, druid_init_defence, druid_healing_rate, druid_desc, nullptr), healing_bonus(druid_init_healing_bonus) {}

Druid::~Druid() = default;

void Druid::setHealingBonus(int bonus) { healing_bonus = bonus; }
int Druid::getHealingBonus() const { return healing_bonus; }


std::shared_ptr<Player> Druid::clone() const {
    return std::make_shared<Druid>(*this);
}

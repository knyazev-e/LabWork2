/* Kniazeva Eva Andreevna
st128104@student.spbu.ru
labwork2: rpg game */

#include "Knight.h"


Knight::Knight(const std::string& name,
               int health,
               int mana,
               int attack_power,
               int defence,
               int hr,
               const std::string& desc,
               std::shared_ptr<Item> item,
               double crit_chance)
    : Player(name, 3, health, mana, attack_power, defence, hr, desc, item),
      crit_chance(crit_chance) {}

Knight::Knight() : Player("Knight", 3, knight_init_hp, knight_init_mana, knight_init_attack, knight_init_defence, knight_healing_rate, knight_desc, nullptr), crit_chance(knight_init_crit_chance) {}

Knight::~Knight() = default;

void Knight::setCritChance(double chance) { crit_chance = chance; }
double Knight::getCritChance() const { return crit_chance; }


std::shared_ptr<Player> Knight::clone() const {
    return std::make_shared<Knight>(*this);
}

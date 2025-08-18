/* Kniazeva Eva Andreevna
st128104@student.spbu.ru
labwork2: rpg game */

#include "Weapon.h"


Weapon::Weapon(const std::string& name,
               const std::string& desc,
               int durability,
               int defence_bonus,
               int attack_bonus,
               double crit_chance_bonus,
               int lvl)
    : Item(name, desc, durability, 2, 0, defence_bonus, 0, attack_bonus, 0, 0, crit_chance_bonus, 0),
      level(lvl) {}

void Weapon::setLevel(int lvl) { level = lvl; }
int Weapon::getLevel() const { return level; }

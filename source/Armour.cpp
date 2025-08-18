/* Kniazeva Eva Andreevna
st128104@student.spbu.ru
labwork2: rpg game */

#include "Armour.h"

Armour::Armour(const std::string& name,
               const std::string& desc,
               int durability,
               int defence_bonus,
               int attack_bonus,
               int weight)
    : Item(name, desc, durability, 1, 0, defence_bonus, 0, attack_bonus, 0, 0, 0, 0),
      weight(weight) {}

void Armour::setWeight(int w) { weight = w; }
int Armour::getWeight() const { return weight; }

/* Kniazeva Eva Andreevna
st128104@student.spbu.ru
labwork2: rpg game */

#include "Equip.h"

Equip::Equip(const std::string& name, const std::string& desc, int mana) : Action(name, desc, mana) {}

void Equip::execute(Character& performer, Character&, Battle&, std::shared_ptr<Item> item, Character& item_target) {
    if (std::shared_ptr<Armour> a = std::dynamic_pointer_cast<Armour>(item)) {
        item_target.setArmour(a);
    } else if (std::shared_ptr<Weapon> w = std::dynamic_pointer_cast<Weapon>(item)) {
        item_target.setWeapon(w);
    } else if (item->getType() == 0) {
        item_target.setItem(item);
    }
    performer.setMana(performer.getMana() - mana_usage);
}

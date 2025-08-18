/* Kniazeva Eva Andreevna
st128104@student.spbu.ru
labwork2: rpg game */

#include "Wizard.h"


Wizard::Wizard(const std::string& name,
               int health,
               int mana,
               int attack_power,
               int defence,
               int hr,
               const std::string& desc,
               std::shared_ptr<Item> item,
               int intelligence)
    : Player(name, 4, health, mana, attack_power, defence, hr, desc, item),
      intelligence(intelligence) {}

Wizard::Wizard() : Player("Wizard", 4, wizard_init_hp, wizard_init_mana, wizard_init_attack, wizard_init_defence, wizard_healing_rate, wizard_desc, nullptr), intelligence(wizard_init_intelligence) {}

Wizard::~Wizard() = default;

void Wizard::setIntelligence(int intel) { intelligence = intel; }
int Wizard::getIntelligence() const { return intelligence; }

std::shared_ptr<Player> Wizard::clone() const {
    return std::make_shared<Wizard>(*this);
}

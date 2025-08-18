#include "Spell.h"
#include "Wizard.h"
#include "StatModifyingAction.h"


Spell::Spell(const std::string& name, const std::string& desc, int mana) : Action(name, desc, mana) {}


void Spell::exucute(Character& performer, Character& target, Battle& battle, std::shared_ptr<Item> item, Character& item_target) {
    int max_amount = performer.getAttackPower();
    int intelligence = performer.getIntelligence();
    if (performer.getItem() != nullptr) {
        intelligence += performer.getItem()->getIntBonus();
    }
    double intelligence_factor = intelligence / 10.0;

    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> stat_dist(1,4);
    std::uniform_int_distribution<int> amount_dist(1, max_amount);

    int stat_id = stat_dist(gen);
    int base_amount = amount_dist(gen);
    int magnitude = static_cast<int>(std::ceil(base_amount * (1 + intelligence_factor)));

    StatModifyingAction spell("spell", "", mana_usage, stat_id, -magnitude);
    spell.execute(performer, target, battle, item, item_target);
}

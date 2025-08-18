#include "StatModifyingAction.h"


StatModifyingAction::StatModifyingAction(const std::string& name,
                                         const std::string& desc,
                                         int mana,
                                         int modified_stat,
                                         int quantity)
    : Action(name, desc, mana),
      modified_stat(modified_stat),
      quantity(quantity) {}

void StatModifyingAction::setModifiedStat(int stat) { modified_stat = stat; }
int StatModifyingAction::getModifiedStat() const { return modified_stat; }

void StatModifyingAction::setQuantity(int q) { quantity = q; }
int StatModifyingAction::getQuantity() const { return quantity; }

void StatModifyingAction::execute(Character& performer, Character& target, Battle& battle, std::shared_ptr<Item>, Character&) {
    if (modified_stat == 1 && name == "Heal") {
        quantity = performer.getHealingRate();
        if (performer.getCid() != -1) {
            if (performer.getItem() != nullptr) {
                quantity += performer.getItem()->getHealthBonus();
            }
        }
        performer.setHealth(performer.getHealth() + quantity);
    }
    else if (modified_stat == 1 && (name == "Attack" || name == "Heavy attack" || name == "Spell")) {
        if (name == "Attack") {
            quantity = -(battle.calculate_damage(performer, target));
        }
        else if (name == "Heavy attack") {
            quantity = -(battle.calculate_damage(performer, target) + heavy_atk_addition);
        }
        target.setHealth(target.getHealth() + quantity);
        if (target.getHealth() < 0) {
            target.setHealth(0);
        }
    }
    else if (modified_stat == 2) {
        target.setMana(target.getMana() + quantity);
        if (target.getMana() < 0) {
            target.setMana(0);
        }
    }
    else if (modified_stat == 3) {
        target.setAttackPower(target.getAttackPower() + quantity);
        if (target.getAttackPower() < 0) {
            target.setAttackPower(0);
        }
    }
    else if (modified_stat == 4 && name == "Defend") {
        performer.setDefence(performer.getDefence() + quantity);
    }
    else if (modified_stat == 4 && (name == "Weaken" || name == "Spell")) {
        target.setDefence(target.getDefence() + quantity);
        if (target.getDefence() < 0) {
            target.setDefence(0);
        }
    }
    performer.setMana(performer.getMana() - mana_usage);
}



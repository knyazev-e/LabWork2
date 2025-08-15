#include "Battle.h"

Battle::Battle() : turn(true), turn_block(0), report_message(-1) {}

void Battle::set_turn(bool t) { turn = t; }
bool Battle::get_turn() const { return turn; }

void Battle::set_turn_block(int n) { turn_block = n; }
int Battle::get_turn_block() { return turn_block; }

void Battle::setReportMessage(int m) { report_message = m; }
int Battle::getReportMessage() { return report_message; }

void Battle::setActionsCatalogue(std::vector<std::shared_ptr<Action>> a) {
    actions_catalogue = a;
}

const std::vector<std::shared_ptr<Action>>& Battle::getActionsCatalogue() {
    return actions_catalogue;
}

void Battle::setItemsCatalogue(std::vector<std::shared_ptr<Item>> i) {
    items_catalogue = i;
}

const std::vector<std::shared_ptr<Item>>& Battle::getItemsCatalogue() {
    return items_catalogue;
}

int Battle::calculate_damage(Character& performer, Character& target) {
    int attack = performer.getAttackPower();
    int defence = target.getDefence();


    if (performer.getCid() != -1) {
        if (performer.getItem() != nullptr) {
            attack += performer.getItem()->getAttackBonus();
        }
    }
    if (performer.getArmour() != nullptr) {
        attack += performer.getArmour()->getAttackBonus();
    }
    if (performer.getWeapon() != nullptr) {
        attack += performer.getWeapon()->getAttackBonus();
    }


    if (target.getCid() != -1) {
        if (target.getItem() != nullptr) {
            defence += target.getItem()->getDefenceBonus();
        }
    }
    if (target.getArmour() != nullptr) {
        defence += target.getArmour()->getDefenceBonus();
    }
    if (target.getWeapon() != nullptr) {
        defence += target.getWeapon()->getDefenceBonus();
    }


    double damage = attack * (100 / (100 + defence));
    if (performer.getCid() == 3 || performer.getCid() == -1) {
        if (is_critical(performer)) {
            damage = damage * crit_atk_coef;
        }
    }
    return static_cast<int>(damage);
}

bool Battle::is_critical(Character& performer) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    double crit_chance = performer.getCritChance();
    if (performer.getCid() == 1) {
        if (performer.getItem() != nullptr) {
            crit_chance += performer.getItem()->getCritChanceBonus();
        }
    }
    if (performer.getArmour() != nullptr) {
        crit_chance += performer.getArmour()->getCritChanceBonus();
    }
    if (performer.getWeapon() != nullptr) {
        crit_chance += performer.getWeapon()->getCritChanceBonus();
    }

    return (dis(gen) < performer.getCritChance());
}

bool Battle::is_enough_mana(Character& performer, Action& action) {
    if (performer.getMana() >= action.getManaUsage()) {
        return true;
    } else {
        return false;
    }
}


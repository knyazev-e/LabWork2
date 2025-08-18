/* Kniazeva Eva Andreevna
st128104@student.spbu.ru
labwork2: rpg game */

#include "Dodge.h"

Dodge::Dodge(const std::string& name, const std::string& desc, int mana) : Action(name, desc, mana) {}

bool Dodge::attempt(Character& performer) {
    performer.setMana(performer.getMana() - mana_usage);
    double probability;
    if (performer.getCid() == 1) {
        probability = 0.5 + performer.getLuck();
        if (performer.getItem() != nullptr) {
            probability += performer.getItem()->getLuckBonus();
        }
    }
    else { probability = 0.55; }

    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::bernoulli_distribution dist(probability);
    return dist(gen);
}

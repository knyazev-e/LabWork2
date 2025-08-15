#include "Distract.h"


Distract::Distract(const std::string& name, const std::string& desc, int mana) : Action(name, desc, mana) {}


void Distract::execute(Character& performer, Character&, Battle& battle, std::shared_ptr<Item>, Character&) {
    performer.setMana(performer.getMana() - mana_usage);
    battle.set_turn_block(2);
}


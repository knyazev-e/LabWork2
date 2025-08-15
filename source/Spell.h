#ifndef SPELL_H
#define SPELL_H

#include <random>
#include <cmath>
#include "Action.h"

class Spell : public Action {
public:
    Spell(const std::string& name, const std::string& desc, int mana);

    void exucute(Character& performer, Character& target, Battle& battle, std::shared_ptr<Item> item, Character& item_target);
};

#endif

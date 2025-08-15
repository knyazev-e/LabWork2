#ifndef EQUIP_H
#define EQUIP_H

#include "Action.h"

class Equip : public Action {
public:
    Equip(const std::string& name, const std::string& description, int mana);

    void execute(Character& performer, Character&, Battle&, std::shared_ptr<Item> item, Character& item_target) override;

};

#endif

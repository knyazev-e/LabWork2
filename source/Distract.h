#ifndef DISTRACT_H
#define DISTRACT_H

#include "Action.h"
#include "Battle.h"

class Distract : public Action {
public:
    Distract(const std::string& name, const std::string& desc, int mana);

    void execute(Character& performer, Character&, Battle& battle, std::shared_ptr<Item>, Character&) override;
};

#endif

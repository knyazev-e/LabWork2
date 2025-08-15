#ifndef DODGE_H
#define DODGE_H

#include <random>
#include "Action.h"

class Dodge: public Action {
public:
    Dodge(const std::string& name, const std::string& desc, int mana);

    bool attempt(Character& performer) override;
};

#endif

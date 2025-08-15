#ifndef STATMODIFYINGACTION_H
#define STATMODIFYINGACTION_H

#include "Action.h"
#include "Battle.h"

class StatModifyingAction : public Action {
public:
    StatModifyingAction(const std::string& name, const std::string& desc, int mana, int modified_stat, int quantity);

    void setModifiedStat(int stat);
    int getModifiedStat() const;

    void setQuantity(int quantity);
    int getQuantity() const;

    void execute(Character& performer, Character& target, Battle& battle, std::shared_ptr<Item>, Character&) override;

protected:
    int modified_stat;
    int quantity;
};

#endif

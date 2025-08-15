#ifndef ACTION_H
#define ACTION_H

#include <string>
#include "Character.h"
#include "Item.h"

class Battle;

class Action {
public:
    Action(const std::string& name, const std::string& desc, int mana);
    ~Action();

    void setName(const std::string& name);
    const std::string& getName() const;

    void setDesc(const std::string& desc);
    const std::string& getDesc();

    void setManaUsage(int mana);
    int getManaUsage();

    virtual void execute(Character&, Character&, Battle&, std::shared_ptr<Item>, Character&);
    virtual bool attempt(Character&);

protected:
    std::string name;
    std::string description;
    int mana_usage;
};

#endif

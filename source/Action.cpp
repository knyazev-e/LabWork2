#include "Action.h"


Action::Action(const std::string& name, const std::string& desc, int mana)
    : name(name), description(desc), mana_usage(mana) {}

Action::~Action() = default;

void Action::setName(const std::string& n) { name = n; }
const std::string& Action::getName() const { return name; }

void Action::setDesc(const std::string& desc) {
    description = desc;
}

const std::string& Action::getDesc() {
    return description;
}

void Action::setManaUsage(int mana) {
    mana_usage = mana;
}

int Action::getManaUsage() {
    return mana_usage;
}

void Action::execute(Character&, Character&, Battle&, std::shared_ptr<Item>, Character&) {}

bool Action::attempt(Character&) { return 0; }

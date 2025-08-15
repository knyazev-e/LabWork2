#include "Character.h"

Character::Character(const std::string& name,
                     int cid,
                     int health,
                     int mana,
                     int attack_power,
                     int defence,
                     int hr)
    : name(name),
      class_id(cid),
      health(health),
      mana(mana),
      attack_power(attack_power),
      defence(defence),
      healing_rate(hr),
      weapon(nullptr),
      armour(nullptr) {}

Character::~Character() = default;

void Character::setName(const std::string& n) { name = n; }
std::string Character::getName() const { return name; }

void Character::setHealth(int h) { health = h; }
int Character::getHealth() const { return health; }

void Character::setMana(int m) { mana = m; }
int Character::getMana() const { return mana; }

void Character::setAttackPower(int ap) { attack_power = ap; }
int Character::getAttackPower() const { return attack_power; }

void Character::setDefence(int d) { defence = d; }
int Character::getDefence() const { return defence; }

void Character::setHealingRate(int hr) { healing_rate = hr; }
int Character::getHealingRate() { return healing_rate; }



void Character::setLuck(double) {}
double Character::getLuck() const { return 0; }

void Character::setHealingBonus(int) {}
int Character::getHealingBonus() const { return 0; }

void Character::setCritChance(double) {}
double Character::getCritChance() const { return 0; }

void Character::setIntelligence(int) {}
int Character::getIntelligence() const { return 0; }



void Character::setArmour(std::shared_ptr<Armour> a) {
    armour = std::move(a);
}

std::shared_ptr<Armour> Character::getArmour() const {
    return armour;
}


void Character::setWeapon(std::shared_ptr<Weapon> w) {
    weapon = std::move(w);
}

std::shared_ptr<Weapon> Character::getWeapon() const {
    return weapon;
}



void Character::setItem(std::shared_ptr<Item>) {}

std::shared_ptr<Item> Character::getItem() const {
    return nullptr;
}


int Character::getCid() {
    return class_id;
}

#include "Item.h"

Item::Item(const std::string& name,
         const std::string& desc,
         int durability,
         int type,
         int health_bonus,
         int defence_bonus,
         int mana_bonus,
         int attack_bonus,
         double luck_bonus,
         int hb_bonus,
         double crit_chance_bonus,
         int int_bonus)
    : name(name),
      description(desc),
      durability(durability),
      type(type),
      health_bonus(health_bonus),
      defence_bonus(defence_bonus),
      mana_bonus(mana_bonus),
      attack_bonus(attack_bonus),
      luck_bonus(luck_bonus),
      hb_bonus(hb_bonus),
      crit_chance_bonus(crit_chance_bonus),
      int_bonus(int_bonus) {}

Item::~Item() = default;

void Item::setName(const std::string& n) { name = n; }
const std::string& Item::getName() const { return name; }

void Item::setDesc(const std::string& desc) { description = desc; }
const std::string& Item::getDesc() const { return description; }

void Item::setDurability(int d) { durability = d; }
int Item::getDurability() const { return durability; }

void Item::setHealthBonus(int h) { health_bonus = h; }
int Item::getHealthBonus() const { return health_bonus; }

void Item::setDefenceBonus(int d) { defence_bonus = d; }
int Item::getDefenceBonus() const { return defence_bonus; }

void Item::setManaBonus(int m) { mana_bonus = m; }
int Item::getManaBonus() const { return mana_bonus; }

void Item::setAttackBonus(int a) { attack_bonus = a; }
int Item::getAttackBonus() const { return attack_bonus; }

void Item::setLuckBonus(double l) { luck_bonus = l; }
double Item::getLuckBonus() const { return luck_bonus; }

void Item::setHBBonus(int hbb) { hb_bonus = hbb; }
int Item::getHBBonus() const { return hb_bonus; }

void Item::setCritChanceBonus(double c) { crit_chance_bonus = c; }
int Item::getCritChanceBonus() const { return crit_chance_bonus; }

void Item::setIntBonus(int i) { int_bonus = i; }
int Item::getIntBonus() const { return int_bonus; }

int Item::getType() const { return type; }

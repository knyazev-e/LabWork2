#include "Enemy.h"


Enemy::Enemy() : Character("Enemy", -1, enemy_init_hp, enemy_init_mana, enemy_init_attack, enemy_init_defence, enemy_healing_rate), crit_chance(enemy_init_crit_chance), equipping_flag(0), next_action(nullptr) {}

Enemy::Enemy(const std::string& name,
             int health,
             int mana,
             int attack_power,
             int defence,
             int hr,
             double crit_chance,
             int equipping_flag,
             std::shared_ptr<Action> nxt_act)
    : Character(name, -1, health, mana, attack_power, defence, hr),
      crit_chance(crit_chance),
      equipping_flag(equipping_flag),
      next_action(nxt_act) {}

Enemy::~Enemy() = default;

void Enemy::setCritChance(double chance) { crit_chance = chance; }
double Enemy::getCritChance() const { return crit_chance; }

void Enemy::setEquippingFlag(int f) { equipping_flag = f; }
int Enemy::getEquippingFlag() { return equipping_flag; }

void Enemy::setNextAction(std::shared_ptr<Action> act) { next_action = act; }
std::shared_ptr<Action> Enemy::getNextAction() const { return next_action; }

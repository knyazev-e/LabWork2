/* Kniazeva Eva Andreevna
st128104@student.spbu.ru
labwork2: rpg game */

#include "Player.h"

Player::Player() : Character("Player", 0, player_init_hp, player_init_mana, player_init_attack, player_init_defence, player_healing_rate), item(nullptr), description(default_desc) {}

Player::Player(const std::string& name,
               int cid,
               int health,
               int mana,
               int attack_power,
               int defence,
               int hr,
               const std::string& desc,
               std::shared_ptr<Item> item)
    : Character(name, cid, health, mana, attack_power, defence, hr), item(item), description(desc) {}

Player::~Player() = default;

void Player::setItem(std::shared_ptr<Item> i) {
    item = std::move(i);
}

std::shared_ptr<Item> Player::getItem() const {
    return item;
}

void Player::setDesc(const std::string& desc) {
    description = desc;
}

std::string Player::getDesc() {
    return description;
}

void Player::setClassItems(const std::vector<std::shared_ptr<Item>>& v) {
    class_items = v;
}

const std::vector<std::shared_ptr<Item>>& Player::getClassItems() {
    return class_items;
}

void Player::setClassActions(const std::vector<std::shared_ptr<Action>>& v) {
    class_actions = v;
}

const std::vector<std::shared_ptr<Action>>& Player::getClassActions() {
    return class_actions;
}


std::shared_ptr<Player> Player::clone() const {
    return std::make_shared<Player>(*this);
}

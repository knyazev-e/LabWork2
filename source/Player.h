#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include "Item.h"
#include "Action.h"
#include "ConstVariables.h"
#include <stdexcept>
#include <vector>
#include <memory>

class Player : public Character {
public:
    Player();
    Player(const std::string& name,
           int cid,
           int health,
           int mana,
           int attack_power,
           int defence,
           int hr,
           const std::string& desc,
           std::shared_ptr<Item> item);

    ~Player();

    void setItem(std::shared_ptr<Item> i) override;
    std::shared_ptr<Item> getItem() const override;

    void setDesc(const std::string& desc);
    std::string getDesc();

    void setClassActions(const std::vector<std::shared_ptr<Action>>& v);
    const std::vector<std::shared_ptr<Action>>& getClassActions();

    void setClassItems(const std::vector<std::shared_ptr<Item>>& v);
    const std::vector<std::shared_ptr<Item>>& getClassItems();

    virtual std::shared_ptr<Player> clone() const;

protected:
    std::vector<std::shared_ptr<Item>> class_items;
    std::vector<std::shared_ptr<Action>> class_actions;
    std::shared_ptr<Item> item;
    std::string description;
};

#endif

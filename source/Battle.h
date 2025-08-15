#ifndef BATTLE_H
#define BATTLE_H

#include <vector>
#include <memory>
#include <random>
#include <string>
#include "Action.h"
#include "Enemy.h"


class Battle {
public:
    Battle();

    void set_turn(bool turn);
    bool get_turn() const;

    void set_turn_block(int n);
    int get_turn_block();

    void setReportMessage(int m);
    int getReportMessage();

    int calculate_damage(Character& performer, Character& target);
    bool is_critical(Character& performer);
    bool is_enough_mana(Character& performer, Action& action);

    void setActionsCatalogue(std::vector<std::shared_ptr<Action>> a);
    const std::vector<std::shared_ptr<Action>>& getActionsCatalogue();

    void setItemsCatalogue(std::vector<std::shared_ptr<Item>> i);
    const std::vector<std::shared_ptr<Item>>& getItemsCatalogue();

protected:
    bool turn;
    int turn_block;
    int report_message;
    std::vector<std::shared_ptr<Action>> actions_catalogue;
    std::vector<std::shared_ptr<Item>> items_catalogue;
};


#endif

#include "EnemyAI.h"

EnemyAI::EnemyAI() {}

int EnemyAI::chooseAction(Player& player, Enemy& enemy, Battle& battle) {

    if (enemy.getHealth()/enemy_init_hp < low_hp && enemy.getMana() >= healing_cost) {
        battle.setReportMessage(1);
        return 2;
    }

    if (player.getDefence() > high_defence && enemy.getMana() >= weakening_cost) {
        battle.setReportMessage(3);
        return 4;
    }

    if (enemy.getDefence() <= low_defence && enemy.getMana() >= defending_cost) {
        battle.setReportMessage(2);
        return 3;
    }

    if (enemy.getArmour() == nullptr || enemy.getWeapon() == nullptr) {
        if (enemy.getWeapon() == nullptr) {
            enemy.setEquippingFlag(2);
            battle.setReportMessage(5);
            return 5;
        }

        if (enemy.getArmour() == nullptr) {
            enemy.setEquippingFlag(1);
            battle.setReportMessage(4);
            return 5;
        }
    }

    battle.setReportMessage(0);
    return 1;

}


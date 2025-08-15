#ifndef ENEMYAI_H
#define ENEMYAI_H

#include <memory>
#include "ConstVariables.h"
#include "Player.h"
#include "Enemy.h"
#include "Battle.h"

class EnemyAI {
public:
    EnemyAI();

    int chooseAction(Player& player, Enemy& enemy, Battle& battle);
};

#endif

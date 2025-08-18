/* Kniazeva Eva Andreevna
st128104@student.spbu.ru
labwork2: rpg game */

#include "Game.h"

Game::Game() : battle(), player(std::make_shared<Player>()), enemy(), statistics(), state(0), difficulty(1), is_running(false) {}

void Game::init_characters() {
    std::vector<std::shared_ptr<Player>> c;

    c.push_back(std::make_shared<Bard>());
    c.push_back(std::make_shared<Druid>());
    c.push_back(std::make_shared<Knight>());
    c.push_back(std::make_shared<Wizard>());

    characters = c;
}

void Game::init_items(std::shared_ptr<Player> bard, std::shared_ptr<Player> druid, std::shared_ptr<Player> knight, std::shared_ptr<Player> wizard) {
    std::vector<std::shared_ptr<Item>> items;
    std::vector<std::shared_ptr<Item>> bard_items;
    std::vector<std::shared_ptr<Item>> druid_items;
    std::vector<std::shared_ptr<Item>> knight_items;
    std::vector<std::shared_ptr<Item>> wizard_items;
    std::vector<std::shared_ptr<Item>> enemy_item;

    items.push_back(std::make_shared<Armour>("Armour", armour_desc, -1, armour_def, armour_atk, 0));
    items.push_back(std::make_shared<Weapon>("Dagger", dagger_desc, -1, 0, dagger_atk, 0, 0));
    items.push_back(std::make_shared<Weapon>("Bow", bow_desc, -1, 0, bow_atk, 0, 0));
    items.push_back(std::make_shared<Item>("Potion", potion_desc, -1, 0, potion_hp, potion_def, potion_mana, 0, 0, 0, potion_cc, 0));
    bard_items.push_back(std::make_shared<Item>("Lyre", lyre_desc, -1, 0, 0, 0, lyre_mana, lyre_atk, 0, 0, 0, 0));
    bard_items.push_back(std::make_shared<Item>("Artefact", artefact_desc, -1, 0, artefact_hp, 0, artefact_mana, 0, artefact_lck, 0, 0, 0));
    druid_items.push_back(std::make_shared<Item>("Shield", shield_desc, -1, 0, 0, shield_def, 0, 0, 0, shield_hb, 0, 0));
    druid_items.push_back(std::make_shared<Weapon>("Sword", sword_desc, -1, 0, 7, sword_cc, 0));
    knight_items.push_back(std::make_shared<Armour>("Heavy Armour", heavy_armour_desc, -1, heavy_armour_def, 0, 0));
    knight_items.push_back(std::make_shared<Weapon>("Sword", sword_desc, -1, 0, 7, sword_cc, 0));
    wizard_items.push_back(std::make_shared<Item>("Artefact", artefact_desc, -1, 0, artefact_hp, 0, artefact_mana, 0, artefact_lck, 0, 0, 0));
    wizard_items.push_back(std::make_shared<Item>("Spellbook", spellbook_desc, -1, 0, spellbook_hp, 0, spellbook_mana, 0, 0, 0, 0, spellbook_int));
    enemy_item.push_back(std::make_shared<Armour>("Enemy Armour", enemy_armour_desc, -1, enemy_armour_def, enemy_armour_def, 0));
    enemy_item.push_back(std::make_shared<Weapon>("Enemy Weapon", enemy_weapon_desc, -1, enemy_weapon_def, enemy_weapon_atk, enemy_weapon_cc, 0));

    bard->setClassItems(bard_items);
    druid->setClassItems(druid_items);
    knight->setClassItems(knight_items);
    wizard->setClassItems(wizard_items);
    enemy_items = enemy_item;
    general_items = items;

}

void Game::init_actions(std::shared_ptr<Player> bard, std::shared_ptr<Player> druid, std::shared_ptr<Player> knight, std::shared_ptr<Player> wizard) {
    std::vector<std::shared_ptr<Action>> actions;
    std::vector<std::shared_ptr<Action>> bard_actions;
    std::vector<std::shared_ptr<Action>> druid_actions;
    std::vector<std::shared_ptr<Action>> knight_actions;
    std::vector<std::shared_ptr<Action>> wizard_actions;


    actions.push_back(std::make_shared<Dodge>("Dodge", dodging_desc, dodging_cost));
    actions.push_back(std::make_shared<StatModifyingAction>("Attack", attack_desc, attack_cost, 1, 0));
    actions.push_back(std::make_shared<StatModifyingAction>("Heal", healing_desc, healing_cost, 1, 0));
    actions.push_back(std::make_shared<StatModifyingAction>("Defend", defending_desc, defending_cost, 4, defend_value));
    actions.push_back(std::make_shared<StatModifyingAction>("Weaken", weakening_desc, weakening_cost, 4, -weaken_value));
    actions.push_back(std::make_shared<Equip>("Equip", equipping_desc, equipping_cost));
    knight_actions.push_back(std::make_shared<StatModifyingAction>("Heavy attack", heavy_attack_desc, heavy_attack_cost, 1, 0));
    bard_actions.push_back(std::make_shared<Distract>("Distraction", distraction_desc, distraction_cost));
    wizard_actions.push_back(std::make_shared<Spell>("Spell", spell_desc, spell_cost));


    bard->setClassActions(bard_actions);
    druid->setClassActions(druid_actions);
    knight->setClassActions(knight_actions);
    wizard->setClassActions(wizard_actions);
    general_actions = actions;
}


void Game::display() {
    if (state == 0) {
        std::cout << "                     | WELCOME TO THE GAME! |                     \n" << std::endl;
        std::cout << "To choose an option enter its number: " << std::endl;
        std::cout << "1. Start battle " << std::endl;
        std::cout << "2. Character selection " << std::endl;
        std::cout << "3. Game statistics " << std::endl;
        std::cout << "4. Settings | Help screen " << std::endl;
        std::cout << "5. Quit game " << std::endl;
    }

    else if (state == 1 || state == 11 || state == 12 || state == 13) {
        std::cout << "                            | BATTLE |                            \n" << std::endl;
        std::cout << "     " << player->getName() << "                                   " <<  enemy.getName() <<  "     " << std::endl;
        std::cout << "HP   " << player->getHealth() << "                             | HP   " << enemy.getHealth() << "        " << std::endl;
        std::cout << "ATK  " << player->getAttackPower() << "                             | ATK  " << enemy.getAttackPower() << "        " << std::endl;
        std::cout << "DEF  " << player->getDefence() << "                             | DEF  " << enemy.getDefence() << "        " << std::endl;
        std::cout << "MANA " << player->getMana() << "                             | MANA " << enemy.getMana() << "        " << std::endl;
        if (player->getCid() == 1) {
            std::cout << "LCK  " << player->getLuck() << "                             |" << std::endl;
        } else if (player->getCid() == 2) {
            std::cout << "HP BONUS " << player->getHealingBonus() << "                         |" << std::endl;
        } else if (player->getCid() == 3) {
            std::cout << "CRIT CHANCE " << player->getCritChance() << "                      |" << std::endl;
        } else if (player->getCid() == 4) {
            std::cout << "INT  " << player->getIntelligence() << "                             |" << std::endl;
        }
        std::cout << "\n_______________________________________________________________________________________\n" << std::endl;

        if (state == 1) {
            if (battle.get_turn()) {

                if (battle.getReportMessage() != -1) {
                    std::cout << report_messages[battle.getReportMessage()] << std::endl;
                    std::cout << "_______________________________________________________________________________________\n" << std::endl;
                }

                std::cout << "     CHOOSE AN ACTION     \n" << std::endl;
                int counter = 0;
                for (auto& act : battle.getActionsCatalogue()) {
                    if (act->getName() != "Dodge") {
                        std::cout << ++counter << ". " << act->getName() << " (Required mana: " << act->getManaUsage() << ") " << std::endl;
                        std::cout << act->getDesc() << "\n" << std::endl;
                    }
                }
                std::cout << "Make sure your character has enough mana to perform the chosen action or the inputted value will be ignored.\n" <<std::endl;
                std::cout << "To choose an action enter the number next to it. To return to the main screen enter x." << std::endl;
            }
            else {
                if (enemy.getNextAction()->getName() == "Attack" || enemy.getNextAction()->getName() == "Weaken") {
                    std::cout << "     THE ENEMY IS PLANNING AN ATTACK     " << std::endl;
                    std::cout << "_______________________________________________________________________________________\n" << std::endl;
                    std::cout << "1. Countinue" << std::endl;
                    std::cout << "2. Dodge " << " (Required mana: " << dodging_cost << ") " << std::endl;
                    std::cout << battle.getActionsCatalogue()[0]->getDesc() << "\n" << std::endl;
                }
                else {
                    std::cout << "     THE ENEMY IS CHOOSING NEXT ACTION     " << std::endl;
                    std::cout << "_______________________________________________________________________________________\n" << std::endl;
                    std::cout << "1. Countinue \n" << std::endl;
                }
                std::cout << "To proceed choose an option and enter the number next to it." << std::endl;
            }
        }

        else if (state == 11) {
            std::cout << "     CHOOSE AN ITEM TO EQUIP     \n" << std::endl;
            int counter = 0;
            for (auto& i : battle.getItemsCatalogue()) {
                std::cout << ++counter << ". " << i->getName() << std::endl;
                std::cout << i->getDesc() << "\n" << std::endl;
            }
            std::cout << "To choose an option enter the number next to it. To return to the action choice stage enter x." << std::endl;
        }

        else if (state == 12 || state == 13) {
            if (state == 12) { std::cout << "     THE PLAYER WINS     \n" << std::endl; }
            else { std::cout << "     THE ENEMY WINS     \n" << std::endl; }
            std::cout << "_______________________________________________________________________________________\n" << std::endl;
            std::cout << "The battle has finished. To return to the main screen enter x." << std::endl;
        }
    }

    else if (state == 2) {
        std::cout << "                            | CHARACTER EDITOR |                            \n" << std::endl;
        std::cout << "1. Set a name " << std::endl;
        std::cout << "2. Choose the character class \n" << std::endl;
        std::cout << "To choose an option enter the number next to it. To return to the main screen enter x." << std::endl;
    }

    else if (state == 21) {
        std::cout << "                   | NAME |                   \n" << std::endl;
        std::cout << "Enter the name you want your character to have. To return to the character editor screen enter x." << std::endl;
    }

    else if (state == 22) {
        std::cout << "                            | CHARACTER CLASS CHOICE |                            \n" << std::endl;
        int counter = 0;
        for (auto& ch : characters) {
            std::cout << ++counter << ". " << ch->getName() << std::endl;
            std::cout << ch->getDesc() << "\n" << std::endl;
        }
        std::cout << "Choosing or changing the character class will reset the name to the default name for the chosen character class. It can be changed later through the character editor screen.\n" << std::endl;
        std::cout << "To choose an option enter the number next to it. To return to the character editor screen enter x." << std::endl;
    }

    else if (state == 3) {
        std::cout << "                            | GAMES STATISTICS |                            \n" << std::endl;
        std::cout << "GAMES PLAYED : " << statistics.get_games() << std::endl;
        std::cout << "GAMES WON : " << statistics.get_score() << "\n" << std::endl;
        std::cout << "To return to the main screen enter x." << std::endl;
    }

    else if (state == 4) {
        std::cout << "                            | SETTINGS |                            \n" << std::endl;
        std::cout << "1. Select difficulty " << std::endl;
        std::cout << "                            | HELP |                            \n" << std::endl;
        std::cout << "The player can interact with the system through text input. To choose an option enter its number and press the enter button. \nUse the reminders on the screen to navigate between different screens.\n" << std::endl;
        std::cout << "To switch to difficulty selection enter 1. To return to the main screen enter x." << std::endl;
    }

    else if (state == 41) {
        std::cout << "                            | DIFFICULTY SELECTION |                            \n" << std::endl;
        std::cout << "Current difficulty: " << difficulty << "\n" << std::endl;
        std::cout << "1. Easy" << std::endl;
        std::cout << "2. Moderate\n" << std::endl;
        std::cout << "To choose an option enter the number next to it. To return to the settings screen enter x." << std::endl;
    }
}

void Game::start() {
    is_running = true;
    init_characters();
    init_items(characters[0], characters[1], characters[2], characters[3]);
    init_actions(characters[0], characters[1], characters[2], characters[3]);
    std::cout << "the game has started" << std::endl;
    while(is_running) {
        system("clear");
        Game::display();
        std::string input;
        std::cin >> input;
        if (state == 0) {
            if (input == "1") {
                Game::start_battle();
            }
            else if (input == "2") {
                Game::edit_character();
            }
            else if (input == "3") {
                Game::leaderboard();
            }
            else if (input == "4") {
                Game::settings();
            }
            else if (input == "5") {
                Game::quit();
            }
        }

        else if (state == 1) {

            if (player->getHealth() > 0 && enemy.getHealth() > 0) {
                if (battle.get_turn()) {

                    if (input == "x") {
                        exit_battle();
                    }
                    else if (input == "5") {
                        if (battle.is_enough_mana(*player, *battle.getActionsCatalogue()[5])) {
                            state = 11;
                        }
                    }
                    else if (is_numeric(input)) {

                        if (std::stoi(input) >= 1 && std::stoi(input) <= (static_cast<int>(battle.getActionsCatalogue().size()) - 1)) {

                            if (battle.is_enough_mana(*player, *battle.getActionsCatalogue()[std::stoi(input)])) {

                                battle.getActionsCatalogue()[std::stoi(input)]->execute(*player, enemy, battle, nullptr, *player);

                                if (battle.get_turn_block() == 0) {
                                    battle.set_turn(!(battle.get_turn()));
                                } else {
                                    battle.set_turn_block(battle.get_turn_block() - 1);
                                }

                                enemy.setMana(enemy.getMana() + enemy_mana_rest);
                                enemy.setNextAction(battle.getActionsCatalogue()[enemy_ai.chooseAction(*player, enemy, battle)]);
                            }
                        }
                    }
                }

                else {

                    if (is_numeric(input)) {

                        if (std::stoi(input) >= 1 && std::stoi(input) <= 2) {

                            if (!(input == "2" && battle.getActionsCatalogue()[0]->attempt(*player) && (enemy.getNextAction()->getName() == "Attack" || enemy.getNextAction()->getName() == "Weaken"))) {
                                std::shared_ptr<Item> it = nullptr;
                                if (enemy.getEquippingFlag() != 0) {
                                    if (enemy.getEquippingFlag() == 1) {
                                        it = enemy_items[0];
                                    }
                                    else if (enemy.getEquippingFlag() == 2) {
                                        it = enemy_items[1];
                                    }
                                    enemy.setEquippingFlag(0);

                                }
                                enemy.getNextAction()->execute(enemy, *player, battle, it, enemy);
                            }
                            else {
                                battle.setReportMessage(6);
                            }
                            battle.set_turn(!(battle.get_turn()));


                            int m;
                            if (player->getCid() == 4) {
                                m = wizard_mana_rest;
                            } else {
                                m = player_mana_rest;
                            }
                            if (player->getItem() != nullptr) {
                                m += player->getItem()->getManaBonus();
                            }
                            player->setMana(player->getMana() + m);


                            if (player->getCid() == 2) {
                                int h = player->getHealingBonus();
                                if (player->getItem() != nullptr) {
                                    h += player->getItem()->getHBBonus();
                                }
                                player->setHealth(player->getHealth() + h);
                            }

                        }
                    }
                }
            }

            if (player->getHealth() <= 0 || enemy.getHealth() <= 0) {
                statistics.set_games(statistics.get_games() + 1);
                if (enemy.getHealth() <= 0) {
                    statistics.set_score(statistics.get_score() + 1);
                    state = 12;
                } else {
                    state = 13;
                }
            }

        }

        else if (state == 11) {

            if (input == "x") {
                state = 1;
            }
            else if (is_numeric(input)) {
                if (std::stoi(input) >= 1 && std::stoi(input) <= static_cast<int>(battle.getItemsCatalogue().size())) {
                    std::shared_ptr<Item> i = battle.getItemsCatalogue()[std::stoi(input) - 1];
                    battle.getActionsCatalogue()[5]->execute(*player, enemy, battle, i, *player);
                    if (battle.get_turn_block() == 0) {
                        battle.set_turn(!(battle.get_turn()));
                    } else {
                        battle.set_turn_block(battle.get_turn_block() - 1);
                    }
                    enemy.setMana(enemy.getMana() + enemy_mana_rest);
                    enemy.setNextAction(battle.getActionsCatalogue()[enemy_ai.chooseAction(*player, enemy, battle)]);
                    state = 1;
                }
            }
        }

        else if (state == 12 || state == 13) {
            if (input == "x") {
                exit_battle();
            }
        }

        else if (state == 2) {
            if (input == "x") {
                state = 0;
            }
            else if (input == "1") {
                state = 21;
            }
            else if (input == "2") {
                state = 22;
            }
        }

        else if (state == 21) {
            player->setName(input);
            state = 2;
        }

        else if (state == 22) {
            if (input == "x") {
                state = 2;
            }
            else if (is_numeric(input)) {
                if (std::stoi(input) >= 1 && std::stoi(input) <= static_cast<int>(characters.size())) {
                    player = characters[std::stoi(input) - 1]->clone();
                    state = 2;
                }
            }
        }

        else if (state == 3) {
            if (input == "x") {
                state = 0;
            }
        }

        else if (state == 4) {
            if (input == "x") {
                state = 0;
            }
            else if (input == "1") {
                state = 41;
            }
        }

        else if (state == 41) {
            if (input == "x") {
                state = 4;
            }
            else if (input == "1") {
                difficulty = 1;
                state = 4;
            }
            else if (input == "2") {
                difficulty = 2;
                state = 4;
            }
        }
    }
    system("clear");

}

void Game::quit() {
    std::cout << "quittinng the game..." << std::endl;
    is_running = false;
}


void Game::start_battle() {
    std::vector<std::shared_ptr<Action>> temp_act = general_actions;
    std::vector<std::shared_ptr<Item>> temp_item = general_items;

    if (player->getCid() >= 1 && player->getCid() <= 4) {
        temp_act.insert(temp_act.end(), characters[player->getCid() - 1]->getClassActions().begin(), characters[player->getCid() - 1]->getClassActions().end());
        temp_item.insert(temp_item.end(), characters[player->getCid() - 1]->getClassItems().begin(), characters[player->getCid() - 1]->getClassItems().end());
    }
    battle.setActionsCatalogue(temp_act);
    battle.setItemsCatalogue(temp_item);

    if (difficulty == 1) {
        battle.set_turn(true);
        battle.setReportMessage(-1);
        enemy.setArmour(nullptr);
        enemy.setWeapon(nullptr);
    } else if (difficulty == 2) {
        battle.set_turn(false);
        battle.setReportMessage(-1);
        enemy = Enemy("Enemy", static_cast<int>(enemy_init_hp * difficulty_coef), static_cast<int>(enemy_init_mana * difficulty_coef), static_cast<int>(enemy_init_attack * difficulty_coef), static_cast<int>(enemy_init_defence * difficulty_coef), static_cast<int>(enemy_healing_rate * difficulty_coef), enemy_init_crit_chance * difficulty_coef, 0, battle.getActionsCatalogue()[1]);
        enemy.setArmour(std::dynamic_pointer_cast<Armour>(enemy_items[0]));
        enemy.setWeapon(std::dynamic_pointer_cast<Weapon>(enemy_items[1]));
    }
    state = 1;
}

void Game::edit_character() {
    state = 2;
}

void Game::leaderboard() {
    state = 3;
}

void Game::settings() {
    state = 4;
}

bool Game::is_numeric(std::string& input) {
    for (char c : input) {
        if (c < '0' || c > '9') {
            return false;
        }
    }
    return true;
}

void Game::exit_battle() {
    enemy = Enemy();
    std::string name = player->getName();
    if (player->getCid() == 0) {
        player = std::make_shared<Player>();
    } else if (player->getCid() >= 1 && player->getCid() <= 4) {
        player = characters[player->getCid() - 1]->clone();
    }
    player->setName(name);
    state = 0;
}


const std::vector<std::shared_ptr<Action>>& Game::getGeneralActions() const {
    return general_actions;
}

const std::vector<std::shared_ptr<Player>>& Game::getCharacters() const {
    return characters;
}

bool Game::getState() const {
    return is_running;
}


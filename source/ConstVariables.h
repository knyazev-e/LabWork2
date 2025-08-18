#ifndef CONSTVARIABLES_H
#define CONSTVARIABLES_H

#include <string>
#include <vector>


// Various consts

inline const int defend_value = 10;
inline const int weaken_value = 10;
inline const int crit_atk_coef = 2;
inline const int heavy_atk_addition = 3;
inline const double difficulty_coef = 1.3;

// Initializing the main character stats

inline const int player_init_hp = 80;
inline const int player_init_mana = 50;
inline const int player_init_attack = 15;
inline const int player_init_defence = 10;
inline const int player_healing_rate = 10;

inline const int enemy_init_hp = 100;
inline const int enemy_init_mana = 60;
inline const int enemy_init_attack = 15;
inline const int enemy_init_defence = 10;
inline const int enemy_healing_rate = 10;
inline const double enemy_init_crit_chance = 0.1;

inline const int bard_init_hp = 75;
inline const int bard_init_mana = 60;
inline const int bard_init_attack = 12;
inline const int bard_init_defence = 12;
inline const int bard_healing_rate = 10;
inline const double bard_init_luck = 0.2;

inline const int druid_init_hp = 90;
inline const int druid_init_mana = 60;
inline const int druid_init_attack = 60;
inline const int druid_init_defence = 14;
inline const int druid_healing_rate = 17;
inline const int druid_init_healing_bonus = 2;

inline const int knight_init_hp = 100;
inline const int knight_init_mana = 40;
inline const int knight_init_attack = 18;
inline const int knight_init_defence = 15;
inline const int knight_healing_rate = 10;
inline const double knight_init_crit_chance = 0.15;

inline const int wizard_init_hp = 70;
inline const int wizard_init_mana = 80;
inline const int wizard_init_attack = 13;
inline const int wizard_init_defence = 8;
inline const int wizard_healing_rate = 10;
inline const int wizard_init_intelligence = 14;

// Character class descriptions

inline const std::string default_desc = "Does not have special abilities or additional stats.";
inline const std::string bard_desc = "Has a luck bonus, increasing the probability of success when dodging the enemy's attacks. \nCan distract the enemy, making it skip the next turn.";
inline const std::string druid_desc = "Higher HP and healing rates. \nHas a healing bonus, which gets added to the HP at the end of every turn. \nIs the only character class capable of setting a shield.";
inline const std::string knight_desc = "Has the highest HP, can perform heavier attacks. \nWhen attacking, has the chance of doing critical damage (base damage multiplied by " + std::to_string(crit_atk_coef) + ").";
inline const std::string wizard_desc = "Has the highest mana, can perform spells, causing a random decrease in one of the enemy's stats.";

// Actions descriptions

inline const std::string attack_desc = "Damages the target.";
inline const std::string healing_desc = "Restores health points.";
inline const std::string defending_desc = "Increases the defence.";
inline const std::string weakening_desc = "Decreases the opponent's defence.";
inline const std::string equipping_desc = "Equips an item, a weapon or a piece of armour.";
inline const std::string dodging_desc = "Gives a chance of dodging the opponent's attack.";
inline const std::string heavy_attack_desc = "Damages the target more than a standard attack, but requires more mana.";
inline const std::string distraction_desc = "Makes the opponent skip the next turn.";
inline const std::string spell_desc = "Randomly chooses one of the target's main stats and modifies it by a random magnitude.";

// Items' descriptions

inline const std::string armour_desc = "Provides a defence bonus.";
inline const std::string dagger_desc = "Makes the attack slightly stronger.";
inline const std::string bow_desc = "Makes the attack moderately stronger.";
inline const std::string potion_desc = "Provides a slight bonus to most of the stats.";
inline const std::string lyre_desc = "Makes a Bard's attack power stronger.";
inline const std::string artefact_desc = "Increases the health and mana for Bards and Wizards.";
inline const std::string shield_desc = "Provides Druids with a significant defence bonus.";
inline const std::string sword_desc = "Makes Druids' and Knights' attacks significantly stronger.";
inline const std::string heavy_armour_desc = "Provides a significant defence bonus to Knights.";
inline const std::string spellbook_desc = "Provides a significant intelligence bonus to Wizards.";
inline const std::string enemy_armour_desc = "Provides the enemy with a defence bonus.";
inline const std::string enemy_weapon_desc = "Provides the enemy with an attack bonus.";

// Actions' mana usage

inline const int attack_cost = 5;
inline const int healing_cost = 10;
inline const int defending_cost = 6;
inline const int weakening_cost = 7;
inline const int equipping_cost = 0;
inline const int dodging_cost = 8;
inline const int heavy_attack_cost = 10;
inline const int distraction_cost = 10;
inline const int spell_cost = 15;

// Mana restoration rates

inline const int player_mana_rest = 5;
inline const int enemy_mana_rest = 5;
inline const int wizard_mana_rest = 7;

// Items' effects

inline const int armour_def = 5;
inline const int armour_atk = 1;

inline const int dagger_atk = 3;
inline const int bow_atk = 4;

inline const int potion_hp = 4;
inline const int potion_def = 1;
inline const int potion_mana = 1;
inline const double potion_cc = 0.01;

inline const int lyre_mana = 1;
inline const int lyre_atk = 2;

inline const int artefact_hp = 2;
inline const int artefact_mana = 3;
inline const double artefact_lck = 0.02;

inline const int shield_def = 2;
inline const int shield_hb = 3;

inline const int sword_atk = 7;
inline const double sword_cc = 0.05;

inline const int heavy_armour_def = 10;

inline const int spellbook_hp = 2;
inline const int spellbook_mana = 3;
inline const int spellbook_int = 10;

inline const int enemy_armour_def = 7;
inline const int enemy_armour_atk = 1;

inline const int enemy_weapon_def = 1;
inline const int enemy_weapon_atk = 5;
inline const double enemy_weapon_cc = 0.03;

// AI logic stats

inline const double low_hp = 0.35;
inline const int high_defence = 13;
inline const int low_defence = 5;

// Report messages

inline const std::vector<std::string> report_messages = {
    "The enemy made an attack.",
    "The enemy healed.",
    "The enemy rised the defence.",
    "The enemy lowered your defence.",
    "The enemy equipped their armour.",
    "The enemy equipped their weapon.",
    "You dodged the enemy's attack successfully."
};

#endif

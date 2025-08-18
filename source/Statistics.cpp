/* Kniazeva Eva Andreevna
st128104@student.spbu.ru
labwork2: rpg game */

#include "Statistics.h"

Statistics::Statistics() : player_score(0), games_played(0) {}

void Statistics::set_score(int score) {
    player_score = score;
}

int Statistics::get_score() {
    return player_score;
}

void Statistics::set_games(int games) {
    games_played = games;
}

int Statistics::get_games() {
    return games_played;
}


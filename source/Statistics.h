#ifndef STATISTICS_H
#define STATISTICS_H

class Statistics {
public:
    Statistics();

    void set_score(int score);
    int get_score();

    void set_games(int games);
    int get_games();
private:
    int player_score;
    int games_played;
};

#endif

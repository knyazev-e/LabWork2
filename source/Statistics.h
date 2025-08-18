#ifndef STATISTICS_H
#define STATISTICS_H

/**
 * @class Statistics
 * @brief Keeps track of the player's score and number of games played.
 */
class Statistics {
public:
    /**
     * @brief Default constructor initializes score and games played.
     */
    Statistics();

    /**
     * @brief Sets the player score.
     * @param score New player score.
     */
    void set_score(int score);

    /**
     * @brief Gets the player score.
     * @return Current player score.
     */
    int get_score();

    /**
     * @brief Sets the number of games played.
     * @param games Number of games played.
     */
    void set_games(int games);

    /**
     * @brief Gets the number of games played.
     * @return Number of games played.
     */
    int get_games();

private:
    int player_score; ///< Player's score (number of wins)
    int games_played; ///< Number of games played
};

#endif

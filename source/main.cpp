/* Kniazeva Eva Andreevna
st128104@student.spbu.ru
labwork2: rpg game */


#include <iostream>
#include "Game.h"


int main() {
    std::cout << "starting..." << std::endl;
    Game test_game;
    std::cout << "new game created" << std::endl;
    test_game.start();
    return 0;
}

#ifndef BOARD_H
#define BOARD_H

#include "Move.h"

class Board {
    public:
        Board();
        void enter_move(char player, int row, int col);
        bool checkgame();
        std::string get_current_state();
    private:
        char player;
        std::string current_state;
        int game_state[3][3] = {};
};

#endif

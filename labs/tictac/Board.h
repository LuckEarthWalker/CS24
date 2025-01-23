#ifndef BOARD_H
#define BOARD_H

#include "Move.h"

class Board {
    public:
        Board();
        void enter_move(char player, int row, int col);
        void checkgame();
    private:
        char game_state[3][3];
};

#endif

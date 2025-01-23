#ifndef BOARD_H
#define BOARD_H

#include "Move.h"

class Board {
    public:
        Board();
    private:
        char game_state[3][3];
}

#endif

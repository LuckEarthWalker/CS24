#include "Errors.h"
#include "Board.h"

// Space for implementing Board functions.
void Board::enter_move(char player, int row, int col) {
    if (game_state[row][col] == 0) {
        game_state[row][col] = player;
    }
}
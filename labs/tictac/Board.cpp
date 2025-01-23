#include "Errors.h"
#include "Board.h"
#include <iostream>

Board::Board() {
    player = 'a';
    current_state = "";
}

std::string Board::get_current_state() {
    return current_state;
}

void Board::enter_move(char player, int row, int col) {
    row--;
    col--;
    if (game_state[row][col] == 0) {
        game_state[row][col] = player;
        this->player = (player == 'X' ? 'O' : 'X');
    } else {
        throw InvalidMove("invalid location");
    }
}
//79-O  88-X
bool Board::checkgame() {
    if (player == 'a') {
        current_state = "Game in progress: New game.\n";
        return true;
    }
    //horizontal    O
    if ((game_state[0][0] + game_state[0][1] + game_state[0][2]) == 79*3 || (game_state[1][0] + game_state[1][1] + game_state[1][2]) == 79*3 || (game_state[2][0] + game_state[2][1] + game_state[2][2]) == 79*3) {
        current_state = "Game over: O wins.\n";
        return false;
    }
    //vertical      O
    if ((game_state[0][0] + game_state[1][0] + game_state[2][0]) == 79*3 || (game_state[0][1] + game_state[1][1] + game_state[2][1]) == 79*3 || (game_state[0][2] + game_state[1][2] + game_state[2][2]) == 79*3) {
        current_state = "Game over: O wins.\n";
        return false;
    }
    //diagonal      O
    if ((game_state[0][0] + game_state[1][1] + game_state[2][2]) == 3*79 || (game_state[0][2] + game_state[1][1] + game_state[2][0]) == 79*3) {
        current_state = "Game over: O wins.\n";
        return false;
    }
    //horizontal    X
    if ((game_state[0][0] + game_state[0][1] + game_state[0][2]) == 88*3 || (game_state[1][0] + game_state[1][1] + game_state[1][2]) == 88*3 || (game_state[2][0] + game_state[2][1] + game_state[2][2]) == 88*3) {
        current_state = "Game over: X wins.\n";
        return false;
    }
    //vertical      X
    if ((game_state[0][0] + game_state[1][0] + game_state[2][0]) == 88*3 || (game_state[0][1] + game_state[1][1] + game_state[2][1]) == 88*3 || (game_state[0][2] + game_state[1][2] + game_state[2][2]) == 88*3) {
        current_state = "Game over: X wins.\n";
        return false;
    } 
    //diagonal      X
    if ((game_state[0][0] + game_state[1][1] + game_state[2][2]) == 3*88 || (game_state[0][2] + game_state[1][1] + game_state[2][0]) == 88*3) {
        current_state = "Game over: X wins.\n";
        return false;
    }

    bool is_full = true;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (game_state[i][j] == 0) {
                is_full = false;
                break;
            }
        }
    }
    if (is_full) {
        current_state = "Game over: Draw.\n";
        return false;
    }

    if (player == 'O') {
        current_state = "Game in progress: O's turn.\n";
        return true;
    } else {
        current_state = "Game in progress: X's turn.\n";
        return true;
    }
}
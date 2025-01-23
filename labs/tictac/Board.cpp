#include "Errors.h"
#include "Board.h"
#include <iostream>

Board::Board() {
    player = 'a';
}

void Board::enter_move(char player, int row, int col) {
    if (game_state[row][col] == 0) {
        game_state[row][col] = player;
    } else {
        throw InvalidMove("invalid location");
    }
}
//79-O  88-X
void Board::checkgame() {
    if (player == 'a') {
        std::cout << "Game in progress: New game.\n";
        return;
    }
    //horizontal    O
    if ((game_state[0][0] + game_state[0][1] + game_state[0][2]) == 79*3 || (game_state[1][0] + game_state[1][1] + game_state[1][2]) == 79*3 || (game_state[2][0] + game_state[2][1] + game_state[2][2]) == 79*3) {
        std::cout << "Game over: O wins.\n";
        return;
    }
    //vertical      O
    if ((game_state[0][0] + game_state[1][0] + game_state[2][0]) == 79*3 || (game_state[0][1] + game_state[1][1] + game_state[2][1]) == 79*3 || (game_state[0][2] + game_state[1][2] + game_state[2][2]) == 79*3) {
        std::cout << "Game over: O wins.\n";
        return;
    }
    //diagonal      O
    if ((game_state[0][0] + game_state[1][1] + game_state[2][2]) == 3*79 || (game_state[0][2] + game_state[1][1] + game_state[2][0]) == 79*3) {
        std::cout << "Game over: O wins.\n";
        return;
    }
    //horizontal    X
    if ((game_state[0][0] + game_state[0][1] + game_state[0][2]) == 88*3 || (game_state[1][0] + game_state[1][1] + game_state[1][2]) == 88*3 || (game_state[2][0] + game_state[2][1] + game_state[2][2]) == 88*3) {
        std::cout << "Game over: O wins.\n";
        return;
    }
    //vertical      X
    if ((game_state[0][0] + game_state[1][0] + game_state[2][0]) == 88*3 || (game_state[0][1] + game_state[1][1] + game_state[2][1]) == 88*3 || (game_state[0][2] + game_state[1][2] + game_state[2][2]) == 88*3) {
        std::cout << "Game over: O wins.\n";
        return;
    }
    //diagonal      X
    if ((game_state[0][0] + game_state[1][1] + game_state[2][2]) == 3*88 || (game_state[0][2] + game_state[1][1] + game_state[2][0]) == 88*3) {
        std::cout << "Game over: O wins.\n";
        return;
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
        std::cout << "Game over: Draw.\n";
        return;
    }

    if (player == 'O') {
        std::cout << "Game in progress: O's turn.\n";
        return;
    } else {
        std::cout << "Game in progress: X's turn.\n";
        return;
    }
}
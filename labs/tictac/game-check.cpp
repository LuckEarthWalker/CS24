#include "Board.h"
#include "Errors.h"
#include "Move.h"
#include <iostream>

int main() {
    Board game;
    int move_num = 1;
    bool ongoing = true;
    std::string str;
    while(std::getline(std::cin, str)) {
        try {
            Move move(str);
            
            try {
                if (!ongoing) {
                    throw InvalidMove("game has ended");
                }
                if (move.number != move_num) {
                    throw InvalidMove("invalid move number");
                }
                game.enter_move(move.player, move.row, move.column);
                ongoing = game.checkgame();
            }
            catch(const InvalidMove& error) {
                std::cout << "Invalid move.\n";
                return 2;
            }
        }
        catch(const ParseError& e) {
            std::cout << "Parse error.\n";
            return 1;
        }
        move_num++;
    }
    if (game.get_current_state().empty()) {
        std::cout << "Game in progress: New game.\n";
        return 0;
    }
    std::cout << game.get_current_state();
    return 0;
}

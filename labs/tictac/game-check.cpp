#include "Board.h"
#include "Errors.h"
#include "Move.h"
#include <iostream>

int main() {
    Board game;
    bool ongoing = true;
    std::string str;
    while(std::getline(std::cin, str)) {
        try {
            Move move(str);
            try {
                if (!ongoing) {
                    throw InvalidMove("game has ended");
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
    }
    std::cout << game.get_current_state();
    return 0;
}

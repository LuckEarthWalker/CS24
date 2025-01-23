#include "Board.h"
#include "Errors.h"
#include "Move.h"
#include <iostream>

int main() {
    Board game;

    std::string str;
    while(std::getline(std::cin, str)) {
        try {
            Move move(str);
            try {
                game.enter_move(move.player, move.row, move.column);
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

    return 0;
}

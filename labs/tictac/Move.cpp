#include "Errors.h"
#include "Move.h"
#include <sstream>
#include <iostream>

Move::Move(const std::string& input) {

    std::istringstream move_ln(input);
    
    move_ln >> std::ws;

    //check move number
    std::string buffer;
    if (!(move_ln >> buffer) || buffer.empty()) {
        throw ParseError("invalid number.");
    }

    int temp = stoi(buffer);
    if (temp < 1 || temp > 9 || std::to_string(temp) != buffer) {
        throw ParseError("invalid number.");
    }
    number = temp;

    move_ln >> std::ws;

    //check player code
    if (!(move_ln >> buffer) || buffer.length() != 1) {
        throw ParseError("invalid player.");
    }
    if ((toupper(buffer[0]) != 'X' && toupper(buffer[0]) != 'O')) {
        throw ParseError("invalid player.");
    }
    player = toupper(buffer[0]);

    move_ln >> std::ws;

    //check square code
    if (!(move_ln >> buffer) || buffer.length() != 2) {
        throw ParseError("invalid location.");
    }
    buffer[0] = toupper(buffer[0]);
    if ((buffer[0] != 'A' && buffer[0] != 'B' && buffer[0] != 'C') || 
        (buffer[1] != '1' && buffer[1] != '2' && buffer[1] != '3')) {
        throw ParseError("invalid location.");
    }
    row = buffer[0] - 64;
    column = buffer[1] - '0';

    move_ln >> std::ws;

    //check comment validity
    if (!move_ln.eof()) {
        if (move_ln.peek() != '#') {
            throw ParseError("invalid format.");
        }
    }
}

std::string Move::to_string() const {
    std::string str(1, player);
    std::string str1(1, '@'+row);
    return std::to_string(number) + " " + str + " " + str1 + std::to_string(column);
}

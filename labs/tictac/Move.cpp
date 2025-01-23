#include "Errors.h"
#include "Move.h"
#include <sstream>
#include <iostream>

Move::Move(const std::string& input) {

    std::istringstream move_ln(input);
    
    //check move number
    int temp;
    move_ln >> temp;
    if (temp < 1 || temp > 9) {
        throw ParseError("invalid number.");
        exit(1);
    }
    number = temp;

    //check player code
    std::string buffer;
    move_ln >> buffer;
    if (buffer.size() != 1 || (toupper(buffer[0]) != 'X' && toupper(buffer[0]) != 'O')) {
        throw ParseError("invalid player.");
        exit(1);
    }
    player = toupper(buffer[0]);

    //check square code
    move_ln >> buffer;
    buffer[0] = toupper(buffer[0]);
    if (buffer.size() != 2 || (buffer[0] != 'A' && buffer[0] != 'B' && buffer[0] != 'C') || (buffer[1] != '1' && buffer[1] != '2' && buffer[1] != '3')) {
        throw ParseError("invalid location.");
        exit(1);
    }
    row = buffer[0] - 64;
    column = buffer[1] - '0';

    //check comment validity
    move_ln >> buffer;
    if (buffer[0] != '#' && !move_ln.eof()) {
        throw ParseError("Parse error.");
        exit(1);
    }
}

std::string Move::to_string() const {
    std::string str(1, player);
    std::string str1(1, '@'+row);
    return std::to_string(number) + " " + str + " " + str1 + std::to_string(column);
}

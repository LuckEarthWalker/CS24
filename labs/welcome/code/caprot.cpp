#include <iostream>
#include <string>
#include <cctype>
#include <vector>

void rotate_cap(std::string &str, int rotate_num);

int main(int argc, char* argv[]) {

    //error case
    if (argc != 2) {
        std::cerr << "USAGE: caprot [rotation]\n";
        exit(1);
    }

    std::string input_line;
    getline(std::cin, input_line);

    int rot_num = std::atoi(argv[1]);
    rotate_cap(input_line, rot_num);

    std::cout << input_line << std::endl;
}

void rotate_cap(std::string &str, int rotate_num) {
    int strlen = str.length();
    std::vector<int> cap_indexes;
    for (int i = 0; i < strlen; i++) {
        if (isupper(str[i])) {
            str[i] = tolower(str[i]);
            cap_indexes.push_back(i);
        }
    }
    for (int index : cap_indexes) {
        str[((index + rotate_num) % strlen + strlen) % strlen] = toupper(str[((index + rotate_num) % strlen + strlen) % strlen]);
    }
    return;
}
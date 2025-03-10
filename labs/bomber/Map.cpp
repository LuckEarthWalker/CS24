#include "Map.h"

Map::Map(std::istream& stream) {
    //recreate map
    std::string curr_row;
    while (std::getline(stream, curr_row)) {
        std::vector<char> row;
        for (char curr_space : curr_row) {
            if (isspace(curr_space)) {
                continue;
            } else {
                row.push_back(curr_space);
            }
        }
        map.push_back(row);
    }
    map_height = map.size();
    map_width = map[0].size();

    for (int i = 0; i < map_height; i++) {
        for (int j = 0; j < map_width; j++) {
            if (map[i][j] == '#') {
                Point temp(i,j);
                walls.insert(temp);
            }
            if (map[i][j] == '~') {
                Point temp(i,j);
                waters.insert(temp);
            }
        }
    }
}

void Map::print() {
    for (auto row : map) {
        for (auto space : row) {
            std::cout << space;
        }
        std::cout << "\n";
    }
}

std::string Map::route(Point src, Point dst) {
    // edgecases
    if (src.lat < 0 || src.lat > (int)map.size() || src.lng < 0 || src.lng > (int)map[0].size() || walls.count(src) == 1 || waters.count(src) == 1) {
        PointError error(src);
        throw error;
    }
    if (dst.lat < 0 || dst.lat > (int)map.size() || dst.lng < 0 || dst.lng > (int)map[0].size()) {
        PointError error(dst);
        throw error;
    }
    if (waters.find(dst) != waters.end()) {
        RouteError error(src,dst);
        throw error;
    }

    // tuple<lat, long, bomb_count> storing ministate
    std::unordered_set<std::tuple<int,int,int>> visted;
    std::queue<state> explorer;


    explorer.push({src, 0, ""});
    while (!explorer.empty()) {
        state curr = explorer.front();
        explorer.pop();

        if (curr.pt == dst) {
            return curr.path;
        }

        if (visted.count({curr.pt.lat, curr.pt.lng, curr.bomb_count}) > 0) {
            continue;
        }
        visted.insert({curr.pt.lat, curr.pt.lng, curr.bomb_count});

        for (char move : MOVESET) {
            // move pt and check if valid
            Point new_pt(curr.pt);
            if (move == 'n') {
                if (new_pt.lat == 0) {
                    continue;
                } else {
                    new_pt.lat--;
                }
            } else if (move == 'e') {
                if (new_pt.lng == map_width-1) {
                    continue;
                } else {
                    new_pt.lng++;
                }
            } else if (move == 's') {
                if (new_pt.lat == map_height-1) {
                    continue;
                } else {
                    new_pt.lat++;
                }
            } else {
                if (new_pt.lng == 0) {
                    continue;
                } else {
                    new_pt.lng--;
                }
            }

            // move
            char terrain = map[new_pt.lat][new_pt.lng];

            if (terrain == '.') {
                explorer.push({new_pt, curr.bomb_count, curr.path+move});
            } else if (terrain == '*') {
                explorer.push({new_pt, curr.bomb_count+1, curr.path+move});
            } else if (terrain == '#') {
                if (curr.bomb_count > 0) {
                    explorer.push({new_pt, curr.bomb_count-1, curr.path+move});
                }
            } else {
                continue;
            }
        }
    }
    return "No route from (" + std::to_string(src.lat) + ", " + std::to_string(src.lng) + ") to (" + std::to_string(dst.lat) + ", " + std::to_string(dst.lng) + ").\n";
}
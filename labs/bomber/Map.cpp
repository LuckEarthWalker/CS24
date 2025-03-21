#include "Map.h"

bool operator < (pstate state1, pstate state2) {
    return state1.dist < state2.dist;
}
// bool operator == (pstate state1, pstate state2) {
//     return state1.bomb_count == state2.bomb_count && state1.changed == state2.changed && state1.dist == state2.dist && state1.pt == state2.pt;
// }

Map::Map(std::istream& stream) {
    //recreate map
    std::string curr_row;
    map_height = 0;
    while (std::getline(stream, curr_row)) {
        map_height++;
        std::vector<char> row;
        map_width = 0;
        for (char curr_space : curr_row) {
            if (isspace(curr_space)) {
                continue;
            } else {
                map_width++;
                row.push_back(curr_space);
            }
            if (curr_space == '#') {
                Point temp(map_height-1,map_width-1);
                walls.insert(temp);
            }
            if (curr_space == '~') {
                Point temp(map_height-1,map_width-1);
                waters.insert(temp);
            }
        }
        map.push_back(row);
    }
}

double taxi_dist(Point pt1, Point pt2) {
    return (abs(pt2.lat-pt1.lat) + abs(pt2.lng-pt1.lng));
}

std::string Map::route(Point src, Point dst) { // A*
    // edgecases
    if (src.lat < 0 || src.lat >= (int)map.size() || src.lng < 0 || src.lng >= (int)map[0].size() || walls.count(src) == 1 || waters.count(src) == 1) {
        PointError error(src);
        throw error;
    }
    if (dst.lat < 0 || dst.lat >= (int)map.size() || dst.lng < 0 || dst.lng >= (int)map[0].size()) {
        PointError error(dst);
        throw error;
    }
    if (waters.count(dst) > 0) {
        RouteError error(src, dst);
        throw error;
    }

    // tuple<lat, long, bomb_count> storing ministate
    std::unordered_map<Point, int> visited;
    // std::unordered_set<std::tuple<int,int,int>> visted;
    std::priority_queue<pstate> explorer;

    if (map[src.lat][src.lng] == '*') {
        pstate temp = {src, 1, "", -1*taxi_dist(src, dst),{}};
        temp.changed.insert(src);
        explorer.push(temp);
    } else {
        explorer.push({src, 0, "", -1*taxi_dist(src, dst),{}});
    }

    while (!explorer.empty()) {
        pstate curr = explorer.top();
        explorer.pop();

        if (curr.pt.lat == dst.lat && curr.pt.lng == dst.lng) {
            return curr.path;
        }

        if (visited.count(curr.pt) > 0 && visited[curr.pt] >= curr.bomb_count) {
            continue;
        }
        visited[curr.pt] = curr.bomb_count;

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
                explorer.push({new_pt, curr.bomb_count, curr.path+move, -1*taxi_dist(new_pt,dst),curr.changed});
            } else if (terrain == '*') {
                if (curr.changed.count(new_pt) > 0) {
                    explorer.push({new_pt, curr.bomb_count, curr.path+move, -1*taxi_dist(new_pt,dst),curr.changed});
                } else {
                    pstate temp = {new_pt, curr.bomb_count+1, curr.path+move, -1*(taxi_dist(new_pt,dst)*.90),curr.changed};
                    temp.changed.insert(new_pt);
                    explorer.push(temp);
                }
            } else if (terrain == '#') {
                if (curr.changed.count(new_pt) > 0) {
                    explorer.push({new_pt, curr.bomb_count, curr.path+move, -1*taxi_dist(new_pt,dst),curr.changed});
                } else if (curr.bomb_count > 0) {
                    pstate temp = {new_pt, curr.bomb_count-1, curr.path+move, -1*(taxi_dist(new_pt,dst)*1.1), curr.changed};
                    temp.changed.insert(new_pt);
                    explorer.push(temp);
                }
            } else {
                continue;
            }
        }
    }
    RouteError error(src, dst);
    throw error;
}
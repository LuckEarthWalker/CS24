#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <unordered_set>
#include <tuple>
#include <queue>

#include "Point.h"
#include "Errors.h"

#define MOVESET {'n','e','s','w'}

struct state {
    Point pt;
    int bomb_count;
    std::string path;
};

// custom hashs to use unordered_set. template gotten from https://en.cppreference.com/w/cpp/utility/hash
template<>
struct std::hash<Point>
{
    std::size_t operator()(const Point& pt) const noexcept
    {
        std::size_t hash1 = std::hash<int>{}(pt.lat);
        std::size_t hash2 = std::hash<int>{}(pt.lng);
        return hash1 ^ (hash2 << 1);
    }
};

template<>
struct std::hash<std::tuple<int,int,int>>
{
    std::size_t operator()(const std::tuple<int,int,int>& tup) const noexcept
    {
        std::size_t hash1 = std::hash<int>{}(std::get<0>(tup));
        std::size_t hash2 = std::hash<int>{}(std::get<1>(tup));
        std::size_t hash3 = std::hash<int>{}(std::get<2>(tup));
        return ((hash1 ^ (hash2 << 1)) >> 1) ^ (hash3 << 1);
    }
};

class Map {
    int map_width;
    int map_height;

    std::vector<std::vector<char>> map;
    std::unordered_set<Point> walls;
    std::unordered_set<Point> waters;

public:
    Map(std::istream& stream);
    // ~Map();

    void print();
    std::string route(Point src, Point dst);
};

#endif

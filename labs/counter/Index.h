#ifndef INDEX_H
#define INDEX_H

#include "List.h"

#include <string>
#include <cmath>
#include <iostream>

class Index { //using FNV-1a hash function, sourced from https://en.wikipedia.org/wiki/Fowler%E2%80%93Noll%E2%80%93Vo_hash_function
private:
    //FNV hash parameters from wikipedia 
    const size_t FNV_prime = 16777619;
    const size_t FNV_offset = 2166136261;

    size_t map_size;
    size_t count;

    Node** map;

    size_t hashfunc(std::string str) const;
    void add_key(const std::string& key, Node* pair);
    void rehash();

public:
    Index();
    ~Index();

    void new_key(const std::string& key, Node* pair);
    Node* lookup(const std::string& key) const;
};

#endif

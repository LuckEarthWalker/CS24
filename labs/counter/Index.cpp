#include "Index.h"

// Index Member Functions
size_t Index::hashfunc(std::string str) const {
    size_t hash = FNV_offset;
    for (char c : str) {
        hash = hash ^ c;
        hash = hash * FNV_prime;
    }
    return hash%map_size;
}

void Index::rehash() {
    Node** temp = map;
    map = new Node*[map_size*2]();
    for (size_t i = 0; i < map_size; i++) {
        if (temp[i] != nullptr) {
            add_key(temp[i]->str, temp[i]);
        }
    }
    map_size *= 2;
    delete []temp;
    temp = nullptr;
}

Index::Index() {
    map = new Node*[32](); // use 32 due to it being closest 2^n to alphabet size
    map_size = 32;
    count = 0;
}

Index::~Index() {
    delete []map;
}

void Index::add_key(const std::string& key, Node* pair) {
    size_t index = hashfunc(key);
    size_t offset = 1;
    size_t buffer = index;

    while (map[buffer] != nullptr) {
        buffer = index;
        buffer = (size_t)(index + (offset + pow(offset, 2))/2)%map_size;
        offset++;
    }
    map[buffer] = pair;
    count++;
}

void Index::new_key(const std::string& key, Node* pair) {
    if ((float)count/map_size > .5) {
        rehash();
    }
    add_key(key, pair);
}

Node* Index::lookup(const std::string& key) const {
    size_t index = hashfunc(key);
    size_t offset = 1;
    size_t buffer = index;
    while (map[buffer] != nullptr && map[buffer]->str != key) {
        buffer = index;
        buffer = (size_t)(index + (offset + pow(offset, 2))/2)%map_size;
        offset++;
    }

    if (map[buffer] != nullptr) {
        return map[buffer];
    }
    return nullptr;
}

Node* Index::del_key(const std::string& key) {
    size_t index = hashfunc(key);
    size_t offset = 1;
    size_t buffer = index;
    while (map[buffer] != nullptr && map[buffer]->str != key) {
        buffer = index;
        buffer = (size_t)(index + (offset + pow(offset, 2))/2)%map_size;
        offset++;
    }

    if (map[buffer] != nullptr) {
        Node* temp = map[buffer];
        map[buffer] = nullptr;
        count--;
        return temp;
    }
    return nullptr;    
}
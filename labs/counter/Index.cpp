#include "Index.h"


size_t Index::hashfunc(std::string_view str) const {
    size_t hash = FNV_offset;
    for (char c : str) {
        hash = hash ^ c;
        hash = hash * FNV_prime;
    }
    return hash%map_size;
}

// size_t Index::hashfunc(std::string str) const {
//     size_t hash = 0;
//     for (char c : str) {
//         hash = hash * 101 + c;
//     }
//     return hash%map_size;
// }

void Index::rehash() {
    size_t counter = 0;
    Node** temp = map;
    map = new Node*[map_size << 1]();
    size_t previous_msize = map_size;
    map_size = map_size << 1;
    for (size_t i = 0; i < previous_msize; i++) {
        if (counter > count) {
            break;
        }
        if (temp[i] != nullptr) {
            add_key(temp[i]->str, temp[i]);
            counter++;
        }
    }
    delete []temp;
    temp = nullptr;
}

Index::Index() {
    map = new Node*[64](); // use 64 to avoid rehash for char count
    map_size = 64;
    count = 0;
}

Index::~Index() {
    delete []map;
}

void Index::add_key(std::string_view key, Node* pair) {
    size_t index = hashfunc(key);
    size_t offset = 1;
    size_t buffer = index;

    while (map[buffer] != nullptr) {
        buffer = (size_t)(index + (offset + offset*offset)/2)%map_size;
        offset++;
    }
    map[buffer] = pair;
    count++;
}

void Index::new_key(std::string_view key, Node* pair) {
    if ((float)count/map_size > .6) {
        rehash();
    }
    add_key(key, pair);
}

Node* Index::lookup(std::string_view key) const {
    size_t index = hashfunc(key);
    size_t offset = 1;
    size_t buffer = index;
    while (map[buffer] != nullptr && map[buffer]->str != key) {
        buffer = (size_t)(index + (offset + offset*offset)/2)%map_size;
        offset++;
    }

    if (map[buffer] != nullptr) {
        return map[buffer];
    }
    return nullptr;
}

Node* Index::del_key(std::string_view key) {
    size_t index = hashfunc(key);
    size_t offset = 1;
    size_t buffer = index;
    while (map[buffer] != nullptr && map[buffer]->str != key) {
        buffer = (size_t)(index + (offset + offset*offset)/2)%map_size;
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
#include "Counter.h"

size_t Counter::count() const {
    return pairs.count();
}

// int Counter::total() const {
//     Node* temp = pairs.Head();
//     int sum = 0;
//     while (temp != nullptr) {
//         sum += temp->num;
//         temp = temp->next;
//     }
//     return sum;
// }

int Counter::total() const {
    int sum = 0;
    for (auto itr = this->begin(); itr != this->end(); ++itr) {
        sum += itr.value();
    }
    return sum;
}

void Counter::inc(const std::string& key, int by) {
    Node* temp = hashmap.lookup(key);
    if (temp == nullptr) {
        temp = pairs.push_back(key, by);
        hashmap.new_key(key, temp);
        return;
    }
    temp->num += by;
}

void Counter::dec(const std::string& key, int by) {
    Node* temp = hashmap.lookup(key);
    if (temp == nullptr) {
        temp = pairs.push_back(key, -1*by);
        hashmap.new_key(key, temp);
        return;
    }
    temp->num -= by;
}

void Counter::del(const std::string& key) {
    Node* temp = hashmap.del_key(key);
    pairs.remove(temp);
}

int Counter::get(const std::string& key) const {
    Node* temp = hashmap.lookup(key);
    if (temp == nullptr) {
        return 0;
    }
    return temp->num;
}

void Counter::set(const std::string& key, int count) {
    Node* temp = hashmap.lookup(key);
    if (temp == nullptr) {
        temp = pairs.push_back(key, count);
        hashmap.new_key(key, temp);
        return;
    }
    temp->num = count;
}


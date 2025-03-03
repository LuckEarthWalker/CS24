#include "Counter.h"

Counter::Counter() {
}

Counter::~Counter() {
    pairs.~List();
}

size_t Counter::count() const {
    return pairs.count();
}

int Counter::total() const {
    Node* temp = pairs.Head();
    int sum = 0;
    while (temp != nullptr) {
        sum += temp->num;
        temp = temp->next;
    }
    return sum;
}

void Counter::inc(const std::string& key, int by) {
    Node* temp = pairs.find(key);
    temp->num += by;
}

void Counter::dec(const std::string& key, int by) {
    Node* temp = pairs.find(key);
    temp->num -= by;
}

void Counter::del(const std::string& key) {
    pairs.remove(key);
}

int Counter::get(const std::string& key) const {
    return pairs.find(key)->num;
}

void Counter::set(const std::string& key, int count) {
    Node* temp = pairs.find(key);
    temp->num = count;
}


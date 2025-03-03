#include "Counter.h"

Counter::Iterator::Iterator(Node* head) {
    it = head;
}

const std::string& Counter::Iterator::key() const {
    return it->str;
}

int Counter::Iterator::value() const {
    return it->num;
}

void Counter::Iterator::operator ++ () {
    it = it->next;
}

bool Counter::Iterator::operator == (const Iterator& other) const {
    if (this->it == other.it) {
        return true;
    }
    return false;
}

bool Counter::Iterator::operator != (const Iterator& other) const {
    if (this->it != other.it) {
        return true;
    }
    return false;
}

Counter::Iterator Counter::begin() const {
    Counter::Iterator temp(pairs.Head());
    return temp;
}

Counter::Iterator Counter::end() const {
    return nullptr;
}
#include "Heap.h"

Heap::Heap(size_t capacity) {
    mData = new Entry[capacity];
    mCapacity = capacity;
}

Heap::Heap(const Heap& other) {
    mData = new Entry[other.capacity()];
    mCapacity = other.capacity();
    mCount = other.count();

    for (size_t i = 0; i < mCount; i++) {
        mData[i] = other.lookup(i);
    }
}

Heap::Heap(Heap&& other) {
    mData = other.mData;
    other.mData = nullptr;

    mCapacity = other.capacity();
    other.mCapacity = 0;

    mCount = other.count();
    other.mCount = 0;
}

Heap::~Heap() {
    delete []mData;
    mData = nullptr;
}

size_t Heap::capacity() const {
    return this->mCapacity;
}

size_t Heap::count() const {
    return this->mCount;
}

const Heap::Entry& Heap::lookup(size_t index) const {
    return this->mData[index];
}

Heap::Entry Heap::pop() {
    return this->mData[0]; //stubbing
}

Heap::Entry Heap::pushpop(const std::string& value, float score) {
    return this->mData[0]; //stubbing
}

void Heap::push(const std::string& value, float score) {
    return; //stubbing
}

const Heap::Entry& Heap::top() const {
    return this->mData[0];
}
#include "Heap.h"
#include <stdexcept>

Heap::Heap(size_t capacity) {
    mData = new Entry[capacity];
    mCapacity = capacity;
    mCount = 0;
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
    this->mData = other.mData;
    other.mData = nullptr;

    this->mCapacity = other.capacity();
    other.mCapacity = 0;

    this->mCount = other.count();
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
    if (index >= mCount) {
        throw std::out_of_range("index is out of range");
    }
    return mData[index];
}

Heap::Entry Heap::pop() {
    if (mCount == 0) {
        throw std::underflow_error("empty heap, nothing to pop");
    }

    Heap::Entry temp = mData[0];
    //move leftmost node to top
    mData[0] = mData[mCount-1];
    //start node swapping
    size_t node_pos = 0;
    Heap::Entry least_child;
    size_t lc_pos;
    if (node_pos*2+1 < mCount && node_pos*2+2 < mCount) {
        least_child = (mData[node_pos*2+1].score < mData[node_pos*2+2].score) ? mData[node_pos*2+1] : mData[node_pos*2+2];
        lc_pos = (mData[node_pos*2+1].score < mData[node_pos*2+2].score) ? node_pos*2+1 : node_pos*2+2;
    } else if (node_pos*2+1 < mCount) { //based on min heap structure, if missing a child, then remaining must be left child
        least_child = mData[node_pos*2+1];
        lc_pos = node_pos*2+1;
    } else {
        mCount--;
        return temp;
    }
    while (mData[node_pos].score > least_child.score) {
        //swap nodes
        Heap::Entry buffer = mData[node_pos];
        mData[node_pos] = mData[lc_pos];
        mData[lc_pos] = buffer;

        //update node positions and least child
        node_pos = lc_pos;
        if (node_pos*2+1 < mCount && node_pos*2+2 < mCount) {
            least_child = (mData[node_pos*2+1].score < mData[node_pos*2+2].score) ? mData[node_pos*2+1] : mData[node_pos*2+2];
            lc_pos = (mData[node_pos*2+1].score < mData[node_pos*2+2].score) ? node_pos*2+1 : node_pos*2+2;
        } else if (node_pos*2+1 < mCount) { //based on min heap structure, if missing a child, then remaining must be left child
            least_child = mData[node_pos*2+1];
            lc_pos = node_pos*2+1;
        } else {break;}
    }
    mCount--;
    return temp;
}

Heap::Entry Heap::pushpop(const std::string& value, float score) {
    if (mCount == 0) {
        throw std::underflow_error("empty heap, nothing to pop");
    }
    Heap::Entry temp = mData[0];
    //move leftmost node to top
    mData[0].value = value;
    mData[0].score = score;
    //start node swapping
    size_t node_pos = 0;
    Heap::Entry least_child;
    size_t lc_pos;
    if (node_pos*2+1 < mCount && node_pos*2+2 < mCount) {
        least_child = (mData[node_pos*2+1].score < mData[node_pos*2+2].score) ? mData[node_pos*2+1] : mData[node_pos*2+2];
        lc_pos = (mData[node_pos*2+1].score < mData[node_pos*2+2].score) ? node_pos*2+1 : node_pos*2+2;
    } else if (node_pos*2+1 < mCount) { //based on min heap structure, if missing a child, then remaining must be left child
        least_child = mData[node_pos*2+1];
        lc_pos = node_pos*2+1;
    } else {
        return temp;
    }
    while (mData[node_pos].score > least_child.score) {
        //swap nodes
        Heap::Entry buffer = mData[node_pos];
        mData[node_pos] = mData[lc_pos];
        mData[lc_pos] = buffer;

        //update node positions and least child
        node_pos = lc_pos;
        if (node_pos*2+1 < mCount && node_pos*2+2 < mCount) {
            least_child = (mData[node_pos*2+1].score < mData[node_pos*2+2].score) ? mData[node_pos*2+1] : mData[node_pos*2+2];
            lc_pos = (mData[node_pos*2+1].score < mData[node_pos*2+2].score) ? node_pos*2+1 : node_pos*2+2;
        } else if (node_pos*2+1 < mCount) { //based on min heap structure, if missing a child, then remaining must be left child
            least_child = mData[node_pos*2+1];
            lc_pos = node_pos*2+1;
        } else {break;}
    }
    return temp;
}

void Heap::push(const std::string& value, float score) {
    if (mCount == mCapacity) {
        throw std::overflow_error("no space for new node");
    }

    mData[mCount].value = value;
    mData[mCount].score = score;
    size_t node_pos = mCount;
    mCount++;

    //swap nodes
    while (mData[node_pos].score < mData[(node_pos-1)/2].score) {
        Heap::Entry buffer = mData[node_pos];
        mData[node_pos] = mData[(node_pos-1)/2];
        mData[(node_pos-1)/2] = buffer;

        node_pos = (node_pos-1)/2;
    }
    return;
}

const Heap::Entry& Heap::top() const {
    if (mCount == 0) {
        throw std::underflow_error("empty heap, nothing to pop");
    }
    return this->mData[0];
}
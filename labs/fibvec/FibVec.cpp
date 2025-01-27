#include "FibVec.h"

// This provides exception types:
#include <stdexcept>
#include <cstddef>

// FibVec Function Implementations
FibVec::FibVec() {
    vector = new int[1];
    curr_size = 1;
    pre_size = 1;
    user_size = 0;
}

FibVec::~FibVec() {
    delete[] vector;
}

void FibVec::fib_next() {
    size_t temp = curr_size;
    curr_size = curr_size + pre_size;
    pre_size = temp;
}

void FibVec::fib_before() {
    size_t temp = pre_size;
    pre_size = curr_size - pre_size;
    curr_size = temp;
}

void FibVec::extend() {
    fib_next();
    int* temp = vector;
    vector = new int[curr_size];
    for (size_t i = 0; i < pre_size; i++) {
        vector[i] = temp[i];
    }
    delete[] temp;
}

size_t FibVec::capacity() const {
    return curr_size;
}

size_t FibVec::count() const {
    return user_size;
}

void FibVec::insert(int val, size_t i) {
    if (i >= curr_size || i >= user_size) { // catch invalid index
        throw std::out_of_range("invalid index for insert");
    }
    if (user_size+1 > curr_size) { // determine if resize needed
        extend();
    }

    for (size_t j = curr_size; j >= i; j--) {
        vector[j+1] = vector[j];
    }
    vector[i] = val;
}

int FibVec::lookup(size_t i) const {
    return 0;
}

int FibVec::pop() {
    return 0;
}

void FibVec::push(int val) {
    return;
}

int FibVec::remove(size_t i) {
    return 0;
}
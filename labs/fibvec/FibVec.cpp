#include "FibVec.h"

// This provides exception types:
#include <stdexcept>
#include <cstddef>
#include <iostream>

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

void FibVec::extend(size_t i) {
    fib_next();
    int* temp = vector;
    vector = new int[curr_size];
    for (size_t j = 0; j < user_size; j++) {
        if (j < i) {
            vector[j] = temp[j];
        } else {
            vector[j+1] = temp[j];
        }
    }
    delete[] temp;
}

void FibVec::retract(size_t i) {
    fib_before();
    int* temp = vector;
    vector = new int[curr_size];
    for (size_t j = 0; j < user_size; j++) {
        if (j < i) {
            vector[j] = temp[j];
        } else {
            vector[j] = temp[j+1];
        }
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
    if (i > curr_size || i > user_size) { // catch invalid index
        throw std::out_of_range("invalid index for insert");
    }
    if (user_size+1 > curr_size) { // determine if resize needed
        extend(i);
    } else {
        for (size_t j = user_size; j >= i+1; j--) {
            vector[j] = vector[j-1];
        }
    }

    vector[i] = val;
    user_size++;
}

int FibVec::lookup(size_t i) const {
    if (i >= user_size) {
        throw std::out_of_range("nonexistent index");
    }
    return vector[i];
}

int FibVec::pop() {
    if (user_size == 0) {
        throw std::underflow_error("no more values to pop");
    }
    user_size--;
    int pop_val = vector[user_size];
    if (user_size < curr_size-pre_size) {
        retract(user_size);
    }
    return pop_val;
}

void FibVec::push(int val) {
    if (user_size+1 > curr_size) { // determine if resize needed
        extend(user_size);
    }
    vector[user_size] = val;
    user_size++;
    return;
}

int FibVec::remove(size_t i) {
    if (i > curr_size || i > user_size) { // catch invalid index
        throw std::out_of_range("invalid index for insert");
    }
    if (user_size == 0) {
        throw std::underflow_error("no more values to pop");
    }

    int rm_val = vector[i];
    user_size--;
    if (user_size < curr_size-pre_size) {
        retract(i);
    } else {
        for (size_t j = i; j < user_size; j++) {
            vector[j] = vector[j+1];
        }
    }
    return rm_val;
}
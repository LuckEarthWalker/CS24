#include "Heap.h"
#include <iostream>

// Use this file to test your Heap class!
// This file won't be graded - do whatever you want.

int main() {
    Heap heap(8);

    heap.push("gold", 1);
    heap.push("iron", 5);
    heap.push("silver", -2);
    heap.pushpop("andisite", 11);

    while (heap.count() > 0) {
        std::cout << "[" << heap.pop().value << "] ";
    }
    std::cout << "\n";
    return 0;
}

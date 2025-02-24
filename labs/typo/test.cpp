#include "Heap.h"
#include <iostream>

// Use this file to test your Heap class!
// This file won't be graded - do whatever you want.

int main() {
    Heap heap(8);

    heap.push("iron", 5);
    heap.push("silver", 2);
    heap.push("gold", 1);
    heap.push("andisite", -11);

    for (size_t i = 0; i < heap.count(); i++) {
        std::cout << "[" << heap.lookup(i).value << "] ";
    }
    // while (heap.count() > 0) {
    //     std::cout << "[" << heap.pop().value << "] ";
    // }
    std::cout << "\n";
    return 0;
}

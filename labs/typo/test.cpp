#include "Heap.h"
#include <iostream>

// Use this file to test your Heap class!
// This file won't be graded - do whatever you want.

int main() {
    Heap heap(8);
    //(kings 3) (bears 3) (apostles 12) (pillars 5) (animals 12)
    heap.push("kings", 3);
    heap.push("bears", 3);
    heap.push("animals", 12);
    heap.push("apostles", 12);
    heap.push("pillars", 5);

    for (size_t i = 0; i < heap.count(); i++) {
        std::cout << "[" << heap.lookup(i).value << "] ";
    }
    // while (heap.count() > 0) {
    //     std::cout << "[" << heap.pop().value << "] ";
    // }
    std::cout << "\n";
    return 0;
}

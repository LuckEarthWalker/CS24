#include "FibVec.h"
#include <iostream>
#include <stdexcept>

// Use this file to test your FibVec class!
// This file won't be graded - do whatever you want.

int main() {
  FibVec fibvec;

  int array[] = {1,2,3,4,8,7};  
  try {
    fibvec.push(array[0]);
    fibvec.push(array[1]);
    fibvec.push(array[2]);
    fibvec.push(array[3]);
    fibvec.push(array[4]);
    fibvec.push(array[5]);
  } catch (const std::out_of_range& e) {
    std::cout << "invalid index\n";
    return 1;
  }

  fibvec.insert(19, 0);

  size_t size = fibvec.count();
  for (size_t i = 0; i < size; i++) {
    try {
      std::cout << fibvec.lookup(i) << " ";
    }
    catch (const std::out_of_range& e) {
      std::cout << "out of range\n";
      return 1;
    }
  }


  return 0;
}

#include "Set.h"
#include <iostream>

// Use this file to test your Set class.
// This file won't be graded - do whatever you want.

int main() {
  Set set;

  std::cout << set.insert("A") << " " << set.insert("B") << " " << set.insert("Z") << " " << set.insert("S") << "\n";
  std::string str = "A";
  std::cout << set.contains(str);


  return 0;
}

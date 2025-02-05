#include "List.h"
#include <iostream>

// Use this file to test your List class!
// This file won't be graded - do whatever you want.

int main() {
  List list;


  list.insert("A");
  list.insert("B");
  list.insert("C");
  list.insert("Fh");
  list.insert("D");
  list.insert("E");
  list.insert("F");
  list.insert("Bo");
  list.insert("H");

  list.print();
  std::cout << list.count() << "\n";

  std::cout << list.lookup(0) << "\n";
  return 0;
}

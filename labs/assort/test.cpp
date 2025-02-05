#include "List.h"
#include <iostream>

// Use this file to test your List class!
// This file won't be graded - do whatever you want.

int main() {
  List list;


  list.insert("A");
  list.print();
  list.insert("B");
  list.print();
  list.insert("C");
  list.print();
  list.insert("F");
  list.print();
  list.insert("D");
  list.print();
  list.insert("E");
  list.print();
  list.insert("F");
  list.print();
  list.insert("B");

  list.print();
  
  list.insert("H");
  list.print();
  return 0;
}

#ifndef COUNTER_H
#define COUNTER_H

#include "List.h"
#include "Index.h"

#include <cstddef>
#include <string>
#include <iostream>

// This is the Counter class you need to implement.
// It includes the Counter::Iterator as a nested class.

class Counter {
public:
  class Iterator {
    Node* it;

  public:
    Iterator(Node* head);

    std::string_view key() const;
    int value() const;

    void operator ++ ();
    bool operator == (const Iterator& other) const;
    bool operator != (const Iterator& other) const;
  };

private:
  List pairs;
  Index hashmap;

private:
  // Helper Functions

public:

  size_t count() const;
  int    total() const;

  void inc(std::string_view key, int by = 1);
  void dec(std::string_view key, int by = 1);
  void del(std::string_view key);
  int  get(std::string_view key) const;
  void set(std::string_view key, int count);

  Iterator begin() const;
  Iterator end() const;
};

#endif

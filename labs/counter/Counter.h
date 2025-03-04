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

    const std::string& key() const;
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

  void inc(const std::string& key, int by = 1);
  void dec(const std::string& key, int by = 1);
  void del(const std::string& key);
  int  get(const std::string& key) const;
  void set(const std::string& key, int count);

  Iterator begin() const;
  Iterator end() const;
};

#endif

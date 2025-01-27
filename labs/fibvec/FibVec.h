#ifndef FIBVEC_H
#define FIBVEC_H

// This provides the size_t type:
#include <cstddef>

class FibVec {
  // Member Variables
  int* vector;
  size_t curr_size;
  size_t pre_size;
  size_t user_size;

  // Helper Functions
  void fib_next();
  void fib_before();
  void extend(size_t i);
  void retract();

public:
  // Constructor and Destructor
  FibVec();
  ~FibVec();
  
  // Member Functions
  size_t capacity() const;
  size_t count() const;
  void insert(int val, size_t i);
  int lookup(size_t i) const;
  int pop();
  void push(int val);
  int remove(size_t i);

};

#endif

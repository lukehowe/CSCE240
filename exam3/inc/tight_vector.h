// Copyright 2022 Luke Howe
//
#ifndef EXAM3_INC_TIGHT_VECTOR_H_
#define EXAM3_INC_TIGHT_VECTOR_H_
// TightVector points:
//   Compilation: 0.5 (make test-tight-vector)
//   Style: 0.5 (make test tight-vector-style)
//   TestAppendEmpty: 0.5 (./test-tight-vector 0)
//   TestAppendNotEmpty: 1.0 (./test-tight-vector 1)
//   TestAppendEmpty: 0.5 (./test-tight-vector 2)
//   TestAppendNotEmpty: 1.0 (./test-tight-vector 3)
//   test-tight-vector-memory: 1.0 (make test-tight-vector-memory)
//
#include <cstddef>  // size_t


// TightVector class is an exploration of an alternative implementation of the
// vector class from the STL. This class maintains a tight bound on its
// underlying array. That is, its underlying array is always full or is not
// allocated if empty.
//
// To receive any points, you may not allocate any extra space. This is a test
// of your ability to manage memory that fills up or is not available. It is
// also a test of your ability to manage memory "in place."
//
class TightVector {
 public:
  TightVector();


  // Deletes any allocated memory
  //
  ~TightVector();


  // Adds a new element to the end of the array after growing the array by ONE
  // element.
  //
  void Append(int element);


  // Adds a new element to the beginning of the array after growing the array
  // by ONE element.
  //
  void Prepend(int element);


  // Used for open-box testing
  friend class TightVectorTester;  // ignore me

 private:
  int *array_;  // you must use this for memory
  size_t count_;  // you must use this for memory size
};

#endif  // EXAM3_INC_TIGHT_VECTOR_H_

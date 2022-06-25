// Copyright 2022 CSCE 240 Exam 3
//
#ifndef EXAM3_INC_TEST_TIGHT_VECTOR_H_
#define EXAM3_INC_TEST_TIGHT_VECTOR_H_

#include <exam3/inc/tight_vector.h>
#include <cassert>  // assert
#include <cstdlib>  // atoi
#include <iostream>

class TightVectorTester {
 public:
  /* tests for TightVector::Append both empty and with elements
   */
  bool TestAppendEmpty();
  bool TestAppendNotEmpty();
  
  /* tests for TightVector::Prepend both empty and with elements
   */
  bool TestPrependEmpty();
  bool TestPrependNotEmpty();

};

#endif  // EXAM3_INC_TEST_TIGHT_VECTOR_H_

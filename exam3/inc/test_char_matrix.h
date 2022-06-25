// Copyright 2022 CSCE 240 Exam 3
//
#ifndef EXAM3_INC_TEST_CHAR_MATRIX_H_
#define EXAM3_INC_TEST_CHAR_MATRIX_H_

#include <exam3/inc/char_matrix.h>
#include <cassert>  // assert
#include <cstdlib>  // atoi
#include <iostream>


// This is what your matrix and size parameters might look like
const size_t kTestRows = 7;
const size_t kTestCols = 4;
const char kTestMatrix[kTestRows][kTestCols] = {
 { 'z', 'y', 'w', 'v' },
 { 'u', 't', 's', 'r' },
 { 'q', 'p', 'o', 'n' },
 { 'm', 'l', 'k', 'j' },
 { 'i', 'h', 'g', 'f' },
 { 'h', 'g', 'f', 'e' },
 { 'd', 'c', 'b', 'a' },
};


class CharMatrixTester {
 public:
  // Converts kTestMatrix to const char** and uses to test fill constructor
  bool TestFillConstructor();

  // Converts kTestMatrix to const char** and uses to test copy constructor
  bool TestCopyConstructor();
  
  // Converts kTestMatrix to const char** and uses to test assignment operator
  bool TestAssignOperator();


  friend int main(int, char*[]);  // What a horrid idea this is. You should
                                  // ignore. I have my reasons. (;

 private:
  void BuildChars();
  void CleanChars();

  char** chars_;
};

#endif  // EXAM3_INC_TEST_CHAR_MATRIX_H_

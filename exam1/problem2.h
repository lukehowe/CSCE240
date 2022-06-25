// Copyright 2022 Luke Howe
#ifndef EXAM1_PROBLEM2_H_
#define EXAM1_PROBLEM2_H_
#include <string>
std::string SumDigits(const std::string& value);
const char kTestVal = 'A';  // used to test correct header construction
#endif  // EXAM1_PROBLEM2_H_

//  SumDigits
//   The function accepts a read-only std::string reference containing a signed
//   integer value and returns the sum of its digits as a string. For example,
//   input "12345" returns "15", i.e. 1 + 2 + 3 + 4 + 5.  Negative values
//   should be expected, such that "-12345" returns "-15".
//
//   Note that if you solve the problem by conversion to integers and back, the
//   functions std::stoi and std::to_string are useful and are found in the
//   string library already included. Usage of integer modulus by 10 (int_val %
//   10) and integer division by 10 (int_val / 10) can extract the ones-place
//   digit and shift-right all digits to the left of the ones-place.
//
//   A different solution would see you converting each character in the string
//   value to an integer and summing them. You would need to handle (possible)
//   leading signs, e.g., 12, +12, -12, etc.
//
//   Sometimes there may be errors such that strings containing something other
//   than integers are passed in. You should detect these errors and return the
//   empty string (""), e.g., 1two3, +twelve, etc. If you use std::stoi,
//   reference
//   the method you used in homework program 2, if not you will need to devise
//   your own.
//  Points:
//  - compilation: 1
//  - style: 1
//  - correctness: 3 (non-negative, negative, error)
//


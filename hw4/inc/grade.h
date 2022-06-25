// Copyright 2022 Luke Howe
//
#ifndef HW4_INC_GRADE_H_
#define HW4_INC_GRADE_H_
#include <string>

// namespace csce240 {

// Grade: Represents the outcome of a scored assignment consisting of scored
//   points of the assignment and total points of the assignment. Grades are
//   always non-negative.
//
//  Example Usage:
//    Grade a(3, 6), b(4, 7);
//    Grade sum = a.Plus(b);  // calculate sum of a and b
//    Grade two(2, 1);
//    Grade avg = sum.DividedBy(two);  // calculate average of a and b
class Grade {
 public:
  // constructor (unsigned int, unsigned int)
  //
  //  * Initializes instance with two integer parameters. First is points
  //      scored. Second is total points.
  //  * Precondition: scored is > -1 and total is > 0. You may assert.
Grade();
Grade(unsigned int pointsScored, unsigned int totalPoints);

  // scored: accessor method for points scored
  //
  //  * Returns points scored as unsigned integer
  //  * Does not modify calling instance; const method
inline unsigned int scored() const { return scored_; }

  // total: accessor method for total points possible
  //
  //  * Returns total points as unsigned integer
  //  * Does not modify calling instance; const method
inline unsigned int total() const { return total_; }

  // ToDouble: converts stored values into a precentage representing the
  //   percentage of scored points to total points.
  //
  //  * Accepts unsigned integer to set precision. The parameter represents the
  //      number of decimal places before rounding. For example, when parameter
  //      is 3, 7/32 is returned as 21.875; when 2, 7/32 is returned as 21.88.
  //  * THE DEFAULT VALUE OF PRECISION PARAMETER IS 3.
  //  * Returns floating point (double) approximation of the percentage of the
  //      total points earned.
  //  * Does not modify calling instance; const method.
const double ToDouble() const;
const double ToDouble(unsigned int precision) const;

  // ToString: converts stored values into a print-able format, e.g. 6/10
  //
  //  * Returns string containing s/p where s is the points scored and p is
  //      points possible. When s is 0, returns string 0.
  //  * Does not modify calling instance; const method.
const std::string ToString() const;

  // ToLetter: converts scored point's percentage of total points to a letter
  //   grade with possible +, e.g. 7/8 converts to a B or possibly B+
  //
  //  * Accepts unsigned integer (plus threshold) parameter which is percent of
  //      range at which a + is assigned. For example, when plus threshold is
  //      75, then:
  //        A+ : grade percent >= 97.5
  //        ...
  //        D+ : grade percent >= 67.5
  //      If plus threshold is a zero, there is no plus.
  //  * THE DEFAULT VALUE OF PLUS THRESHOLD PARAMETER IS 0.
  //  * Returns string containing the letter grade, including a possible +
  //      character. Uses a regular U.S. college-level percent breakdown;
  //        A : grade percent >= 90.0
  //        B : grade percent >= 80.0
  //        C : grade percent >= 70.0
  //        D : grade percent >= 60.0
  //        F : otherwise
  //  * Does not modify calling instance; const method.
const std::string ToLetter() const;
const std::string ToLetter(unsigned int threshold) const;

  // Equals: returns Boolean true or false depending on the equality of the
  //   ratio of the calling instance and the provided parameter, e.g. 1/2 ==
  //   2/4 returns true, 1/2 == 1/4 returns false.
  //
  //  * Accepts an instance of Grade class. Parameter is used as the
  //      right-hand-side of the equation:
  //        calling instance == Grade parameter
  //  * Returns a boolean value which is true if the calling instance's ratio
  //      and Grade parameter's ratio are equal:
  //        scored:possible == scored:possible
  //      Ratios are calculated exactly---that is floating point values are not
  //      used, only integer values.
  //  * Does not modify calling instance; const method.
const bool Equals(const Grade& rhs) const;

  // DividedBy: calculates and returns quotient (as a Grade instance) of
  //   calling instance divided by parameter, e.g. 1/2 / 1/4 returns 2/1
  //
  //  * Accepts an instance of the Grade class. It is used as the
  //      right-hand-side of the equation:
  //        calling instance / Grade parameter
  //  * Returns an instance of Grade class containing the result of equation
  //      above. The two instances' point values should be used as the two
  //      numerators and two denominators in the equation
  //        scored/possible / scored/possible
  //      The equation is calculated using fractional arithmetic.
  //  * Does not modify calling instance; const method.
const Grade DividedBy(const Grade& rhs) const;

  // Plus: calculates and returns the sum of the calling instance a
  //
  //  * Accepts an instance of Grade class. Parameter is used as the
  //      right-hand-side of the equation:
  //        calling instance + Grade parameter
  //  * Returns an instance of the Grade class containing the result of the
  //      above equation. The two instances' point values should be used as the
  //      two numerators and two denominators in the equation
  //        scored/possible + scored/possible
  //      The equation is calculated using fractional arithmetic.
  //  * Does not modify calling instance; const method.
  //
const Grade Plus(const Grade& rhs) const;

 private:
unsigned int scored_;
unsigned int total_;
};
// }  // namespace csce240
#endif  // HW4_INC_GRADE_H_

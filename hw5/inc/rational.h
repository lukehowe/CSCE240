// Copyright 2022 Luke Howe
//
#ifndef HW5_INC_RATIONAL_H_
#define HW5_INC_RATIONAL_H_
#include <cmath>
#include <string>

namespace csce240 {
namespace hw5 {
// Rational class: Represents the ratio of two integers. Will be extended
//                 (inherited from) by Grade class.
//
class Rational {
 public:
  // constructor ()
  //
  //  * Initializes object as 0/1. Is equivalent to Rational(0).
  Rational();

  // constructor (int)
  //
  //  * Initializes object with an integer parameter; the numerator. The
  //    denominator must be 1. You may modify the two parameter constructor to
  //    accept a default value of 1, instead.
  //  * Is explicit
  explicit Rational(int num);

  // constructor (int, int)
  //
  //  * Initializes object with two integer parameters; first is numerator,
  //    second is denominator
  //  * Precondition: second parameter is not 0. You may assert.
  //  * Method is explicit if second param has default value.
  Rational(int num, int den);


  // num: accessor method for numerator
  //
  //  * Returns numerator as a signed integer
  //  * Does not modify calling instance; const method.
  inline int num() const { return num_; }

  // den: accessor method for denominator
  //
  //  * Returns denominator as a signed integer
  //  * Does not modify calling instance; const method.
  inline int den() const { return den_; }

  // ToDouble:
  //
  //  * Returns double precision floating point containing the quotient of the
  //    numerator and denominator.
  //  * Does not modify calling object; const method.
  //  * Virtual method; not abstract.
  virtual const double ToDouble() const;


  // ToString: converts stored values into a print-able format, e.g. 6/10
  //
  //  * Returns string containing n/d where n is the numerator and d is the
  //    denominator.  When n is 0, returns string 0.
  //  * Does not modify calling object; const method.
  //  * Virtual method; not abstract.
virtual const std::string ToString() const;

  // Equals: returns true or false depending on the equality of the
  //         ratio of the calling object and a parameter Rational object, e.g.
  //           Rational(-1, 2).Equals(Rational(2, -4))
  //         returns true, while
  //           Rational(1, 2).Equals(Rational(1, 4))
  //         returns false.
  //
  //  * Accepts an object of Rational class. Parameter is used as the
  //    right-hand-side of the equation:
  //      calling object == Rational parameter
  //  * Returns a boolean value which is true if the calling object's ratio
  //    and Rational parameter's ratio are equal:
  //      numerator:denominator == numerator:denominator
  //    Ratios are calculated exactly---that is floating point values are not
  //    used, only integer values.
  //  * Does not modify calling object; const method.
  const bool Equals(const Rational rhs) const;

  // operator==: see Equals(Rational) above
  const bool operator==(const Rational rhs) const;

  // Equals: returns Boolean true or false depending on the equality of the
  //         ratio of the calling object and the provided parameter, e.g.
  //           Rational(4, -2).Equals(-2)
  //         returns true and
  //           Rational(65, 2).Equals(32)
  //         returns false.
  //
  //  * Accepts an integer parameter. Parameter is used as the right-hand-side
  //    of the equation:
  //      calling object == int parameter
  //  * Returns a boolean value which is true if the calling object's ratio
  //    and integer parameter's ratio are equal:
  //      scored:possible == integer:1
  //    Ratios are calculated exactly---that is floating point values are not
  //    used, only integer values.
  //  * Does not modify calling object; const method.
  const bool Equals(const int rhs) const;

  // operator==: see Equals(int) above
  const bool operator==(const int rhs) const;

  // DividedBy: calculates and returns quotient (as a Rational object) of
  //            calling object divided by parameter, e.g. 1/2 / 1/4 returns 2/1
  //
  //  * Accepts an object of the Rational class. It is used as the
  //    right-hand-side of the equation:
  //      calling Rational object / Rational object parameter
  //  * Returns an object of Rational class containing the result of equation
  //    above. The two objects' point values should be used as the two
  //    numerators and two denominators in the equation
  //      scored/possible / scored/possible
  //    The equation is calculated using fractional arithmetic.
  //  * Does not modify calling object; const method.
  const Rational DividedBy(const Rational rhs) const;
  // operator/: see DividedBy(Rational) above.
  const Rational operator/(const Rational rhs) const;

  // DividedBy: calculates and returns the quotient (as a Rational object) of
  //            the calling object and an integer value.
  //
  //  * Accepts an integer as the right-hand-side of qoutient with calling
  //    object using the equation:
  //      calling object / right-hand-side/1
  //  * Does not modify calling object; const method.
  const Rational DividedBy(const int rhs) const;
  // operator/: see DividedBy(int) above
  const Rational operator/(const int rhs) const;

  // Plus: calculates and returns the sum of the calling object and a
  //       Rational object.
  //
  //  * Accepts an object of Rational class. Parameter is used as the
  //    right-hand-side of the equation:
  //      calling object + parameter
  //  * Returns an object of the Rational class containing the result of the
  //    above equation.
  //  * Does not modify calling object; const method.
const Rational Plus(const Rational rhs) const;
  // operator+: see Plus(Rational) above.
const Rational operator+(const Rational rhs) const;

  // Plus: calculates and returns the sum of the calling object and an
  //       integer.
  //
  //  * Accepts an integer as the right-hand-side of summation with calling
  //    object using the equation:
  //      calling object + parameter/1
  //  * Does not modify calling object; const method.
const Rational Plus(const int rhs) const;
  // operator+: as Plus(int) above
const Rational operator+(const int rhs) const;

 private:
int num_;
int den_;
};

// operator/: Overloaded operator function to divide an int by a Rational. See
//       Rational::DividedBy(int)
//     above, except int / Rational, rather than the other way around
const Rational operator/(int lhs, Rational rhs);

// operator+: Overloaded operator function to add a Rational to an int. See
//       Rational::Plus(int)
//     above.
const Rational operator+(int lhs, Rational rhs);

// operator==: Overloaded operator function for comparison to integers. See
//       bool Rational::Equals(int)
//     above.
const bool operator==(int lhs, Rational rhs);

}  // namespace hw5
}  // namespace csce240
#endif  // HW5_INC_RATIONAL_H_

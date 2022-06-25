// Copyright 2022 Luke Howe
//
#include <hw5/inc/rational.h>
namespace csce240 {
namespace hw5 {

// Constructors
Rational::Rational() : num_(0), den_(1) {
    // empty
}

Rational::Rational(int num) : num_(num), den_(1) {
    // empty
}

Rational::Rational(int num, int den) : num_(num), den_(den) {
    if (den < 0 && num_ > 0) {
        num_ *= -1;
        den_ *= -1;
    }
    if (num_ < 0 && den_ < 0) {
        num_ *= -1;
        den_ *= -1;
    }
}

// ToString()
const std::string Rational::ToString() const {
if (num_ == 0)
    return "0";
return std::to_string(num_) + "/" + std::to_string(den_);
// return num_ + "/" + den_;
}

// ToDouble()
const double Rational::ToDouble() const {
double numerator = num_;
double denominator = den_;
return numerator / denominator;
}

// Equals(rational)
const bool Rational::Equals(const Rational rhs) const {
int this_num = num_;
int this_den = den_;
int that_num = rhs.num();
int that_den = rhs.den();
int lhs_num = this_num*that_den;
int rhs_num = that_num*this_den;
if (lhs_num == rhs_num)
    return true;
return false;
}

// Operator==rational
const bool Rational::operator==(const Rational rhs) const {
    return Equals(rhs);
}

// Equals(int)
const bool Rational::Equals(const int rhs) const {
if (num_ / den_ == rhs)
    return true;
return false;
}

// Operator==int
const bool Rational::operator==(const int rhs) const {
    return Equals(rhs);
}

// DividedBy(rational)
const Rational Rational::DividedBy(const Rational rhs) const {
    int this_num = num_;
    int this_den = den_;
    int that_num = rhs.den();
    int that_den = rhs.num();
    int returnNum = this_num * that_num;
    int returnDen = this_den * that_den;
    return Rational(returnNum, returnDen);
}

// Operator/rational
const Rational Rational::operator/(const Rational rhs) const {
    return DividedBy(rhs);
}

// DividedBy(int)
const Rational Rational::DividedBy(const int rhs) const {
    int this_num = num_;
    int this_den = den_;
    int that_num = 1;
    int that_den = rhs;
    int returnNum = this_num * that_num;
    int returnDen = this_den * that_den;
    return Rational(returnNum, returnDen);
}

// Operator/int
const Rational Rational::operator/(const int rhs) const {
    return DividedBy(rhs);
}

// Operator int/rational
const Rational operator/(int lhs, Rational rhs) {
    return Rational(lhs, 1).DividedBy(rhs);
}

// Plus(rational)
const Rational Rational::Plus(const Rational rhs) const {
int this_num = num_;
int this_den = den_;
int that_num = rhs.num();
int that_den = rhs.den();
if (this_den == that_den) {
    int newNum = this_num + that_num;
    return Rational(newNum, this_den);
}
int swapDen = this_den * that_den;
int swapFirstNum = this_num * that_den;
int swapSecNum = this_den * that_num;
int retNum = swapFirstNum + swapSecNum;
return Rational(retNum, swapDen);
}

// Operator +(rational)
const Rational Rational::operator+(const Rational rhs) const {
return Plus(rhs);
}

// Plus(int)
const Rational Rational::Plus(const int rhs) const {
return Plus(Rational(rhs, 1));
}

// Operator+(int)
const Rational Rational::operator+(const int rhs) const {
return Plus(Rational(rhs, 1));
}

// Operator rational+int
const Rational operator+(int lhs, Rational rhs) {
    return Rational(lhs, 1).Plus(rhs);
}

// Operator int==rational
const bool operator==(int lhs, Rational rhs) {
    return Rational(lhs, 1).Equals(rhs);
}



// Namespaces
}  // namespace hw5
}  // namespace csce240

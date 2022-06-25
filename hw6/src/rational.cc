// Copyright 2022 Luke Howe
//
#include <hw6/inc/rational.h>

namespace csce240 {
namespace hw6 {

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

bool Rational::operator==(const Rational& rhs) const {
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

std::ostream& operator<<(std::ostream& lhs, const Rational& rhs) {
    double numerator = rhs.num();
    double denominator = rhs.den();
    if (numerator == 0) {
        lhs << "0";
        return lhs;
    }
    if (denominator == 1) {
        lhs << numerator;
        return lhs;
    }
    lhs << numerator << "/" << denominator;
    return lhs;
}

}  // namespace hw6
}  // namespace csce240

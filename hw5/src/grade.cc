// Copyright 2022 Luke Howe
//
#include <hw5/inc/grade.h>
namespace csce240 {
namespace hw5 {
Grade::Grade(unsigned int scored, unsigned int total) :
                                                 Rational(scored, total),
                                                 scored_(scored),
                                                 total_(total) {
// empty
}
// ToDouble()
const double Grade::ToDouble(unsigned int precision) const {
    // double this_scored = scored_;
    // double this_total = total_;
    // double val = (this_scored / this_total*100);
    // for (size_t i = 0; i < precision; i++) {
    //     val *= 10;
    // }
    // val = round(val);
    // for (size_t i = 0; i < precision; ++i) {
    //     val /= 10;
    // }
    // return val;
    double this_scored = scored_;
    double this_total = total_;
    double val = (this_scored / this_total*100);
    val *= pow(10, precision);
    val = round(val);
    val /= pow(10, precision);
    return val;
}

// ToDouble() virtual
const double Grade::ToDouble() const {
    // double this_scored = scored_;
    // double this_total = total_;
    // double val = this_scored/this_total*100;
    // for (int i = 0; i < 3; i++) {
    //     val *= 10;
    // }
    // val = round(val);
    // for (int i = 0; i < 3; i++) {
    //     val /= 10;
    // }
    // return val;
    double this_scored = scored_;
    double this_total = total_;
    double val = (this_scored / this_total*100);
    val *= pow(10, 3);
    val = round(val);
    val /= pow(10, 3);
    return val;
}

// ToString()
const std::string Grade::ToString() const {
    int this_scored = scored_;
    std::string scored = std::to_string(this_scored);
    int this_total = total_;
    std::string total = std::to_string(this_total);
    return scored + "/" + total;
}

// Operator==(grade)
const bool Grade::operator==(const Grade rhs) const {
return Equals(Rational(rhs.num(), rhs.den()));
}

// Operator==(int)
const bool Grade::operator==(const int rhs) const {
return Equals(rhs);
}

// Overloaded operator==(int, grade)
const bool operator==(const int lhs, const Grade rhs) {
return Rational(lhs, 1).Equals(Rational(rhs.num(), rhs.den()));
}

}  // namespace hw5
}  // namespace csce240

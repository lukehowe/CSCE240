// Copyright 2022 Luke Howe
//
#include <hw4/inc/grade.h>
#include <cmath>
#include <iostream>

// namespace csce240 {
// default constructor
Grade::Grade() : scored_(0), total_(1) {
    // empty
}
// init constructor
Grade::Grade(unsigned int scored, unsigned int total) :
                    scored_(scored), total_(total) {
    // empty
}

// toDouble method
const double Grade::ToDouble() const {
    double this_scored = scored_;
    double this_total = total_;
    double val = this_scored/this_total*100;
    for (int i = 0; i < 3; i++) {
        val *= 10;
    }
    val = round(val);
    for (int i = 0; i < 3; i++) {
        val /= 10;
    }
    return val;
}

const double Grade::ToDouble(unsigned int precision) const {
    double this_scored = scored_;
    double this_total = total_;
    double val = (this_scored / this_total*100);
    for (size_t i = 0; i < precision; i++) {
        val *= 10;
    }
    val = round(val);
    for (size_t i = 0; i < precision; ++i) {
        val /= 10;
    }
    return val;
}

// ToString method
const std::string Grade::ToString() const {
    int this_scored = scored_;
    std::string scored = std::to_string(this_scored);
    int this_total = total_;
    std::string total = std::to_string(this_total);
    if (this_scored == 0) {
        return "0";
    } else {
        return scored + "/" + total;
    }
}

// ToLetter method
const std::string Grade::ToLetter() const {
    double this_scored = scored_;
    double this_total = total_;
    double val = this_scored / this_total * 100;
    if (val >= 90.0)
        return "A";
    if (val >= 80.0)
        return "B";
    if (val >= 70.0)
        return "C";
    if (val >= 60.0)
        return "D";
    else
        return "F";
}

const std::string Grade::ToLetter(unsigned int threshold) const {
    double newThresh = threshold / 10;
    double this_scored = score_;
    double this_total = total_;
    double val = this_scored / this_total * 100;
    if (val >= 90.0 + newThresh)
        return "A+";
    if (val >= 90.0)
        return "A";
    if (val >= 80.0 + newThresh)
        return "B+";
    if (val >= 80.0)
        return "B";
    if (val >= 70.0 + newThresh)
        return "C+";
    if (val >= 70.0)
        return "C";
    if (val >= 60.0 + newThresh)
        return "D+";
    if (val >= 60.0)
        return "D";
    else
        return "F";
}

// Equals method
const bool Grade::Equals(const Grade& rhs) const {
// double this_scored = scored_;
// double this_total = total_;
// double that_scored = rhs.scored();
// double that_total = rhs.total();
// double this_ratio = (this_scored/this_total);
// double that_ratio = (that_scored/that_total);
// std::cout << this_ratio << " = " << that_ratio << "?" << std::endl;
// if(this_ratio == that_ratio) {
//     return true;
// }
// return false;
// ----------------------------------------------------------------------------
// unsigned int this_scored = scored_;
// unsigned int this_total = total_;
// unsigned int that_scored = rhs.scored();
// unsigned int that_total = rhs.total();
// if (this_total % this_scored == 0 && that_total % that_scored != 0) {
//     return false;
// }
// if (this_total % this_scored != 0 && that_total % that_scored == 0) {
//     return false;
// }
// if (this_total % this_scored == 0 && that_total % that_scored == 0) {
//     unsigned int this_newDen = this_total / this_scored;
//     unsigned int this_newNum = this_scored / this_scored;
//     unsigned int that_newDen = that_total / that_scored;
//     unsigned int that_newNum = that_scored / that_scored;
//     if (this_newDen == that_newDen && this_newNum == that_newNum)
//         return true;
// } else {
// unsigned int this_mod = this_total % this_scored;
// unsigned int this_newDen = this_total / this_mod;
// unsigned int this_newNum = this_scored / this_mod;
// unsigned int that_mod = that_total % that_scored;
// unsigned int that_newDen = that_total / that_mod;
// unsigned int that_newNum = that_scored / that_mod;
//     if (this_newDen == that_newDen && this_newNum == that_newNum) {
//         return true;
//     }
// }
// return false;
// ----------------------------------------------------------------------------
unsigned int this_scored = scored_;
unsigned int this_total = total_;
unsigned int that_scored = rhs.scored();
unsigned int that_total = rhs.total();
unsigned int this_num = this_scored * that_total;
unsigned int that_num = that_scored * this_total;
if (this_num == that_num) {
    return true;
}
return false;
}

// DividedBy method
const Grade Grade::DividedBy(const Grade& rhs) const {
unsigned int this_scored = scored_;
unsigned int this_total = total_;
unsigned int that_scored = rhs.total();
unsigned int that_total = rhs.scored();
unsigned int num = this_scored * that_scored;
unsigned int den = this_total * that_total;
return Grade(num, den);
}

// Plus method
const Grade Grade::Plus(const Grade& rhs) const {
unsigned int this_scored = scored_;
unsigned int this_total = total_;
unsigned int that_scored = rhs.scored();
unsigned int that_total = rhs.total();
if (this_total == that_total) {
    unsigned int newDen = this_scored + that_scored;
    return Grade(newDen, this_total);
}
unsigned int this_den = this_total * that_total;
unsigned int this_num = this_scored * that_total;
unsigned int that_num = that_scored * this_total;
unsigned int ret_num = this_num + that_num;
return Grade(ret_num, this_den);
}
// }  // namespace csce240

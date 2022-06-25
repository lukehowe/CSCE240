// Copyright 2022 Luke Howe
//
#include <hw4/inc/gradebook.h>
#include <iostream>
#include <vector>
// namespace csce240 {
// default constructor
GradeBook::GradeBook() : elements_(nullptr), size_(0), count_(0) {
    // empty
}

// init constructor
GradeBook::GradeBook(Grade *elements, size_t size, size_t count) :
                        elements_(elements), size_(size), count_(count) {
    // empty
}
// GradeBook::GradeBook(vector<Grade> elements, size_t size, size_t count) :
//                         elements_(elements), size_(size), count_(count) {
//     // empty
// }

// Get method
Grade GradeBook::Get(size_t index) const {
// if (count_ < index) {
//     return Grade(0, 1);
// }
// return elements_[index];
// ----------------------------------------------------------------------------
if (index < size_) {
    return elements_[index];
}
return Grade(0, 1);
// return elements_[index];
}

// Add method
void GradeBook::Add(Grade grade) {
double delta = 2;
// case 1: elements_ is null
if (!elements_) {
    size_ = 2;
    elements_ = new Grade[size_];
    count_ = 0;
}
// case 2: elements_ is full
if (count_ == size_) {
    Grade *tmp = new Grade[static_cast<size_t>(delta * size_)];
    for (size_t i = 0; i < size_; ++i) {
        *(tmp + i) = *(elements_ + i);
    }
    delete [] elements_;
    elements_ = tmp;
    size_ = static_cast<size_t>(delta * size_);
}
elements_[count_] = grade;
count_++;
}

// Add GradeBook method
const GradeBook GradeBook::Add(const GradeBook rhs) const {
size_t newSize = size_ + rhs.size();
size_t newCount = count_ + rhs.count();
Grade *retElements = new Grade[newSize];
for (size_t i = 0; i < count_; i++) {
    retElements[i] = elements_[i];
}
for (size_t i = 0; i < rhs.count(); i++) {
    retElements[i+count_] = rhs.elements_[i];
}
return GradeBook(retElements, newSize, newCount);
}

// CalcAverage function
const Grade GradeBook::CalcAverage() const {
if (count_ == 0) {
    return Grade(1, 1);
}
Grade tmp = Grade(0, 0);
unsigned int numOfFractions = 0;
for (size_t i = 0; i < count_; i++) {
    tmp.Plus(elements_[i]);
    numOfFractions++;
}
unsigned int denom = tmp.total()*numOfFractions;
return Grade(tmp.scored(), denom);
}
// }  // namespace csce240

// Copyright 2022 Luke Howe
//

#include <exam3/inc/char_matrix.h>

CharMatrix::CharMatrix(const char** chars,
                        ::size_t rows,
                        ::size_t cols) : matrix_(const_cast<char**>(chars)),
                        rows_(rows), cols_(cols) {
// empty
}

CharMatrix::CharMatrix(const CharMatrix& that) : matrix_(nullptr),
 rows_(0), cols_(0) {
    rows_ = that.rows_;
    cols_ = that.cols_;
    if (that.matrix_) {
        char** retMatrix;
        for (size_t r = 0; r < rows_; ++r) {
            retMatrix = new char*[that.rows_];
        }
        // retMatrix = new char*[that.rows_];
        for (size_t n = 0; n < cols_; ++n) {
            retMatrix[n] = new char[that.cols_];
        }
        for (size_t n = 0; n < rows_; ++n) {
            for (size_t nn = 0; nn < cols_; ++nn) {
                matrix_[n][nn] = that.matrix_[n][nn];
            }
        }
    }
}


CharMatrix::~CharMatrix() {
// empty
}

const CharMatrix& CharMatrix::operator=(const CharMatrix& rhs) {
matrix_ = rhs.matrix_;
rows_ = rhs.rows_;
cols_ = rhs.cols_;
for (size_t n = 0; n < rhs.rows_; ++n) {
    for (size_t nn = 0; nn < rhs.cols_; ++nn) {
        matrix_[n][nn] = rhs.matrix_[n][nn];
    }
}
return *this;
}

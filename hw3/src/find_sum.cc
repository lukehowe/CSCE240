// Copyright 2022 Luke Howe
#include <hw3/inc/find_sum.h>
#include <array>
#include <iostream>

// Find sum method. Essentially the "main method". used to call helper methods
const size_t** FindSum(const int** matrix,
                       const size_t* matrix_size,
                       int search_sum,
                       size_t* sums_found) {
    // initialize sums found to 0
    *sums_found = 0;
    // create return array based off sums found
    size_t** coordinates;  // declare return array
    size_t size = 4;  // create starting size
    coordinates = new size_t*[size];  // create inner array
    // allocate inner array
    coordinates[kIndices_start_row_idx] = new size_t[kIndices_size];
    // allocate outer array using for loop
    for (size_t n = 0; n < size; ++n) {
        coordinates[n] = new size_t[kIndices_size];
    }
    // iterate through 2d array / matrix
    for (size_t i = 0; i < matrix_size[kMatrix_size_rows_idx]; ++i) {
        for (size_t ii = 0; ii < matrix_size[kMatrix_size_cols_idx]; ++ii) {
            // check for single result
            if (SearchSingleResult(matrix, matrix_size,
              search_sum, i, ii, coordinates, sums_found, &size)) {
                  break;
              }
              // search row
            SearchRow(matrix, matrix_size,
              search_sum, i, ii, coordinates, sums_found, &size);
              // search column
            SearchCol(matrix, matrix_size,
              search_sum, i, ii, coordinates, sums_found, &size);
              // search ascending diagonally
            SearchAscDiag(matrix, matrix_size,
              search_sum, i, ii, coordinates, sums_found, &size);
              // search descending diagonally
            SearchDscDiag(matrix, matrix_size,
              search_sum, i, ii, coordinates, sums_found, &size);
        }
    }
    // return array as read only (const)
return const_cast<const size_t**>(coordinates);
                       }

void SearchRow(const int** matrix, const size_t* matrix_size, int search_sum,
size_t currRow, size_t currCol, size_t **coordinates, size_t* sums_found,
size_t *size) {
    // create value to hold sum
    int sum = 0;
    // hold row constant, iterate through columns
    for (size_t i = currCol; i < matrix_size[kMatrix_size_cols_idx]; ++i) {
        // add each value to sum
        sum += matrix[currRow][i];
        // if adds up to target
        if (sum == search_sum) {
            // if sums found is greater than size of return array
            if (*sums_found >= *size) {
                // grow array
                coordinates = growArray(coordinates, size);
            }
            // assign coordinates
            coordinates[*sums_found][0] = currRow;
            coordinates[*sums_found][1] = currCol;
            coordinates[*sums_found][2] = currRow;
            coordinates[*sums_found][3] = i;
            // increment sums found
            *sums_found += 1;
        }
    }
}

void SearchCol(const int** matrix, const size_t* matrix_size, int search_sum,
size_t currRow, size_t currCol, size_t **coordinates, size_t* sums_found,
size_t* size) {
    // create value to hold sum
    int sum = 0;
    // hold column constant and iterate rows
    for (size_t i = currRow; i < matrix_size[kMatrix_size_rows_idx]; ++i) {
        // add each value to sum
        sum += matrix[i][currCol];
        // if adds up to target
        if (sum == search_sum) {
            // if return array is full
            if (*sums_found >= *size) {
                // grow array
                coordinates = growArray(coordinates, size);
            }
            // assign coordinates
            coordinates[*sums_found][0] = currRow;
            coordinates[*sums_found][1] = currCol;
            coordinates[*sums_found][2] = i;
            coordinates[*sums_found][3] = currCol;
            // increment sums found
            *sums_found += 1;
        }
    }
}

void SearchAscDiag(const int** matrix, const size_t* matrix_size,
int search_sum, size_t currRow, size_t currCol, size_t **coordinates,
size_t* sums_found, size_t* size) {
    // create value to hold sum
    int sum = 0;
    // create constants for matrix size to increase readability
    const size_t kRow = matrix_size[kMatrix_size_rows_idx];
    const size_t kCol = matrix_size[kMatrix_size_cols_idx];
    // iterate up to the right ^, ->
    for (size_t row = currRow, col = currCol; row < kRow &&
     col < kCol; --row, ++col) {
         // add to sum
        sum += matrix[row][col];
        // if adds up to target
        if (sum == search_sum) {
            // if return array is full
            if (*sums_found >= *size) {
                // grow array
                coordinates = growArray(coordinates, size);
            }
            // assign coordinates
            coordinates[*sums_found][0] = currRow;
            coordinates[*sums_found][1] = currCol;
            coordinates[*sums_found][2] = row;
            coordinates[*sums_found][3] = col;
            // increment sums found
            *sums_found += 1;
        }
    }
}

void SearchDscDiag(const int** matrix, const size_t* matrix_size,
int search_sum, size_t currRow, size_t currCol, size_t **coordinates,
size_t* sums_found, size_t* size) {
    // create value to hold sum
    int sum = 0;
    // create constants for readability
    const size_t kRow = matrix_size[kMatrix_size_rows_idx];
    const size_t kCol = matrix_size[kMatrix_size_cols_idx];
    // allocate to the bottom right V, ->
    for (size_t row = currRow, col = currCol; row < kRow &&
     col < kCol; --row, --col) {
         // add to sum
        sum += matrix[row][col];
        // if adds to target
        if (sum == search_sum) {
            // if array is full
            if (*sums_found >= *size) {
                // grow array
                coordinates = growArray(coordinates, size);
            }
            // assign coordinates
            coordinates[*sums_found][0] = row;
            coordinates[*sums_found][1] = col;
            coordinates[*sums_found][2] = currRow;
            coordinates[*sums_found][3] = currCol;
            // increment sums found
            *sums_found += 1;
        }
    }
}

bool SearchSingleResult(const int** matrix, const size_t* matrix_size,
int search_sum, size_t currRow, size_t currCol, size_t **coordinates,
size_t* sums_found, size_t* size) {
    // create value to hold sum
    int sum = 0;
    // check if current index is equal to sum
    sum += matrix[currRow][currCol];
    // if sum is equal to target
    if (sum == search_sum) {
        // if array is full
        if (*sums_found >= *size) {
            // grow array
            coordinates = growArray(coordinates, size);
        }
        // assign coordinates
        coordinates[*sums_found][0] = currRow;
        coordinates[*sums_found][1] = currCol;
        coordinates[*sums_found][2] = currRow;
        coordinates[*sums_found][3] = currCol;
        // increment sums found
        *sums_found += 1;
        // break loop
        return true;
    }
    // continue loop
    return false;
}

// -------------------------( I DO NOT WORK, FIX ME )--------------------------
size_t** growArray(size_t **coordinates, size_t* size) {
    size_t **tmp_array;
    tmp_array = new size_t*[*size * 2];  // double number of rows
    for (size_t i = 0; i < *size; ++i) {  // for each row in original
        tmp_array[i] = new size_t[kIndices_size];  // not increasing size
        for (size_t ii = 0; ii < kIndices_size; ++ii) {  // for each col
            tmp_array[i][ii] = coordinates[i][ii];  // copy each value
        }
        delete [] coordinates[i];  // delete inner array
    }
    // for (size_t i = *size; i < *size * 2; ++i) {
    //     tmp_array[i] = new size_t[kIndices_size];  // allocate new array
    // }
    // // delete old memory
    // for (size_t i = 0; i < *size; ++i) {
    // delete [] coordinates[i];  // delete row of matrix
    // }
    delete [] coordinates;  // delete overall matrix
    *size *= 2;
    return tmp_array;
}
// -------------------------( I DO NOT WORK, FIX ME )--------------------------

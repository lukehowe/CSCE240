// Copyright 2022 Luke Howe
#include <exam2/inc/functional_array.h>

::size_t** Allocate(const ::size_t* sizes, ::size_t length) {
    // create return array
    ::size_t** returnArray;
    // create outter array
    returnArray = new size_t*[length];
    // allocate inner array using for loop
    for (size_t row = 0; row < length; ++row) {
        returnArray[row] = new size_t[sizes[row]];
    }
    // add values to return array
    // for each row
    for (size_t row = 0; row < length; ++row) {
        // for each column
        for (size_t col = 0; col < sizes[row]; ++col) {
            // return array at each index is equal to that index of sizes
            returnArray[row][col] = sizes[row];
        }
    }
    // return returnarray (-;
    return returnArray;
}

::size_t Deallocate(const ::size_t** delete_me,
                    const ::size_t* sizes,
                    ::size_t length) {
// find sum
// create return value
::size_t returnSum = 0;
// for every row
for (size_t row = 0; row < length; ++row) {
    // for every column
    for (size_t col = 0; col < sizes[row]; ++col) {
        // add value at every index to return value
        returnSum += delete_me[row][col];
    }
}
// delete me
// for every row
for (size_t row = 0; row < length; ++row) {
    // delete every row array
    delete [] delete_me[row];
}
// delete outer array
delete [] delete_me;
// return sum
return returnSum;
                    }

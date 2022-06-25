// Copyright 2022 Luke Howe
//
#ifndef EXAM2_INC_FUNCTIONAL_ARRAY_H_
#define EXAM2_INC_FUNCTIONAL_ARRAY_H_
// functional_array (points):
//   Compiles: 0.5 (make test-functional-array)
//   Lints: 1.0 (make test-functional-array-style)
//   TestAllocateRectangle: 0.75
//   TestDeallocateRectangle: 0.75
//   TestAllocateJagged: 1.0
//   TestDeallocateJagged: 1.0
//   Test functional_array Memory: 1.0 (make test_functional_array_memory)

#include <cstddef>  // ::size_t
#include <iostream>  // std::cin std::cout


// Builds an n x s_i array, where s_i is a value at the i-th index of the sizes
//   parameter. Initializes each element of a given row in the array to a
//   value equal to the size of that row. Returns the allocated and initialized
//   array.
//  - sizes is a one dimensional array
//  - length is the number of elements in sizes
//
// e.g. Calling
//        Allocate({3, 3, 3}, 3);
//      returns the array:
//        { { 3, 3, 3 },
//          { 3, 3, 3 },
//          { 3, 3, 3 } }
//      and calling
//        Allocate({ 5, 1, 2, 3}, 4);
//      returns the array:
//        { { 5, 5, 5, 5, 5 },
//          { 1 },
//          { 2, 2 },
//          { 3, 3, 3} }
//
// Preconditions: Parameter length is > 0. Each element of sizes is > 0.
//
::size_t** Allocate(const ::size_t* sizes, ::size_t length);


// Accepts an array created by Allocate, sums the elements of the array,
// deletes the array, and returns the calculated sum.
//  - delete_me: array of arrays (returned by Allocate)
//  - sizes: array with elements containing the length of each array element
//           in delete_me
//  - length: number of elements in sizes
//
// e.g. The above arrays passed to Deallocate would result in the sums of
//     3*3 + 3*3 + 3*3
//   and
//     5*5 + 1*1 + 2*2 + 3*3
//   being returned, respectively.
//
// Note: Your Allocate method must pass before this method will be tested.
//
::size_t Deallocate(const ::size_t** delete_me,
                    const ::size_t* sizes,
                    ::size_t length);

#endif  // EXAM2_INC_FUNCTIONAL_ARRAY_H_

// Copyright 2022 CSCE 240 Exam 2
//
#include <exam2/inc/test_functional_array.h>


int main(int argc, char* argv[]) {
  assert(argc == 2
    && "You must supply the test number as argument to test-functional-app");
  size_t kTest_arg = 1;

  switch (atoi(argv[kTest_arg])) {
    case 0:  // test Allocate with rectangular array
      std::cout << "  RUNNING TestAllocateRectangle" << std::endl;
      if (TestAllocateRectangle()) {
        std::cout << "    PASSED" << std::endl;
        return 0;
      } else {
        std::cout << "    FAILED" << std::endl;
        return 1;
      }

    case 1:  // test Deallocate with rectangular array
      std::cout << "  RUNNING TestDeallocateRectangle" << std::endl;
      if (TestDeallocateRectangle()) {
        std::cout << "    PASSED" << std::endl;
        return 0;
      } else {
        std::cout << "    FAILED" << std::endl;
        return 1;
      }

    case 2:  // test Allocate with jagged array
      std::cout << "  RUNNING TestAllocateJagged" << std::endl;
      if (TestAllocateJagged()) {
        std::cout << "    PASSED" << std::endl;
        return 0;
      } else {
        std::cout << "    FAILED" << std::endl;
        return 1;
      }

    case 3:  // test Deallocate with rectangular array
      std::cout << "  RUNNING TestDeallocateJagged" << std::endl;
      if (TestDeallocateJagged()) {
        std::cout << "    PASSED" << std::endl;
        return 0;
      } else {
        std::cout << "    FAILED" << std::endl;
        return 1;
      }

    default:
      assert(false && "Incorrect test number argument.");
  }

  return 0;
}


bool TestAllocateRectangle() {
  const size_t *sizes = AutoToDynamic(kRectangle_sizes,
                                      kRectangle_sizes_length);
  size_t **actual = Allocate(sizes, kRectangle_sizes_length);  // testing

  bool passed = true;
  for (size_t i = 0; i < kRectangle_sizes_length; ++i)
    for (size_t j = 0; j < kRectangle_sizes[i]; ++j)
      if (actual[i][j] != kRectangle_sizes[i]) {
        std::cout << "      Expected allocated array[" << i << "][" << j
          << "]: " << kRectangle_sizes[i] << ", Actual: " << actual[i][j]
          << std::endl;

        passed = false;
      }

  delete [] sizes;
  return passed;
}


bool TestDeallocateRectangle() {
  const size_t *sizes = AutoToDynamic(kRectangle_sizes,
                                      kRectangle_sizes_length);
  size_t **allocation = Allocate(sizes, kRectangle_sizes_length);

  size_t actual = Deallocate(const_cast<const size_t**>(allocation),
                             sizes,
                             kRectangle_sizes_length);  // testing

  delete [] sizes;
  if (kRectangle_sum != actual) {
    std::cout << "      Expected Deallocate sum: " << kRectangle_sum
        << ", Actual: " << actual << std::endl;
    return false;
  }

  return true;
}


bool TestAllocateJagged() {
  const size_t *sizes = AutoToDynamic(kJagged_sizes,
                                      kJagged_sizes_length);
  size_t **actual = Allocate(sizes, kJagged_sizes_length);  // testing

  bool passed = true;
  for (size_t i = 0; i < kJagged_sizes_length; ++i)
    for (size_t j = 0; j < kJagged_sizes[i]; ++j)
      if (actual[i][j] != kJagged_sizes[i]) {
        std::cout << "      Expected allocated array[" << i << "][" << j
          << "]: " << kJagged_sizes[i] << ", Actual: " << actual[i][j]
          << std::endl;

        passed = false;
      }

  delete [] sizes;
  return passed;
}


bool TestDeallocateJagged() {
  const size_t *sizes = AutoToDynamic(kJagged_sizes,
                                      kJagged_sizes_length);
  size_t **allocation = Allocate(sizes, kJagged_sizes_length);

  size_t actual = Deallocate(const_cast<const size_t**>(allocation),
                             sizes,
                             kJagged_sizes_length);  // testing

  delete [] sizes;
  if (kJagged_sum != actual) {
    std::cout << "      Expected Deallocate sum: " << kJagged_sum
        << ", Actual: " << actual << std::endl;
    return false;
  }
  return true;
}


const size_t* AutoToDynamic(const size_t auto_array[], const size_t length) {
  size_t *dyna_array = new size_t[length];

  for (size_t i = 0; i < length; ++i)
    dyna_array[i] = auto_array[i];

  return const_cast<const size_t *>(dyna_array);
}

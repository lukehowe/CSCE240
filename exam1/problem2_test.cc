// Copyright 2022 CSCE 240
//

#include <exam1/problem2.h>
#include <exam1/problem2.h>  // check correct header construction

#include <cassert>  // assert
#include <cstddef>  // size_t

#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
  std::cout << "Problem 2" << std::endl;

  assert(kTestVal == 'A');  // check correct header construction

  std::string values[] = { "813546", "-7613", "-twelve" };
  std::string expected[] = { "27", "-17", "empty string" };

  for (size_t i = 0; i < sizeof(values)/sizeof(std::string); ++i) {
    std::cout << "  SumDigits(" << values[i] << ")" << std::endl;

    std::string sum = SumDigits(values[i]);
    std::cout << "    Expected: " << expected[i];

    std::cout << ", Actual: ";
    if (sum.length() > 0)
      std::cout << sum;
    else
      std::cout << "empty string";
    std::cout << std::endl;
  }

  return 0;
}

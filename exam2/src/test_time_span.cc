// Copyright 2022 CSCE 240 Exam 2
//

#include <exam2/inc/test_time_span.h>
#include <exam2/inc/time_span.h>  // test define guards (idempotent #include)


int main(int argc, char* argv[]) {
  assert(argc == 2
    && "You must supply the test number as argument to test-time-span");
  size_t kTest_arg = 1;

  switch (atoi(argv[kTest_arg])) {
    case 0:  // test TimeSpan::operator+(const TimeSpan&)
      std::cout << "  RUNNING TestOperatorPlusTimeSpan" << std::endl;
      if (TestOperatorPlusTimeSpan()) {
        std::cout << "    PASSED" << std::endl;
        return 0;
      } else {
        std::cout << "    FAILED" << std::endl;
        return 1;
      }

    case 1:  // test TimeSpan::operator+(int)
             // test operator+(int, TimeSpan)
      std::cout << "  RUNNING TestOperatorPlusInt" << std::endl;
      if (TestOperatorPlusInt()) {
        std::cout << "    PASSED" << std::endl;
        return 0;
      } else {
        std::cout << "    FAILED" << std::endl;
        return 1;
      }

    case 2:  // test operator<<(ostream&, const TimeSpan&)
      std::cout << "  RUNNING TestOperatorExtract" << std::endl;
      if (TestOperatorExtract()) {
        std::cout << "    PASSED" << std::endl;
        return 0;
      } else {
        std::cout << "    FAILED" << std::endl;
        return 1;
      }

    case 3:  // test operator>>(istream, TimeSpan&)
      std::cout << "  RUNNING TestOperatorInsert" << std::endl;
      if (TestOperatorInsert()) {
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


bool TestOperatorPlusTimeSpan() {
  int expected_hours = 13;
  int expected_minutes = 0;
  int expected_seconds = 9;

  TimeSpan lhs(9, 21, 26), rhs(3, 38, 43);

  TimeSpan actual;
  actual = lhs + rhs;  // testing

  bool passed = true;
  if (expected_hours != actual.hours()) {
    std::cout << "      expected hours: " << expected_hours
        << ", actual.hours(): " << actual.hours() << std::endl;
    passed = false;
  }

  if (expected_minutes != actual.minutes()) {
    std::cout << "      expected minutes: " << expected_minutes
        << ", actual.minutes(): " << actual.minutes() << std::endl;
    passed = false;
  }

  if (expected_seconds != actual.seconds()) {
    std::cout << "      expected seconds: " << expected_seconds
        << ", actual.seconds(): " << actual.seconds() << std::endl;
    passed = false;
  }

  return passed;
}


bool TestOperatorPlusInt() {
  int expected_hours = 11;
  int expected_minutes = 30;
  int expected_seconds = 5;

  int lhs = 60*60*5 + 60*11 + 21;
  TimeSpan rhs(6, 18, 44);

  TimeSpan actual;
  actual = lhs + rhs;  // testing

  bool passed = true;
  if (expected_hours != actual.hours()) {
    std::cout << "      expected hours: " << expected_hours
        << ", actual.hours(): " << actual.hours() << std::endl;
    passed = false;
  }

  if (expected_minutes != actual.minutes()) {
    std::cout << "      expected minutes: " << expected_minutes
        << ", actual.minutes(): " << actual.minutes() << std::endl;
    passed = false;
  }

  if (expected_seconds != actual.seconds()) {
    std::cout << "      expected seconds: " << expected_seconds
        << ", actual.seconds(): " << actual.seconds() << std::endl;
    passed = false;
  }

  return passed;
}


bool TestOperatorExtract() {
  std::string expected("13 : 13 : 13");
  TimeSpan rhs(13, 13, 13);
  std::stringstream lhs;

  lhs << rhs;  // testing

  if (expected != lhs.str()) {
    std::cout << "      Expected: " << expected << ", Actual: " << lhs.str()
        << std::endl;
    return false;
  }

  return true;
}


bool TestOperatorInsert() {
  int expected_hours = 17;
  int expected_minutes = 32;
  int expected_seconds = 59;
  TimeSpan rhs;
  std::stringstream lhs("17 : 32 : 59");

  lhs >> rhs;  // testing

  bool failed = true;
  if (expected_hours != rhs.hours()) {
    std::cout << "      expected hours: " << expected_hours
        << ", actual.hours(): " << rhs.hours() << std::endl;
    failed = false;
  }

  if (expected_minutes != rhs.minutes()) {
    std::cout << "      expected minutes: " << expected_minutes
        << ", actual.minutes(): " << rhs.minutes() << std::endl;
    failed = false;
  }

  if (expected_seconds != rhs.seconds()) {
    std::cout << "      expected seconds: " << expected_seconds
        << ", actual.seconds(): " << rhs.seconds() << std::endl;
    failed = false;
  }

  return failed;
}

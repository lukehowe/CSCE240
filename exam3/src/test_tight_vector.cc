// Copyright 2022 CSCE 240 Exam 3
//
#include <exam3/inc/test_tight_vector.h>
#include <exam3/inc/tight_vector.h>


using std::cout;
using std::endl;


int main(int argc, char* argv[]) {
  assert(argc == 2
    && "You must supply the test number as argument to test-tight-vector");
  size_t kTest_arg = 1;

  TightVectorTester tester;

  switch(atoi(argv[kTest_arg])) {
    case 0: // test TightVector::Append with empty array
      cout << "  RUNNING TightVectorTester::TestAppendEmpty" << endl;
      if (tester.TestAppendEmpty()) {
        cout << "    PASSED" << endl;
        return 0;
      } else {
        cout << "    FAILED" << endl;
        return 1;
      }

    case 1: // test TightVector::Append with (not) empty array
      cout << "  RUNNING TightVectorTester::TestAppendNotEmpty" << endl;
      if (tester.TestAppendNotEmpty()) {
        cout << "    PASSED" << endl;
        return 0;
      } else {
        cout << "    FAILED" << endl;
        return 1;
      }

    case 2: // test TightVector::Prepend with empty array
      cout << "  RUNNING TightVectorTester::TestPrependEmpty" << endl;
      if (tester.TestPrependEmpty()) {
        cout << "    PASSED" << endl;
        return 0;
      } else {
        cout << "    FAILED" << endl;
        return 1;
      }

    case 3: // test TightVector::Prepend with (not) empty array
      cout << "  RUNNING TightVectorTester::TestPrependNotEmpty" << endl;
      if (tester.TestPrependNotEmpty()) {
        cout << "    PASSED" << endl;
        return 0;
      } else {
        cout << "    FAILED" << endl;
        return 1;
      }

    default:
      assert(false && "Incorrect test number argument.");
  }

  return 1;
}



bool TightVectorTester::TestAppendEmpty() {
  const int kValues[] = { 919, -771, 833, 221, -1024, 512, -222, -1000377 };
  const size_t kCount = sizeof(kValues) / sizeof(int);
  TightVector t_vec;

  for (const int *itr = kValues; itr != kValues + kCount; ++itr)
    t_vec.Append(*itr);

  bool passed = true;
  if (t_vec.count_ != kCount) {
    cout << "      Expected member TightVector::count_: " << kCount
        << ", Actual: " << t_vec.count_ << endl;
    passed = false;
  }

  for (size_t i = 0; i < kCount; ++i)
    if (t_vec.array_[i] != kValues[i]) {
      cout << "      Expected member TightVector::array_[" << i << "]: "
          << kValues[i] << ",  Actual: " << t_vec.array_[i] << endl;
      passed = false;
    }

  return passed;
}


bool TightVectorTester::TestAppendNotEmpty() {
  const int kValues[] = { 919, -771, 833, 221, -1024, 512, -222, -1000377 };
  const size_t kCount = sizeof(kValues) / sizeof(int);

  TightVector t_vec;
  const size_t kStartSize = 1024;
  t_vec.array_ = new int[kStartSize];
  t_vec.count_ = kStartSize;

  for (const int *itr = kValues; itr != kValues + kCount; ++itr)
    t_vec.Append(*itr);

  bool passed = true;
  if (t_vec.count_ != kCount + kStartSize) {
    cout << "      Expected member TightVector::count_: "
        << (kCount + kStartSize) << ", Actual: " << t_vec.count_ << endl;
    passed = false;
  }

  for (size_t i = 0; i < kCount; ++i)
    if (t_vec.array_[kStartSize + i] != kValues[i]) {
      cout << "      Expected member TightVector::array_["
          << (kStartSize + i) << "]: "
          << kValues[i] << ",  Actual: " << t_vec.array_[kStartSize + i]
          << endl;
      passed = false;
    }

  return passed;
}


bool TightVectorTester::TestPrependEmpty() {
  const int kValues[] = { 919, -771, 833, 221, -1024, 512, -222, -1000377 };
  const size_t kCount = sizeof(kValues) / sizeof(int);
  TightVector t_vec;

  for (const int *itr = kValues; itr != kValues + kCount; ++itr)
    t_vec.Prepend(*itr);

  bool passed = true;
  if (t_vec.count_ != kCount) {
    cout << "      Expected member TightVector::count_: " << kCount
        << ", Actual: " << t_vec.count_ << endl;
    passed = false;
  }

  for (size_t i = 0; i != kCount; ++i)
    if (t_vec.array_[i] != kValues[kCount - i - 1]) {
      cout << "      Expected member TightVector::array_[" << i << "]: "
          << kValues[kCount - i - 1] << ",  Actual: " << t_vec.array_[i]
          << endl;
      passed = false;
    }

  return passed;
}


bool TightVectorTester::TestPrependNotEmpty() {
  const int kValues[] = { 919, -771, 833, 221, -1024, 512, -222, -1000377 };
  const size_t kCount = sizeof(kValues) / sizeof(int);
  TightVector t_vec;
  const size_t kStartSize = 1024;
  t_vec.array_ = new int[kStartSize];
  t_vec.array_[0] = -17;
  t_vec.count_ = kStartSize;

  for (const int *itr = kValues; itr != kValues + kCount; ++itr)
    t_vec.Prepend(*itr);

  bool passed = true;
  if (t_vec.count_ != kCount + kStartSize) {
    cout << "      Expected member TightVector::count_: " << kCount
        << ", Actual: " << t_vec.count_ << endl;
    passed = false;
  }

  for (size_t i = 0; i != kCount; ++i)
    if (t_vec.array_[i] != kValues[kCount - i - 1]) {
      cout << "      Expected member TightVector::array_[" << i << "]: "
          << kValues[kCount - i - 1] << ",  Actual: " << t_vec.array_[i]
          << endl;
      passed = false;
    }

  if (t_vec.array_[kCount] != -17) {
    cout << "      Expected member TightVector::array_[" << kCount << "]: "
        << 17 << ",  Actual: " << t_vec.array_[kCount]
        << endl;
    passed = false;
  }

  return passed;
}


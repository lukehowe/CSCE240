// Copyright 2022 CSCE 240 Exam 3
//
#include <exam3/inc/test_employee.h>

// declares a pair containing test name and test function
typedef std::pair<const char *, bool (*)()> TestPairType;

int main(int argc, char* argv[]) {
  // set of test names and test callbacks. See tests below for behavior.
  const std::vector<TestPairType> kTests{
    std::make_pair("Demographic::first_name",       TestDemographicFirstName),
    std::make_pair("Demographic::last_name",        TestDemographicLastName),
    std::make_pair("Demographic::date_of_birth",    TestDemographicDateOfBirth),
    std::make_pair("Employee::employee_id",         TestEmployeeEmployeeId),
    std::make_pair("HourlyEmployee::pay_rate",      TestHourlyEmployeePayRate),
    std::make_pair("HourlyEmployee::CalculatePay",
                   TestHourlyEmployeeCalculatePay),
    std::make_pair("SalaryEmployee::pay_rate",      TestSalaryEmployeePayRate),
    std::make_pair("SalaryEmployee::CalculatePay",
                   TestSalaryEmployeeCalculatePay)
  };

  // internal lambda function to execute above test and output feedback
  //   does not use closure because a for-each over the pairs is cleaner; see
  //   below when argc == 1
  auto dispatcher = [](const TestPairType& test) {
    std::cout << "Testing exam3::problem2::" << test.first << std::endl;
    if (test.second()) {
      std::cout << "  PASSED" << std::endl;
      return true;
    } else {
      std::cout << "  FAILED" << std::endl;
      return false;
    }
  };

  bool passed = true;
  if (argc == 1) {
    for (const TestPairType& pair : kTests)
      passed = dispatcher(pair) && passed;
  } else {
    const size_t kArg = 1;
    const size_t kTest_index = atoi(argv[kArg]);
    passed = dispatcher(kTests[kTest_index]);
  }

  return passed ? 0 : 1;
}

bool TestDemographicFirstName() {
  exam3::problem2::Demographic test_d(kFirst_name, kLast_name, kDate_of_birth);

  return test_d.first_name() == kFirst_name;
}

bool TestDemographicLastName() {
  exam3::problem2::Demographic test_d(kFirst_name, kLast_name, kDate_of_birth);

  return test_d.last_name() == kLast_name;
}


bool TestDemographicDateOfBirth() {
  exam3::problem2::Demographic test_d(kFirst_name, kLast_name, kDate_of_birth);

  return test_d.date_of_birth() == kDate_of_birth;
}


bool TestEmployeeEmployeeId() {
  exam3::problem2::Employee *test_e
    = new exam3::problem2::HourlyEmployee(kFirst_name,
                                          kLast_name,
                                          kDate_of_birth,
                                          kEmployee_id,
                                          0.0);
  bool passed = test_e->employee_id() == kEmployee_id;

  delete test_e;

  test_e = new exam3::problem2::SalaryEmployee(kFirst_name,
                              kLast_name,
                              kDate_of_birth,
                              kEmployee_id,
                              0.0);

  delete test_e;

  return test_e->employee_id() == kEmployee_id && passed;
}


bool TestHourlyEmployeePayRate() {
  exam3::problem2::Employee *test_e
    = new exam3::problem2::HourlyEmployee(kFirst_name,
                                          kLast_name,
                                          kDate_of_birth,
                                          kEmployee_id,
                                          kHourly_rate);
  bool passed = test_e->pay_rate() == kHourly_rate;

  delete test_e;

  return passed;
}

bool TestHourlyEmployeeCalculatePay() {
  exam3::problem2::Employee *test_e
    = new exam3::problem2::HourlyEmployee(kFirst_name,
                                          kLast_name,
                                          kDate_of_birth,
                                          kEmployee_id,
                                          kHourly_rate);

  bool passed = fabs(test_e->CalculatePay(kHours_worked)
                     - kHourly_rate * kHours_worked)
    < kAbs_diff;

  delete test_e;

  return passed;
}


bool TestSalaryEmployeePayRate() {
  exam3::problem2::Employee *test_e
    = new exam3::problem2::SalaryEmployee(kFirst_name,
                                          kLast_name,
                                          kDate_of_birth,
                                          kEmployee_id,
                                          kSalary);
  bool passed = test_e->pay_rate() == kSalary;

  delete test_e;

  return passed;
}


bool TestSalaryEmployeeCalculatePay() {
  exam3::problem2::Employee *test_e
    = new exam3::problem2::SalaryEmployee(kFirst_name,
                                          kLast_name,
                                          kDate_of_birth,
                                          kEmployee_id,
                                          kSalary);
  bool passed = fabs(test_e->CalculatePay(kAnnual_percentage)
                     - kSalary * 0.01*kAnnual_percentage)
    < kAbs_diff;

  delete test_e;

  return passed;
}

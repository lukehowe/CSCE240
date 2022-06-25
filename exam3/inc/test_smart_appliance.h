// Copyright 2022 CSCE 240 Exam 3
//
#ifndef EXAM3_INC_TEST_SMART_APPLIANCE_H_
#define EXAM3_INC_TEST_SMART_APPLIANCE_H_

#include <exam3/inc/smart_appliance.h>
#include <cctype>  // isspace
#include <cstddef>  // size_t
#include <cstdlib>  // atoi
#include <algorithm>
#include <iostream>
#include <string>


// Active devices behave differently from inactive ones
enum class TestType {
  ACTIVE,
  INACTIVE
};

// POINTS: 2 points for SmartLight, 2 points for SmartThermostat
// PARAMETERS:
// test determines inactive vs active devices
// name is printed type of smart device---Thermostat or Light
// expected is expected return string from method
// appliance is the device being tested---a child of SmartAppliance
bool TestSmartApplianceActivate(TestType test,
                                const char* name,
                                const std::string& expected,
                                exam3::problem3::SmartAppliance* appliance);


// POINTS: 2 points for SmartLight, 2 points for SmartThermostat
// PARAMETERS:
// test determines inactive vs active devices
// name is printed type of smart device---Thermostat or Light
// expected is expected return string from method
// appliance is the device being tested---a child of SmartAppliance
bool TestSmartApplianceDeactivate(TestType test,
                                  const char* name,
                                  const std::string& expected,
                                  exam3::problem3::SmartAppliance* appliance);


// POINTS: 6 points for SmartLight, 5 points for SmartThermostat
// PARAMETERS:
// test determines inactive vs active devices
// name is printed type of smart device---Thermostat or Light
// input is character string representation of curr
// prev is any previous value to which device should be set
// curr is value passed to test method
// expected is expected return string from method
// appliance is the device being tested---a child of SmartAppliance
bool TestSmartApplianceSet(TestType test,
                           const char* name,
                           const char* input,
                           int prev,
                           unsigned int curr,
                           const std::string&& expected,
                           exam3::problem3::SmartAppliance* appliance);


//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//                  DEFINITIONS SHARED BY BOTH TEST FILES                   //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////

inline const std::string RemoveWhiteSpace(const std::string& string) {
  std::string tmp(string);

  tmp.erase(std::remove_if(tmp.begin(), tmp.end(), isspace), tmp.end());

  return tmp;
}


bool TestSmartApplianceActivate(TestType test,
                                const char* name,
                                const std::string& expected,
                                exam3::problem3::SmartAppliance* appliance) {
  std::cout << "  Smart" << name << "::Activate : ";
  if (test == TestType::ACTIVE)  // preset active when indicated
    appliance->Activate();

  const std::string kActual = appliance->Activate();

  if (RemoveWhiteSpace(kActual) == expected)
    std::cout << "PASSED" << std::endl;
  else
    std::cout << "FAILED" << std::endl
         << "    Expected: " << expected << std::endl
         << "    Actual: " << RemoveWhiteSpace(kActual) << std::endl;

  return RemoveWhiteSpace(kActual) == expected;
}


bool TestSmartApplianceDeactivate(TestType test,
                                  const char* name,
                                  const std::string& expected,
                                  exam3::problem3::SmartAppliance* appliance) {
  std::cout << "  Smart" << name << "::Activate : ";
  if (test == TestType::ACTIVE)  // preset active when indicated
    appliance->Activate();

  const std::string kActual = appliance->Deactivate();

  if (RemoveWhiteSpace(kActual) == expected)
    std::cout << "PASSED" << std::endl;
  else
    std::cout << "FAILED" << std::endl
         << "    Expected: " << expected << std::endl
         << "    Actual: " << kActual << std::endl;

  return RemoveWhiteSpace(kActual) == expected;
}


bool TestSmartApplianceSet(TestType test,
                           const char* name,
                           const char* input,
                           int prev,
                           unsigned int curr,
                           const std::string&& expected,
                           exam3::problem3::SmartAppliance* appliance) {
  std::cout << "  Smart" << name << "::Set(" << input << "): ";
  if (test == TestType::ACTIVE)  // preset active when indicated
    appliance->Activate();

  if (prev > -1)
    appliance->Set(static_cast<unsigned int>(prev));

  const std::string kActual = appliance->Set(curr);

  if (RemoveWhiteSpace(kActual) == expected)
    std::cout << "PASSED" << std::endl;
  else
    std::cout << "FAILED" << std::endl
         << "    Expected: " << expected << std::endl
         << "    Actual: " << kActual << std::endl;

  return RemoveWhiteSpace(kActual) == expected;
}

#endif  // EXAM3_INC_TEST_SMART_APPLIANCE_H_

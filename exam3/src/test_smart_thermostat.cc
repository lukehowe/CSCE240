// Copyright 2022 CSCE 240 Exam 3
//
#include <exam3/inc/test_smart_appliance.h>
using exam3::problem3::SmartAppliance;
using exam3::problem3::SmartThermostat;
using std::cout;
using std::endl;
using std::string;


bool TestSmartAppliance(size_t test) {
  if (test == 0) {  // only non-base case
    const size_t kTestNo = 9;
    bool passed = true;
    for (size_t i = 1; i <= kTestNo; ++i)
      passed = TestSmartAppliance(i) && passed;

    return passed;
  }

  SmartThermostat thermostat;

  switch (test) {
  case 1:
    cout << "Testing exam3::problem3::SmartThermostat::Activate 1 of 2" << endl;
    return TestSmartApplianceActivate(TestType::INACTIVE,
                                  "Thermostat",
                                  "{\"active\":true,\"previous\":false}",
                                  &thermostat);
  case 2:
    cout << "Testing exam3::problem3::SmartThermostat::Activate 2 of 2" << endl;
    return TestSmartApplianceActivate(TestType::ACTIVE,
                                  "Thermostat",
                                  "{\"active\":true,\"previous\":true}",
                                  &thermostat);
  case 3:
    cout << "Testing exam3::problem3::SmartThermostat::Dectivate 1 of 2"
      << endl;
    return TestSmartApplianceDeactivate(TestType::INACTIVE,
                                    "Thermostat",
                                    "{\"active\":false,\"previous\":false}",
                                    &thermostat);
  case 4:
    cout << "Testing exam3::problem3::SmartThermostat::Dectivate 2 of 2"
      << endl;
    return TestSmartApplianceDeactivate(TestType::ACTIVE,
                                    "Thermostat",
                                    "{\"active\":false,\"previous\":true}",
                                    &thermostat);
  case 5:
    cout << "Testing exam3::problem3::SmartThermostat::Set 1 of 5" << endl;
    return TestSmartApplianceSet(TestType::INACTIVE,
                                 "Thermostat",
                                 "50",
                                 -1,  // use default setting
                                 50,
                                 "{\"active\":false}",
                                 &thermostat);
  case 6:
    cout << "Testing exam3::problem3::SmartThermostat::Set 2 of 5" << endl;
    return TestSmartApplianceSet(TestType::ACTIVE,
                                 "Thermostat",
                                 "50",
                                 -1,  // default temp setting
                                 50,
                            "{\"active\":true,\"temp\":65,\"previous\":null}",
                                 &thermostat);
  case 7:
    cout << "Testing exam3::problem3::SmartThermostat::Set 3 of 5" << endl;
    return TestSmartApplianceSet(TestType::ACTIVE,
                                 "Thermostat",
                                 "50",
                                 0,  // previous setting of 40 deg
                                 50,
                            "{\"active\":true,\"temp\":65,\"previous\":40}",
                                 &thermostat);
  case 8:
    cout << "Testing exam3::problem3::SmartThermostat::Set 4 of 5" << endl;
    return TestSmartApplianceSet(TestType::ACTIVE,
                                 "Thermostat",
                                 "50",
                                 10,  // previous setting of 45 deg
                                 50,
                            "{\"active\":true,\"temp\":65,\"previous\":45}",
                                 &thermostat);
  case 9:
    cout << "Testing exam3::problem3::SmartThermostat::Set 5 of 5" << endl;
    return TestSmartApplianceSet(TestType::ACTIVE,
                                 "Thermostat",
                                 "75",
                                 25,  // previous setting of 53 deg
                                 75,
                            "{\"active\":true,\"temp\":78,\"previous\":53}",
                                 &thermostat);
  default:
    return false;
  }
}


int main(int argc, char* argv[]) {
  if (argc == 1)
    return TestSmartAppliance(0) ? 0 : 1;

  const int kArg = 1;
  size_t test = static_cast<size_t>(atoi(argv[kArg]));

  return TestSmartAppliance(test) ? 0 : 1;
}

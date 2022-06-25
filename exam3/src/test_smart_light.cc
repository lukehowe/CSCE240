// Copyright 2022 CSCE 240 Exam 3
//
#include <exam3/inc/test_smart_appliance.h>
using exam3::problem3::SmartAppliance;
using exam3::problem3::SmartLight;
using std::cout;
using std::endl;
using std::string;


bool TestSmartAppliance(size_t test) {
  if (test == 0) {  // only non-base case
    bool passed = true;
    const size_t kTest_no = 10;
    for (size_t i = 1; i <= kTest_no; ++i) {
      passed = TestSmartAppliance(i) && passed;
    }
    return passed;
  }

  SmartLight light;

  switch (test) {
  case 1:
    cout << "Testing exam3::problem3::SmartLight::Activate 1 of 2" << endl;
    return TestSmartApplianceActivate(TestType::INACTIVE,
                                      "light",
                                      "{\"active\":true,\"previous\":false}",
                                      &light);
  case 2:
    cout << "Testing exam3::problem3::SmartLight::Activate 2 of 2" << endl;
    return TestSmartApplianceActivate(TestType::ACTIVE,
                                      "light",
                                  "{\"active\":true,\"previous\":true}",
                                  &light);
  case 3:
    cout << "Testing exam3::problem3::SmartLight::Dectivate 1 of 2" << endl;
    return TestSmartApplianceDeactivate(TestType::INACTIVE,
                                      "light",
                                    "{\"active\":false,\"previous\":false}",
                                    &light);
  case 4:
    cout << "Testing exam3::problem3::SmartLight::Dectivate 2 of 2" << endl;
    return TestSmartApplianceDeactivate(TestType::ACTIVE,
                                      "light",
                                    "{\"active\":false,\"previous\":true}",
                                    &light);
  case 5:
    cout << "Testing exam3::problem3::SmartLight::Set 1 of 6" << endl;
    return TestSmartApplianceSet(TestType::INACTIVE,
                                 "light",
                                 "SmartAppliance::ON",
                                 -1,  // tell test to not set previous
                                 SmartAppliance::ON,
                                 "{\"active\":false}",
                                 &light);
  case 6:
    cout << "Testing exam3::problem3::SmartLight::Set 2 of 6" << endl;
    return TestSmartApplianceSet(TestType::INACTIVE,
                                 "light",
                                 "SmartAppliance::OFF",
                                 -1,  // tell test to not set previous
                                 SmartAppliance::OFF,
                                 "{\"active\":false}",
                                 &light);
  case 7:
    cout << "Testing exam3::problem3::SmartLight::Set 3 of 6" << endl;
    return TestSmartApplianceSet(TestType::ACTIVE,
                                 "light",
                                 "SmartAppliance::ON",
                                 -1,  // tell test to not set previous
                                 SmartAppliance::ON,
                            "{\"active\":true,\"on\":true,\"previous\":false}",
                                 &light);
  case 8:
    cout << "Testing exam3::problem3::SmartLight::Set 4 of 6" << endl;
    return TestSmartApplianceSet(TestType::ACTIVE,
                                 "light",
                                 "SmartAppliance::ON",
                                 SmartAppliance::ON,
                                 SmartAppliance::ON,
                             "{\"active\":true,\"on\":true,\"previous\":true}",
                             &light);
  case 9:
    cout << "Testing exam3::problem3::SmartLight::Set 5 of 6" << endl;
    return TestSmartApplianceSet(TestType::ACTIVE,
                                 "light",
                                 "SmartAppliance::OFF",
                                 SmartAppliance::ON,
                                 SmartAppliance::OFF,
                             "{\"active\":true,\"on\":false,\"previous\":true}",
                                 &light);
  case 10:
    cout << "Testing exam3::problem3::SmartLight::Set 6 of 6" << endl;
    return TestSmartApplianceSet(TestType::ACTIVE,
                                 "light",
                                 "SmartAppliance::OFF",
                                 -1,  // tell test to not set previous
                                 SmartAppliance::OFF,
                            "{\"active\":true,\"on\":false,\"previous\":false}",
                                 &light);

  default:
    cout << 104 << endl;
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

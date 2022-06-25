// Copyright 2022 Luke Howe
//
#ifndef EXAM3_INC_SMART_APPLIANCE_H_
#define EXAM3_INC_SMART_APPLIANCE_H_
// SmartAppliance Points:
//   Compilation: 0.5 points
//   Style: 0.5 points
//   SmartLight::Activate: 0.5 points
//   SmartLight::Deactivate: 0.5 points
//   SmartLight::Set: 1.0 point
//   SmartThermostat::Activate: 0.5 points
//   SmartThermostat::Deactivate: 0.5 points
//   SmartThermostat::Set: 1.0 point
//
#include <string>

namespace exam3 {

namespace problem3 {

// SmartAppliance represents a class of objects with the following
//   characteristics:
//   - They have a low power state in which they are inactive
//   - They must be activated via Activate() before any internal state may be
//     changed.
//   - They define a Set method which is used to set an internal state.
//     Note: binary internal states may be represented via a 0 for off and 1
//           for on. See SmartAppliance class for SmartAppliance::OFF and
//           SmartAppliance::ON and below for usage with binary state device--a
//           light.
//   - The Activate, Deactivate, and Set methods return a status string each
//     time they are called.
//
// USAGE:
//   SmartLight light;
//   std::cout << light.Activate() << '\n';
//   std::cout << light.Set(SmartAppliance::ON) << '\n';
//
//   SmartAppliance *appliance = &light;
//   std::cout << appliance->Set(SmartAppliance::OFF) << '\n';
//   std::cout << appliance->Deactivate() << std::endl;
//
//   SmartThermostat thermo;
//   std::cout << thermostat.Activate() << '\n';
//   std::cout << thermostat.Set(70) << '\n';
//
//   SmartAppliance *appliance = &thermostat;
//   std::cout << appliance->Set(25) << '\n';
//   std::cout << appliance->Deactivate() << std::endl;
class SmartAppliance {
 public:
  static const unsigned int ON = 1;
  static const unsigned int OFF = 0;

  // not necessarily pure virtual
  virtual ~SmartAppliance();

  virtual const std::string Activate() = 0;
  virtual const std::string Deactivate() = 0;

  virtual const std::string Set(unsigned int setting) = 0;
};


// SmartLight
// Extends the SmartAppliance. A light is off when deactivated and remains so
// until set using the Set method.
//
//  Activate: (1) Object is inactive, activates light and returns the string
//                  { "active": true, "previous": false };
//            (2) Object is active, returns the string
//                  { "active": true, "previous": true };
//
//  Deactivate: (1) Object is inactive, does nothing and returns the string
//                    { "active": false, "previous": false }
//              (2) Object is active, deactivates light and returns string
//                    { "active": false, "previous": true };
//
//  Set: (1) Object is inactive, setting parameter is ignored and returns the
//           string
//             { "active": false }
//       (2) Object is active:
//           (a) Setting parameter is 1(ON) and light is off, turns light on
//               and returns string:
//                 { "active": true, "on": true, "previous": false }
//           (b) Setting parameter is 1(ON) and light is on, returns string:
//                 { "active": true, "on": true, "previous": true }
//           (c) Setting parameter is 0(OFF) and light is on, turns light off
//               and returns string:
//                 { "active": true, "on": false, "previous": true }
//           (d) When setting parameter is 0(OFF) and light is off, returns
//               string:
//                 { "active": true, "on": false, "previous": false }
//
class SmartLight : public SmartAppliance {
// empty
};


// SmartThermostat
// Extends the SmartAppliance. A thermostat object has "no temperature" when it
// is deactivated and remains so until set using the Set method. You may
// represent this however you choose, but the value is returned as the literal
// null
//
// A thermostat receives it setting as a value in [0, 100]. A thermostat has a
// temperature range between 40 and 90 degrees Fahrenheight---a range of 50
// degrees. Use the 0 to 100 as the percent of the range to set the
// temperature,
//   i.e. setting 0(%) => 40, setting 50(%) => 65, setting 100(%) => 90, etc.
// You should round to one decimal place.
//
//  Activate: (1) Object is inactive, activates light and returns the string
//                  { "active": true, "previous": false };
//            (2) Object is active, returns the string
//                  { "active": true, "previous": true };
//
//  Deactivate: (1) Object is inactive, does nothing and returns the string
//                    { "active": false, "previous": false }
//              (2) Object is active, deactivates light and returns string
//                    { "active": false, "previous": true };
//
//  Set: (1) object is inactive, setting parameter is ignored and returns the
//           string
//             { "active": false }
//       (2) object is active:
//           (a) Current temperature is not set, updates temperature using
//               setting parameter accordingly and returns the string:
//                 { "active": true, "temp": 75, "previous": null }
//           (b) Setting parameter is not equal to the current temperature,
//               returns the string:
//                 { "active": true, "temp": 75, "previous": 75 }
//           (b) Setting parameter is equal to current temperature, updates
//               temperature accordingly and returns the string:
//                 { "active": true, "temp": 75, "previous": 73 }
//
class SmartThermostat : public SmartAppliance {
// empty
};

}  // namespace problem3

}  // namespace exam3

#endif  // EXAM3_INC_SMART_APPLIANCE_H_

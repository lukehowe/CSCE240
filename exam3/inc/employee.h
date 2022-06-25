// Copyright 2022 Luke Howe
//
#ifndef EXAM3_INC_EMPLOYEE_H_
#define EXAM3_INC_EMPLOYEE_H_
// Employee Points:
//   Compilation: 0.5 points
//   Style: 0.5 points
//   Demographic::first_name() : 0.25 points
//   Demographic::last_name() : 0.25 points
//   Demographic::date_of_birth() : 0.25 points
//   Employee::employee_id() : 0.25 points (requires child class)
//   HourlyEmpolyee::pay_rate() : 0.75 points
//   HourlyEmployee::CalculatePay(double) : 0.75 points
//   SalaryEmployee::pay_rate() : 0.75 points
//   SalaryEmployee::CalculatePay(double) : 0.75 points
//
#include <string>

namespace exam3 {

namespace problem2 {

// The Demographic class provides a base for people in the system. It will be
// extended by other classes, such as Employee.
//
// The class provides a constructor, a virtual destructor, and three accessor
// methods for the class members passed into the constructor.
//
class Demographic {
 public:
  Demographic(const std::string& first_name,
              const std::string& last_name,
              const std::string& date_of_birth);
  virtual ~Demographic() { /* empty */ }

  // accessors
  const std::string first_name() const;
  const std::string last_name() const;
  const std::string date_of_birth() const;
};


class Employee : public Demographic {
 public:
  // Additional parameter employee_id stored by the Employee class
  //
  Employee(const std::string& first_name,
           const std::string& last_name,
           const std::string& date_of_birth,
           const std::string& employee_id);
  virtual ~Employee() { /* empty */ }

  // accessor
  const std::string employee_id() const;

  // Must be defined by child
  // Returns the payment unit of a child class, i.e. salary or hourly rate
  //
  virtual double pay_rate() const = 0;

  // Must be defined by child
  // Calculates and returns the payment based on child class behavior.
  //
  virtual double CalculatePay(double) const = 0;
};


// HourlyEmplyee extends the Employee class and provides the following methods:
// - Constructor: accepts 4 const pass-by-reference strings, representing
//                first_name, last_name, date_of_birth, employee_id, and a
//                double representing the instance's hourly_rate.
//
// - pay_rate: access for the hourly_rate parameter above
// - CalculatePay: accepts number of hours worked and returns the pay for the
//                 hourly rate based on hours worked.
//
class HourlyEmployee : public Employee {
 public:
  // Additional parameter hourly_rate is stored privately in HourlyEmployee
  //
  HourlyEmployee(const std::string& first_name,
                 const std::string& last_name,
                 const std::string& date_of_birth,
                 const std::string& employee_id,
                 double hourly_rate);

  // accessor for hourly_rate
  //
  double pay_rate() const;

  // Calculates payment based on the employee's hourly_rate and the
  // hours_worked.
  //
  double CalculatePay(double hours_worked) const;
};


// SalaryEmplyee extends the Employee class and provides the following methods:
// - Constructor: accepts 4 const pass-by-reference strings, representing
//                first_name, last_name, date_of_birth, employee_id, and a
//                double representing the instance's salary.
//
// - pay_rate: accessor for the salary parameter above
// - CalculatePay: accepts a double representing the percentage of the year for
//                 which the salaried employee is paid e.g. a week is 1/52 of
//                 a year ~1.923%.
//
class SalaryEmployee : public Employee {
 public:
  // Additional parameter salary is stored privately in SalaryEmployee
  //
  SalaryEmployee(const std::string& first_name,
                 const std::string& last_name,
                 const std::string& date_of_birth,
                 const std::string& employee_id,
                 double salary);

  // accessor for salary
  //
  double pay_rate() const;

  // Calculates payment based on the worker's salary and the percentage of the
  // year for which payment is made e.g. a week payment is ~1.923% (1/52).
  //
  double CalculatePay(double annual_percentage) const;
};
}  // namespace problem2

}  // namespace exam3

#endif  // EXAM3_INC_EMPLOYEE_H_

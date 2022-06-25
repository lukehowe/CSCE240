// Copyright 2022 CSCE 240 Exam 3
//
#ifndef EXAM3_INC_TEST_EMPLOYEE_H_
#define EXAM3_INC_TEST_EMPLOYEE_H_


#include <exam3/inc/employee.h>
#include <cmath>  // fabs
#include <cstddef>  // size_t
#include <iostream>
#include <string>
#include <utility>  // pair
#include <vector>


bool TestDemographicFirstName();  // 1 point
bool TestDemographicLastName();  // 1 point
bool TestDemographicDateOfBirth();  // 1 point

bool TestEmployeeEmployeeId();  // 1 point

bool TestHourlyEmployeePayRate();  // 1.5 points
bool TestHourlyEmployeeCalculatePay();  // 2 points

bool TestSalaryEmployeePayRate();  // 1.5 points
bool TestSalaryEmployeeCalculatePay();  // 2 points


// Test values
const char *kFirst_name = "Jackson";
const char *kLast_name = "Seller";
const char *kDate_of_birth = "1999 10 14";
const char *kEmployee_id = "911911";
const double kHourly_rate = 17.25;
const double kHours_worked = 37.50;
const double kSalary = 68525.01;
const double kAnnual_percentage = 1.0/24.0;


// close enough for floating point equality
const double kAbs_diff = 1e-6;

#endif  // EXAM3_INC_TEST_EMPLOYEE_H_

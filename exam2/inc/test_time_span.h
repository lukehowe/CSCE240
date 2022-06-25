// Copyright 2022 CSCE 240 Exam 2
//
#ifndef EXAM2_INC_TEST_TIME_SPAN_H_
#define EXAM2_INC_TEST_TIME_SPAN_H_

#include <exam2/inc/time_span.h>
#include <cassert>  // ::assert
#include <cstdlib>  // ::atoi
#include <iostream>
#include <sstream>
#include <string>


bool TestOperatorPlusTimeSpan();
bool TestOperatorPlusInt();
bool TestOperatorExtract();
bool TestOperatorInsert();

#endif  // EXAM2_INC_TEST_TIME_SPAN_H_

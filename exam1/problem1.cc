// Copyright 2022 Luke Howe
#include <iostream>
#include <cstddef>
#include <string>

int main() {
// Create a double value to hold first operand
double value1;
// Create a string value to hold operator (nolint??)
std::string value2;  // NOLINT
// Create a double value to hold second operand
double value3;
// Read in values
std::cin >> value1;
std::cin >> value2;
std::cin >> value3;

// Check for < operator
if (value2 == "<") {
    // Logic
    if (value1 < value3) {
        std::cout << "true";
    } else {
        std::cout << "false";
    }
}

// Check for <= operator
if (value2 == "<=") {
    // Logic
    if (value1 <= value3) {
        std::cout << "true";
    } else {
        std::cout << "false";
    }
}

// Check for == operator
if (value2 == "==") {
    // Logic
    if (value1 == value3) {
        std::cout << "true";
    } else {
        std::cout << "false";
    }
}

// Check for >= operator
if (value2 == ">=") {
    // Logic
    if (value1 >= value3) {
        std::cout << "true";
    } else {
        std::cout << "false";
    }
}

// Check for > operator
if (value2 == ">") {
    // Logic
    if (value1 > value3) {
        std::cout << "true";
    } else {
        std::cout << "false";
    }
}

// Check for != operator
if (value2 == "!=") {
    // Logic
    if (value1 != value3) {
        std::cout << "true";
    } else {
        std::cout << "false";
    }
}
}

// Problem1: infix notation floating point comparator
//
// Task: WITHOUT PROMPTING read two numbers and an operator from STDIN, using
//     std::cin three times or in its form
//       std::cin >> value1 >> value2 >> value 3;
//
//     The input will always be given as
//       number operator number
//     e.g., 2.3 == 2.3, 4.5 != 4.5, etc
//
//     Using the operands and operators and conditional statement(s) perform
//     the operation. Emit the string "true" or "false" as necessary.
//
//     DO NOT emit anything other than the result. This is a calculator. Simply
//     emit the result of the operation. Do not prompt for input. Just write the
//     result of the operation to STDOUT using std::cout.
//
//   You must provide operators:
//     <
//     <=
//     ==
//     >=
//     >
//     !=
//
// Notes:
//   The two operands should be read as floating point data and the operator
//   can be read as an std::string. You need not set precision for the floating
//   point (in)equality operators. The default precision for a double is all
//   that is required.
//
// Points:
//  compilation: 1
//  style: 1
//  correctness: 2
//

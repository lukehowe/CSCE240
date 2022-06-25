// Copyright 2022 Luke Howe
#include <exam1/problem2.h>
#include <iostream>
#include <string>
#include <cstddef>
#include <cmath>

std::string SumDigits(const std::string& value) {
    // Create a flag for negative
    bool isNegative = false;
    // Try the following
    try {
        // Convert value to an integer
        int input = std::stoi(value);
        // Check if value is negative
        if (input < 0) {
            // Flag as such
            isNegative = true;
            // Convert to positive
            input = input * -1;
        }
        // Find how many numbers are in the input
        int numOfPowers = log10(input);
        // Create a sum variable
        int sum = 0;
        // Create a loop to separate the numbers
        for (int i = numOfPowers; i > -1; --i) {
            // Modulo 10 gives the number in the ones power
            sum += input % 10;
            // Divided by 10 gives the remainder
            input = input / 10;
        }
        // If flagged
        if (isNegative == true) {
            // Convert back to negative
            sum = sum*-1;
        }
        // Convert back to string
        std::string retValue = std::to_string(sum);
        // Return
        return retValue;
        // If contains invalid characters
    } catch (const std::invalid_argument& exception) {
        // Return empty string
        return "";
    }
}

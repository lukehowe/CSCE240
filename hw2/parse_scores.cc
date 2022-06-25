// Copyright 2022 Luke Howe CSCE 240
#include <hw2/parse_scores.h>
#include <stdexcept> // std::invalid_argument
#include <cstddef>  // size_t
#include <string>  // string
#include <iostream>  // std::cin, std::cout

// ############################################################################

std::string GetID(const std::string input[], size_t size) {
    if (size < 2) {  // If the size of the array is less than 2, it does not
                     // have the correct amount of indexes to be valid
        return "";   // In this case, return ""
    }
    return input[0];  // In a valid input array, the ID should be in index 0.
}

// ############################################################################

int GetGradeCount(const std::string input[], size_t size) {
    if (size < 2) {  // Check if the size of the input array is valid
        return -1;  // Return corrupt value
    }
    int gradeCount = std::stoi(input[1]);  // Convert str to int
    if (gradeCount < 0) {  // If the grade count is negative, it is invalid
        return -1;  // Return corrupt value
    }
    for (size_t i = 2; i < size; i++) {  // Cycle through the grades
        try {
            double gradeValue = std::stod(input[i]);  // Try to convert
            if (gradeValue < 0) {  // If the grade is negative,
            return -1;         // return -1
        }
        }  catch(const std::invalid_argument& exception) {  // If convert fails
            return -1;                                      // return -1
        }
    }
    return (size - 2);  // Returns true grade count
}

// ############################################################################

double GetGrade(size_t grade_index, const std::string input[], size_t size) {
    if (size < 2) {  // Check if the size of the input array is valid
        return -1;  // Return corrupt value
    }
    for (size_t i = 0; i < size; i++) {  // For every value in array
        try {
            if (GetGradeCount(input, size) < 0) {  // Check if grade count is
                                                   // invalid
                return -1;  // Return corrupted
            }
            if (input[grade_index + 2].empty()) {  // Check if grade index is
                                                   // out of bounds
                return -2;  // Return out of bounds
            }
            double retGrade = std::stod(input[grade_index + 2]);  // Convert
            if (retGrade < 0) {  // If grade is invalid,
                return -1;  // return corrupt
            }
            return retGrade;  // Return grade
        } catch (const std::invalid_argument& exception) {  // Catch letters
            return -1;  // Return corrupt
        }
    }
    return -1;
}

// ############################################################################

double GetMaxGrade(const std::string input[], const size_t kSize) {
    double highestGrade = 0;  // Create a double to hold the highest value
    if (kSize <= 2) {  // Check if the size of the array is valid
        return -2;  // Return out of bounds
    }
    for (size_t i = 2; i < kSize; i++) {  // Iterate through array
        try {
            if (highestGrade < GetGrade(i, input, kSize)) {  // If i is > than
                highestGrade = GetGrade(i, input, kSize);  // value, replace it
            }
        } catch (const std::invalid_argument& exception) {  // Catch letters
            return -1;  // Return corrupt
        }
    }
    if (highestGrade == 0) {  // If the highest grade is 0, invalid
        return -1;  // Return corrupt
    }
    return highestGrade;  // Return highest grade
}

// ############################################################################

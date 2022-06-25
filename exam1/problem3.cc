// Copyright 2022 Luke Howe
#include <exam1/problem3.h>
#include <fstream>
#include <iostream>
#include <cstddef>
#include <string>
using std::string;

double Max(const string& ref) {
    // Create fstream
    std::fstream fileReader;
    // Open file
    fileReader.open(ref);
    // Create value to hold number of doubles in file
    int kNumOfDoubles = 0;
    // Create value to hold the double being read
    double input = 0;
    // Create double to hold max value
    double max = 0;
    // Read number of doubles
    fileReader >> kNumOfDoubles;
    // While the file is open and is good
    while (fileReader) {
        // Read into input
        fileReader >> input;
        // If the double being read is currently larger than what is max,
        if (input > max) {
            // Replace max with what is being read
            max = input;
        }
    }
    // Return the max value
    return max;
}

double Min(const string& ref) {
    // Create fstream
    std::fstream fileReader;
    // Open file
    fileReader.open(ref);
    // Create value to hold number of doubles in file
    int kNumOfDoubles = 0;
    // Create value to hold the double being read
    double input = 0;
    // Create double to hold min value
    double min = 0;
    // Read number of doubles
    fileReader >> kNumOfDoubles;
    // While the file is open and good
    while (fileReader) {
        // Read into input
        fileReader >> input;
        // If the double being read is less than what is min,
        if (input < min) {
            // Replace min with what is being read
            min = input;
        }
    }
    // Return the min value
    return min;
}

double Sum(const string& ref) {
    // Create fstream
    std::fstream fileReader;
    // Open file
    fileReader.open(ref);
    // Create value to hold number of doubles in file
    int kNumberOfDoubles = 0;
    // Create value to hold the double being read
    double input = 0;
    // Create double to hold sum value
    double sum = 0;
    // Read number of doubles
    fileReader >> kNumberOfDoubles;
    // While the file is open and good
    while (fileReader) {
        // Read into input
        fileReader >> input;
        // Check if fileReader is at the end of the file
        if (fileReader.eof()) {
            // If so, break to avoid repeating values
            break;
        }
        // Add the double to sum
        sum = sum + input;
    }
    // Return the sum
    return sum;
}

double Avg(const string& ref) {
    // Create fstream
    std::fstream fileReader;
    // Open file
    fileReader.open(ref);
    // Create value to hold number of doubles in file
    int kNumberOfDoubles = 0;
    // Create value to hold the double being read
    double input = 0;
    // Create double to hold avg value
    double avg = 0;
    // Get sum
    double sum = Sum(ref);
    // Read number of doubles
    fileReader >> kNumberOfDoubles;
    // While the file is open and good
    while (fileReader) {
        // Read into input
        fileReader >> input;
        // Check if fileReader is at the at end of the file
        if (fileReader.eof()) {
            // If so, break to avoid repeating values
            break;
        }
        // Divide sum by number of doubles
        avg = sum / kNumberOfDoubles;
    }
    // Return the average
    return avg;
}

void Sort(const string& ref, double array[]) {
    // Create fstream
    std::fstream fileReader;
    // Open file
    fileReader.open(ref);
    // Create value to hold number of doubles in file
    int kNumberOfDoubles = 0;
    // Create value to hold the double being read
    double input = 0;
    // Create value to count iterations
    int i = 0;
    // Read number of doubles
    fileReader >> kNumberOfDoubles;
    // While the file is open and good
    while (fileReader) {
        // Read into input
        fileReader >> input;
        // Set array at index i equal to input
        array[i] = input;
        // Add 1 to i to iterate through the array
        ++i;
    }
    // Create temp value
    double temp;
    // Sort array
    for (int i = 0; i < kNumberOfDoubles; ++i) {
        // Look at the index ahead of i
        for (int j = i+1; j < kNumberOfDoubles; ++j) {
            // If the index at i is greater than the one ahead of it
            if (array[i] > array[j]) {
                // Place value at index i in temp value
                temp = array[i];
                // Swap
                array[i] = array[j];
                // Replace with temp
                array[j] = temp;
            }
        }
    }
}

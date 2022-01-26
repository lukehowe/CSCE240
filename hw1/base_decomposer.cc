// Copyright 2022 Luke Howe
#include <iostream>
#include <cmath>
int main(int argc, char *argv[]) {
int input;
bool isNegative = false;
std::cin >> input;
if (input < 0) {
  isNegative = true;
  input = input*(-1);
  std::cout << "-(";
  }
// for int i = length of input; i = -1; i--
// i = std::cin.width ?????
//
// find how many numbers are in integer
int numOfNumbers = (log10(input));
// std::cout << isNegative << std::endl;  // PRINTS TRUE OR FALSE
// std::cout << numOfNumbers << " is the powers."  // PRINTS POWER
// << std::endl;
// Create loop to divide input by 10 raised to numOfNum and multiply
// the result by 10 raised to numOfNum, then take the remainder and
// repeat
// while(input > 0) {
// int output = input / (pow(10, numOfNumbers)) * (pow(10, numOfNumbers));
// numOfNumbers = numOfNumbers - 1;
// std::cout << output << " + ";
// INSERT ENDL ^^^
// input = input - output;
// }
// return 0;
for(int i = numOfNumbers; i > -1; i--) {
int step1 = input / (pow(10, i));
int step2 = step1 * (pow(10, i));
input = input - step2;
std::cout << step2;
if(i != 0) {
std::cout << " + ";
}
}
if((isNegative == true)) {
std::cout << ")";
}
// std::cout << std::endl;
}

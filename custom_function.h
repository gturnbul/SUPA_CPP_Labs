// header file: custom_function
#ifndef CUSTOM_FUNCTION_H
#define CUSTOM_FUNCTION_H

#include <iostream>
#include <fstream>
#include <vector>

// function declarations
void read_data(const std::string& filename, std::vector<std::string>& x, std::vector<std::string>& y);

// print the first lines of the data
void print_data(const std::vector<std::string>& x, const std::vector<std::string>& y, int lines);

// calculate the magnitude
void calc_mag(const std::vector<std::string>& x, const std::vector<std::string>& y, std::vector<double>& mag);

// calculate the least squares
void lin_reg(const std::vector<double>& x, const std::vector<double>& y, double& slope, double& intercept);

#endif // CUSTOM_FUNCTION_H

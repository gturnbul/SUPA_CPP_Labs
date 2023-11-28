//code to read in the file input2D_float.txt
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

#include "custom_function.h"

int main() {
    std::ifstream my_input;
    my_input.open("Exercises2023/Ex1_2/input2D_float.txt");

    if (my_input.fail()) {
        std::cout << "Could not open file" << std::endl;
        exit(1);
    } else {
        std::vector<double> x;
        std::vector<double> y;

        std::string line;
        while (getline(my_input, line)) {
            int comma = line.find(',');
            std::string xval = line.substr(0, comma);
            std::string yval = line.substr(comma + 1, line.length());

            // Convert x and y values to double
            double x_double;
            std::stringstream ssx(xval);
            ssx >> x_double;
            
            double y_double;
            std::stringstream ssy(yval);
            ssy >> y_double;

            x.push_back(x_double);
            y.push_back(y_double);

            std::cout << x_double << " " << y_double << std::endl;
        }

        // Perform linear regression
        double slope, intercept;
        lin_reg(x, y, slope, intercept);

        // Output the fitted line equation as a string
        std::string equation = "Fitted Line: y = " + std::to_string(slope) + "x + " + std::to_string(intercept);
        std::cout << equation << std::endl;
    }

    return 0;
}
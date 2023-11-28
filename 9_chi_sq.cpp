#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <cmath>

// Function to perform linear regression
void lin_reg(const std::vector<double>& x, const std::vector<double>& y, double& slope, double& intercept) {
    int n = x.size();

    double meanX = 0.0, meanY = 0.0;
    for (int i = 0; i < n; ++i) {
        meanX += x[i];
        meanY += y[i];
    }
    meanX /= n;
    meanY /= n;

    double numerator = 0.0, denominator = 0.0;
    for (int i = 0; i < n; ++i) {
        numerator += (x[i] - meanX) * (y[i] - meanY);
        denominator += pow((x[i] - meanX), 2);
    }

    slope = numerator / denominator;
    intercept = meanY - slope * meanX;
}

// Function to calculate chi-square
void calc_chi_square(const std::vector<double>& x, const std::vector<double>& y, const std::vector<double>& xerr, const std::vector<double>& yerr, double slope, double intercept, double& chi_square, int& degrees_of_freedom) {
    int n = x.size();

    chi_square = 0.0; // Initialize chi-square to zero

    for (int i = 0; i < n; ++i) {
        double expected_y = slope * x[i] + intercept;
        double total_error = pow(xerr[i], 2) + pow((slope * xerr[i]), 2) + pow(yerr[i], 2);
        chi_square += pow((y[i] - expected_y), 2) / pow(total_error,2);
    }

    degrees_of_freedom = n - 2; // Calculate degrees of freedom
}

int main() {
    std::ifstream my_input;
    my_input.open("Exercises2023/Ex1_2/input2D_float.txt");

    if (my_input.fail()) {
        std::cout << "Could not open file" << std::endl;
        exit(1);
    } else {
        std::vector<double> x;
        std::vector<double> y;
        std::vector<double> xerr;
        std::vector<double> yerr;

        std::string line;
        while (getline(my_input, line)) {
            int comma = line.find(',');
            std::string xval = line.substr(0, comma);
            std::string yval = line.substr(comma + 1, line.length());

            double x_double;
            std::stringstream ssx(xval);
            ssx >> x_double;

            double y_double;
            std::stringstream ssy(yval);
            ssy >> y_double;

            x.push_back(x_double);
            y.push_back(y_double);
        }

        std::ifstream my_err;
        my_err.open("Exercises2023/Ex1_2/error2D_float.txt");
        if (my_err.fail()) {
            std::cout << "Could not open error file" << std::endl;
            exit(1);
        }

        while (getline(my_err, line)) {
            int comma = line.find(',');
            std::string xerrval = line.substr(0, comma);
            std::string yerrval = line.substr(comma + 1, line.length());

            double x_errdouble;
            std::stringstream ssxerr(xerrval);
            ssxerr >> x_errdouble;

            double y_errdouble;
            std::stringstream ssyerr(yerrval);
            ssyerr >> y_errdouble;

            xerr.push_back(x_errdouble);
            yerr.push_back(y_errdouble);
        }

        my_input.close();
        my_err.close();

        double slope, intercept;
        lin_reg(x, y, slope, intercept);

        std::cout << "Fitted Line: y = " << slope << "x + " << intercept << std::endl;

        double chi_square;
        int degrees_of_freedom;
        calc_chi_square(x, y, xerr, yerr, slope, intercept, chi_square, degrees_of_freedom);

        std::cout << "Chi-square: " << chi_square << std::endl;
        std::cout << "Degrees of freedom: " << degrees_of_freedom << std::endl;
    }

    return 0;
}
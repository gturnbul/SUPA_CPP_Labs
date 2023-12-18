#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <vector>

#include "FiniteFunctions.h"

int main() {
    // Create an instance of the FiniteFunction class
    FiniteFunction my_function;

    // Create an ifstream object to read the file
    std::ifstream my_input;

    // Open the file
    my_input.open("MysteryData24202.txt");

    // Check if the file was opened correctly
    if (my_input.fail()) {
        std::cout << "Could not open file" << std::endl;
        exit(1); // from the cstdlib library
    } else {
        std::vector<double> x;

        std::string line;
        while (getline(my_input, line)) {
            // Convert x values to double
            double x_double;
            std::stringstream ssx(line); // Corrected variable name to 'line'
            ssx >> x_double;

            x.push_back(x_double);

            //std::cout << x_double << std::endl;
        }
                // Find min and max values
        double min_x = *min_element(x.begin(), x.end());
        double max_x = *max_element(x.begin(), x.end());

        std::cout << "Min x value: " << min_x << std::endl;
        std::cout << "Max x value: " << max_x << std::endl;

        // Now that you have the dataset, you can use it with the FiniteFunction class

        // Set the range of the function
        my_function.setRangeMin(min_x);
        my_function.setRangeMax(max_x);

        FiniteFunction my_function(min_x, max_x,"my_output");
 
         my_function.plotFunction();
         my_function.plotData(x,40,true);
    }

    return 0;
}
//g++ -std=c++20 -I ../../GNUplot/ -I /opt/homebrew/Cellar/boost/1.83.0/include/ -L /opt/homebrew/Cellar/boost/1.83.0/lib -lboost_iostreams -o UsingFF UsingFF.cpp FiniteFunctions.cxx 
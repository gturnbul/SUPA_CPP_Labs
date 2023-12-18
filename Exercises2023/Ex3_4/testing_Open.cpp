#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <vector>

int main() {
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

          //  std::cout << x_double << std::endl;
        }
    }

    return 0;
}
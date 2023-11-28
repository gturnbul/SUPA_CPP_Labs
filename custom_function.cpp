// CustomFunctions.cpp  is the implementation file for the functions declared in CustomFunctions.h.
#include <algorithm>
#include "custom_function.h"
#include <cmath>

// function to perform the read operation
void read_data(const std::string& file_name, std::vector<std::string>& x, std::vector<std::string>& y) {
    std::ifstream my_input(file_name);

    if (my_input.fail()) {
        std::cout << "could not open file" << std::endl;
        exit(1);
    } else {
        std::string line;
        while (getline(my_input, line)) {
            if (line.empty()) {
                continue;
            }
            int comma = line.find(',');
            x.push_back(line.substr(0, comma));
            y.push_back(line.substr(comma + 1, line.length()));
            std::cout << line << std::endl;
        }
    }
}

// function to print the first x lines of the data
void print_data(const std::vector<std::string>& x, const std::vector<std::string>& y, int no_lines) {
    //create an ifstream object to read the file
    std::ifstream my_input;

    // open the file
    my_input.open("Exercises2023/Ex1_2/input2D_float.txt");

    //check if the file was opened correctly
    if ( my_input.fail()){
        std::cout << "could not open file" << std::endl;
        exit(1); //from the cstdlib library
    }
    else{ 
        //create two vectors to store the x and y values
        std::vector<std::string> x;
        std::vector<std::string> y;

        // read each line 
        std::string line;
        std::string xval;
        std::string yval;
// how many lines to be read?
std::cout << "How many lines would you like to print?" << std::endl;
std::cin >> no_lines;
int linecount = 0;
        while(std::getline(my_input, line) &&linecount < no_lines){
            //find comma position
            int comma = line.find(',');

            //the first string is the x value
            std::string xval = line.substr(0, comma);

            //the second string is the y value
            std::string yval = line.substr(comma+1, line.length());
            
            //add the x and y values to the vectors
            x.push_back(xval); 
            y.push_back(yval);

            //print out the x and y values
            std::cout << xval << " " << yval << std::endl;

            //increment the line count
            linecount++;
        }
    }
}

// function to calculate the magnitude
void calc_mag(const std::vector<std::string>& x, const std::vector<std::string>& y, std::vector<double>& mag) {
   //create an ifstream object to read the file
    std::ifstream my_input;

    // open the file
    my_input.open("Exercises2023/Ex1_2/input2D_float.txt");

    //check if the file was opened correctly
    if ( my_input.fail()){
        std::cout << "could not open file" << std::endl;
        exit(1); //from the cstdlib library
    }
    else{ 
        //create two vectors to store the x and y values
        std::vector<std::string> x;
        std::vector<std::string> y;

        // create a vector to store the magnitude
        std::vector<double> vecval;

        // read each line 
        std::string line;
        std::string xval;
        std::string yval;

        //track first line
        bool first_line = true;

        while(getline(my_input, line)){
            //skip the first line
            if (first_line){
                first_line = false;
                continue;
            }
            
            //find comma position
            int comma = line.find(',');

            //the first string is the x value
            std::string xval = line.substr(0, comma);

            //the second string is the y value
            std::string yval = line.substr(comma+1, line.length());

            //convert the strings to doubles
            double xvals = stod(xval);
            double yvals = stod(yval);

            //calculate the magnitude
            double mag = sqrt(pow(xvals, 2)+pow(yvals, 2));
            
            //add the x and y values to the vectors
            x.push_back(xval); 
            y.push_back(yval);

            //add the magnitude to the vector
            vecval.push_back(mag);

           //print out the x and y values along with the magnitude
           std::cout << xval << " " << yval << " " << mag << std::endl;
        }
    }
}

// Function to perform linear regression
void lin_reg(const std::vector<double>& x, const std::vector<double>& y, double& slope, double& intercept) {
    int n = x.size();

    // Calculate the mean of x and y
    double meanX = 0.0, meanY = 0.0;
    for (int i = 0; i < n; ++i) {
        meanX += x[i];
        meanY += y[i];
    }
    meanX /= n;
    meanY /= n;

    // Calculate slope and intercept
    double numerator = 0.0, denominator = 0.0;
    for (int i = 0; i < n; ++i) {
        numerator += (x[i] - meanX) * (y[i] - meanY);
        denominator += pow((x[i] - meanX), 2);
    }

    slope = numerator / denominator;
    intercept = meanY - slope * meanX;
}


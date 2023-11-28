//code to read in the file input2D_float.txt
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    //create an ifstream object to read the file
    ifstream my_input;

    // open the file
    my_input.open("Exercises2023/Ex1_2/input2D_float.txt");

    //check if the file was opened correctly
    if ( my_input.fail()){
        cout << "could not open file" << endl;
        exit(1); //from the cstdlib library
    }
    else{ 
        //create two vectors to store the x and y values
        vector<string> x;
        vector<string> y;

        // create a vector to store the magnitude
        vector<double> vecval;

        // read each line 
        string line;
        string xval;
        string yval;

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
            string xval = line.substr(0, comma);

            //the second string is the y value
            string yval = line.substr(comma+1, line.length());

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
           cout << xval << " " << yval << " " << mag << endl;
        }
    }
    return 0;
}
//code to read in the file input2D_float.txt
#include <iostream>
#include <fstream>
#include <cstdlib>

#include "custom_function.h"

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
    else{ // what option will it perform if the file was opened correctly?
        cout << "Which option would you like to perform?: (r/w/m)" << endl;
        string option;
        cin >> option;
         //create two vectors to store the x and y values
        vector<string> x;
        vector<string> y;

        if (option == "r"){
         //read the data from the custom_function.cpp file
         read_data("Exercises2023/Ex1_2/input2D_float.txt", x, y);
        }
        else if (option == "w"){
            //print the data from the custom_function.cpp file
             int no_lines;
            print_data(x, y, no_lines); 
            }
        else if (option == "m"){
            //calculate the magnitude from the custom_function.cpp file
            vector<double> magnitude;
            calc_mag(x, y, magnitude);
            }
        else{
            cout << "Invalid option" << endl;
        }
    }
    return 0;
}
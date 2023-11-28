//code to read in the file input2D_float.txt
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main() {
    //create an ifstream object to read the file
    ifstream myInput;

    // open the file
    myInput.open("Exercises2023/Ex1_2/input2D_float.txt");

    //check if the file was opened correctly
    if ( myInput.fail()){
        cout << "could not open file" << endl;
        exit(1); //from the cstdlib library
    }
    else{ 
        //create two vectors to store the x and y values
        vector<string> x;
        vector<string> y;

        // read each line 
        string line;
        string xval;
        string yval;

        while(getline(myInput, line)){
            //find comma position
            int comma = line.find(',');

            //the first string is the x value
            string xval = line.substr(0, comma);

            //the second string is the y value
            string yval = line.substr(comma+1, line.length());
            
            //add the x and y values to the vectors
            x.push_back(xval); 
            y.push_back(yval);

            //print out the x and y values
            cout << xval << " " << yval << endl;
        }
    }
    return 0;
}
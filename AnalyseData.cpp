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
        string line;
        while(getline(myInput, line)){
            cout << line << endl;
        }
    }
    return 0;
}
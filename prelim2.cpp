// this code is to calculate the magnitue of a vector
#include <iostream>

int main() {

//declare and initialise the variables
double x = 2.3;
double y = 4.5;

//create the calculation
double magnitude = sqrt(x*x + y*y);
std::cout << "The magnitude of the vector is " << magnitude << "\n";
}
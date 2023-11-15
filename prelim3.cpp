// this code is to calculate the magnitue of a vector from input functions
#include <iostream>

int main() {

//declare and initialise the variables
double x = 0;
double y = 0;

//ask for the input
std::cout << "Enter the x value of the vector: ";
//input assigned by user added to variable
std::cin >> x;

std::cout << "Enter the y value of the vector: ";
std::cin >> y;

//create the calculation
double magnitude = sqrt(x*x + y*y);
std::cout << "The magnitude of the vector is " << magnitude << "\n";
}
#include <iostream>
#include <fstream>
#include <vector>

#include "gnuplot-iostream.h"

double myFunction(double x) {
    return x * x;
}

int main() {
    // Generate data
    std::vector<std::pair<double, double>> data;
    for (double x = -5.0; x <= 5.0; x += 0.1) {
        double y = myFunction(x);
        data.push_back(std::make_pair(x, y));
    }

    // Plot using Gnuplot
    Gnuplot gp;
    gp << "set terminal pngcairo\n";
    gp << "set output 'my_plot.png'\n";
    gp << "plot '-' with linespoints title 'My Function'\n";
    gp.send1d(data);

    std::cout << "Plot saved as my_plot.png" << std::endl;

    return 0;
}
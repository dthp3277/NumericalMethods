#include <iostream>
#include <cmath>

double f(double x) {
    return cos(x)+sin(x*x);
}

double df(double x) {
    return -sin(x)+2*x*cos(x*x);
}

double newtonRaphson(double x, double tolerance, unsigned int maxIter) {
    if(--maxIter < 0){
        std::cout<<"Max Iteration Reached"<<std::endl;
        exit(2);
    }
    if(std::abs(df(x)) < 0.0001){
        std::cout<<"Derivative is too small"<<std::endl;
        exit(1);
    }
    double x1 = x - f(x) / df(x);
    if (abs(x1 - x) < tolerance) {
        return x1;
    }
    return newtonRaphson(x1, tolerance, maxIter);
}

int main() {
    double x = 1.7, tolerance = 0.0005;
    double root = newtonRaphson(x, tolerance, 1000);
    std::cout << root << std::endl;
    return 0;
}
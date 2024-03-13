#include <iostream>
#include <cmath>

double f(double x) {
    return x*x*x+12*x+8;
}

double bisection(double a, double b, double tolerance, unsigned int maxIter) {
    if(--maxIter < 0){
        std::cout<<"Max Iteration Reached"<<std::endl;
        exit(2);
    }
    
    double c = (a + b) / 2;

    if (std::abs(b - a) < tolerance)
        return c;

    if (f(c) == 0)
        return c;
    if (f(c) * f(a) < 0) 
        return bisection(a, c, tolerance, maxIter);
    return bisection(c, b, tolerance, maxIter);
}

int main() {
    double a = -5, b = 5, tolerance = 0.00005;
    if (f(a) * f(b) >= 0) {
        std::cout << "Invalid a and b" << std::endl;
        exit(1);
    }
    std::cout << bisection(a, b, tolerance, 1000) << std::endl;
    return 0;
}

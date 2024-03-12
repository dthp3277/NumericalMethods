#include <iostream>
#include <cmath>

double f(double x)
{
    return sin(x)+cos(x*x);
}

double secantMethod(double a, double b, double tolerance, unsigned int maxIter)
{
    if (--maxIter < 0)
    {
        std::cout << "Max Iteration Reached" << std::endl;
        exit(2);
    }
    if (abs(f(b) - f(a)) < 0.0001)
    {
        std::cout << "Derivative is too small" << std::endl;
        exit(1);
    }

    double c = b - (f(b) * (b - a)) / (f(b) - f(a));

    if (abs(c - b) < tolerance)
        return c;
    return secantMethod(b, c, tolerance, maxIter);
}

int main()
{
    double a=3, b=7, tolerance=0.00005;
    double root = secantMethod(a, b, tolerance, 10000);

    std::cout << "Root: " << root << std::endl;

    return 0;
}
#include <iostream>

double f(double x){
    return 5 - x*x; // x = sqrt(5)
}
double g(double x){
    return ((5/x)+x)/2;
}

double fixedPointIteration(double x, double tolerance, unsigned int maxIterations){
    for (size_t i = 0; i < maxIterations; i++)
    {
        double x1 = g(x);
        if(std::abs(x-x1)<tolerance) return x1;
        x = x1;
    }
    
    std::cout<<"Couldn't converge in "<<maxIterations<<" iterations"<<std::endl;
    exit(1);
}

int main(){
    double initialGuess = 1.0;
    double tolerance = 0.0005;  
    unsigned int maxIterations = 1000;

    std::cout<<fixedPointIteration(initialGuess, tolerance, maxIterations)<<std::endl;
}
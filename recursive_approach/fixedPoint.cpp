#include <iostream>

double f(double x){
    return 5 - x*x; // x = sqrt(5)
}
double g(double x){
    return ((5/x)+x)/2;
}

double fixedPointIterationRec(double x ,double tolerance, unsigned int maxIterations){
    if(maxIterations == 0){
        std::cout<<"Couldn't converge in maximum iterations"<<std::endl;
        exit(1);
    }

    double x1 = g(x);
    if(std::abs(x-x1)<tolerance) return x1;
    return fixedPointIterationRec(x1, tolerance, --maxIterations);
}
int main(){
    double initialGuess = 1.0;
    double tolerance = 0.0005;  
    unsigned int maxIterations = 1000;

    std::cout<<fixedPointIterationRec(initialGuess, tolerance, maxIterations)<<std::endl;
}
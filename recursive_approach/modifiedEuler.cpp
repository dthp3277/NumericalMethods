#include <iostream>
#include <iomanip>
#include <cmath>
double f(double x, double y){
    return x+y;
}
double originalFunc(double x) {
    return 2 * exp(x) - x - 1;
}
double modifiedEulerApproximater(double x0, double y0, double initialApprox, double h, double tolerance){
    double nextApprox = y0 + h*(f(x0, y0)+f(x0+h, initialApprox))/2;
    if(std::abs(nextApprox-initialApprox)< tolerance) return nextApprox;
    return modifiedEulerApproximater(x0, y0, nextApprox, h, tolerance);
}
double modifiedEuler(double x, double y, double h, double target, double tolerance = 0.005){
    std::cout<<std::left<<std::setw(10)<<x<<std::left<<std::setw(10)<<y<<std::endl;
    if(x>=target) return y;
    double initialApprox = y + h*f(x, y);
    double finalApprox = modifiedEulerApproximater(x, y, initialApprox, h, tolerance);
    return modifiedEuler(x+h, finalApprox, h, target, tolerance);
}
int main(){
    int target = 1;
    double val = modifiedEuler(0, 1, 0.5, target);
    std::cout<<"The value of y(1) through Modified Euler's method is :"<<val<<std::endl;
    std::cout<<"The value of y(1) through Functional value is:"<<originalFunc(target)<<std::endl;
    return 0;
}
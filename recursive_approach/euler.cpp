#include <iostream>
#include <iomanip>
#include <cmath>
double f(double x, double y){
    return x+y;
}
double originalFunc(double x) {
    return 2 * exp(x) - x - 1;
}
double euler(double x, double y, double h, double target){
    std::cout<<std::left<<std::setw(10)<<x<<std::left<<std::setw(10)<<y<<std::endl;
    if(x>=target) return y;
    return euler(x+h, y+h*f(x, y), h, target);
}

int main(){
    int target = 1;
    double val = euler(0, 1, 0.5, target);
    std::cout<<"The value of y(1) through Euler's method is :"<<val<<std::endl;
    std::cout<<"The value of y(1) through Functional value is:"<<originalFunc(target)<<std::endl;
    return 0;
}
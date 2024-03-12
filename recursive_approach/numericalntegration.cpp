#include <iostream>
#include <cmath>

const int N = 1000;

double f(double x){
    return (1/(1+x*x));
}

double trapezoidal(double& from , double& to, double h = 0,  double acc=0, unsigned int i =1){
    if(h == 0){
        h = std::abs(from - to)/N;
    }
    if(i==N-1){
        double s1 = f(from)+f(to);
        return (h/2)*(s1+2*acc);
    }
    return trapezoidal(from, to, h, ++i, acc+f(from+i*h));
}

double simpsons_1_3(double& from , double& to, double h = 0, unsigned int i =1, double acc=0){
    if(h == 0){
        h = std::abs(from - to)/N;
    }
    if(i==N-1){
        double s1 = f(from)+f(to);
        return (h/3)*(s1+acc);
    }
    acc += (i%2 == 0)? 2*f(from+(i)*h) : 4*f(from+(i)*h);
    return simpsons_1_3(from, to, h, ++i, acc);
}

double simpsons_3_8(double& from , double& to, double h = 0, unsigned int i =1, double acc=0){
    if(h == 0){
        h = std::abs(from - to)/(N-1);
    }
    if(i==N-1){
        double s1 = f(from)+f(to);
        return (3*h/8)*(s1+acc);
    }
    acc += (i%3 == 0)? 2*f(from+(i)*h) : 3*f(from+(i)*h);
    return simpsons_3_8(from, to, h, ++i, acc);
}

int main() {
    double a = 0, b = 6;
    
    std::cout << "Using Trapezoidal Rule: " << trapezoidal(a, b) << std::endl;
    std::cout << "Using Simpson's 1/3 Rule: " << simpsons_1_3(a, b) << std::endl;
    std::cout << "Using Simpson's 3/8 Rule: " << simpsons_3_8(a, b) << std::endl;

    return 0;
}
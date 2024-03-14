#include <iostream>
#include <cmath>
using namespace std;
//euler ma graph ko print garne arey

double func1(double x) { return x*x + 5*(x-3);}
double func2(double x) { return exp(x)*sin(x);}
double func3(double x) { return x*x*x - 4*x - 9; }

double secant(double a, double b, double(*f)(double), unsigned int currentCount , unsigned int countLimit) {
    if(fabs(f(b)) < 0.000005) return b;
    if(currentCount >= countLimit) {
            cerr<<"Cannot find the root"<<endl;
            exit(1);
    }

    double fa, fb, c;
    fa = f(a);
    fb = f(b);
    if(fb == fa) {
        cerr<<"Infinity error"<<endl;
        exit(2);
    }
    c = (a*fb - b * fa)/(fb-fa);
    return secant(b, c, f, currentCount++, countLimit);
}

int main() {
    double a, b;
    double(*f[3])(double);
    f[0] = func1;
    f[1] = func2;
    f[2]  = func3;
    for(int i = 0; i < 3; i++) {
    cout<<"Enter the value of a and b: ";
    cin>>a>>b;
    cout<<"The value of the root from Secant Method is: "<<secant(a, b, f[i], 0, 50);
    }
    return 0;
}


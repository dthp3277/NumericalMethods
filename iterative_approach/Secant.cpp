#include <iostream>
#include <cmath>
using namespace std;
//euler ma graph ko print garne arey

double func1(double x) { return x*x + 5*(x-3);}
double func2(double x) { return exp(x)*sin(x);}
double func3(double x) { return x*x*x - 4*x - 9; }

double secant(double a, double b, double(*f)(double)) {
    double fa, fb, c;
    unsigned int count = 0;
    do {
        fa = f(a);
        fb = f(b);
        if(fb == fa) {
            cerr<<"Infinity error"<<endl;
        }
        c = (a*fb - b * fa)/(fb-fa);
        a = b;
        b = c;
        count++;
        if(count > 50) {
            cerr<<"Cannot find the root"<<endl;
        }
    } while(abs(f(c)) > 0.00005);
    return c;
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
    cout<<"The value of the root from Secant Method is: "<<secant(a, b, f[i]);
    }
    return 0;
}

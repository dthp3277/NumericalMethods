#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {
    return x*sin(x);
}

double fd(double x) {
    return x*cos(x) + sin(x);
}

int main() {
    double xi, xii;
    double fun, deriv;
    unsigned int count = 0;
    cout<<"Enter the initial guess: ";
    cin>>xi;
    do {
        if(count >= 250) {
            cout<<"Cannot find the root, The function is discontinuous."<<endl;
            return 2;
        }
        xii = xi;
        fun = f(xi);
        deriv = fd(xi);
        if(abs(deriv) < 0.0000001) {
            cout<<"Cannot find root. Derivative error."<<endl;
            return 1;
        }
        count++;
        xi = xi - f(xi)/fd(xi);
    } while(abs(xii - xi) > 0.00005) ;
    cout<<"After "<<count<<" iterations, ";
    cout<<"The root is: "<<xi;
    return 0;
}

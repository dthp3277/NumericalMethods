#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double slope(double x, double y) {
    return x + y;
}

double originalFunc(double x) {
    return 2 * exp(x) - x - 1;
}

double euler(double stepSize, double x0, double y0, double xValue, double(*ODE)(double, double)) {
    double x = x0, y = y0;
    double s;
    unsigned int count = 0;
    cout<<endl;
    cout<<setw(10)<<'x'<<setw(10)<<'y'<<setw(10)<<endl;
    cout<<setw(10)<<x<<setw(10)<<y<<endl;
    do {
        s = ODE(x, y);  
        y = y + stepSize * s;
        x+=stepSize;
        cout<<setw(10)<<x<<setw(10)<<y<<endl;
        count++;
    } while(x < xValue);
    return y;
}

int main() {
    int x = 1;
    double val = euler(0.5, 0, 1, x, slope);
    cout<<"The value of y(1) through Euler's method is :"<<val<<endl;
    cout<<"The value of y(1) through Functional value is:"<<originalFunc(1);
    return 0;
}

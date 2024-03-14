#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double f1(double x) {
    return 1/(1+x*x);
}
/* ans: Enter x0 and xN: 0 6
The area of the curve from trapezoidal is: 1.40565
The area of the curve from Simpson's 1/3 rule is: 1.40565
The area of the curve from Simpson's 3/8 rule is: 1.40565
*/

double f2(double x) {
    return 2*sin(x*x);
}

double trapezoidal(double(*f)(double), double x0, double xN) {
    const unsigned int n = 300;
    double h = (xN - x0)/n;
    double result = h / 2;
    double sum1 = f(x0) + f(xN);
    double sum2 = 0;
    for(int i = 1; i < n; i++) {
        sum2 += f(x0 + i * h);
    }
    sum2 *= 2;
    result *= sum1 + sum2;
    return result;
}

double simpson1_3(double(*f)(double), double x0, double xN) {
    const unsigned int n = 300;
    double h = (xN - x0)/n;
    double result = h / 3;
    double sum1 = f(x0) + f(xN);
    double sum2 = 0;
    double term;
    for(int i = 1; i < n; i++) {
        term = f(x0 + i * h);
        sum2 += (i % 2 == 0) ? 2 * term : 4 * term;
    }
    result *= sum1 + sum2;
    return result;
}

double simpson3_8(double(*f)(double), double x0, double xN) {
    const unsigned int n = 300;
    double h = (xN - x0)/n;
    double result = 3 * h / 8;
    double sum1 = f(x0) + f(xN);
    double sum2 = 0;
    double term;
    for(int i = 1; i < n; i++) {
        term = f(x0 + i * h);
        sum2 += (i % 3 == 0) ? 2 * term : 3 * term;
    }
    result *= sum1 + sum2;
    return result;
}

int main() {
    double x0, xN;
    cout<<"Enter x0 and xN: ";
    cin>>x0>>xN;
    cout<<"The area of the curve from trapezoidal is: "<<trapezoidal(f2, x0, xN)<<endl;
    cout<<"The area of the curve from Simpson's 1/3 rule is: "<<simpson1_3(f2, x0, xN)<<endl;
    cout<<"The area of the curve from Simpson's 3/8 rule is: "<<simpson3_8(f2, x0, xN)<<endl;
    return 0;
}

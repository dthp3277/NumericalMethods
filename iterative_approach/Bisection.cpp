#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {
    return x*x - 3 + tan(x);
}

int main() {
    double a, b;
    cout<<"Enter the value of the initial intervals  for x * sin(x): ";
    cin>>a>>b;

    double c;
    double value;
    if((f(a) * f(b)) > 0) {
        cout<<"Improper Intervals";
        return 0;
    }
    int count = 0;
    while(true) {
        c = (a+b)/2;
        value = f(c);

        if(abs(value) < 0.00005) break;
        if(count > 25) {
            cout<<"Function is Discontinuous"<<endl;
            return 0;
        }
        if(f(a)*value > 0) {
            a = c;
        } else {
            b = c;
        }
        count++;
    }
    cout<<"The functional value is: "<<f(c)<<endl;
    cout<<"The variable value is: "<<c<<endl;
    return 0;
}

#include <iostream>
#include <cmath>
#include <iomanip>

double df(double x, double y) {
    return x+y;
}

void RK4(double x, double y, double h, double target) {
    std::cout<<std::left<<std::setw(10)<<x<<y<<std::endl;
    if(x >= target){
        return;
    }
    double k1 = h*df(x, y);
    double k2 = h*df(x + h/2, y + k1/2);
    double k3 = h*df(x + h/2, y + k2/2);
    double k4 = h*df(x + h, y + k3);

    RK4(x+h, y + (k1 + 2*k2 + 2*k3 + k4)/6, h, target);
}

int main() {
    RK4(0, 1, 0.2, 0.4);
    return 0;
}
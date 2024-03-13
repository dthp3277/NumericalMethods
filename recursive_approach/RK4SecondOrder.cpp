#include <iostream>
#include <iomanip>
double f(double x, double y, double z){
    return z;
}

double g(double x, double y, double z){
    return x+2*y+z;
}

void RK4(double x, double y, double z, double h, double target){
    std::cout<<std::left<<std::setw(10)<<x<<std::left<<std::setw(10)<<y<<z<<std::endl;
    if(x>=target) return;

    double k1 = h*f(x, y, z);
    double l1 = h*g(x, y, z);
    double k2 = h*f(x+h/2, y+k1/2, z+l1/2);
    double l2 = h*g(x+h/2, y+k1/2, z+l1/2);
    double k3 = h*f(x+h/2, y+k2/2, z+l2/2);
    double l3 = h*g(x+h/2, y+k2/2, z+l2/2);
    double k4 = h*f(x+h, y+k3, z+l3);
    double l4 = h*g(x+h, y+k3, z+l3);

    return RK4(x+h, y+(k1+2*k2+2*k3+k4)/6, z+(l1+2*l2+2*l3+l4)/6, h, target);
}


int main(){
    RK4(0, 1, -0.25, 0.5, 1);
    return 0;
}
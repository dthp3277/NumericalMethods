#include <iostream>
#include <iomanip>
double f(double x, double y, double z){
    return z;
}

double g(double x, double y, double z){
    return x-y-2*z;
}

double RK4(double x, double y, double z, double h, double target){
    std::cout<<std::left<<std::setw(10)<<x<<std::left<<std::setw(10)<<y<<z<<std::endl;
    if(x>=target) return y;

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

/// @param M1 First guess
/// @param M2 Second guess
void ShootingRK4(double x0, double y0, double xN, double yN, double h=0.25, double M1 = 10, double M2 =5){
    std::cout<<"First shot with M = "<<M1<<std::endl;
    double b1 = RK4(x0, y0, M1, h, xN);
    std::cout<<"Second shot with M = "<<M2<<std::endl;
    double b2 = RK4(x0, y0, M2, h, xN);

    double M = M1 + (M2-M1)*(yN-b1)/(b2-b1);
    std::cout<<"Final shot with M = "<<M<<std::endl;
    RK4(x0, y0, M, h, xN);
}
int main(){
    ShootingRK4(0, 1, 2, 3, 0.5);
    return 0;
}
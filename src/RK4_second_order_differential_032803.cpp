#include <iostream>
#include <vector>
#include <cmath>


using namespace std;

double f(double x, double y, double z) {
    return z;
}

double g(double x, double y, double z) {
    return x + 2*y + z;
}

vector<double> solveDiff(const double& x0, const double&  y0, const double& z0, const double& xN, double h) {
    double k1, k2, k3, k4, l1, l2, l3, l4, k, l;
    double x = x0, y = y0, z = z0;
    while(x < xN) {
        k1 = h * f(x, y, z);
        l1 = h * g(x, y, z);
        k2 = h * f(x + h/2, y + k1/2, z + l1/2);
        l2 = h * g(x + h/2, y + k1/2, z + l1/2);
        k3 = h * f(x + h/2, y + k2/2, z + l2/2);
        l3 = h * g(x + h/2, y + k2/2, z + l2/2);
        k4 = h * f(x + h, y + k3, z + l3);
        l4 = h * g(x + h, y + k3, z + l3);

        k = (k1+2*k2+2*k3+k4)/6;
        l = (l1+2*l2+2*l3+l4)/6;

        cout<<"x = "<<x<<", y = "<<y<<"  z = "<<z<<endl;

        x += h;
        y += k;
        z += l;
    }
    vector<double> result;
    result.push_back(y);
    result.push_back(z);
    return result;
}

int main() {
    solveDiff(0, 1, -0.25, 1, 0.5);
    return 0;
}

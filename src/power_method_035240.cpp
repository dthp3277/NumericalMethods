#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<double> mat_mul(vector<vector<double>> mat1, vector<double> mat2) {
    double sum;
    vector<double> result(mat1.size(), 0);
    for(int i = 0; i < mat1.size(); i++) {
        sum = 0;
        for(int j = 0; j < mat1.size(); j++) {
            sum += mat1[i][j] * mat2[j];
        }
        result[i] = sum;
    }
    return result;
}

void power_method(vector<vector<double>> A, vector<double> X, double e) {
    vector<double> Z;
    vector<double> Y(X.size(), 0.f);
    vector<double> YminusX(X.size(), 0.f);
    double error;
    double L;
    do {
        cout<<"*";
        Z = mat_mul(A, X);
        L = *max_element(Z.begin(), Z.end());
        for(int i = 0; i < X.size(); i++) {
                Y[i] = Z[i] / L;
                YminusX[i] = fabs(Y[i] - X[i]);
        }
        error = *max_element(YminusX.begin(), YminusX.end());
        X = Y;
    } while(error > e);
    cout<<"L = "<<L<<endl;
    cout<<"Y : "<<endl;
    for(auto i : Y) cout<<i<<' ';
}

int main() {
    int n;
    double e;
    cout<<"Enter the value of n: ";
    cin>>n;
    vector<vector<double>> A(n, vector<double>(n, 0.f));
    vector<double> X(n, 0.f);
    cout<<"Enter the matrix: ";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin>>A[i][j];
    cout<<"Enter the guess matrix: ";
    for(int i = 0; i < n; i++) cin>>X[i];
    cout<<"Enter the tolerance: ";
    cin>>e;
    power_method(A, X, e);
    return 0;
}

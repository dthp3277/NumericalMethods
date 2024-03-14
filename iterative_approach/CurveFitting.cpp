#include <iostream>
#include <cmath>
#include <string>
#include <utility>
#include <vector>
#include "gauss_jordan.cpp"

using namespace std;

void printMatrix(vector<vector<double>> mat) {
    for(int i = 0; i < mat.size(); i++) {
        for(int j = 0; j < mat[i].size(); j++) {
            cout<<mat[i][j]<<'\t';
        }
        cout<<endl;
    }
}

vector<double> polynomialFit(vector<pair<double, double>> data, int d) {
    vector<vector<double>> aug(d+1, vector<double>(d+2, 0));

    for(int i = 0; i <= d; i++) {
        for(int j = 0; j <= d; j++) {
            for(int k = 0; k < data.size(); k++) {
                aug[i][j] += pow(data[k].first, i + j);
            }
        }
        for(int k = 0; k < data.size(); k++) {
            aug[i][d+1] += pow(data[k].first, i) * data[k].second;
        }
    }

    vector<double> result(d+1, 0);
    result = gaussjordan(aug);
    return result;

}

void printResult(vector<double> data) {
    cout<<"The values of coefficients are: ";
    for(int i = 0; i < data.size(); i++) {
        cout<<data[i]<<' ';
    }
    cout<<endl;
}

void printData(vector<pair<double, double>> data) {
    for(int i = 0; i < data.size(); i++) {
        cout<<"x = "<<data[i].first<<"y = "<<data[i].second<<endl;
    }
}



int main() {
    int n, d;
    cout<<"Enter the no. of data: ";
    cin>>n;
    cout<<"Enter the degree of polynomial: ";
    cin>>d;
    if(n <= d) cout<<"Error! n must be greather than d ";
    vector<pair<double, double>> data;
    double x, y;
    for(int i = 0; i < n; i++) {
        cout<<"Enter x and y: ";
        cin>>x>>y;
        data.push_back(pair<double, double>(x, y));
    }
    //printData(data);
    vector<double> result = polynomialFit(data, d);
    printResult(result);
    return 0;
}
